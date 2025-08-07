#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_core/juce_core.h>
#include <juce_graphics/juce_graphics.h>
#include <juce_dsp/juce_dsp.h>
#include <array>
#include <atomic>
#include <mutex>
#include <thread>
#include <chrono>

class SpectrumAnalyzerComponent : public juce::Component,
                                  public juce::Timer,
                                  public juce::TooltipClient,
                                  private juce::AudioProcessorValueTreeState::Listener
{
public:
    SpectrumAnalyzerComponent(juce::AudioProcessorValueTreeState& apvts);
    
    // Update sample rate for correct frequency mapping
    void setSampleRate(double newSampleRate) noexcept;
    ~SpectrumAnalyzerComponent() override;
    
    void paint(juce::Graphics& g) override;
    void timerCallback() override;
    void mouseMove(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDoubleClick(const juce::MouseEvent& event) override;
    
    // TooltipClient interface
    juce::String getTooltip() override;
    
    void pushNextSampleIntoFifo(float sample) noexcept;
    void setBypassMode(bool enabled) noexcept;
    
    // Frequency scale toggle
    enum class FrequencyScale {
        Linear,
        Logarithmic
    };
    
    void setFrequencyScale(FrequencyScale scale) noexcept;
    FrequencyScale getFrequencyScale() const noexcept { return currentScale; }
    
    // Zoom control for FFT mode
    void setZoomEnabled(bool enabled) noexcept;
    bool getZoomEnabled() const noexcept { return zoomEnabled; }
    
private:
    // FFT Configuration - High resolution for professional analysis
    static constexpr auto fftOrder = 11;  // 2048 points (increased resolution)
    static constexpr auto fftSize = 1 << fftOrder;
    static constexpr auto scopeSize = 512;  // Visual resolution
    
    // Display Range Configuration - Easy to modify
    static constexpr float defaultMinDB = -80.0f;  // Full range bottom
    static constexpr float defaultMaxDB = 0.0f;    // Full range top
    static constexpr float zoomedMinDB = -48.0f;   // Zoomed range bottom
    static constexpr float zoomedMaxDB = 0.0f;     // Zoomed range top
    
    // FFT Components
    juce::dsp::FFT forwardFFT;
    juce::dsp::WindowingFunction<float> window;
    
    // Data Buffers - Lock-free design
    std::array<float, fftSize> fifo;
    std::array<float, fftSize> fftCopy;  // Intermediate buffer for audio thread
    std::array<float, fftSize * 2> fftData;  // GUI thread processing buffer
    std::array<float, scopeSize> scopeData;
    std::array<float, scopeSize> copyScopeData;  // Thread-safe copy for painting
    std::array<float, scopeSize> peakHoldData;
    
    // Thread-safe State Management
    std::atomic<int> fifoIndex{0};
    std::atomic<bool> nextFFTBlockReady{false};
    std::atomic<bool> bypassMode{false};
    std::atomic<bool> zoomEnabled{false};
    FrequencyScale currentScale = FrequencyScale::Logarithmic;
    std::atomic<double> currentSampleRate{44100.0};
    std::atomic<int> peakHoldCounter{0};
    static constexpr int peakHoldFrames = 60;  // Hold peaks for ~2 seconds at 30 FPS
    
    // Thread safety flags (no mutex needed in audio thread)
    std::atomic<bool> scopeDataReady{false};
    std::atomic<bool> isDestroying{false};
    
    // GUI thread mutex (never used in audio thread)
    mutable std::mutex guiMutex;
    
    // Reference to value tree
    juce::AudioProcessorValueTreeState& valueTreeState;
    
    // Internal methods
    void parameterChanged(const juce::String& parameterID, float newValue) override;
    void drawNextFrameOfSpectrum();
    void drawFrame(juce::Graphics& g, const juce::Rectangle<int>& bounds);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SpectrumAnalyzerComponent)
};