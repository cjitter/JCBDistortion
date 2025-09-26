//==============================================================================
//
//  Copyright 2025 Juan Carlos Blancas
//  This file is part of JCBDistortion and is licensed under the GNU General Public License v3.0 or later.
//
//==============================================================================

//==============================================================================
// INCLUDES
//==============================================================================
// Archivos del proyecto
#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Helpers/UTF8Helper.h"

//==============================================================================
// CALLBACK SETTERS (THREAD-SAFE)
//==============================================================================

void JCBDistortionAudioProcessor::setSpectrumAnalyzerCallback(SpectrumCallback callback)
{
    if (callback)
    {
        auto holder = std::make_shared<SpectrumCallback>(std::move(callback));
        std::atomic_store_explicit(&spectrumAnalyzerCallbackShared, holder, std::memory_order_release);
    }
    else
    {
        std::shared_ptr<SpectrumCallback> empty;
        std::atomic_store_explicit(&spectrumAnalyzerCallbackShared, empty, std::memory_order_release);
    }
}

void JCBDistortionAudioProcessor::setSampleRateChangedCallback(SampleRateCallback callback)
{
    if (callback)
    {
        auto holder = std::make_shared<SampleRateCallback>(std::move(callback));
        std::atomic_store_explicit(&sampleRateChangedCallbackShared, holder, std::memory_order_release);
    }
    else
    {
        std::shared_ptr<SampleRateCallback> empty;
        std::atomic_store_explicit(&sampleRateChangedCallbackShared, empty, std::memory_order_release);
    }
}

//==============================================================================
// CONSTRUCTOR Y DESTRUCTOR
//==============================================================================
JCBDistortionAudioProcessor::JCBDistortionAudioProcessor()
    : juce::AudioProcessor(createBusesProperties()),
      apvts(*this, nullptr, "PARAMETERS", createParameterLayout()),  // nullptr = no automatic undo (proven solution tested on jr-granular)
      m_CurrentBufferSize(0),
      editorSize(1260, 360),
      lastPreset(0),
      currentProgram(-1)
{
    // Configurar límites del guiUndoManager para optimizar rendimiento
    guiUndoManager.setMaxNumberOfStoredUnits(0, 20); // Solo 20 transacciones exactas (ahorro de memoria)
    
    
    // Inicializar Gen~ state
    m_PluginState = (CommonState *)JCBDistortion::create(44100, 64);
    JCBDistortion::reset(m_PluginState);

    // Inicializar buffers de Gen~
    m_InputBuffers = new t_sample *[JCBDistortion::num_inputs()];
    m_OutputBuffers = new t_sample *[JCBDistortion::num_outputs()];
    
    for (int i = 0; i < JCBDistortion::num_inputs(); i++) {
        m_InputBuffers[i] = nullptr;
    }
    for (int i = 0; i < JCBDistortion::num_outputs(); i++) {
        m_OutputBuffers[i] = nullptr;
    }

    // Vincular listeners de parámetros de gen~ a APVTS
    for (int i = 0; i < JCBDistortion::num_params(); i++)
    {
        auto name = juce::String(JCBDistortion::getparametername(m_PluginState, i));
        apvts.addParameterListener(name, this);
    }
    
    // IMPORTANTE: Sincronizar valores iniciales con Gen~
    // Esto asegura que Gen~ tenga los valores correctos desde el principio
    for (int i = 0; i < JCBDistortion::num_params(); i++)
    {
        auto paramName = juce::String(JCBDistortion::getparametername(m_PluginState, i));
        if (auto* param = apvts.getRawParameterValue(paramName)) {
            float value = param->load();
            
            // Aplicar misma validación que en parameterChanged() (DISTORTION)
            if (paramName == "a_DRYWET") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "b_DRIVE") {
                value = juce::jlimit(1.0f, 50.0f, value);
            }
            else if (paramName == "c_DC") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "d_MODE") {
                value = juce::jlimit(0.0f, 7.0f, value);
            }
            else if (paramName == "e_CEILING") {
                value = juce::jlimit(-20.0f, 6.0f, value);
            }
            else if (paramName == "f_BYPASS") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "g_BITS") {
                value = juce::jlimit(3.0f, 16.0f, value);
            }
            else if (paramName == "h_BITSON") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "i_TILT") {
                value = juce::jlimit(-6.0f, 6.0f, value);
            }
            else if (paramName == "j_HPF") {
                value = juce::jlimit(20.0f, 1000.0f, value);
            }
            else if (paramName == "k_LPF") {
                value = juce::jlimit(1000.0f, 20000.0f, value);
            }
            else if (paramName == "l_SC") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "k_INPUT") {
                value = juce::jlimit(-12.0f, 12.0f, value);
            }
            else if (paramName == "l_OUTPUT") {
                value = juce::jlimit(-12.0f, 12.0f, value);
            }
            else if (paramName == "m_DOWNSAMPLE") {
                value = juce::jlimit(0.0f, 99.0f, value);
            }
            else if (paramName == "n_DOWNSAMPLEON") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "o_BAND") {
                value = juce::jlimit(0.0f, 2.0f, value);
            }
            else if (paramName == "p_TILTPOS") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "u_TONEPOS") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "t_TONEQ") {
                value = juce::jlimit(0.7071067811865476f, 16.0f, value);
            }
            else if (paramName == "p_DISTON") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "p_BANDSOLO") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "p_SAFELIMITON") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "q_TONEON") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            else if (paramName == "r_TONEFREQ") {
                value = juce::jlimit(20.0f, 20000.0f, value);
            }
            else if (paramName == "s_TILTON") {
                value = juce::jlimit(0.0f, 1.0f, value);
            }
            
            JCBDistortion::setparameter(m_PluginState, i, value, nullptr);
        }
    }

    // DISTORTION: No requiere parámetro AAX de gain reduction
    // Los distorsionadores no tienen reducción dinámica de ganancia como limitadores/maximizadores
}

JCBDistortionAudioProcessor::~JCBDistortionAudioProcessor()
{
    // CRÍTICO: Primero indicar que estamos destruyendo para evitar race conditions
    isBeingDestroyed = true;

    setSpectrumAnalyzerCallback({});
    setSampleRateChangedCallback({});

    // Detener timer AAX inmediatamente (antes que cualquier otra cosa)
    #if JucePlugin_Build_AAX
    stopTimer();
    // Pequeña espera para asegurar que el timer callback no esté ejecutándose
    juce::Thread::sleep(10);
    #endif
    
    // Destruir listeners de parámetros del apvts
    for (int i = 0; i < JCBDistortion::num_params(); i++)
    {
        auto name = juce::String(JCBDistortion::getparametername(m_PluginState, i));
        apvts.removeParameterListener(name, this);
    }
    
    // Limpiar buffers con protección nullptr
    if (m_InputBuffers != nullptr) {
        for (int i = 0; i < JCBDistortion::num_inputs(); i++) {
            if (m_InputBuffers[i] != nullptr) {
                delete[] m_InputBuffers[i];
                m_InputBuffers[i] = nullptr;
            }
        }
        delete[] m_InputBuffers;
        m_InputBuffers = nullptr;
    }
    
    if (m_OutputBuffers != nullptr) {
        for (int i = 0; i < JCBDistortion::num_outputs(); i++) {
            if (m_OutputBuffers[i] != nullptr) {
                delete[] m_OutputBuffers[i];
                m_OutputBuffers[i] = nullptr;
            }
        }
        delete[] m_OutputBuffers;
        m_OutputBuffers = nullptr;
    }
    
    // Destruir Gen~ state al final
    if (m_PluginState != nullptr) {
        JCBDistortion::destroy(m_PluginState);
        m_PluginState = nullptr;
    }
}

