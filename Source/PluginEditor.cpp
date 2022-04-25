#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JCBDistoAudioProcessorEditor::JCBDistoAudioProcessorEditor (JCBDistoAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    auto backgroundImage = ImageCache::getFromMemory(BinaryData::morado_jpg,
                                                     BinaryData::morado_jpgSize);

    if (!backgroundImage.isNull())
        mFondo.setImage(backgroundImage, RectanglePlacement::stretchToFit);
    else
        jassert(!backgroundImage.isNull());
    
    addAndMakeVisible(mFondo);
    
    // Título
    addAndMakeVisible (titleLink);
    titleLink.setURL(juce::URL("https://github.com/cjitter"));
    titleLink.setColour (juce::HyperlinkButton::textColourId, juce::Colours::azure);
    titleLink.changeWidthToFitText();
    titleLink.setFont(juce::Font(4.f), true);
    titleLink.setTooltip (TRANS("https://github.com/cjitter"));
    titleLink.setButtonText (TRANS("JCBDisto 0.0.1"));
    
    
    // SATU
    addAndMakeVisible(dryWetSlider);
    dryWetSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    dryWetSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    dryWetSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));
    
    dryWetSlider.setTextValueSuffix(" ");
    dryWetSlider.setTextBoxIsEditable(true);

    dryWetSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    dryWetSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkviolet);
    dryWetSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    dryWetSlider.setDoubleClickReturnValue (true, 1.4);
    dryWetSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                   "a_drywet",
                                                                                                   dryWetSlider);
    
    
    addAndMakeVisible(driveSlider);
    driveSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    driveSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    driveSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));
    
    driveSlider.setTextValueSuffix(" ");
    driveSlider.setTextBoxIsEditable(true);
        
    driveSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    driveSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkviolet);
    driveSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    driveSlider.setDoubleClickReturnValue (true, -10);
    driveSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "b_drive",
                                                                                                 driveSlider);
    
    
    addAndMakeVisible(dcSlider);
    dcSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    dcSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    dcSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    dcSlider.setTextValueSuffix(" ");
    dcSlider.setTextBoxIsEditable(true);
    
    dcSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    dcSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkviolet);
    dcSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    dcSlider.setDoubleClickReturnValue (true, 50);
    dcSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                "c_dc",
                                                                                                 dcSlider);
    
    addAndMakeVisible(modeSlider);
    modeSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    modeSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    modeSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    modeSlider.setTextValueSuffix(" ");
    modeSlider.setTextBoxIsEditable(true);
    
    modeSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    modeSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkviolet);
    modeSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    modeSlider.setDoubleClickReturnValue (true, 10);
    modeSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "d_mode",
                                                                                                 modeSlider);
    
    
    addAndMakeVisible(cellingSlider);
    cellingSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    cellingSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    cellingSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    cellingSlider.setTextValueSuffix(" dB");
    cellingSlider.setTextBoxIsEditable(true);
    
    cellingSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    cellingSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkviolet);
    cellingSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    cellingSlider.setDoubleClickReturnValue (true, 80);
    cellingSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "e_celling",
                                                                                                   cellingSlider);
    
    addAndMakeVisible(bypassSlider);
    bypassSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    bypassSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    bypassSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    bypassSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    bypassSlider.setColour(juce::Slider::trackColourId, juce::Colours::darkviolet);
    bypassSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
    bypassSlider.setDoubleClickReturnValue (true, 0);
    bypassSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                    "f_bypass",
                                                                                                    bypassSlider);
    
    addAndMakeVisible(bitsSlider);
    bitsSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    bitsSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    bitsSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    bitsSlider.setTextValueSuffix(" Bits");
    bitsSlider.setTextBoxIsEditable(true);
    
    bitsSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    bitsSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::whitesmoke);
    bitsSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    bitsSlider.setDoubleClickReturnValue (true, 12);
    bitsSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "g_bits",
                                                                                                  bitsSlider);
    
    addAndMakeVisible(bitsOnSlider);
    bitsOnSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    bitsOnSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    bitsOnSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    bitsOnSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    bitsOnSlider.setColour(juce::Slider::trackColourId, juce::Colours::darkviolet);
    bitsOnSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
    bitsOnSlider.setDoubleClickReturnValue (true, 0);
    
    bitsOnSlider.addListener(this);
    
    bitsOnSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                    "h_bitsOn",
                                                                                                    bitsOnSlider);

    addAndMakeVisible(tiltSlider);
    tiltSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    tiltSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    tiltSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    tiltSlider.setTextValueSuffix(" ");
    tiltSlider.setTextBoxIsEditable(true);
    
    tiltSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    tiltSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkviolet);
    tiltSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    tiltSlider.setDoubleClickReturnValue (true, 0);
    tiltSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "i_tilt",
                                                                                                  tiltSlider);
    
    
    addAndMakeVisible(gainSlider);
    gainSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    gainSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    gainSlider.setTextValueSuffix(" ");
    gainSlider.setTextBoxIsEditable(true);
    
    gainSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    gainSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkviolet);
    gainSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    gainSlider.setDoubleClickReturnValue (true, 0);
    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "j_gain",
                                                                                                  gainSlider);
    

    
    
