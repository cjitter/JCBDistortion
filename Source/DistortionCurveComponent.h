#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_core/juce_core.h>
#include <juce_graphics/juce_graphics.h>

class DistortionCurveComponent : public juce::Component,
                                private juce::AudioProcessorValueTreeState::Listener
{
public:
    DistortionCurveComponent(juce::AudioProcessorValueTreeState& apvts);
    ~DistortionCurveComponent() override;
    
    void paint(juce::Graphics& g) override;
    
private:
    juce::AudioProcessorValueTreeState& valueTreeState;
    
    float currentMode = 0.0f;
    float currentDrive = 1.0f;
    float currentDC = 0.0f;
    float currentCeiling = 1.0f;
    float currentTilt = 0.0f;
    
    void parameterChanged(const juce::String& parameterID, float newValue) override;
    void updateFromParameters();
    
    // Funciones de distorsión
    float processDistortion(float input);
    float softClip(float input);
    float sigmoid(float input);
    float rectFull(float input);
    float fuzzExp(float input);
    float tanhDist(float input);
    float rectHalf(float input);
    float arctanDist(float input);
    float hardClip(float input);
    
    // Funciones de dibujo
    void drawGrid(juce::Graphics& g, juce::Rectangle<float> bounds);
    void drawDistortionCurve(juce::Graphics& g, juce::Rectangle<float> bounds);
    juce::Colour getColorForMode();
    juce::String getModeName();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DistortionCurveComponent)
};