//==============================================================================
// MÉTODOS PRINCIPALES DEL AUDIOPROCESSOR
//==============================================================================
void JCBDistortionAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Configuración de canales en modo debug eliminada para release
    
    // Inicializar sample rate y vector size
    m_PluginState->sr = sampleRate;
    m_PluginState->vs = samplesPerBlock;
    
    // Notify spectrum analyzer of sample rate change
    if (auto callback = std::atomic_load_explicit(&sampleRateChangedCallbackShared, std::memory_order_acquire))
    {
        auto& cb = *callback;
        cb(sampleRate);
    }
    
    // Pre-asignar buffers con tamaño máximo esperado para evitar allocations en audio thread
    // Usar un tamaño seguro que cubra la mayoría de casos (4096 samples es común máximo)
    const long maxExpectedBufferSize = juce::jmax(static_cast<long>(samplesPerBlock), 4096L);
    assureBufferSize(maxExpectedBufferSize);
    
    // Pre-asignar vectors de waveform data para evitar resize en audio thread
    {
        std::lock_guard<std::mutex> lock(waveformMutex);
        const size_t maxWaveformSize = static_cast<size_t>(maxExpectedBufferSize);
        currentInputSamples.resize(maxWaveformSize);
        currentProcessedSamples.resize(maxWaveformSize);
    }
    
    // DISTORTION: Latencia mínima fija - no necesita lookahead variable
    // Solo compensar 1 sample mínimo de Gen~ 
    setLatencySamples(0);
    
    // === INICIALIZACIÓN DEL SISTEMA DE BYPASS SUAVE ===
    // Pre-asignar scratch buffers para evitar allocations en audio thread
    ensureScratchCapacity(juce::jmax(static_cast<int>(samplesPerBlock), 4096));
    
    // Configurar longitud del fade desde bypassFadeMs (7ms por defecto)
    {
        const int lenFromMs = juce::roundToInt(bypassFadeMs * static_cast<float>(sampleRate) / 1000.0f);
        bypassFadeLen = juce::jlimit(128, 512, lenFromMs > 0 ? lenFromMs : 128);
    }
    bypassFadePos = 0;
    
    // Estado inicial coherente con el host
    const bool hb = isHostBypassed();
    hostBypassMirror.store(hb, std::memory_order_relaxed);
    bypassState = hb ? BypassState::Bypassed : BypassState::Active;
    lastWantsBypass = hb;

    // Initialize atomic meter values
    // CRITICAL: Changed from SmoothedValue to atomic - no reset() needed
    leftInputRMS.store(-100.0f, std::memory_order_relaxed);
    rightInputRMS.store(-100.0f, std::memory_order_relaxed);
    
    leftOutputRMS.store(-100.0f, std::memory_order_relaxed);
    rightOutputRMS.store(-100.0f, std::memory_order_relaxed);
    
    
    
    // leftSC.store(-100.0f, std::memory_order_relaxed);
    // rightSC.store(-100.0f, std::memory_order_relaxed);
    
    // Configurar buffers auxiliares
    
    trimInputBuffer.setSize(2, samplesPerBlock);
    trimInputBuffer.clear();
    
    // sidechainBuffer.setSize(getTotalNumInputChannels(), samplesPerBlock);
    // sidechainBuffer.clear();
    
    // Inicializar buffers de forma de onda
    currentInputSamples.resize(samplesPerBlock, 0.0f);
    currentProcessedSamples.resize(samplesPerBlock, 0.0f);
    
    // IMPORTANTE: Re-sincronizar todos los parámetros con Gen~ en prepareToPlay
    // Esto asegura que los valores estén correctos cuando el DAW comienza a reproducir
    for (int i = 0; i < JCBDistortion::num_params(); i++)
    {
        auto paramName = juce::String(JCBDistortion::getparametername(m_PluginState, i));
        if (auto* param = apvts.getRawParameterValue(paramName)) {
            float value = param->load();
            JCBDistortion::setparameter(m_PluginState, i, value, nullptr);
        }
    }
}

void JCBDistortionAudioProcessor::releaseResources()
{
    // Limpiar buffers auxiliares
    trimInputBuffer.setSize(0, 0);
    // sidechainBuffer.setSize(0, 0);
}

//==============================================================================
// PROCESAMIENTO DE AUDIO
//==============================================================================
void JCBDistortionAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);
    processBlockCommon(buffer, /*hostWantsBypass*/ false);
}

void JCBDistortionAudioProcessor::processBlockBypassed(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);
    processBlockCommon(buffer, /*hostWantsBypass*/ true);
}

void JCBDistortionAudioProcessor::processBlockCommon(juce::AudioBuffer<float>& buffer, bool hostWantsBypass)
{
    juce::ScopedNoDenormals noDenormals;
    const int numSamples = buffer.getNumSamples();
    const int numChannels = buffer.getNumChannels();
    
    // Ajustar buffers auxiliares si es necesario
    assureBufferSize(numSamples);
    
    // === 1. SIEMPRE capturar entrada ANTES de procesar (crítico para bypass) ===
    ensureScratchCapacity(numSamples);
    float* inL = scratchIn.getWritePointer(0);
    float* inR = scratchIn.getWritePointer(1);
    {
        const float* srcL = buffer.getReadPointer(0);
        const float* srcR = (numChannels > 1) ? buffer.getReadPointer(1) : srcL;
        std::memcpy(inL, srcL, sizeof(float) * static_cast<size_t>(numSamples));
        if (numChannels > 1) 
            std::memcpy(inR, srcR, sizeof(float) * static_cast<size_t>(numSamples));
        else
            std::memcpy(inR, inL, sizeof(float) * static_cast<size_t>(numSamples));
    }
    
    // === 2. Procesar WET con Gen~ (siempre activo, f_BYPASS interno manejado por Gen~) ===
    fillGenInputBuffers(buffer);
    processGenAudio(numSamples);
    fillOutputBuffers(buffer); // buffer = WET procesado
    
    auto* wetL = buffer.getWritePointer(0);
    auto* wetR = (numChannels > 1) ? buffer.getWritePointer(1) : wetL;
    
    // === 3. DRY sin compensación (JCBDistortion no tiene latencia/lookahead) ===
    float* dryL = scratchDry.getWritePointer(0);
    float* dryR = scratchDry.getWritePointer(1);
    // DRY = entrada capturada (sin delay porque no hay latencia)
    for (int n = 0; n < numSamples; ++n) {
        dryL[n] = inL[n];
        if (numChannels > 1) 
            dryR[n] = inR[n];
    }
    
    // === 4. FSM de Bypass y mezcla equal-power (como JCBCompressor) ===
    const bool wantsBypass = hostWantsBypass;
    hostBypassMirror.store(wantsBypass, std::memory_order_relaxed);
    const bool bypassEdge = (wantsBypass != lastWantsBypass);
    lastWantsBypass = wantsBypass;
    
    // Transiciones de estado en flancos (al inicio del bloque)
    switch (bypassState)
    {
        case BypassState::Active:
            if (bypassEdge && wantsBypass) {
                bypassState = BypassState::FadingToBypass;
                bypassFadePos = 0;
            }
            break;
            
        case BypassState::Bypassed:
            if (bypassEdge && !wantsBypass) {
                bypassState = BypassState::FadingToActive;
                bypassFadePos = 0;
            }
            break;
            
        case BypassState::FadingToBypass:
            if (bypassEdge && !wantsBypass) {
                // Revertir fade en curso
                bypassState = BypassState::FadingToActive;
                bypassFadePos = juce::jmax(0, bypassFadeLen - bypassFadePos);
            }
            break;
            
        case BypassState::FadingToActive:
            if (bypassEdge && wantsBypass) {
                // Revertir fade en curso
                bypassState = BypassState::FadingToBypass;
                bypassFadePos = juce::jmax(0, bypassFadeLen - bypassFadePos);
            }
            break;
    }
    
    // === 5. Aplicar estado o fade ===
    const bool fading = (bypassState == BypassState::FadingToBypass || 
                         bypassState == BypassState::FadingToActive);
    
    if (!fading)
    {
        // Estados estables
        if (bypassState == BypassState::Active)
        {
            // WET tal cual (ya está en buffer)
        }
        else // Bypassed
        {
            for (int n = 0; n < numSamples; ++n) {
                wetL[n] = dryL[n];
                if (numChannels > 1) wetR[n] = dryR[n];
            }
        }
    }
    else
    {
        // === Fade con detección de cruce por cero (como JCBCompressor) ===
        int fadeStartOffset = 0;
        const bool startingFadeThisBlock = 
            ((bypassEdge && wantsBypass && bypassState == BypassState::FadingToBypass) ||
             (bypassEdge && !wantsBypass && bypassState == BypassState::FadingToActive)) &&
            (bypassFadePos == 0);
        
        if (startingFadeThisBlock)
        {
            // Buscar cruce por cero en primeras 32 muestras
            const float* refL = (bypassState == BypassState::FadingToBypass) ? dryL : wetL;
            const float* refR = (numChannels > 1) ?
                               ((bypassState == BypassState::FadingToBypass) ? dryR : wetR) : refL;
            
            auto nearZero = [](float x) noexcept { return std::abs(x) < 1.0e-5f; };
            const int searchMax = juce::jmin(32, numSamples - 1);
            
            for (int i = 1; i <= searchMax; ++i)
            {
                const float l0 = refL[i-1], l1 = refL[i];
                const float r0 = refR[i-1], r1 = refR[i];
                const bool zcL = (nearZero(l0) || nearZero(l1) || (l0 * l1 <= 0.0f));
                const bool zcR = (nearZero(r0) || nearZero(r1) || (r0 * r1 <= 0.0f));
                if (zcL || zcR) {
                    fadeStartOffset = i;
                    break;
                }
            }
        }
        
        // Aplicar fade con ventana Hann
        for (int n = 0; n < numSamples; ++n)
        {
            float wWet = 0.0f, wDry = 0.0f;
            
            // Antes del offset, mantener pesos fijos
            if (n < fadeStartOffset)
            {
                if (bypassState == BypassState::FadingToBypass) {
                    wWet = 1.0f; wDry = 0.0f;
                } else {
                    wWet = 0.0f; wDry = 1.0f;
                }
                const float outL = wWet * wetL[n] + wDry * dryL[n];
                const float outR = wWet * wetR[n] + wDry * (numChannels > 1 ? dryR[n] : dryL[n]);
                wetL[n] = outL;
                if (numChannels > 1) wetR[n] = outR;
                continue;
            }
            
            // Calcular pesos del fade
            const float t = juce::jlimit(0.0f, 1.0f,
                                         static_cast<float>(bypassFadePos) / 
                                         static_cast<float>(juce::jmax(1, bypassFadeLen)));
            
            // Ventana Hann (sin²/cos²) para mantener amplitud estable
            const float s = std::sin(t * juce::MathConstants<float>::halfPi);
            const float c = std::cos(t * juce::MathConstants<float>::halfPi);
            
            if (bypassState == BypassState::FadingToBypass) {
                wWet = c * c;  // cos² (de 1 a 0)
                wDry = s * s;  // sin² (de 0 a 1)
            } else {
                wWet = s * s;  // sin² (de 0 a 1)
                wDry = c * c;  // cos² (de 1 a 0)
            }
            
            const float outL = wWet * wetL[n] + wDry * dryL[n];
            const float outR = wWet * wetR[n] + wDry * (numChannels > 1 ? dryR[n] : dryL[n]);
            wetL[n] = outL;
            if (numChannels > 1) wetR[n] = outR;
            
            // Avanzar fade
            ++bypassFadePos;
            if (bypassFadePos >= bypassFadeLen)
            {
                bypassState = (bypassState == BypassState::FadingToBypass) ? 
                             BypassState::Bypassed : BypassState::Active;
                
                // Resto del bloque ya en estado final
                if (bypassState == BypassState::Bypassed) {
                    for (int k = n + 1; k < numSamples; ++k) {
                        wetL[k] = dryL[k];
                        if (numChannels > 1) wetR[k] = dryR[k];
                    }
                }
                // Si Active, WET ya está correcto
                break;
            }
        }
    }
    
    // Safety: sanitize final output and recover Gen state on trips
    #if !defined(JCB_DISABLE_SANITIZER)
    sanitizeStereo(wetL, (numChannels > 1 ? wetR : nullptr), numSamples, nanTripped);
    #endif

    if (nanTripped.exchange(false, std::memory_order_acq_rel))
    {
        JCBDistortion::reset(m_PluginState);

        for (int i = 0; i < JCBDistortion::num_params(); ++i)
        {
            const char* raw = JCBDistortion::getparametername(m_PluginState, i);
            if (auto* p = apvts.getRawParameterValue(juce::String(raw ? raw : "")))
                JCBDistortion::setparameter(m_PluginState, i, p->load(), nullptr);
        }
    }

    // === 6. Análisis y medición post-procesamiento ===
    
    // Feed spectrum analyzer con salida final
    if (buffer.getNumChannels() > 0)
    {
        if (auto callback = std::atomic_load_explicit(&spectrumAnalyzerCallbackShared, std::memory_order_acquire))
        {
            auto& cb = *callback;
            auto* outputSamples = buffer.getReadPointer(0);
            for (int sample = 0; sample < numSamples; ++sample)
            {
                cb(outputSamples[sample]);
            }
        }
    }
    
    // Capturar formas de onda
    captureInputWaveformData(buffer, numSamples);
    captureOutputWaveformData(numSamples);
    
    // Actualizar detección de clipping
    updateClipDetection(buffer, buffer);
    
    // Actualizar medidores
    updateInputMeters(buffer);
    updateOutputMeters(buffer);
}

