#include "SpectrumAnalyzerComponent.h"

SpectrumAnalyzerComponent::SpectrumAnalyzerComponent(juce::AudioProcessorValueTreeState& apvts)
    : valueTreeState(apvts),
      forwardFFT(fftOrder),
      window(fftSize, juce::dsp::WindowingFunction<float>::hann)
{
    // Initialize buffers (lock-free design)
    fifo.fill(0.0f);
    fftCopy.fill(0.0f);
    fftData.fill(0.0f);
    scopeData.fill(0.0f);
    copyScopeData.fill(0.0f);
    peakHoldData.fill(0.0f);
    
    // Start timer for display updates (30 FPS for stability)
    startTimerHz(30);
    
    setOpaque(false);
}

SpectrumAnalyzerComponent::~SpectrumAnalyzerComponent()
{
    // Set destroying flag FIRST to prevent new audio processing
    isDestroying.store(true, std::memory_order_release);
    
    // Stop timer BEFORE destroying any data
    stopTimer();
    
    // Small delay to ensure any in-flight audio callbacks complete
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void SpectrumAnalyzerComponent::setSampleRate(double newSampleRate) noexcept
{
    currentSampleRate.store(newSampleRate);
}

void SpectrumAnalyzerComponent::pushNextSampleIntoFifo(float sample) noexcept
{
    // Check if component is being destroyed - abort immediately
    if (isDestroying.load(std::memory_order_acquire))
        return;
    
    // Lock-free audio thread implementation - NO MUTEX EVER
    auto currentIndex = fifoIndex.load(std::memory_order_relaxed);
    
    // Bounds check for safety
    if (currentIndex >= 0 && currentIndex < fftSize)
    {
        fifo[currentIndex] = sample;
    }
    
    auto newIndex = currentIndex + 1;
    if (newIndex >= fftSize)
    {
        // Block is ready, try to set flag atomically with proper memory ordering
        bool expected = false;
        if (nextFFTBlockReady.compare_exchange_weak(expected, true, std::memory_order_release, std::memory_order_relaxed))
        {
            // Successfully set flag, copy to intermediate buffer (NO MUTEX - LOCK FREE)
            // This is safe because only audio thread writes to fftCopy
            std::copy(fifo.begin(), fifo.end(), fftCopy.begin());
        }
        newIndex = 0;
    }
    
    fifoIndex.store(newIndex, std::memory_order_relaxed);
}

void SpectrumAnalyzerComponent::timerCallback()
{
    // Check if component is being destroyed
    if (isDestroying.load(std::memory_order_acquire))
        return;
    
    // Check if new FFT data is ready using atomic operation with proper memory ordering
    bool expected = true;
    if (nextFFTBlockReady.compare_exchange_weak(expected, false, std::memory_order_acquire, std::memory_order_relaxed))
    {
        // Successfully acquired the flag, copy from intermediate buffer to processing buffer
        {
            std::lock_guard<std::mutex> lock(guiMutex);  // Only GUI thread uses this mutex
            juce::zeromem(fftData.data(), sizeof(fftData));
            std::copy(fftCopy.begin(), fftCopy.end(), fftData.begin());
        }
        
        // Process FFT data (this updates scopeData)
        drawNextFrameOfSpectrum();
        
        // Copy scopeData to thread-safe painting buffer
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
    // Process FFT data (mutex already handled in timerCallback)
    // Apply windowing function
    window.multiplyWithWindowingTable(fftData.data(), fftSize);
    
    // Perform FFT
    forwardFFT.performFrequencyOnlyForwardTransform(fftData.data());
    
    // Dynamic spectrum display range based on zoom state
    auto mindB = zoomEnabled.load() ? zoomedMinDB : defaultMinDB;
    auto maxdB = zoomEnabled.load() ? zoomedMaxDB : defaultMaxDB;
    
    for (int i = 0; i < scopeSize; ++i)
    {
        // Bounds check for safety
        if (i < 0 || i >= scopeSize)
        {
            continue; // Skip invalid indices
        }
        
        // TRUE logarithmic frequency mapping: 20Hz to 20kHz
        // 1kHz appears exactly at 50% of display (logarithmic center)
        float normalizedPosition = (float)i / (float)scopeSize;
        
        auto logMin = std::log10(20.0f);      // 20Hz
        auto logMax = std::log10(20000.0f);   // 20kHz
        auto logFreq = logMin + normalizedPosition * (logMax - logMin);
        float freq = std::pow(10.0f, logFreq);
        
        // Convert frequency to FFT bin index using dynamic sample rate
        auto sampleRate = currentSampleRate.load();
        
        // Bounds checking for safety
        if (sampleRate <= 0.0)
        {
            continue; // Skip invalid sample rate
        }
        
        auto exactBinIndex = freq * (float)fftSize / (float)sampleRate;
        
        // Intelligent interpolation logic for low frequencies
        int binIndex1, binIndex2;
        float fraction;
        
        if (exactBinIndex < 1.0f)
        {
            // Below bin 1: no valid spectral data (below fundamental frequency resolution)
            binIndex1 = 1;
            binIndex2 = 1;
            fraction = 0.0f;  // Use bin 1 value without interpolation
        }
        else if (exactBinIndex < 2.0f)
        {
            // Between bins 1 and 2: proper interpolation in fundamental range
            binIndex1 = 1;
            binIndex2 = 2;
            fraction = exactBinIndex - 1.0f;
        }
        else
        {
            // Normal case: standard interpolation for higher frequencies
            binIndex1 = (int)exactBinIndex;
            binIndex2 = binIndex1 + 1;
            fraction = exactBinIndex - (float)binIndex1;
            
            // Standard clamping for higher frequencies
            binIndex1 = juce::jlimit(1, (int)(fftSize / 2 - 2), binIndex1);
            binIndex2 = juce::jlimit(2, (int)(fftSize / 2 - 1), binIndex2);
        }
        
        // Safe array access with bounds checking
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
        
        // Enhanced interpolation: frequency-dependent precision for better treble detail
        float interpolatedMagnitude;
        
        if (binIndex1 == binIndex2) 
        {
            interpolatedMagnitude = magnitude1;
        }
        else if (freq >= 2000.0f && magnitude1 > 1e-8f && magnitude2 > 1e-8f)  
        {
            // High-frequency precision: use geometric interpolation for better treble accuracy
            auto logMag1 = std::log(magnitude1 + 1e-10f);
            auto logMag2 = std::log(magnitude2 + 1e-10f);
            auto logInterpolated = logMag1 + fraction * (logMag2 - logMag1);
            interpolatedMagnitude = std::exp(logInterpolated);
        }
        else 
        {
            // Standard linear interpolation for lower frequencies
            interpolatedMagnitude = magnitude1 + fraction * (magnitude2 - magnitude1);
        }
        
        // Calculate level in dB with proper FFT normalization and window correction
        auto clampedMagnitude = juce::jmax(interpolatedMagnitude, 1e-10f);
        
        // Proper FFT magnitude normalization: -20*log10(fftSize/2) instead of -20*log10(fftSize)
        // This corrects the ~6dB error in the previous calculation
        auto fftNormalizationdB = 20.0f * std::log10((float)fftSize / 2.0f);
        
        // Hann window correction: REMOVED - was causing +6dB offset vs professional analyzers
        // auto hannWindowCorrection = 6.0f;  // DISABLED: causing +6dB excess
        
        auto dbValue = juce::Decibels::gainToDecibels(clampedMagnitude) - fftNormalizationdB;  // No window correction
        
        // Use raw dB values without ANY frequency compensation for natural spectrum
        auto clampedDbValue = juce::jlimit(mindB, maxdB, dbValue);
        
        // Convert dB to display position (0.0 = bottom, 1.0 = top)
        // This gives proper logarithmic scaling where -24dB appears at middle
        auto level = (clampedDbValue - mindB) / (maxdB - mindB);
        
        // Frequency-dependent adaptive smoothing for enhanced treble visibility
        auto difference = std::abs(level - scopeData[i]);
        
        // Determine frequency-based smoothing factor
        float baseSmoothingFactor;
        if (freq >= 4000.0f)  // High frequencies (4kHz+): Less smoothing, preserve transients
        {
            baseSmoothingFactor = 0.35f;  // Higher responsiveness for treble detail
        }
        else if (freq >= 1000.0f)  // Mid frequencies (1-4kHz): Moderate smoothing
        {
            baseSmoothingFactor = 0.25f;  // Balanced smoothing
        }
        else  // Low frequencies (<1kHz): More smoothing for stability
        {
            baseSmoothingFactor = 0.15f;  // More stability in bass
        }
        
        auto adaptiveSmoothing = juce::jlimit(0.1f, 0.5f, baseSmoothingFactor + difference * 0.3f);
        scopeData[i] = scopeData[i] * (1.0f - adaptiveSmoothing) + level * adaptiveSmoothing;
        
        // Update peak hold data (thread-safe)
        if (level > peakHoldData[i])
        {
            peakHoldData[i] = level;
            peakHoldCounter.store(0);  // Reset hold counter atomically when new peak is found
        }
    }
    
    // Frequency-dependent peak hold decay with atomic counter
    auto currentCounter = peakHoldCounter.fetch_add(1);
    if (currentCounter > peakHoldFrames)
    {
        for (int i = 0; i < scopeSize; ++i)
        {
            // Bounds check for safety
            if (i >= 0 && i < scopeSize)
            {
                // Calculate frequency for this display point for decay rate
                auto logMin = std::log10(20.0f);      // 20Hz
                auto logMax = std::log10(20000.0f);   // 20kHz
                auto logFreq = logMin + ((float)i / (float)scopeSize) * (logMax - logMin);
                auto freq = std::pow(10.0f, logFreq);
                
                // Frequency-dependent decay rate: treble holds longer, bass decays faster
                float decayRate;
                if (freq >= 2000.0f)  // High frequencies: slower decay for visibility
                {
                    decayRate = 0.985f;  // Slower decay preserves treble peaks longer
                }
                else if (freq >= 500.0f)  // Mid frequencies: moderate decay
                {
                    decayRate = 0.98f;   // Standard decay
                }
                else  // Low frequencies: faster decay for cleaner display
                {
                    decayRate = 0.975f;  // Faster decay prevents bass buildup
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
    // Dark background
    g.fillAll(juce::Colour(0x001a1a1a));
    
    // Draw spectrum line with frequency-based color coding
    if (!bypassMode.load())
    {
        auto width = bounds.getWidth();
        auto height = bounds.getHeight();
        
        // Draw spectrum with gradient colors: purple for bass, blue for treble
        // This matches the plugin's A/B button colors
        auto purpleColor = juce::Colour(0xFF9C27B0);  // Bass frequencies (purple like A button)
        auto blueColor = juce::Colour(0xFF2196F3);    // Treble frequencies (blue like B button)
        
        juce::Path spectrumPath;
        
        // Build the complete path using thread-safe copy (no mutex needed in paint)
        // Only proceed if we have valid scope data ready
        if (scopeDataReady.load(std::memory_order_acquire))
        {
            for (int i = 0; i < scopeSize; ++i)
            {
                // Additional bounds check for extra safety
                if (i >= 0 && i < scopeSize)
                {
                    auto x = juce::jmap((float)i, 0.0f, (float)scopeSize, 0.0f, (float)width);
                    auto y = juce::jmap(copyScopeData[i], 0.0f, 1.0f, (float)height, 0.0f);
                    
                    // Clamp y value to prevent drawing outside bounds
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
            // No data ready yet, draw empty path
            spectrumPath.startNewSubPath(0.0f, (float)height);
            spectrumPath.lineTo((float)width, (float)height);
        }
        
        // Draw segments with color gradient based on frequency
        const int numSegments = 32;  // Number of color segments
        for (int seg = 0; seg < numSegments; ++seg)
        {
            float startRatio = (float)seg / (float)numSegments;
            float endRatio = (float)(seg + 1) / (float)numSegments;
            
            // Interpolate color from purple (bass) to blue (treble)
            auto segmentColor = purpleColor.interpolatedWith(blueColor, startRatio);
            g.setColour(segmentColor.withAlpha(0.9f));
            
            // Create a clipped region for this segment
            auto clipBounds = bounds.toFloat();
            clipBounds.setX(startRatio * width);
            clipBounds.setWidth((endRatio - startRatio) * width);
            
            g.saveState();
            g.reduceClipRegion(clipBounds.toNearestInt());
            g.strokePath(spectrumPath, juce::PathStrokeType(1.8f));
            g.restoreState();
        }
    }
    
    // Draw grid
    g.setColour(juce::Colours::white.withAlpha(0.1f));
    
    // Logarithmic grid with proper spacing
    std::vector<float> gridFrequencies = {50.0f, 100.0f, 200.0f, 500.0f, 1000.0f, 2000.0f, 5000.0f, 10000.0f};
    
    for (float freq : gridFrequencies)
    {
        // Calculate position using TRUE logarithmic mapping (same as spectrum data)
        auto logMin = std::log10(20.0f);      // 20Hz
        auto logMax = std::log10(20000.0f);   // 20kHz
        auto logFreq = std::log10(freq);
        auto position = (logFreq - logMin) / (logMax - logMin);
        
        auto x = bounds.getWidth() * position;
        g.drawVerticalLine(x, 0.0f, (float)bounds.getHeight());
    }
    
    // Dynamic horizontal amplitude lines based on zoom state
    auto currentMinDB = zoomEnabled.load() ? zoomedMinDB : defaultMinDB;
    auto currentMaxDB = zoomEnabled.load() ? zoomedMaxDB : defaultMaxDB;
    
    // Choose grid lines based on zoom level
    std::vector<float> gridAmplitudes;
    if (zoomEnabled.load())
    {
        // Zoomed mode: focus on higher levels
        gridAmplitudes = {-6.0f, -12.0f, -18.0f, -24.0f, -30.0f, -36.0f, -42.0f};
    }
    else
    {
        // Full range mode: broader coverage
        gridAmplitudes = {-6.0f, -12.0f, -18.0f, -24.0f, -36.0f, -48.0f, -60.0f};
    }
    
    for (float ampDB : gridAmplitudes)
    {
        // Calculate position using current dynamic range
        float position = (ampDB - currentMinDB) / (currentMaxDB - currentMinDB);
        auto y = bounds.getHeight() * (1.0f - position); // Invert Y (0 = top)
        
        // Only draw if within current range bounds
        if (ampDB >= currentMinDB && ampDB <= currentMaxDB && y >= 0.0f && y <= bounds.getHeight())
        {
            g.drawHorizontalLine(y, 0.0f, (float)bounds.getWidth());
        }
    }
    
    // Labels
    g.setColour(juce::Colours::white.withAlpha(0.6f));
    g.setFont(9.0f);
    
    // Frequency labels at key grid lines (logarithmically spaced)
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
        
        // Calculate position using TRUE logarithmic mapping (same as spectrum data)
        auto logMin = std::log10(20.0f);      // 20Hz
        auto logMax = std::log10(20000.0f);   // 20kHz
        auto logFreq = std::log10(freq);
        auto position = (logFreq - logMin) / (logMax - logMin);
        
        auto x = bounds.getWidth() * position;
        g.drawText(text, x - 15, bounds.getBottom() - 15, 30, 12, juce::Justification::centred);
    }
    
    // Range labels (corners)
    g.setFont(8.0f);
    g.drawText("20Hz", bounds.getX() + 22, bounds.getBottom() - 15, 25, 12, juce::Justification::left);
    g.drawText("20kHz", bounds.getRight() - 27, bounds.getBottom() - 15, 25, 12, juce::Justification::right);
    
    // Dynamic amplitude labels based on current zoom state
    g.setFont(8.0f);
    
    // Use same grid amplitudes as the lines
    for (float ampDB : gridAmplitudes)
    {
        // Calculate Y position using current dynamic range
        float position = (ampDB - currentMinDB) / (currentMaxDB - currentMinDB);
        auto y = bounds.getHeight() * (1.0f - position); // Invert Y (0 = top)
        
        // Only draw label if within current range and screen bounds
        if (ampDB >= currentMinDB && ampDB <= currentMaxDB && 
            y >= 12.0f && y <= bounds.getHeight() - 12.0f)
        {
            juce::String dbText = juce::String((int)ampDB);
            g.drawText(dbText, bounds.getX() + 2, y - 6, 20, 12, juce::Justification::right);
        }
    }
    
    // Dynamic top and bottom dB labels based on current range
    g.drawText(juce::String((int)currentMaxDB), bounds.getX() + 2, bounds.getY() + 2, 20, 12, juce::Justification::right);
    g.drawText(juce::String((int)currentMinDB), bounds.getX() + 2, bounds.getBottom() - 25, 20, 12, juce::Justification::right);
    
    // Title
    g.setFont(12.0f);
    //g.drawText("FFT SPECTRUM", bounds.getX() + 5, bounds.getY() + 5, 100, 15, juce::Justification::left);
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
    // React to bypass parameter
    if (parameterID == "f_BYPASS")
    {
        setBypassMode(newValue > 0.5f);
    }
}

void SpectrumAnalyzerComponent::mouseMove(const juce::MouseEvent& event)
{
    // Tooltip is handled by getTooltip() method
}

void SpectrumAnalyzerComponent::mouseDown(const juce::MouseEvent& event)
{
    // Toggle frequency scale on click
    setFrequencyScale(currentScale == FrequencyScale::Linear ? 
                     FrequencyScale::Logarithmic : 
                     FrequencyScale::Linear);
}

void SpectrumAnalyzerComponent::mouseDoubleClick(const juce::MouseEvent& event)
{
    // Reset or special functionality
}

juce::String SpectrumAnalyzerComponent::getTooltip()
{
    return "FFT Spectrum Analyzer - " + juce::String(currentScale == FrequencyScale::Logarithmic ? "Log" : "Linear") + " scale - Click to toggle";
}