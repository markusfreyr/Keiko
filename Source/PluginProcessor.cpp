/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KeikoAudioProcessor::KeikoAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{
    
    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());
    
    mySynth.clearVoices();
    
    for (int i = 0; i < 5; i++)
    {
        mySynth.addVoice(new SynthVoice());
    }
    

    
}

KeikoAudioProcessor::~KeikoAudioProcessor()
{
}

//==============================================================================

AudioProcessorValueTreeState::ParameterLayout KeikoAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<RangedAudioParameter>> params;
    
    auto attackParam = std::make_unique<AudioParameterFloat>("attack", "Attack", 0.0f, 5000, 100);
    auto decayParam = std::make_unique<AudioParameterFloat>("decay", "Decay", 0.0f, 5000, 100);
    auto sustainParam = std::make_unique<AudioParameterFloat>("sustain", "Sustain", 0.0f, 1, 1);
    auto releaseParam = std::make_unique<AudioParameterFloat>("release", "Release", 0.0f, 5000, 100);
    auto waveType = std::make_unique<AudioParameterFloat>("wave", "Wave", 0.0f, 3.0f, 0);
    auto filterCutoffParam = std::make_unique<AudioParameterFloat>("cutoff", "Cutoff", 20.0f, 10000.0f, 1000);
    auto filterResParam = std::make_unique<AudioParameterFloat>("res", "Res", 1.0f , 5.0f, 1);
    
    params.push_back(std::move(attackParam));
    params.push_back(std::move(decayParam));
    params.push_back(std::move(sustainParam));
    params.push_back(std::move(releaseParam));
    params.push_back(std::move(waveType));
    params.push_back(std::move(filterCutoffParam));
    params.push_back(std::move(filterResParam));

    return {params.begin(), params.end()};
}

//==============================================================================
const String KeikoAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool KeikoAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KeikoAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KeikoAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double KeikoAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KeikoAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int KeikoAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KeikoAudioProcessor::setCurrentProgram (int index)
{
}

const String KeikoAudioProcessor::getProgramName (int index)
{
    return {};
}

void KeikoAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void KeikoAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void KeikoAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool KeikoAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void KeikoAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    
    for(int i = 0; i < mySynth.getNumVoices(); i++)
    {
        if((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))))
        {
            myVoice->getADSRParam(treeState.getRawParameterValue("attack"),
                                  treeState.getRawParameterValue("decay"),
                                  treeState.getRawParameterValue("sustain"),
                                  treeState.getRawParameterValue("release"));
            
            myVoice->getOscType(treeState.getRawParameterValue("wave"));
            
            myVoice->getFilterParam(treeState.getRawParameterValue("cutoff"),
                                    treeState.getRawParameterValue("res"));
        }
    }
    
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

    
}

//==============================================================================
bool KeikoAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* KeikoAudioProcessor::createEditor()
{
    return new KeikoAudioProcessorEditor (*this);
}

//==============================================================================
void KeikoAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void KeikoAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KeikoAudioProcessor();
}