//==============================================================================
// INTEGRACIÓN GEN~
//==============================================================================

/**
 * Asegurar que los buffers de Gen~ tengan el tamaño correcto
 * CRÍTICO: Esta función gestiona la memoria dinámica para la comunicación con el motor DSP Gen~
 * AUDIO-THREAD SAFE: Solo redimensiona si es absolutamente necesario para evitar RT violations
 */
void JCBDistortionAudioProcessor::assureBufferSize(long bufferSize)
{
    if (bufferSize > m_CurrentBufferSize) {
        // NOTA: RT-safe porque prepareToPlay() pre-asigna hasta 4096 samples
        // Solo se ejecuta este bloque si el DAW solicita > 4096 samples (muy raro)
        
        // Redimensionar buffers de entrada
        for (int i = 0; i < JCBDistortion::num_inputs(); i++) {
            delete[] m_InputBuffers[i];
            m_InputBuffers[i] = new t_sample[bufferSize];
        }
        
        // Redimensionar buffers de salida
        for (int i = 0; i < JCBDistortion::num_outputs(); i++) {
            delete[] m_OutputBuffers[i];
            m_OutputBuffers[i] = new t_sample[bufferSize];
        }
        
        m_CurrentBufferSize = bufferSize;
    }
}

void JCBDistortionAudioProcessor::fillGenInputBuffers(const juce::AudioBuffer<float>& buffer)
{
    const auto mainInputChannels = getMainBusNumInputChannels();
    const int numSamples = buffer.getNumSamples();
    
    if (mainInputChannels > 1) {
        // Modo estéreo - fill main L/R inputs (inputs 0 and 1)
        for (int j = 0; j < numSamples; j++) {
            m_InputBuffers[0][j] = buffer.getReadPointer(0)[j];  // L
            m_InputBuffers[1][j] = buffer.getReadPointer(1)[j];  // R
        }
    } else {
        // Modo mono - duplicar señal mono a ambos canales L/R para procesamiento stereo-linked
        if (mainInputChannels == 1) {
            for (int j = 0; j < numSamples; j++) {
                m_InputBuffers[0][j] = buffer.getReadPointer(0)[j];  // L = mono
                m_InputBuffers[1][j] = buffer.getReadPointer(0)[j];  // R = mono (duplicado)
            }
        }
    }
}

void JCBDistortionAudioProcessor::processGenAudio(int numSamples)
{
    JCBDistortion::perform(m_PluginState,
                          m_InputBuffers,
                          JCBDistortion::num_inputs(),
                          m_OutputBuffers,
                          JCBDistortion::num_outputs(),
                          numSamples);
}

void JCBDistortionAudioProcessor::fillOutputBuffers(juce::AudioBuffer<float>& buffer)
{
    const int numSamples = buffer.getNumSamples();
    const auto mainOutputChannels = getMainBusNumOutputChannels();
    
    // Llenar buffers de salida principales - conversión double a float
    for (int i = 0; i < mainOutputChannels; i++) {
        float* destPtr = buffer.getWritePointer(i);
        const t_sample* srcPtr = m_OutputBuffers[i];
        for (int j = 0; j < numSamples; j++) {
            destPtr[j] = static_cast<float>(srcPtr[j]);
        }
    }
    
    // Preparar buffer para medidor de entrada (después de trim) - conversión double a float
    float* trimL = trimInputBuffer.getWritePointer(0);
    const t_sample* srcL = m_OutputBuffers[3];
    for (int j = 0; j < numSamples; j++) {
        trimL[j] = static_cast<float>(srcL[j]);
    }
    if (trimInputBuffer.getNumChannels() > 1) {
        float* trimR = trimInputBuffer.getWritePointer(1);
        const t_sample* srcR = m_OutputBuffers[4];
        for (int j = 0; j < numSamples; j++) {
            trimR[j] = static_cast<float>(srcR[j]);
        }
    }
}

//==============================================================================
// MEDIDORES DE AUDIO
//==============================================================================
void JCBDistortionAudioProcessor::updateInputMeters(const juce::AudioBuffer<float>& buffer)
{
    const int numSamples = buffer.getNumSamples();
    const auto mainInputChannels = getMainBusNumInputChannels();

    // Calcular valores RMS
    const auto rmsValueL = juce::Decibels::gainToDecibels(trimInputBuffer.getRMSLevel(0, 0, numSamples));
    const auto rmsValueR = (trimInputBuffer.getNumChannels() > 1) ?
    juce::Decibels::gainToDecibels(trimInputBuffer.getRMSLevel(1, 0, numSamples)) : rmsValueL;
    
    // Calcular valores de pico reales
    const auto peakValueL = juce::Decibels::gainToDecibels(trimInputBuffer.getMagnitude(0, 0, numSamples));
    const auto peakValueR = (trimInputBuffer.getNumChannels() > 1) ?
    juce::Decibels::gainToDecibels(trimInputBuffer.getMagnitude(1, 0, numSamples)) : peakValueL;
    
    // Usar combinación ponderada 70% peak + 30% RMS
    const auto displayValueL = (peakValueL * 0.7f) + (rmsValueL * 0.3f);
    const auto displayValueR = (peakValueR * 0.7f) + (rmsValueR * 0.3f);
    
    // Si estamos cerca del clipping (> -3dB), mostrar el valor de pico puro
    const auto inputValueL = (peakValueL > -3.0f) ? peakValueL : displayValueL;
    const auto inputValueR = (peakValueR > -3.0f) ? peakValueR : displayValueR;
    
    // CRÍTICO: Usar atomic store para thread safety
    // No smoothing is done here - just direct atomic updates
    if (mainInputChannels < 2) {
        // Modo mono - ambos medidores muestran el mismo valor
        leftInputRMS.store(inputValueL, std::memory_order_relaxed);
        rightInputRMS.store(inputValueL, std::memory_order_relaxed);
    } else {
        // Modo estéreo - medidores independientes
        leftInputRMS.store(inputValueL, std::memory_order_relaxed);
        rightInputRMS.store(inputValueR, std::memory_order_relaxed);
    }
}

