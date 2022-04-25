#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
JCBDistoAudioProcessor::JCBDistoAudioProcessor() :

apvts(*this, nullptr, "PARAMETERS", createParameterLayout()),
m_CurrentBufferSize(0)

{
    // use a default samplerate and vector size here, reset it later
    m_GEN_DSP_PluginState = (CommonState *)GEN_DSP::create(44100, 64);
    GEN_DSP::reset(m_GEN_DSP_PluginState);
    
    m_InputBuffers = new t_sample *[GEN_DSP::num_inputs()];
    m_OutputBuffers = new t_sample *[GEN_DSP::num_outputs()];
    
    for (int i = 0; i < GEN_DSP::num_inputs(); i++) {
        m_InputBuffers[i] = NULL;
    }
    for (int i = 0; i < GEN_DSP::num_outputs(); i++) {
        m_OutputBuffers[i] = NULL;
    }
    
    // MUY IMPORTNTE: vincular parámetros de gen~ con el APVTS
    for (int i = 0; i < GEN_DSP::num_params(); i++)
    {
        auto name = juce::String (GEN_DSP::getparametername (m_GEN_DSP_PluginState, i));
        apvts.addParameterListener (name, this);
    }
    
}

JCBDistoAudioProcessor::~JCBDistoAudioProcessor()
{
    GEN_DSP::destroy(m_GEN_DSP_PluginState);
    
    // destruir parámetros del apvts
    for (int i = 0; i < GEN_DSP::num_params(); i++)
    {
        auto name = juce::String (GEN_DSP::getparametername(m_GEN_DSP_PluginState, i));
        apvts.removeParameterListener(name, this);
    }
    
}

//==============================================================================
const String JCBDistoAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int JCBDistoAudioProcessor::getNumParameters()
{
    return GEN_DSP::num_params();
}

////////////////////////////////

float JCBDistoAudioProcessor::getParameter (int index)
{
    t_param value;
    t_param min = GEN_DSP::getparametermin(m_GEN_DSP_PluginState, index);
    t_param range = fabs(GEN_DSP::getparametermax(m_GEN_DSP_PluginState, index) - min);
    
    GEN_DSP::getparameter(m_GEN_DSP_PluginState, index, &value);
    
    value = (value - min) / range;
    
    return value;
}

void JCBDistoAudioProcessor::setParameter (int index, float newValue)
{
    t_param min = GEN_DSP::getparametermin(m_GEN_DSP_PluginState, index);
    t_param range = fabs(GEN_DSP::getparametermax(m_GEN_DSP_PluginState, index) - min);
    t_param value = newValue * range + min;
    
    GEN_DSP::setparameter(m_GEN_DSP_PluginState, index, value, NULL);
}

////////////////////////////////

const String JCBDistoAudioProcessor::getParameterName (int index)
{
    return String(GEN_DSP::getparametername(m_GEN_DSP_PluginState, index));
}

const String JCBDistoAudioProcessor::getParameterText (int index)
{
    String text = String(getParameter(index));
    text += String(" ");
    text += String(GEN_DSP::getparameterunits(m_GEN_DSP_PluginState, index));
    
    return text;
}

const String JCBDistoAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String JCBDistoAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool JCBDistoAudioProcessor::isInputChannelStereoPair (int index) const
{
    return GEN_DSP::num_inputs() == 2;
}

bool JCBDistoAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return GEN_DSP::num_outputs() == 2;
}

bool JCBDistoAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool JCBDistoAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool JCBDistoAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double JCBDistoAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int JCBDistoAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int JCBDistoAudioProcessor::getCurrentProgram()
{
    return 0;
}

void JCBDistoAudioProcessor::setCurrentProgram (int index)
{
}

const String JCBDistoAudioProcessor::getProgramName (int index)
{
    return String();
}

void JCBDistoAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void JCBDistoAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    // initialize samplerate and vectorsize with the correct values
    m_GEN_DSP_PluginState->sr = sampleRate;
    m_GEN_DSP_PluginState->vs = samplesPerBlock;
    
    assureBufferSize(samplesPerBlock);
}

void JCBDistoAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void JCBDistoAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    //processBlockBypassed(buffer, midiMessages);
    //auto totalNumInputChannels  = getTotalNumInputChannels();
    //auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    assureBufferSize(buffer.getNumSamples());
    
    // fill input buffers
    for (int i = 0; i < GEN_DSP::num_inputs(); i++) {
        if (i < getTotalNumInputChannels()) {
            for (int j = 0; j < m_CurrentBufferSize; j++) {
                m_InputBuffers[i][j] = buffer.getReadPointer(i)[j];
            }
        } else {
            memset(m_InputBuffers[i], 0, m_CurrentBufferSize *  sizeof(double));
        }
    }
    
    // process audio
    GEN_DSP::perform(m_GEN_DSP_PluginState,
                     m_InputBuffers,
                     GEN_DSP::num_inputs(),
                     m_OutputBuffers,
                     GEN_DSP::num_outputs(),
                     buffer.getNumSamples());
    
    
    // fill output buffers
    for (int i = 0; i < getTotalNumOutputChannels(); i++) {
        if (i < GEN_DSP::num_outputs()) {
            for (int j = 0; j < buffer.getNumSamples(); j++) {
                buffer.getWritePointer(i)[j] = m_OutputBuffers[i][j];
            }
        } else {
            buffer.clear (i, 0, buffer.getNumSamples());
        }
    }
}

//==============================================================================
bool JCBDistoAudioProcessor::hasEditor() const
{
    return true; // (change this to true if you choose to supply an editor)
}

