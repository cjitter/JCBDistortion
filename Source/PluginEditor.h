#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class JCBDistoAudioProcessorEditor : public AudioProcessorEditor,
                                    public juce::Slider::Listener

{
public:
    JCBDistoAudioProcessorEditor (JCBDistoAudioProcessor&);
    ~JCBDistoAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider* slider) override;

private:
    
    juce::TooltipWindow tooltipVentana;
    
    // Declarar variables
    int const ancho {700};
    int const alto  {200};
    
    juce::Label labelDryWet;
    juce::Label labelDrive;
    juce::Label labelDC;
    juce::Label labelMode;
    juce::Label labelCelling;
    juce::Label labelBypass;
    
    juce::Label labelBits;
    juce::Label labelBitsOn;
    juce::Label labelGain;
    juce::Label labelTilt;

    
//    juce::Label labelSoloLow;
//    juce::Label labelSoloMed;
//    juce::Label labelSoloHigh;

   // Texto adicional
    juce::DrawableText txtExtra;
    // Link

    juce::HyperlinkButton titleLink;
    
    // Imagen de fondo como componente
    juce::ImageComponent mFondo;

    // Sliders

    juce::Slider dryWetSlider;
    juce::Slider driveSlider;
    juce::Slider dcSlider;
    juce::Slider modeSlider;
    juce::Slider cellingSlider;
    juce::Slider bypassSlider;
    
    juce::Slider bitsSlider;
    juce::Slider bitsOnSlider;
    juce::Slider gainSlider;
    juce::Slider tiltSlider;
    

    
    // juce::Slider soloLowSlider;
    // juce::Slider soloMedSlider;
    // juce::Slider soloHighSlider;

    // Sliders attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dryWetSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dcSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> modeSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cellingSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> bypassSliderAttachment;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> bitsSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> bitsOnSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> tiltSliderAttachment;


//    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> soloLowSliderAttachment;
//    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> soloMedSliderAttachment;
//    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> soloHighSliderAttachment;


    JCBDistoAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JCBDistoAudioProcessorEditor)
};

#endif  // PLUGINEDITOR_H_INCLUDED