void JCBDistortionAudioProcessor::updateOutputMeters(const juce::AudioBuffer<float>& buffer)
{
    const int numSamples = buffer.getNumSamples();
    const auto mainOutputChannels = getMainBusNumOutputChannels();

    // Calcular valores RMS para el medidor (promedio de potencia)
    const auto rmsValueL = juce::Decibels::gainToDecibels(buffer.getRMSLevel(0, 0, numSamples));
    const auto rmsValueR = (mainOutputChannels > 1) ?
    juce::Decibels::gainToDecibels(buffer.getRMSLevel(1, 0, numSamples)) : rmsValueL;
    
    // Calcular valores de pico reales (máximo absoluto en el buffer)
    const auto peakValueL = juce::Decibels::gainToDecibels(buffer.getMagnitude(0, 0, numSamples));
    const auto peakValueR = (mainOutputChannels > 1) ?
    juce::Decibels::gainToDecibels(buffer.getMagnitude(1, 0, numSamples)) : peakValueL;
    
    // Usar una combinación ponderada de RMS y Peak para mejor visualización
    // 70% peak + 30% RMS da una representación más precisa similar a medidores profesionales
    const auto displayValueL = (peakValueL * 0.7f) + (rmsValueL * 0.3f);
    const auto displayValueR = (peakValueR * 0.7f) + (rmsValueR * 0.3f);
    
    // Si estamos cerca del clipping (> -3dB), mostrar el valor de pico puro
    const auto finalValueL = (peakValueL > -3.0f) ? peakValueL : displayValueL;
    const auto finalValueR = (peakValueR > -3.0f) ? peakValueR : displayValueR;
    
    // CRÍTICO: Usar atomic store para thread safety
    if (mainOutputChannels > 1) {
        // Modo estéreo
        leftOutputRMS.store(finalValueL, std::memory_order_relaxed);
        rightOutputRMS.store(finalValueR, std::memory_order_relaxed);
    } else {
        // Modo mono
        leftOutputRMS.store(finalValueL, std::memory_order_relaxed);
        rightOutputRMS.store(finalValueL, std::memory_order_relaxed);
    }
}

// Los distorsionadores no tienen reducción dinámica de ganancia

/*
void JCBDistortionAudioProcessor::updateSidechainMeters(const juce::AudioBuffer<float>& buffer)
{
    const int numSamples = buffer.getNumSamples();

    // Resetear flags de clipping sidechain para este buffer
    bool scClip[2] = {false, false};
    
    const bool extKeyActive = false;  // Maximizer no tiene external key
    
    // Si EXT KEY no está activo, mostrar silencio en los medidores
    if (!extKeyActive) {
        const auto valueSC = -100.0f;
        
        // leftSC.store(valueSC, std::memory_order_relaxed);
        // rightSC.store(valueSC, std::memory_order_relaxed);
        
        return;  // No procesar más si EXT KEY está desactivado
    }
    
    // CAMBIO: Usar las salidas 5 y 6 de Gen~ (índices 5 y 6 en m_OutputBuffers)
    // Estas salidas ya incluyen el procesamiento de SC TRIM aplicado por Gen~
    if (JCBDistortion::num_outputs() > 6) {
        // Calcular RMS y pico del sidechain desde las salidas de Gen~
        float maxSCL = 0.0f, maxSCR = 0.0f;
        float rmsSumL = 0.0f, rmsSumR = 0.0f;
        
        for (int i = 0; i < numSamples; ++i) {
            // Usar salidas 5 y 6 de Gen~ que ya tienen SC TRIM aplicado
            float sampleL = static_cast<float>(m_OutputBuffers[5][i]);
            float sampleR = static_cast<float>(m_OutputBuffers[6][i]);
            
            // Peak detection
            maxSCL = juce::jmax(maxSCL, std::abs(sampleL));
            maxSCR = juce::jmax(maxSCR, std::abs(sampleR));
            
            // RMS accumulation
            rmsSumL += sampleL * sampleL;
            rmsSumR += sampleR * sampleR;
        }
        
        // Calcular RMS
        float rmsL = std::sqrt(rmsSumL / static_cast<float>(numSamples));
        float rmsR = std::sqrt(rmsSumR / static_cast<float>(numSamples));
        
        const auto rmsValueSCLeft = juce::Decibels::gainToDecibels(rmsL);
        const auto rmsValueSCRight = juce::Decibels::gainToDecibels(rmsR);
        const auto peakValueSCLeft = juce::Decibels::gainToDecibels(maxSCL);
        const auto peakValueSCRight = juce::Decibels::gainToDecibels(maxSCR);
        
        // Detectar clipping basado en el valor de pico
        if (maxSCL >= 0.999f) {  // Usar el mismo umbral que los medidores principales
            scClip[0] = true;
        }
        if (maxSCR >= 0.999f) {
            scClip[1] = true;
        }
        
        // Usar combinación ponderada como en los medidores principales
        const auto displayValueSCLeft = (peakValueSCLeft * 0.7f) + (rmsValueSCLeft * 0.3f);
        const auto displayValueSCRight = (peakValueSCRight * 0.7f) + (rmsValueSCRight * 0.3f);
        
        const auto valueSCLeft = (peakValueSCLeft > -3.0f) ? peakValueSCLeft : displayValueSCLeft;
        const auto valueSCRight = (peakValueSCRight > -3.0f) ? peakValueSCRight : displayValueSCRight;
        
        // if (!isProTools()) {
        //     leftSC.store(valueSCLeft, std::memory_order_relaxed);
        //     rightSC.store(valueSCRight, std::memory_order_relaxed);
        // } else {
        //     // ProTools: usar solo canal izquierdo para ambos medidores
        //     leftSC.store(valueSCLeft, std::memory_order_relaxed);
        //     leftSC.store(valueSCLeft, std::memory_order_relaxed);
        // }
    } else {
        // Sidechain no disponible - mostrar silencio
        const auto valueSC = -100.0f;
        
        // leftSC.store(valueSC, std::memory_order_relaxed);
        // rightSC.store(valueSC, std::memory_order_relaxed);
    }
    
    // Actualizar flags atómicos de clip
    for (int channel = 0; channel < 2; ++channel) {
        if (scClip[channel]) {
            sidechainClipDetected[channel] = true;
        }
    }
}
*/

//==============================================================================
// CONFIGURACIÓN DE BUSES Y PARÁMETROS
//==============================================================================
juce::AudioProcessor::BusesProperties JCBDistortionAudioProcessor::createBusesProperties()
{
    auto propBuses = juce::AudioProcessor::BusesProperties()
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
        .withInput("Input", juce::AudioChannelSet::stereo(), true);
    
    /*
    juce::PluginHostType daw;
    
    if (daw.isProTools())
        propBuses.addBus(true, "Sidechain MONO", juce::AudioChannelSet::mono(), false);
    else
        propBuses.addBus(true, "Sidechain ST", juce::AudioChannelSet::stereo(), false);
    */
    
    return propBuses;
}

// Validación de configuraciones de canales - define qué layouts acepta el plugin
bool JCBDistortionAudioProcessor::isBusesLayoutSupported(const juce::AudioProcessor::BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    juce::ignoreUnused(layouts);
    return true;
#else
    // Verificar bus principal de salida
    auto mainOut = layouts.getMainOutputChannelSet();
    if (mainOut != juce::AudioChannelSet::mono()
        && mainOut != juce::AudioChannelSet::stereo())
        return false;
    
    // Verificar bus principal de entrada
    auto mainIn = layouts.getMainInputChannelSet();
    if (mainIn != juce::AudioChannelSet::mono()
        && mainIn != juce::AudioChannelSet::stereo())
        return false;
    
    // Pro Tools AAX: Rechazar específicamente stereo input → mono output
    // Solo permitir: 1→1, 2→2, 1→2. NO permitir: 2→1
#if JucePlugin_Build_AAX
    // En formato AAX, rechazar siempre stereo input → mono output
    if (mainIn == juce::AudioChannelSet::stereo() && mainOut == juce::AudioChannelSet::mono())
        return false;
#endif
    
    /*
    // Si hay bus de sidechain, verificar que sea válido
    if (layouts.inputBuses.size() > 1)
    {
        auto sidechainBus = layouts.inputBuses[1];
        
        // El sidechain puede estar desactivado (empty)
        if (!sidechainBus.isDisabled())
        {
            // Solo aceptar sidechain mono o estéreo si está activo
            if (sidechainBus != juce::AudioChannelSet::mono() 
                && sidechainBus != juce::AudioChannelSet::stereo())
                return false;
        }
            
        // No aceptar más de 2 buses de entrada
        if (layouts.inputBuses.size() > 2)
            return false;
    }
    */
    
    return true;
#endif
}

/**
 * Crear el layout de parámetros del plugin
 * CRÍTICO: Define todos los parámetros del compresor en orden alfabético
 * Incluye configuración de rangos, valores por defecto y metadata para cada parámetro
 * Version hint 21 fuerza re-escaneo en hosts para parámetros renombrados
 */
