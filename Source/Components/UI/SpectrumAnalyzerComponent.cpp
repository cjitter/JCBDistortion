#include "SpectrumAnalyzerComponent.h"

SpectrumAnalyzerComponent::SpectrumAnalyzerComponent(juce::AudioProcessorValueTreeState& apvts)
    : valueTreeState(apvts),
      forwardFFT(fftOrder),
      window(fftSize, juce::dsp::WindowingFunction<float>::hann)
{
    // Inicializar buffers (diseño lock-free)
    fifo.fill(0.0f);
    fftCopy.fill(0.0f);
    fftData.fill(0.0f);
    scopeData.fill(0.0f);
    copyScopeData.fill(0.0f);
    peakHoldData.fill(0.0f);
    
    // Iniciar timer para actualizaciones de display (30 FPS estable)
    startTimerHz(30);
    
    setOpaque(false);
}

SpectrumAnalyzerComponent::~SpectrumAnalyzerComponent()
{
    // Establecer flag de destrucción PRIMERO para prevenir nuevo procesamiento de audio
    isDestroying.store(true, std::memory_order_release);
    
    // Detener timer ANTES de destruir cualquier dato
    stopTimer();
    
    // Pequeña demora para asegurar que callbacks de audio en curso terminen
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void SpectrumAnalyzerComponent::setSampleRate(double newSampleRate) noexcept
{
    currentSampleRate.store(newSampleRate);
}

void SpectrumAnalyzerComponent::pushNextSampleIntoFifo(float sample) noexcept
{
    // Verificar si el componente está siendo destruido - abortar inmediatamente
    if (isDestroying.load(std::memory_order_acquire))
        return;
    
    // Implementación lock-free para thread de audio - NUNCA USAR MUTEX
    auto currentIndex = fifoIndex.load(std::memory_order_relaxed);
    
    // Verificación de límites por seguridad
    if (currentIndex >= 0 && currentIndex < fftSize)
    {
        fifo[currentIndex] = sample;
    }
    
    auto newIndex = currentIndex + 1;
    if (newIndex >= fftSize)
    {
        // Bloque listo, intentar establecer flag atómicamente con ordenamiento de memoria correcto
        bool expected = false;
        if (nextFFTBlockReady.compare_exchange_weak(expected, true, std::memory_order_release, std::memory_order_relaxed))
        {
            // Flag establecido exitosamente, copiar a buffer intermedio (SIN MUTEX - LOCK FREE)
            // Esto es seguro porque solo el thread de audio escribe en fftCopy
            std::copy(fifo.begin(), fifo.end(), fftCopy.begin());
        }
        newIndex = 0;
    }
    
    fifoIndex.store(newIndex, std::memory_order_relaxed);
}

void SpectrumAnalyzerComponent::timerCallback()
{
    // Verificar si el componente está siendo destruido
    if (isDestroying.load(std::memory_order_acquire))
        return;
    
    // Verificar si hay nuevos datos FFT listos usando operación atómica con ordenamiento de memoria correcto
    bool expected = true;
    if (nextFFTBlockReady.compare_exchange_weak(expected, false, std::memory_order_acquire, std::memory_order_relaxed))
    {
        // Flag adquirido exitosamente, copiar de buffer intermedio a buffer de procesamiento
        {
            std::lock_guard<std::mutex> lock(guiMutex);  // Solo el thread GUI usa este mutex
            juce::zeromem(fftData.data(), sizeof(fftData));
            std::copy(fftCopy.begin(), fftCopy.end(), fftData.begin());
        }
        
        // Procesar datos FFT (esto actualiza scopeData)
        drawNextFrameOfSpectrum();
        
        // Copiar scopeData a buffer de pintado thread-safe
        {
            std::lock_guard<std::mutex> lock(guiMutex);
            std::copy(scopeData.begin(), scopeData.end(), copyScopeData.begin());
            scopeDataReady.store(true, std::memory_order_release);
        }
        
        repaint();
    }
}

void SpectrumAnalyzerComponent::drawNextFrameOfSpectrum()
{
    // Procesar datos FFT (mutex ya manejado en timerCallback)
    // Aplicar función de ventana
    window.multiplyWithWindowingTable(fftData.data(), fftSize);
    
    // Ejecutar FFT
    forwardFFT.performFrequencyOnlyForwardTransform(fftData.data());
    
    // Rango dinámico de display del espectro basado en estado de zoom
    auto mindB = zoomEnabled.load() ? zoomedMinDB : defaultMinDB;
    auto maxdB = zoomEnabled.load() ? zoomedMaxDB : defaultMaxDB;
    
    for (int i = 0; i < scopeSize; ++i)
    {
        
        // Mapeo de frecuencia logarítmico VERDADERO: 20Hz a 20kHz
        // 1kHz aparece exactamente al 50% del display (centro logarítmico)
        float normalizedPosition = (float)i / (float)scopeSize;
        
        auto logMin = std::log10(20.0f);      // 20Hz
        auto logMax = std::log10(20000.0f);   // 20kHz
        auto logFreq = logMin + normalizedPosition * (logMax - logMin);
        float freq = std::pow(10.0f, logFreq);
        
        // Convertir frecuencia a índice de bin FFT usando sample rate dinámico
        auto sampleRate = currentSampleRate.load();
        
        // Verificación de límites por seguridad
        if (sampleRate <= 0.0)
        {
            continue; // Saltar sample rate inválido
        }
        
        auto exactBinIndex = freq * (float)fftSize / (float)sampleRate;
        
        // Lógica de interpolación inteligente para frecuencias bajas
        int binIndex1, binIndex2;
        float fraction;
        
        if (exactBinIndex < 1.0f)
        {
            // Debajo del bin 1: sin datos espectrales válidos (bajo resolución de frecuencia fundamental)
            binIndex1 = 1;
            binIndex2 = 1;
            fraction = 0.0f;  // Usar valor de bin 1 sin interpolación
        }
        else if (exactBinIndex < 2.0f)
        {
            // Entre bins 1 y 2: interpolación correcta en rango fundamental
            binIndex1 = 1;
            binIndex2 = 2;
            fraction = exactBinIndex - 1.0f;
        }
        else
        {
            // Caso normal: interpolación estándar para frecuencias más altas
            binIndex1 = (int)exactBinIndex;
            binIndex2 = binIndex1 + 1;
            fraction = exactBinIndex - (float)binIndex1;
            
            // Límites estándar para frecuencias más altas
            binIndex1 = juce::jlimit(1, (int)(fftSize / 2 - 2), binIndex1);
            binIndex2 = juce::jlimit(2, (int)(fftSize / 2 - 1), binIndex2);
        }
        
        // Acceso seguro a array con verificación de límites
        auto magnitude1 = 0.0f;
        auto magnitude2 = 0.0f;
        
        if (binIndex1 >= 1 && binIndex1 < (fftSize / 2))
        {
            magnitude1 = fftData[binIndex1];
        }
        if (binIndex2 >= 1 && binIndex2 < (fftSize / 2))
        {
            magnitude2 = fftData[binIndex2];
        }
        
        // Interpolación mejorada: precisión dependiente de frecuencia para mejor detalle en agudos
        float interpolatedMagnitude;
        
        if (binIndex1 == binIndex2) 
        {
            interpolatedMagnitude = magnitude1;
        }
        else if (freq >= 2000.0f && magnitude1 > 1e-8f && magnitude2 > 1e-8f)  
        {
            // Precisión en altas frecuencias: usar interpolación geométrica para mejor precisión en agudos
            auto logMag1 = std::log(magnitude1 + 1e-10f);
            auto logMag2 = std::log(magnitude2 + 1e-10f);
            auto logInterpolated = logMag1 + fraction * (logMag2 - logMag1);
            interpolatedMagnitude = std::exp(logInterpolated);
        }
        else 
        {
            // Interpolación lineal estándar para frecuencias más bajas
            interpolatedMagnitude = magnitude1 + fraction * (magnitude2 - magnitude1);
        }
        
        // Calcular nivel en dB con normalización FFT correcta y corrección de ventana
        auto clampedMagnitude = juce::jmax(interpolatedMagnitude, 1e-10f);
        
        // Normalización correcta de magnitud FFT: -20*log10(fftSize/2) en lugar de -20*log10(fftSize)
        // Esto corrige el error de ~6dB en el cálculo anterior
        auto fftNormalizationdB = 20.0f * std::log10((float)fftSize / 2.0f);
        
        // Corrección de ventana Hann: ELIMINADA - causaba offset de +6dB vs analizadores profesionales
        // auto hannWindowCorrection = 6.0f;  // DESHABILITADO: causa exceso de +6dB
        
        auto dbValue = juce::Decibels::gainToDecibels(clampedMagnitude) - fftNormalizationdB;  // Sin corrección de ventana
        
        // Usar valores dB crudos sin NINGUNA compensación de frecuencia para espectro natural
        auto clampedDbValue = juce::jlimit(mindB, maxdB, dbValue);
        
        // Convertir dB a posición de display (0.0 = abajo, 1.0 = arriba)
        // Esto da escalado logarítmico correcto donde -24dB aparece en el medio
        auto level = (clampedDbValue - mindB) / (maxdB - mindB);
        
        // Suavizado adaptativo dependiente de frecuencia para mejor visibilidad en agudos
        auto difference = std::abs(level - scopeData[i]);
        
        // Determinar factor de suavizado basado en frecuencia
        float baseSmoothingFactor;
        if (freq >= 4000.0f)  // Frecuencias altas (4kHz+): Menos suavizado, preservar transitorios
        {
            baseSmoothingFactor = 0.35f;  // Mayor respuesta para detalle en agudos
        }
        else if (freq >= 1000.0f)  // Frecuencias medias (1-4kHz): Suavizado moderado
        {
            baseSmoothingFactor = 0.25f;  // Suavizado balanceado
        }
        else  // Frecuencias bajas (<1kHz): Más suavizado para estabilidad
        {
            baseSmoothingFactor = 0.15f;  // Más estabilidad en graves
        }
        
        auto adaptiveSmoothing = juce::jlimit(0.1f, 0.5f, baseSmoothingFactor + difference * 0.3f);
        scopeData[i] = scopeData[i] * (1.0f - adaptiveSmoothing) + level * adaptiveSmoothing;
        
        // Actualizar datos de peak hold (thread-safe)
        if (level > peakHoldData[i])
        {
            peakHoldData[i] = level;
            peakHoldCounter.store(0);  // Reiniciar contador atómicamente cuando se encuentra nuevo pico
        }
    }
    
    // Decaimiento de peak hold dependiente de frecuencia con contador atómico
    auto currentCounter = peakHoldCounter.fetch_add(1);
    if (currentCounter > peakHoldFrames)
    {
        for (int i = 0; i < scopeSize; ++i)
        {
            {
                // Calcular frecuencia para este punto de display para tasa de decaimiento
                auto logMin = std::log10(20.0f);      // 20Hz
                auto logMax = std::log10(20000.0f);   // 20kHz
                auto logFreq = logMin + ((float)i / (float)scopeSize) * (logMax - logMin);
                auto freq = std::pow(10.0f, logFreq);
                
                // Tasa de decaimiento dependiente de frecuencia: agudos se mantienen más, graves decaen más rápido
                float decayRate;
                if (freq >= 2000.0f)  // Frecuencias altas: decaimiento más lento para visibilidad
                {
                    decayRate = 0.985f;  // Decaimiento lento preserva picos de agudos más tiempo
                }
                else if (freq >= 500.0f)  // Frecuencias medias: decaimiento moderado
                {
                    decayRate = 0.98f;   // Decaimiento estándar
                }
                else  // Frecuencias bajas: decaimiento más rápido para display más limpio
                {
                    decayRate = 0.975f;  // Decaimiento rápido previene acumulación en graves
                }
                
                peakHoldData[i] *= decayRate;
            }
        }
    }
}

void SpectrumAnalyzerComponent::paint(juce::Graphics& g)
{
    drawFrame(g, getLocalBounds());
}

void SpectrumAnalyzerComponent::drawFrame(juce::Graphics& g, const juce::Rectangle<int>& bounds)
{
    // Fondo oscuro
    g.fillAll(juce::Colour(0x001a1a1a));
    
    // Dibujar línea de espectro con codificación de color basada en frecuencia
    if (!bypassMode.load())
    {
        auto width = bounds.getWidth();
        auto height = bounds.getHeight();
        
        // Dibujar espectro con colores gradientes: púrpura para graves, azul para agudos
        // Esto coincide con los colores de los botones A/B del plugin
        auto purpleColor = juce::Colour(0xFF9C27B0);  // Frecuencias graves (púrpura como botón A)
        auto blueColor = juce::Colour(0xFF2196F3);    // Frecuencias agudas (azul como botón B)
        
        juce::Path spectrumPath;
        
        // Construir el path completo usando copia thread-safe (sin mutex necesario en paint)
        // Solo proceder si tenemos datos de scope válidos listos
        if (scopeDataReady.load(std::memory_order_acquire))
        {
            for (int i = 0; i < scopeSize; ++i)
            {
                {
                    auto x = juce::jmap((float)i, 0.0f, (float)scopeSize, 0.0f, (float)width);
                    auto y = juce::jmap(copyScopeData[i], 0.0f, 1.0f, (float)height, 0.0f);
                    
                    // Limitar valor y para prevenir dibujo fuera de límites
                    y = juce::jlimit(0.0f, (float)height, y);
                    
                    if (i == 0)
                        spectrumPath.startNewSubPath(x, y);
                    else
                        spectrumPath.lineTo(x, y);
                }
            }
        }
        else
        {
            // Sin datos listos aún, dibujar path vacío
            spectrumPath.startNewSubPath(0.0f, (float)height);
            spectrumPath.lineTo((float)width, (float)height);
        }
        
        // Dibujar segmentos con gradiente de color basado en frecuencia
        const int numSegments = 32;  // Número de segmentos de color
        for (int seg = 0; seg < numSegments; ++seg)
        {
            float startRatio = (float)seg / (float)numSegments;
            float endRatio = (float)(seg + 1) / (float)numSegments;
            
            // Interpolar color de púrpura (graves) a azul (agudos)
            auto segmentColor = purpleColor.interpolatedWith(blueColor, startRatio);
            g.setColour(segmentColor.withAlpha(0.9f));
            
            // Crear región recortada para este segmento
            auto clipBounds = bounds.toFloat();
            clipBounds.setX(startRatio * width);
            clipBounds.setWidth((endRatio - startRatio) * width);
            
            g.saveState();
            g.reduceClipRegion(clipBounds.toNearestInt());
            g.strokePath(spectrumPath, juce::PathStrokeType(1.8f));
            g.restoreState();
        }
    }
    
    // Dibujar grilla
    g.setColour(juce::Colours::white.withAlpha(0.1f));
    
    // Grilla logarítmica con espaciado correcto
    std::vector<float> gridFrequencies = {50.0f, 100.0f, 200.0f, 500.0f, 1000.0f, 2000.0f, 5000.0f, 10000.0f};
    
    for (float freq : gridFrequencies)
    {
        // Calcular posición usando mapeo logarítmico VERDADERO (igual que datos del espectro)
        auto logMin = std::log10(20.0f);      // 20Hz
        auto logMax = std::log10(20000.0f);   // 20kHz
        auto logFreq = std::log10(freq);
        auto position = (logFreq - logMin) / (logMax - logMin);
        
        auto x = bounds.getWidth() * position;
        g.drawVerticalLine(x, 0.0f, (float)bounds.getHeight());
    }
    
    // Líneas horizontales de amplitud dinámicas basadas en estado de zoom
    auto currentMinDB = zoomEnabled.load() ? zoomedMinDB : defaultMinDB;
    auto currentMaxDB = zoomEnabled.load() ? zoomedMaxDB : defaultMaxDB;
    
    // Elegir líneas de grilla basadas en nivel de zoom
    std::vector<float> gridAmplitudes;
    if (zoomEnabled.load())
    {
        // Modo con zoom: enfoque en niveles más altos
        gridAmplitudes = {-6.0f, -12.0f, -18.0f, -24.0f, -30.0f, -36.0f, -42.0f};
    }
    else
    {
        // Modo rango completo: cobertura más amplia
        gridAmplitudes = {-6.0f, -12.0f, -18.0f, -24.0f, -36.0f, -48.0f, -60.0f};
    }
    
    for (float ampDB : gridAmplitudes)
    {
        // Calcular posición usando rango dinámico actual
        float position = (ampDB - currentMinDB) / (currentMaxDB - currentMinDB);
        auto y = bounds.getHeight() * (1.0f - position); // Invertir Y (0 = arriba)
        
        // Solo dibujar si está dentro de los límites del rango actual
        if (ampDB >= currentMinDB && ampDB <= currentMaxDB && y >= 0.0f && y <= bounds.getHeight())
        {
            g.drawHorizontalLine(y, 0.0f, (float)bounds.getWidth());
        }
    }
    
    // Etiquetas
    g.setColour(juce::Colours::white.withAlpha(0.6f));
    g.setFont(9.0f);
    
    // Etiquetas de frecuencia en líneas clave de grilla (espaciado logarítmico)
    std::vector<std::pair<float, juce::String>> frequencyLabels = {
        {100.0f, "100"},
        {500.0f, "500"},
        {1000.0f, "1k"},
        {2000.0f, "2k"},
        {5000.0f, "5k"},
        {10000.0f, "10k"}
    };
    
    for (auto& label : frequencyLabels)
    {
        float freq = label.first;
        juce::String text = label.second;
        
        // Calcular posición usando mapeo logarítmico VERDADERO (igual que datos del espectro)
        auto logMin = std::log10(20.0f);      // 20Hz
        auto logMax = std::log10(20000.0f);   // 20kHz
        auto logFreq = std::log10(freq);
        auto position = (logFreq - logMin) / (logMax - logMin);
        
        auto x = bounds.getWidth() * position;
        g.drawText(text, x - 15, bounds.getBottom() - 15, 30, 12, juce::Justification::centred);
    }
    
    // Etiquetas de rango (esquinas)
    g.setFont(8.0f);
    g.drawText("20Hz", bounds.getX() + 22, bounds.getBottom() - 15, 25, 12, juce::Justification::left);
    g.drawText("20kHz", bounds.getRight() - 27, bounds.getBottom() - 15, 25, 12, juce::Justification::right);
    
    // Etiquetas de amplitud dinámicas basadas en estado de zoom actual
    g.setFont(8.0f);
    
    // Usar mismas amplitudes de grilla que las líneas
    for (float ampDB : gridAmplitudes)
    {
        // Calcular posición Y usando rango dinámico actual
        float position = (ampDB - currentMinDB) / (currentMaxDB - currentMinDB);
        auto y = bounds.getHeight() * (1.0f - position); // Invertir Y (0 = arriba)
        
        // Solo dibujar etiqueta si está dentro del rango actual y límites de pantalla
        if (ampDB >= currentMinDB && ampDB <= currentMaxDB && 
            y >= 12.0f && y <= bounds.getHeight() - 12.0f)
        {
            juce::String dbText = juce::String((int)ampDB);
            g.drawText(dbText, bounds.getX() + 2, y - 6, 20, 12, juce::Justification::right);
        }
    }
    
    // Etiquetas dinámicas de dB superior e inferior basadas en rango actual
    g.drawText(juce::String((int)currentMaxDB), bounds.getX() + 2, bounds.getY() + 2, 20, 12, juce::Justification::right);
    g.drawText(juce::String((int)currentMinDB), bounds.getX() + 2, bounds.getBottom() - 25, 20, 12, juce::Justification::right);
    
}

void SpectrumAnalyzerComponent::setBypassMode(bool enabled) noexcept
{
    bypassMode.store(enabled);
}

void SpectrumAnalyzerComponent::setFrequencyScale(FrequencyScale scale) noexcept
{
    currentScale = scale;
    repaint();
}

void SpectrumAnalyzerComponent::setZoomEnabled(bool enabled) noexcept
{
    zoomEnabled.store(enabled);
    repaint(); // Trigger redraw with new range
}

void SpectrumAnalyzerComponent::parameterChanged(const juce::String& parameterID, float newValue)
{
    // Reaccionar al parámetro de bypass
    if (parameterID == "f_BYPASS")
    {
        setBypassMode(newValue > 0.5f);
    }
}

void SpectrumAnalyzerComponent::mouseMove(const juce::MouseEvent& event)
{
    // Tooltip es manejado por el método getTooltip()
}

void SpectrumAnalyzerComponent::mouseDown(const juce::MouseEvent& event)
{
    // Alternar escala de frecuencia al hacer clic
    setFrequencyScale(currentScale == FrequencyScale::Linear ? 
                     FrequencyScale::Logarithmic : 
                     FrequencyScale::Linear);
}

void SpectrumAnalyzerComponent::mouseDoubleClick(const juce::MouseEvent& event)
{
    // Reiniciar o funcionalidad especial
}

juce::String SpectrumAnalyzerComponent::getTooltip()
{
    // El tooltip se establece desde PluginEditor usando setHelpText()
    // Este método debe retornar el helpText establecido por el componente padre
    return getHelpText();
}