//    // Solo Sliders
//    addAndMakeVisible(soloLowSlider);
//    soloLowSlider.setSliderStyle (juce::Slider::LinearHorizontal);
//    soloLowSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
//    soloLowSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));
//
//    soloLowSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkred);
//    soloLowSlider.setColour(juce::Slider::trackColourId, juce::Colours::darkred);
//    soloLowSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
//    soloLowSlider.setDoubleClickReturnValue (true, 0);
//
//    soloLowSlider.addListener(this);
//
//    soloLowSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
//                                                                                                    "f_SOLOLOW",
//                                                                                                     soloLowSlider);
//    addAndMakeVisible(soloMedSlider);
//    soloMedSlider.setSliderStyle (juce::Slider::LinearHorizontal);
//    soloMedSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
//    soloMedSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));
//
//    soloMedSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkgreen);
//    soloMedSlider.setColour(juce::Slider::trackColourId, juce::Colours::darkgreen);
//    soloMedSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
//    soloMedSlider.setDoubleClickReturnValue (true, 0);
//
//    soloMedSlider.addListener(this);
//
//    soloMedSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
//                                                                                                    "g_SOLOMED",
//                                                                                                     soloMedSlider);
//
//    addAndMakeVisible(soloHighSlider);
//    soloHighSlider.setSliderStyle (juce::Slider::LinearHorizontal);
//    soloHighSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
//    soloHighSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));
//
//    soloHighSlider.setColour (juce::Slider::thumbColourId, juce::Colours::blue);
//    soloHighSlider.setColour(juce::Slider::trackColourId, juce::Colours::blue);
//    soloHighSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
//    soloHighSlider.setDoubleClickReturnValue (true, 0);
//
//    soloHighSlider.addListener(this);
//
//    soloHighSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
//                                                                                                      "h_SOLOHIGH",
//                                                                                                      soloHighSlider);
    
    // Labels
    addAndMakeVisible(labelMode);
    labelMode.setText(juce::CharPointer_UTF8("WAVESHAPER"), juce::dontSendNotification);
    labelMode.attachToComponent(&modeSlider, false);
    labelMode.setJustificationType(juce::Justification(36));

    addAndMakeVisible(labelCelling);
    labelCelling.setText(juce::CharPointer_UTF8("CELLING"), juce::dontSendNotification);
    labelCelling.attachToComponent(&cellingSlider, false);
    labelCelling.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelTilt);
    labelTilt.setText(juce::CharPointer_UTF8("TILT"), juce::dontSendNotification);
    labelTilt.attachToComponent(&tiltSlider, false);
    labelTilt.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelDC);
    labelDC.setText(juce::CharPointer_UTF8("DC"), juce::dontSendNotification);
    labelDC.attachToComponent(&dcSlider, false);
    labelDC.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelDrive);
    labelDrive.setText(juce::CharPointer_UTF8("DRIVE"), juce::dontSendNotification);
    labelDrive.attachToComponent(&driveSlider, false);
    labelDrive.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelBitsOn);
    labelBitsOn.setText(juce::CharPointer_UTF8("BITS ON"), juce::dontSendNotification);
    labelBitsOn.attachToComponent(&bitsOnSlider, false);
    labelBitsOn.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelBits);
    labelBits.setText(juce::CharPointer_UTF8("BITS"), juce::dontSendNotification);
    labelBits.attachToComponent(&bitsSlider, false);
    labelBits.setJustificationType(juce::Justification(36));

    addAndMakeVisible(labelGain);
    labelGain.setText(juce::CharPointer_UTF8("GAIN"), juce::dontSendNotification);
    labelGain.attachToComponent(&gainSlider, false);
    labelGain.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelDryWet);
    labelDryWet.setText(juce::CharPointer_UTF8("DRYWET"), juce::dontSendNotification);
    labelDryWet.attachToComponent(&dryWetSlider, false);
    labelDryWet.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelBypass);
    labelBypass.setText(juce::CharPointer_UTF8("BYPASS"), juce::dontSendNotification);
    labelBypass.attachToComponent(&bypassSlider, false);
    labelBypass.setJustificationType(juce::Justification(36));
    
    // Tamaño ventana plugin
    auto size = processor.getSavedSize();
    setResizable(true, true);
    setSize(size.x, size.y);
    setResizeLimits(1050, 350, ancho*2.75, alto*2.75);
    getConstrainer()->setFixedAspectRatio(ancho/alto);
}

JCBDistoAudioProcessorEditor::~JCBDistoAudioProcessorEditor()
{
}