juce::AudioProcessorValueTreeState::ParameterLayout JCBDistortionAudioProcessor::createParameterLayout()
{
   const int versionHint = 21;
   std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;

   // a_DRYWET @min 0 @max 1 @default 1 (Mezcla dry/wet)
   auto drywet = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("a_DRYWET", versionHint),
                                                          juce::CharPointer_UTF8("Dry/Wet"),
                                                          juce::NormalisableRange<float>(0.f, 1.f, 0.01f, 1.0f),
                                                          1.f,
                                                          juce::String(),
                                                          juce::AudioParameterFloat::genericParameter,
                                                          [](float value, int){
                                                              if (value <= 0.f)
                                                                  return juce::String("0%");
                                                              else if (value >= 1.f)
                                                                  return juce::String("100%");
                                                              else
                                                                  return juce::String(static_cast<int>(value * 100)) + "%";
                                                          },
                                                          nullptr);

   // b_DRIVE @min 1 @max 50 @default 1 (Drive/saturación)
   auto drive = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("b_DRIVE", versionHint),
                                                              juce::CharPointer_UTF8("Drive"),
                                                              juce::NormalisableRange<float>(1.f, 50.f, 0.1f, 1.0f),
                                                              1.f);

   // c_DC @min 0 @max 1 @default 0 (DC filter)
   auto dc = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("c_DC", versionHint),
                                                          juce::CharPointer_UTF8("DC Filter"),
                                                          juce::NormalisableRange<float>(0.f, 1.f, 0.01f, 1.0f),
                                                          0.f);

   // d_MODE @min 0 @max 7 @default 0 (Distortion mode - continuous, 8 algorithms)
   auto mode = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("d_MODE", versionHint),
                                                            juce::CharPointer_UTF8("Mode"),
                                                            juce::NormalisableRange<float>(0.f, 7.f, 0.1f, 1.0f),
                                                            0.f);

   // e_CEILING @min -20 @max 6 @default 0 (Output ceiling)
   auto ceiling = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("e_CEILING", versionHint),
                                                               juce::CharPointer_UTF8("Ceiling"),
                                                               juce::NormalisableRange<float>(-20.f, 6.f, 0.1f, 1.0f),
                                                               0.f);

   // f_BYPASS @min 0 @max 1 @default 0 (Bypass)
   auto bypass = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("f_BYPASS", versionHint),
                                                            juce::CharPointer_UTF8("Bypass"),
                                                            0, 1, 0);

   // g_BITS @min 3 @max 16 @default 16 (Bit depth)
   auto bits = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("g_BITS", versionHint),
                                                           juce::CharPointer_UTF8("Bits"),
                                                           juce::NormalisableRange<float>(2.0f, 16.0f, 0.1f, 1.0f),
                                                           16.0f,
                                                           juce::String(),
                                                           juce::AudioParameterFloat::genericParameter,
                                                           [](float value, int) {
                                                               return juce::String(static_cast<int>(std::round(value))) + " bit";
                                                           },
                                                           nullptr);

   // h_BITSON @min 0 @max 1 @default 0 (Bit crusher on/off)
   auto bitson = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("h_BITSON", versionHint),
                                                            juce::CharPointer_UTF8("Bits On"),
                                                            0, 1, 0);

   // i_TILT @min -6 @max 6 @default 0 (Tilt EQ)
   auto tilt = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("i_TILT", versionHint),
                                                            juce::CharPointer_UTF8("Tilt"),
                                                            juce::NormalisableRange<float>(-6.f, 6.f, 0.1f, 1.0f),
                                                            0.f);

   // j_HPF @min 20 @max 1000 @default 250 (XOver low frequency Hz)
   auto hpf = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("j_HPF", versionHint),
                                                          juce::CharPointer_UTF8("XLow"),
                                                          juce::NormalisableRange<float>(20.f, 1000.f, 1.f, 0.3f),
                                                          250.f,
                                                          juce::String(),
                                                          juce::AudioParameterFloat::genericParameter,
                                                          [](float value, int){
                                                              if (value < 100.f)
                                                                  return juce::String(static_cast<int>(value)) + " Hz";
                                                              else if (value < 1000.f)
                                                                  return juce::String(static_cast<int>(value)) + " Hz";
                                                              else
                                                                  return juce::String(value/1000.f, 1) + " kHz";
                                                          },
                                                          nullptr);

   // k_LPF @min 1000 @max 20000 @default 5000 (XOver high frequency Hz)
   auto lpf = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("k_LPF", versionHint),
                                                          juce::CharPointer_UTF8("XHigh"),
                                                          juce::NormalisableRange<float>(1000.f, 20000.f, 1.f, 0.3f),
                                                          5000.f,
                                                          juce::String(),
                                                          juce::AudioParameterFloat::genericParameter,
                                                          [](float value, int){
                                                              if (value < 100.f)
                                                                  return juce::String(static_cast<int>(value)) + " Hz";
                                                              else if (value < 1000.f)
                                                                  return juce::String(static_cast<int>(value)) + " Hz";
                                                              else
                                                                  return juce::String(value/1000.f, 1) + " kHz";
                                                          },
                                                          nullptr);

   // l_SC @min 0 @max 1 @default 0 (Input filter enable)
   auto filterEnable = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("l_SC", versionHint),
                                                                 juce::CharPointer_UTF8("Filter Enable"),
                                                                 0, 1, 0);

   // k_INPUT @min -12 @max 12 @default 0 (Input trim gain)
   auto inputTrim = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("k_INPUT", versionHint),
                                                                juce::CharPointer_UTF8("Input"),
                                                                juce::NormalisableRange<float>(-12.f, 12.f, 0.1f, 1.0f),
                                                                0.f);

   // l_OUTPUT @min -12 @max 12 @default 0 (Output makeup gain)
   auto outputGain = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("l_OUTPUT", versionHint),
                                                                 juce::CharPointer_UTF8("Output"),
                                                                 juce::NormalisableRange<float>(-24.f, 12.f, 0.1f, 1.0f),
                                                                 0.f);
   
   // m_DOWNSAMPLE @min 0 @max 99 @default 0 (Factor de downsampling)
   auto downsample = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("m_DOWNSAMPLE", versionHint),
                                                               juce::CharPointer_UTF8("Downsample"),
                                                               0, 100, 0);
   
   // n_DOWNSAMPLEON @min 0 @max 1 @default 0 (Activar downsampling)
   auto downsampleOn = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("n_DOWNSAMPLEON", versionHint),
                                                                 juce::CharPointer_UTF8("Downsample On"),
                                                                 0, 1, 0);

   // o_BAND @min 0 @max 2 @default 1 (Crossover band selector: 0=low, 1=mid, 2=high)
   auto band = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("o_BAND", versionHint),
                                                           juce::CharPointer_UTF8("Band"),
                                                           juce::NormalisableRange<float>(0.f, 2.f, 0.01f, 1.0f),
                                                           1.f,
                                                           juce::String(),
                                                           juce::AudioParameterFloat::genericParameter,
                                                           [](float value, int) {
                                                               if (value <= 0.5f)
                                                                   return juce::String("Low");
                                                               else if (value <= 1.5f)
                                                                   return juce::String("Mid");
                                                               else
                                                                   return juce::String("High");
                                                           },
                                                           nullptr);

   // p_TILTPOS @min 0 @max 1 @default 0 (Tilt position: 0=Pre, 1=Post)
   auto tiltPos = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("p_TILTPOS", versionHint),
                                                            juce::CharPointer_UTF8("Tilt Position"),
                                                            0, 1, 0);

   // p_DISTON @min 0 @max 1 @default 1 (Distortion on/off)
   auto distOn = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("p_DISTON", versionHint),
                                                           juce::CharPointer_UTF8("Distortion On"),
                                                           0, 1, 1);

   // p_BANDSOLO @min 0 @max 1 @default 0 (Band solo: 0=off, 1=solo selected band)
   auto bandSolo = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("p_BANDSOLO", versionHint),
                                                             juce::CharPointer_UTF8("Band Solo"),
                                                             0, 1, 0);

   // p_SAFELIMITON @min 0 @max 1 @default 0 (Safety limiter: 0=off, 1=on)
   auto safeLimitOn = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("p_SAFELIMITON", versionHint),
                                                                juce::CharPointer_UTF8("Safety Limiter"),
                                                                0, 1, 0);