AudioProcessorEditor* JCBDistoAudioProcessor::createEditor()
{
    return new JCBDistoAudioProcessorEditor (*this);
    //return new GenericAudioProcessorEditor (*this);
}

//==============================================================================
void JCBDistoAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
//    auto editor = apvts.state.getOrCreateChildWithName ("editor", nullptr);
//    editor.setProperty ("size-x", editorSize.x, nullptr);
//    editor.setProperty ("size-y", editorSize.y, nullptr);
    
    juce::MemoryOutputStream miMemoria (destData, true);
    apvts.state.writeToStream (miMemoria);
}

Point<int> JCBDistoAudioProcessor::getSavedSize() const
{
    return editorSize;
}

void JCBDistoAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    auto tree = juce::ValueTree::readFromData (data, sizeInBytes);
    if (tree.isValid()) {
        apvts.state = tree;
        
//        auto editor = apvts.state.getChildWithName ("editor");
//        if (editor.isValid())
//        {
//            editorSize.setX (editor.getProperty ("size-x", 700));
//            editorSize.setY (editor.getProperty ("size-y", 200));
//            if (auto* activeEditor = getActiveEditor())
//                activeEditor->setSize (editorSize.x, editorSize.y);
//        }
    }
}

void JCBDistoAudioProcessor::setSavedSize (const Point<int>& size)
{
    editorSize = size;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JCBDistoAudioProcessor();
}

//==============================================================================
// C74 added methods

void JCBDistoAudioProcessor::assureBufferSize(long bufferSize)
{
    if (bufferSize > m_CurrentBufferSize) {
        for (int i = 0; i < GEN_DSP::num_inputs(); i++) {
            if (m_InputBuffers[i]) delete m_InputBuffers[i];
            m_InputBuffers[i] = new t_sample[bufferSize];
        }
        for (int i = 0; i < GEN_DSP::num_outputs(); i++) {
            if (m_OutputBuffers[i]) delete m_OutputBuffers[i];
            m_OutputBuffers[i] = new t_sample[bufferSize];
        }
        
        m_CurrentBufferSize = bufferSize;
    }
}

//==============================================================================
// Implementación  para APVTS: createParameterLayout y parameterChanged

juce::AudioProcessorValueTreeState::ParameterLayout JCBDistoAudioProcessor::createParameterLayout()
{
    static const int versionHint = 0;
    
    std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;
    
    auto drywet = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("a_drywet", versionHint),
                                                              juce::CharPointer_UTF8("Dry/Wet"),
                                                              NormalisableRange<float>(0.f,
                                                                                       1.0f,
                                                                                       0.01,
                                                                                       1.f),
                                                              1.0f);
    
    auto drive = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("b_drive", versionHint),
                                                             juce::CharPointer_UTF8("Drive"),
                                                             NormalisableRange<float>(0.f,
                                                                                      20.0f,
                                                                                      0.01,
                                                                                      1.f),
                                                             1.0f);
    
    auto dc = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("c_dc", versionHint),
                                                          juce::CharPointer_UTF8("DC"),
                                                          NormalisableRange<float>(0.f,
                                                                                   1.0f,
                                                                                   0.01,
                                                                                   1.f),
                                                          0.f);
    
    auto mode = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("d_mode", versionHint),
                                                          juce::CharPointer_UTF8("Waveshaper"),
                                                          1,
                                                          5,
                                                          1);
    
    auto cell = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("e_celling", versionHint),
                                                            juce::CharPointer_UTF8("Celling"),
                                                            NormalisableRange<float>(-20.f,
                                                                                     6.f,
                                                                                     0.01,
                                                                                     3.f),
                                                            0.f);
    
    auto bypass = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("f_bypass", versionHint),
                                                            juce::CharPointer_UTF8("Bypass"),
                                                            NormalisableRange<float>(0.f,
                                                                                     1.f,
                                                                                     1.f,
                                                                                     1.f),
                                                            0.f);
    
    auto bits = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("g_bits", versionHint),
                                                            juce::CharPointer_UTF8("Bits"),
                                                            NormalisableRange<float>(1.f,
                                                                                     16.f,
                                                                                     0.1,
                                                                                     1.f),
                                                            16.f);
    
    auto bitson = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("h_bitsOn", versionHint),
                                                            juce::CharPointer_UTF8("Bits On/Off"),
                                                            NormalisableRange<float>(0.f,
                                                                                     1.f,
                                                                                     1.f,
                                                                                     1.f),
                                                            0.f);
    
    auto tilt = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("i_tilt", versionHint),
                                                            juce::CharPointer_UTF8("Tilt"),
                                                            NormalisableRange<float>(-12.f,
                                                                                     12.f,
                                                                                     0.1f,
                                                                                     1.f),
                                                            0.f);
    
    auto gain = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("j_gain", versionHint),
                                                            juce::CharPointer_UTF8("Tilt"),
                                                            NormalisableRange<float>(-20.f,
                                                                                     6.f,
                                                                                     0.01,
                                                                                     1.f),
                                                            0.f);
    
    
    
    params.push_back(std::move(drywet));
    params.push_back(std::move(drive));
    params.push_back(std::move(dc));
    params.push_back(std::move(mode));
    params.push_back(std::move(cell));
    params.push_back(std::move(bypass));
    
    params.push_back(std::move(bits));
    params.push_back(std::move(bitson));
    params.push_back(std::move(tilt));
    params.push_back(std::move(gain));

    return {params.begin(), params.end()};
}

void JCBDistoAudioProcessor::parameterChanged (const juce::String& parameterID, float newValue)
{
    auto index = apvts.getParameter(parameterID)->getParameterIndex();
    GEN_DSP::setparameter(m_GEN_DSP_PluginState, index, newValue, nullptr);
}