//==============================================================================
void JCBDistoAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void JCBDistoAudioProcessorEditor::resized()
{
    // Satu
    auto correctX = 0;
    auto correctY = 0;
    
    auto xMode = (correctX+getWidth())     * 10/ancho;
    auto yMode = (correctY+getHeight())    * 77/alto;
    auto wMode = (correctX+getWidth())     * 60/ancho;
    auto hMode = (correctY+getHeight())    * 60/alto;
    
    auto xTilt = (correctX+getWidth())     * 70/ancho;
    auto yTilt = (correctY+getHeight())    * 77/alto;
    auto wTilt = (correctX+getWidth())     * 60/ancho;
    auto hTilt = (correctY+getHeight())    * 60/alto;
    
    auto xCelling = (correctX+getWidth())  * 130/ancho;
    auto yCelling = (correctY+getHeight()) * 77/alto;
    auto wCelling = (correctX+getWidth())  * 60/ancho;
    auto hCelling = (correctY+getHeight()) * 60/alto;
    
    auto xDC = (correctX+getWidth())       * 190/ancho;
    auto yDC = (correctY+getHeight())      * 77/alto;
    auto wDC = (correctX+getWidth())       * 60/ancho;
    auto hDC = (correctY+getHeight())      * 60/alto;
    
    auto xDrive = (correctX+getWidth())    * 285/ancho;
    auto yDrive = (correctY+getHeight())   * 45/alto;
    auto wDrive = (correctX+getWidth())    * 130/ancho;
    auto hDrive = (correctY+getHeight())   * 130/alto;
    
    auto xBitsOn =  (correctX+getWidth())  * 450/ancho;
    auto yBitsOn =  (correctY+getHeight()) * 100/alto;
    auto wBitsOn =  (correctX+getWidth())  * 50/ancho;
    auto hBitsOn =  (correctY+getHeight()) * 10/alto;
    
    auto xBits = (correctX+getWidth())     * 510/ancho;
    auto yBits = (correctY+getHeight())    * 77/alto;
    auto wBits = (correctX+getWidth())     * 60/ancho;
    auto hBits = (correctY+getHeight())    * 60/alto;
    
    auto xGain = (correctX+getWidth())     * 570/ancho;
    auto yGain = (correctY+getHeight())    * 77/alto;
    auto wGain = (correctX+getWidth())     * 60/ancho;
    auto hGain = (correctY+getHeight())    * 60/alto;
    
    auto xDryWet = (correctX+getWidth())   * 630/ancho; //170
    auto yDryWet = (correctY+getHeight())  * 77/alto;
    auto wDryWet = (correctX+getWidth())   * 60/ancho;
    auto hDryWet = (correctY+getHeight())  * 60/alto;
    
    auto xBypa   =  (correctX+getWidth())  * 470/ancho;
    auto yBypa   =  (correctY+getHeight()) * 185/alto;
    auto wBypa   =  (correctX+getWidth())  * 50/ancho;
    auto hBypa   =  (correctY+getHeight()) * 10/alto;

    // URL
    auto xUrl   = (correctX+getWidth())  * 505/ancho;
    auto yUrl   = (correctY+getHeight()) * 170/alto;
    auto wUrl   = (correctX+getHeight()) * 600/ancho;
    auto hUrl   = (correctY+getHeight()) * 25/alto;
    
    // set Bounds
    processor.setSavedSize( {getWidth(), getHeight()} );
    mFondo.setBoundsRelative(0.f, 0.f, 1.f, 1.f);
    
    modeSlider.setBounds        (xMode, yMode, wMode, hMode);
    tiltSlider.setBounds        (xTilt, yTilt, wTilt, hTilt);
    cellingSlider.setBounds     (xCelling, yCelling, wCelling, hCelling);
    dcSlider.setBounds          (xDC, yDC, wDC, hDC);
    driveSlider.setBounds       (xDrive, yDrive, wDrive, hDrive);
    bitsOnSlider.setBounds      (xBitsOn, yBitsOn, wBitsOn, hBitsOn);
    bitsSlider.setBounds        (xBits, yBits, wBits, hBits);
    gainSlider.setBounds        (xGain, yGain, wGain, hGain);
    dryWetSlider.setBounds      (xDryWet, yDryWet, wDryWet, hDryWet);
    bypassSlider.setBounds      (xBypa, yBypa, wBypa, hBypa);
    titleLink.setBounds         (xUrl, yUrl, wUrl, hUrl);

}

// Definición e implementación sliderValueChanged
void JCBDistoAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &bitsOnSlider && slider->getValue() == 1) {
        
        bitsSlider.setColour(juce::Slider::thumbColourId,               juce::Colours::whitesmoke);
        bitsSlider.setColour(juce::Slider::rotarySliderFillColourId,    juce::Colours::red);
        bitsSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::red);
    }

    else if (slider == &bitsOnSlider && slider->getValue() == 0) {
        
        bitsSlider.setColour(juce::Slider::thumbColourId,               juce::Colours::darkviolet);
        bitsSlider.setColour(juce::Slider::rotarySliderFillColourId,    juce::Colours::whitesmoke);
        bitsSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
        
    }
}