// q_TONEON @min 0 @max 1 @default 0 (Tone on/off: 0=off, 1=on)
   auto toneOn = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("q_TONEON", versionHint),
                                                          juce::CharPointer_UTF8("Tone On"),
                                                          0, 1, 0);

   // r_TONEFREQ @min 20 @max 20000 @default 20000 (Tone frequency Hz)
   auto toneFreq = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("r_TONEFREQ", versionHint),
                                                              juce::CharPointer_UTF8("Tone Frequency"),
                                                              juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.3f),
                                                              20000.0f);

   // s_TILTON @min 0 @max 1 @default 1 (Tilt on/off: 0=off, 1=on)
   auto tiltOn = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("s_TILTON", versionHint),
                                                          juce::CharPointer_UTF8("Tilt On"),
                                                          0, 1, 1);

   // u_TONEPOS @min 0 @max 1 @default 1 (Tone LPF position: 0=Pre, 1=Post)
   auto tonePos = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("u_TONEPOS", versionHint),
                                                            juce::CharPointer_UTF8("Tone Position"),
                                                            0, 1, 1);

   // t_TONEQ @min 0.7071067811865476 @max 16.0 @default 0.7071067811865476 (Tone Q resonance)
   auto toneQ = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("t_TONEQ", versionHint),
                                                            juce::CharPointer_UTF8("Tone Q"),
                                                            juce::NormalisableRange<float>(0.7071067811865476f, 16.0f, 0.01f, 1.0f),
                                                            0.7071067811865476f,
                                                            juce::String(),
                                                            juce::AudioParameterFloat::genericParameter,
                                                            [](float value, int) {
                                                                // Mapear Q a porcentaje 0-100%
                                                                float percent = (value - 0.7071067811865476f) / (16.0f - 0.7071067811865476f) * 100.0f;
                                                                return juce::String(static_cast<int>(percent)) + "%";
                                                            },
                                                            nullptr);

   // Añadir parámetros en orden alfabético (exactamente como Gen~)
   params.push_back(std::move(drywet));         // a_DRYWET
   params.push_back(std::move(drive));          // b_DRIVE
   params.push_back(std::move(dc));             // c_DC
   params.push_back(std::move(mode));           // d_MODE
   params.push_back(std::move(ceiling));        // e_CEILING
   params.push_back(std::move(bypass));         // f_BYPASS
   params.push_back(std::move(bits));           // g_BITS
   params.push_back(std::move(bitson));         // h_BITSON
   params.push_back(std::move(tilt));           // i_TILT
   params.push_back(std::move(hpf));            // j_HPF
   params.push_back(std::move(lpf));            // k_LPF
   params.push_back(std::move(filterEnable));   // l_SC
   params.push_back(std::move(inputTrim));      // k_INPUT
   params.push_back(std::move(outputGain));     // l_OUTPUT
   params.push_back(std::move(downsample));     // m_DOWNSAMPLE
   params.push_back(std::move(downsampleOn));   // n_DOWNSAMPLEON
   params.push_back(std::move(band));           // o_BAND
   params.push_back(std::move(tiltPos));        // p_TILTPOS
   params.push_back(std::move(distOn));         // p_DISTON
   params.push_back(std::move(bandSolo));       // p_BANDSOLO
   params.push_back(std::move(safeLimitOn));    // p_SAFELIMITON
   params.push_back(std::move(toneOn));         // q_TONEON
   params.push_back(std::move(toneFreq));       // r_TONEFREQ
   params.push_back(std::move(tiltOn));         // s_TILTON
   params.push_back(std::move(tonePos));        // u_TONEPOS
   params.push_back(std::move(toneQ));          // t_TONEQ

   // DISTORTION: No requiere parámetros especiales AAX de gain reduction

   return { params.begin(), params.end() };
}


//==============================================================================
// GESTIÓN DE PARÁMETROS
//==============================================================================
void JCBDistortionAudioProcessor::parameterChanged(const juce::String& parameterID, float newValue)
{
    
    // Validar valores para parámetros del distorsionador
    if (parameterID == "a_DRYWET") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "b_DRIVE") {
        newValue = juce::jlimit(1.0f, 50.0f, newValue);
    }
    else if (parameterID == "c_DC") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "d_MODE") {
        newValue = juce::jlimit(0.0f, 7.0f, newValue);
    }
    else if (parameterID == "e_CEILING") {
        newValue = juce::jlimit(-20.0f, 6.0f, newValue);
    }
    else if (parameterID == "f_BYPASS") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "g_BITS") {
        newValue = juce::jlimit(2.0f, 16.0f, newValue);
    }
    else if (parameterID == "h_BITSON") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "i_TILT") {
        newValue = juce::jlimit(-6.0f, 6.0f, newValue);
    }
    else if (parameterID == "j_HPF") {
        newValue = juce::jlimit(20.0f, 1000.0f, newValue);
    }
    else if (parameterID == "k_LPF") {
        newValue = juce::jlimit(1000.0f, 20000.0f, newValue);
    }
    else if (parameterID == "l_SC") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "k_INPUT") {
        newValue = juce::jlimit(-12.0f, 12.0f, newValue);
    }
    else if (parameterID == "l_OUTPUT") {
        newValue = juce::jlimit(-24.0f, 12.0f, newValue);
    }
    else if (parameterID == "m_DOWNSAMPLE") {
        newValue = juce::jlimit(0.0f, 99.0f, newValue);
    }
    else if (parameterID == "n_DOWNSAMPLEON") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "o_BAND") {
        newValue = juce::jlimit(0.0f, 2.0f, newValue);
    }
    else if (parameterID == "p_TILTPOS") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "p_DISTON") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "p_BANDSOLO") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "p_SAFELIMITON") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "q_TONEON") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "r_TONEFREQ") {
        newValue = juce::jlimit(20.0f, 20000.0f, newValue);
    }
    else if (parameterID == "s_TILTON") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "u_TONEPOS") {
        newValue = juce::jlimit(0.0f, 1.0f, newValue);
    }
    else if (parameterID == "t_TONEQ") {
        newValue = juce::jlimit(0.7071067811865476f, 16.0f, newValue);
    }
    
    // Buscar el índice correcto en Gen~ basado en el nombre del parámetro
    int genIndex = -1;
    for (int i = 0; i < JCBDistortion::num_params(); i++) {
        if (parameterID == JCBDistortion::getparametername(m_PluginState, i)) {
            genIndex = i;
            break;
        }
    }
    
    if (genIndex < 0) {
        return;  // Parámetro no encontrado en Gen~
    }
    
    JCBDistortion::setparameter(m_PluginState, genIndex, newValue, nullptr);
    
    // DISTORTION: No requiere actualización dinámica de latencia
    // La latencia es fija (1 sample) para distorsión
}

//==============================================================================
// Métodos de programa (presets)
int JCBDistortionAudioProcessor::getNumPrograms()
{
    return 0; // 3 antes, añadir 1 por comportamiento extraño algunos hosts
}

int JCBDistortionAudioProcessor::getCurrentProgram()
{
    return currentProgram;
}

void JCBDistortionAudioProcessor::setCurrentProgram(int index)
{
    currentProgram = index;
}

const juce::String JCBDistortionAudioProcessor::getProgramName(int index)
{
    return juce::String();
}

void JCBDistortionAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
    // No implementado - los nombres de preset son fijos
}

//==============================================================================
// Métodos de medidores
float JCBDistortionAudioProcessor::getRmsInputValue(const int channel) const noexcept
{
    // CRASH FIX: Safety check - return safe value if not initialized
    if (!isInitialized()) {
        return -100.0f;  // Safe default value
    }
    
    jassert(channel == 0 || channel == 1);
    if (channel == 0)
        return leftInputRMS.load(std::memory_order_relaxed);
    if (channel == 1)
        return rightInputRMS.load(std::memory_order_relaxed);
    return -100.0f;  // Return -100dB for invalid channels
}

float JCBDistortionAudioProcessor::getRmsOutputValue(const int channel) const noexcept
{
    // CRASH FIX: Safety check - return safe value if not initialized
    if (!isInitialized()) {
        return -100.0f;  // Safe default value
    }
    
    jassert(channel == 0 || channel == 1);
    if (channel == 0)
        return leftOutputRMS.load(std::memory_order_relaxed);
    if (channel == 1)
        return rightOutputRMS.load(std::memory_order_relaxed);
    return -100.0f;  // Return -100dB for invalid channels
}

// DISTORTION: No requiere función getGainReductionValue - eliminada
// Los distorsionadores no tienen gain reduction

/*
float JCBDistortionAudioProcessor::getSCValue(const int channel) const noexcept
{
    jassert(channel == 0 || channel == 1);
    if (channel == 0)
        return leftSC.load(std::memory_order_relaxed);
    if (channel == 1)
        return rightSC.load(std::memory_order_relaxed);
    return -100.0f;  // Return -100dB for invalid channels
}
*/

//==============================================================================
// Utilidades
bool JCBDistortionAudioProcessor::isProTools() const noexcept
{
    juce::PluginHostType daw;
    return daw.isProTools();
}

juce::String JCBDistortionAudioProcessor::getPluginFormat() const noexcept
{
    // Detectar el formato del plugin en tiempo de ejecución
    const auto format = juce::PluginHostType().getPluginLoadedAs();
    
    switch (format)
    {
        case juce::AudioProcessor::wrapperType_VST3:
            return "VST3";
        case juce::AudioProcessor::wrapperType_AudioUnit:
            return "AU";
        case juce::AudioProcessor::wrapperType_AudioUnitv3:
            return "AUv3";
        case juce::AudioProcessor::wrapperType_AAX:
            return "AAX";
        case juce::AudioProcessor::wrapperType_VST:
            return "VST2";
        case juce::AudioProcessor::wrapperType_Standalone:
            return "Standalone";
        default:
            return "";
    }
}


//==============================================================================
// CAPTURA DE DATOS PARA VISUALIZACIÓN DE ENVOLVENTES
//==============================================================================
void JCBDistortionAudioProcessor::captureInputWaveformData(const juce::AudioBuffer<float>& inputBuffer, int numSamples)
{
    // AUDIO-THREAD SAFE: Usar try_lock para evitar bloquear el audio thread
    std::unique_lock<std::mutex> lock(waveformMutex, std::try_to_lock);
    if (!lock.owns_lock()) {
        // Si no puede obtener el lock, salir inmediatamente para evitar RT violations
        return;
    }
    
    // AUDIO-THREAD SAFE: Usar tamaño fijo pre-asignado, no resize() dinámico
    if (currentInputSamples.size() < static_cast<size_t>(numSamples)) {
        // Solo redimensionar si es absolutamente necesario (debería estar pre-asignado)
        currentInputSamples.resize(juce::jmax(numSamples, 4096));
    }
    
    // CAMBIO: Usar las salidas 3 y 4 de Gen~ (post-TRIM) en lugar de entrada RAW
    // Esto da una visualización más precisa de lo que realmente está procesando el compresor
    for (int i = 0; i < numSamples; ++i)
    {
        // Usar directamente las salidas de Gen~ que son post-TRIM
        if (JCBDistortion::num_outputs() > 4) {
            // Promedio de canales L/R post-TRIM (salidas 3 y 4 de Gen~)
            currentInputSamples[i] = static_cast<float>((m_OutputBuffers[3][i] + m_OutputBuffers[4][i]) * 0.5);
        } else {
            // Fallback: usar solo canal izquierdo post-TRIM
            currentInputSamples[i] = static_cast<float>(m_OutputBuffers[3][i]);
        }
    }
}

void JCBDistortionAudioProcessor::captureOutputWaveformData(int numSamples)
{
    // AUDIO-THREAD SAFE: Usar try_lock para evitar bloquear el audio thread
    std::unique_lock<std::mutex> lock(waveformMutex, std::try_to_lock);
    if (!lock.owns_lock()) {
        // Si no puede obtener el lock, salir inmediatamente para evitar RT violations
        return;
    }
    
    // AUDIO-THREAD SAFE: Usar tamaño fijo pre-asignado, no resize() dinámico
    if (currentProcessedSamples.size() < static_cast<size_t>(numSamples)) {
        currentProcessedSamples.resize(juce::jmax(numSamples, 4096));
    }
    
    // Copiar salida procesada (promedio de canales principales L/R)
    for (int i = 0; i < numSamples; ++i)
    {
        currentProcessedSamples[i] = (m_OutputBuffers[0][i] + m_OutputBuffers[1][i]) * 0.5f;
        
        // DISTORTION: No acceder a salida 3 Gen~ - no hay gain reduction
    }
}

void JCBDistortionAudioProcessor::getWaveformData(std::vector<float>& inputSamples, std::vector<float>& processedSamples) const
{
    std::lock_guard<std::mutex> lock(waveformMutex);
    inputSamples = currentInputSamples;
    processedSamples = currentProcessedSamples;
}

// DISTORTION: getWaveformDataWithGR eliminada - no hay gain reduction

// DISTORTION: No requiere función getMaxGainReduction - eliminada
// Los distorsionadores no tienen gain reduction


bool JCBDistortionAudioProcessor::isPlaybackActive() const noexcept
{
    // Siempre activo para decay permanente como plugins profesionales
    return true;
}


//==============================================================================
// GESTIÓN DEL EDITOR
//==============================================================================
juce::AudioProcessorEditor* JCBDistortionAudioProcessor::createEditor()
{
    return new JCBDistortionAudioProcessorEditor(*this, guiUndoManager);
}


//==============================================================================
// SERIALIZACIÓN DEL ESTADO
//==============================================================================
void JCBDistortionAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    // Crear una copia del state para no modificar el original
    auto stateCopy = apvts.state.createCopy();
    
    // Remover parámetros momentáneos antes de guardar
    // Estos botones no deben persistir entre sesiones
    auto paramsNode = stateCopy.getChildWithName("PARAMETERS");
    if (paramsNode.isValid()) {
        auto param = paramsNode.getChildWithProperty("id", "h_BYPASS");
        if (param.isValid())
            param.setProperty("value", 0.0f, nullptr);
        
        // DISTORTION: Plugin completamente limpio de parámetros legacy
    }
    
    auto preset = stateCopy.getOrCreateChildWithName("Presets", nullptr);
    preset.setProperty("currentPresetID", lastPreset, nullptr);
    preset.setProperty("tooltipEnabled", tooltipEnabled, nullptr);
    preset.setProperty("presetDisplayText", presetDisplayText, nullptr);
    preset.setProperty("presetTextItalic", presetTextItalic, nullptr);
    preset.setProperty("envelopeVisualEnabled", envelopeVisualEnabled, nullptr);
    preset.setProperty("tooltipLanguageEnglish", tooltipLanguageEnglish, nullptr);
    
    // Guardar tamaño del editor
    preset.setProperty("editorWidth", editorSize.x, nullptr);
    preset.setProperty("editorHeight", editorSize.y, nullptr);
    
    // Guardar estado del modo de visualización (no automatizable)
    preset.setProperty("displayModeIsFFT", displayModeIsFFT, nullptr);
    
    // Save A/B states
    auto abNode = stateCopy.getOrCreateChildWithName("ABStates", nullptr);
    abNode.setProperty("isStateA", isStateA, nullptr);
    
    // Save state A
    auto stateANode = abNode.getOrCreateChildWithName("StateA", nullptr);
    stateANode.removeAllChildren(nullptr);
    for (const auto& [paramId, value] : stateA.values) {
        stateANode.setProperty(paramId, value, nullptr);
    }
    
    // Save state B
    auto stateBNode = abNode.getOrCreateChildWithName("StateB", nullptr);
    stateBNode.removeAllChildren(nullptr);
    for (const auto& [paramId, value] : stateB.values) {
        stateBNode.setProperty(paramId, value, nullptr);
    }
    
    juce::MemoryOutputStream memoria(destData, true);
    stateCopy.writeToStream(memoria);
}

void JCBDistortionAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    auto tree = juce::ValueTree::readFromData(data, sizeInBytes);
    if (tree.isValid()) {
        apvts.state = tree;
        
        // Forzar parámetros momentáneos a OFF después de cargar
        apvts.getParameter("f_BYPASS")->setValueNotifyingHost(0.0f);
        // DISTORTION: Parámetros momentáneos validados y actualizados
        
        // Clear undo history AFTER all values have been set
        // This prevents any parameter changes from being recorded in undo history
        guiUndoManager.clearUndoHistory();
        
        auto preset = apvts.state.getChildWithName("Presets");
        if (preset.isValid()) {
            lastPreset = preset.getProperty("currentPresetID");
            tooltipEnabled = preset.getProperty("tooltipEnabled");
            presetDisplayText = preset.getProperty("presetDisplayText", "DEFAULT");
            presetTextItalic = preset.getProperty("presetTextItalic", false);
            envelopeVisualEnabled = preset.getProperty("envelopeVisualEnabled", true);
            tooltipLanguageEnglish = preset.getProperty("tooltipLanguageEnglish", false);
            
            // Restaurar tamaño del editor
            int savedWidth = preset.getProperty("editorWidth", 1250);
            int savedHeight = preset.getProperty("editorHeight", 350);
            editorSize = {savedWidth, savedHeight};
            
            // Restaurar estado del modo de visualización (no automatizable)
            displayModeIsFFT = preset.getProperty("displayModeIsFFT", false);
        }
        
        // Restore A/B states
        auto abNode = apvts.state.getChildWithName("ABStates");
        if (abNode.isValid()) {
            isStateA = abNode.getProperty("isStateA", true);
            
            // Restore state A
            auto stateANode = abNode.getChildWithName("StateA");
            if (stateANode.isValid()) {
                stateA.values.clear();
                for (int i = 0; i < stateANode.getNumProperties(); ++i) {
                    auto propName = stateANode.getPropertyName(i);
                    stateA.values[propName.toString()] = stateANode[propName];
                }
            }
            
            // Restore state B
            auto stateBNode = abNode.getChildWithName("StateB");
            if (stateBNode.isValid()) {
                stateB.values.clear();
                for (int i = 0; i < stateBNode.getNumProperties(); ++i) {
                    auto propName = stateBNode.getPropertyName(i);
                    stateB.values[propName.toString()] = stateBNode[propName];
                }
            }
        }
        
        // IMPORTANTE: Sincronizar todos los parámetros con Gen~ después de cargar el estado
        for (int i = 0; i < JCBDistortion::num_params(); i++) {
            auto paramName = juce::String(JCBDistortion::getparametername(m_PluginState, i));
            if (auto* param = apvts.getRawParameterValue(paramName)) {
                float value = param->load();
                
                // Corregir valores muy pequeños en ATK y REL
                if (paramName == "d_ATK") {
                    if (value < 0.1f) {
                        value = 0.1f;
                        // Actualizar el parámetro en el APVTS
                        if (auto* audioParam = apvts.getParameter(paramName)) {
                            audioParam->setValueNotifyingHost(audioParam->convertTo0to1(value));
                        }
                    }
                }
                if (paramName == "e_REL") {
                    if (value < 0.1f) {
                        value = 0.1f;
                        // Actualizar el parámetro en el APVTS
                        if (auto* audioParam = apvts.getParameter(paramName)) {
                            audioParam->setValueNotifyingHost(audioParam->convertTo0to1(value));
                        }
                    }
                }
                // NOTA: El compresor no tiene parámetro HOLD (es del expansor/gate)
                
                parameterChanged(paramName, value);
            }
        }
        
        
        // Forzar actualización del editor de forma thread-safe
        // Usar MessageManager para evitar llamadas directas a getActiveEditor()
        juce::MessageManager::callAsync([this]() {
            if (auto* editor = dynamic_cast<JCBDistortionAudioProcessorEditor*>(getActiveEditor())) {
                // El editor necesita actualizar la función de transferencia
                editor->updateTransferFunctionFromProcessor();
            }
        });
    }
}

//==============================================================================
// COMPARACIÓN A/B
//==============================================================================
void JCBDistortionAudioProcessor::saveCurrentStateToActive() 
{
    if (isStateA) {
        stateA.captureFrom(apvts);
    } else {
        stateB.captureFrom(apvts);
    }
}

void JCBDistortionAudioProcessor::toggleAB() 
{
    // Save current state before switching
    saveCurrentStateToActive();
    
    // Switch state
    isStateA = !isStateA;
    
    // Load the other state
    if (isStateA) {
        stateA.applyTo(apvts);
    } else {
        stateB.applyTo(apvts);
    }
}

void JCBDistortionAudioProcessor::copyAtoB() 
{
    stateA.captureFrom(apvts);
    stateB = stateA;
}

void JCBDistortionAudioProcessor::copyBtoA() 
{
    stateB.captureFrom(apvts);
    stateA = stateB;
}


//==============================================================================
// MÉTODOS LEGACY
//==============================================================================
int JCBDistortionAudioProcessor::getNumParameters()
{
    // Retornar el número real de parámetros del juce::AudioProcessor
    // que incluye los de Gen~ más cualquier parámetro adicional (como AAX gain reduction)
    return static_cast<int>(getParameters().size());
}

float JCBDistortionAudioProcessor::getParameter(int index)
{
    // Verificar si el índice está dentro del rango de Gen~
    if (index < JCBDistortion::num_params())
    {
        t_param value;
        t_param min = JCBDistortion::getparametermin(m_PluginState, index);
        t_param range = fabs(JCBDistortion::getparametermax(m_PluginState, index) - min);
        
        JCBDistortion::getparameter(m_PluginState, index, &value);
        
        value = (value - min) / range;
        
        return value;
    }
    else
    {
        // Manejar parámetros adicionales (como AAX gain reduction)
        // Para el parámetro de gain reduction, devolver 0.0 (sin reducción)
        return 0.0f;
    }
}

void JCBDistortionAudioProcessor::setParameter(int index, float newValue)
{
    // Verificar si el índice está dentro del rango de Gen~
    if (index < JCBDistortion::num_params())
    {
        t_param min = JCBDistortion::getparametermin(m_PluginState, index);
        t_param range = fabs(JCBDistortion::getparametermax(m_PluginState, index) - min);
        t_param value = newValue * range + min;
        
        JCBDistortion::setparameter(m_PluginState, index, value, nullptr);
    }
    else
    {
        // Manejar parámetros adicionales (como AAX gain reduction)
        // El parámetro de gain reduction es de solo lectura, no hacer nada
    }
}

const juce::String JCBDistortionAudioProcessor::getParameterName(int index)
{
    // Verificar si el índice está dentro del rango de Gen~
    if (index < JCBDistortion::num_params())
    {
        return juce::String(JCBDistortion::getparametername(m_PluginState, index));
    }
    else
    {
        // Manejar parámetros adicionales (como AAX gain reduction)
        #if JucePlugin_Build_AAX
        if (index == JCBDistortion::num_params()) // Índice 25 para AAX
        {
            return "Gain Reduction";
        }
        #endif
        return "";
    }
}

const juce::String JCBDistortionAudioProcessor::getParameterText(int index)
{
    // Método legacy para compatibilidad con hosts - algunos DAWs pueden llamarlo
    if (index >= 0 && index < JCBDistortion::num_params())
    {
        juce::String text = juce::String(getParameter(index));
        text += juce::String(" ");
        text += juce::String(JCBDistortion::getparameterunits(m_PluginState, index));
        return text;
    }
    
    // Retornar string vacío para índices inválidos
    return "";
}

const juce::String JCBDistortionAudioProcessor::getInputChannelName(int channelIndex) const
{
    return juce::String(channelIndex + 1);
}

const juce::String JCBDistortionAudioProcessor::getOutputChannelName(int channelIndex) const
{
    return juce::String(channelIndex + 1);
}

bool JCBDistortionAudioProcessor::isInputChannelStereoPair(int index) const
{
    if (isProTools())
    {
        if (getMainBusNumInputChannels() > 1)
            return JCBDistortion::num_inputs() == 4;
        else
            return false;
    }
    else
        return JCBDistortion::num_inputs() == 4;
}

bool JCBDistortionAudioProcessor::isOutputChannelStereoPair(int index) const
{
    return JCBDistortion::num_outputs() == 2;
}


//==============================================================================
// Clip Detection Methods
//==============================================================================

void JCBDistortionAudioProcessor::updateClipDetection(const juce::AudioBuffer<float>& inputBuffer, const juce::AudioBuffer<float>& outputBuffer)
{
    const int numSamples = inputBuffer.getNumSamples();
    const auto mainInputChannels = getMainBusNumInputChannels();
    const auto mainOutputChannels = getMainBusNumOutputChannels();
    
    // NOTA: El compresor no tiene soft clip, siempre detectar clips en salida
    bool isSoftClipActive = false; // Compresor no tiene soft clip
    
    // Reset clip flags for this buffer
    bool inputClip[2] = {false, false};
    bool outputClip[2] = {false, false};
    
    // Detectar clips en entrada (usando trimInputBuffer para consistencia con medidores)
    for (int channel = 0; channel < juce::jmin(2, mainInputChannels); ++channel) {
        for (int sample = 0; sample < numSamples; ++sample) {
            if (channel < trimInputBuffer.getNumChannels()) {
                float value = std::abs(trimInputBuffer.getSample(channel, sample));
                if (value >= 0.999f) {  // Umbral de clip ligeramente por debajo de 1.0
                    inputClip[channel] = true;
                    break;  // Solo necesitamos detectar un clip por buffer
                }
            }
        }
    }
    
    // Detectar clips en salida solo si soft clip NO está activo
    if (!isSoftClipActive) {
        for (int channel = 0; channel < juce::jmin(2, mainOutputChannels); ++channel) {
            for (int sample = 0; sample < numSamples; ++sample) {
                float value = std::abs(outputBuffer.getSample(channel, sample));
                if (value >= 0.999f) {  // Umbral de clip ligeramente por debajo de 1.0
                    outputClip[channel] = true;
                    break;  // Solo necesitamos detectar un clip por buffer
                }
            }
        }
    }
    
    // Actualizar flags atómicos
    for (int channel = 0; channel < 2; ++channel) {
        if (inputClip[channel]) {
            inputClipDetected[channel] = true;
        }
        if (outputClip[channel]) {
            outputClipDetected[channel] = true;
        }
    }
}

bool JCBDistortionAudioProcessor::getInputClipDetected(const int channel) const noexcept
{
    jassert(channel == 0 || channel == 1);
    if (channel >= 0 && channel < 2) {
        return inputClipDetected[channel].load();
    }
    return false;
}

bool JCBDistortionAudioProcessor::getOutputClipDetected(const int channel) const noexcept
{
    jassert(channel == 0 || channel == 1);
    if (channel >= 0 && channel < 2) {
        return outputClipDetected[channel].load();
    }
    return false;
}

/*
bool JCBDistortionAudioProcessor::getSidechainClipDetected(const int channel) const noexcept
{
    jassert(channel == 0 || channel == 1);
    if (channel >= 0 && channel < 2) {
        return sidechainClipDetected[channel].load();
    }
    return false;
}
*/

void JCBDistortionAudioProcessor::resetClipIndicators()
{
    for (int channel = 0; channel < 2; ++channel) {
        inputClipDetected[channel] = false;
        outputClipDetected[channel] = false;
        // sidechainClipDetected[channel] = false;
    }
}

// DISTORTION: No requiere función getGainReductionForHost - eliminada
// Los distorsionadores no tienen gain reduction

//==============================================================================
// Timer implementation
// Los distorsionadores no tienen parámetros AAX de gain reduction

//==============================================================================
// Format-specific implementations

// DISTORTION: No requiere función AAX getAAXMeterValue - eliminada
// Los distorsionadores no tienen medidores de gain reduction

#if JucePlugin_Build_VST3
void JCBDistortionAudioProcessor::updateVST3GainReduction()
{
    // Para VST3, necesitaríamos acceso al IEditController
    // Esto se haría típicamente en el wrapper VST3
    // Por ahora solo preparamos el método
}
#endif

//==============================================================================
// TIMER CALLBACK
//==============================================================================
void JCBDistortionAudioProcessor::timerCallback()
{
    // Timer callback para tareas que requieren ejecución fuera del audio thread
    // Para distorsión, mantenemos funcionalidad mínima necesaria
    
    // Verificar si el processor está siendo destruido
    if (isBeingDestroyed.load()) {
        return;
    }
    
    // Actualizar estado de playback para medidores
    // En distorsión no necesitamos lógica compleja de gain reduction
}

//==============================================================================
// FACTORY FUNCTION DEL PLUGIN
//==============================================================================

/**
 * Función factory requerida por JUCE
 * CRÍTICO: Punto de entrada que utilizan los hosts (DAWs) para crear instancias del plugin
 * Esta función es llamada automáticamente por el framework JUCE cuando:
 * - El DAW carga el plugin por primera vez
 * - Se crea una nueva instancia del plugin en el proyecto
 * - Se duplica una pista que contiene el plugin
 */
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JCBDistortionAudioProcessor();
}
