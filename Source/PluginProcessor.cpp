/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MooderAudioProcessor::MooderAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
    ), parametrs(*this, nullptr, "PARAMETERS",
        {
            std::make_unique<AudioParameterFloat>("octave1", "Octave1", NormalisableRange<float>(-3.0f, 3.0f), 0.0f),
            std::make_unique<AudioParameterFloat>("trans1", "Trans1", NormalisableRange<float>(-12.0f, 12.0f), 0.0f),
            std::make_unique<AudioParameterFloat>("tune1", "Tune1", NormalisableRange<float>(-1.0f, 1.0f), 0.0f),
            std::make_unique<AudioParameterFloat>("level1", "Level1", NormalisableRange<float>(0.0f, 1.0f), 0.7f),

            std::make_unique<AudioParameterFloat>("octave2", "Octave2", NormalisableRange<float>(-3.0f, 3.0f), 0.0f),
            std::make_unique<AudioParameterFloat>("trans2", "Trans2", NormalisableRange<float>(-12.0f, 12.0f), 0.0f),
            std::make_unique<AudioParameterFloat>("tune2", "Tune2", NormalisableRange<float>(-1.0f, 1.0f), 0.0f),
            std::make_unique<AudioParameterFloat>("level2", "Level2", NormalisableRange<float>(0.0f, 1.0f), 0.7f),

            std::make_unique<AudioParameterFloat>("freqFilterLP", "FreqLP", NormalisableRange<float>(20.0f, 20000.0f), 20000.0f),
            std::make_unique<AudioParameterFloat>("rezFilterLP", "RezLP", NormalisableRange<float>(0.0f, 1.0f), 0.0f),

            std::make_unique<AudioParameterFloat>("freqFilterHP", "FreqHP", NormalisableRange<float>(20.0f, 20000.0f), 20.0f),
            std::make_unique<AudioParameterFloat>("rezFilterHP", "RezHP", NormalisableRange<float>(0.0f, 1.0f), 0.0f),
        
            std::make_unique<AudioParameterFloat>("attack", "Attack", NormalisableRange<float>(0.0f, 5.0f), 0.1f),
            std::make_unique<AudioParameterFloat>("decay", "Decay", NormalisableRange<float>(0.0f, 2.0f), 0.0f),
            std::make_unique<AudioParameterFloat>("sustain", "Sustain", NormalisableRange<float>(0.0f, 1.0f), 1.0f),
            std::make_unique<AudioParameterFloat>("release", "Release", NormalisableRange<float>(0.0f, 5.0f), 0.1f),

            std::make_unique<AudioParameterFloat>("freqLFO", "FreqLFO", NormalisableRange<float>(0.0f, 10.0f), 3.0f),
            std::make_unique<AudioParameterFloat>("amountLFO", "AmountLFO", NormalisableRange<float>(0.0f, 1.0f), 0.0f),

        }), waveForm1(1), waveForm2(1), lastSampleRate(44100.0), filterMode(juce::dsp::LadderFilter<float>::Mode::LPF24),
        lastFilterMode(juce::dsp::LadderFilter<float>::Mode::LPF24)
#endif
{
    
}

MooderAudioProcessor::~MooderAudioProcessor()
{
}

//==============================================================================
const String MooderAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MooderAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MooderAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MooderAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MooderAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MooderAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MooderAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MooderAudioProcessor::setCurrentProgram (int index)
{
}

const String MooderAudioProcessor::getProgramName (int index)
{
    return {};
}

void MooderAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MooderAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    audioEngine.setCurrentPlaybackSampleRate(sampleRate);
    audioEngine.prepare ({ sampleRate, (uint32) samplesPerBlock, 2 });
    midiMessageCollector.reset (sampleRate);
}

void MooderAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MooderAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void MooderAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    Voice* voice;

    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (int i = 0; i < audioEngine.getNumVoices(); i++)
    {
        if ((voice = dynamic_cast<Voice*>(audioEngine.getVoice(i))))
        {
            voice->setADSRSampleRate(lastSampleRate);
            
            voice->setWaveForm1(waveForm1);
            voice->setOctave1((float)*parametrs.getRawParameterValue("octave1"));
            voice->setTranspose1((float)*parametrs.getRawParameterValue("trans1"));
            voice->setTune1((float)*parametrs.getRawParameterValue("tune1"));
            voice->setLevel1((float)*parametrs.getRawParameterValue("level1"));

            voice->setWaveForm2(waveForm2);
            voice->setOctave2((float)*parametrs.getRawParameterValue("octave2"));
            voice->setTranspose2((float)*parametrs.getRawParameterValue("trans2"));
            voice->setTune2((float)*parametrs.getRawParameterValue("tune2"));
            voice->setLevel2((float)*parametrs.getRawParameterValue("level2"));

            voice->setFreqFilter((float)*parametrs.getRawParameterValue("freqFilterLP"));
            voice->setRezFilter((float)*parametrs.getRawParameterValue("rezFilterLP"));

            if (filterMode != lastFilterMode)
                voice->setModeFilter(filterMode);
            
            voice->setADSRSParams(
                (float)*parametrs.getRawParameterValue("attack"),
                (float)*parametrs.getRawParameterValue("decay"),
                (float)*parametrs.getRawParameterValue("sustain"),
                (float)*parametrs.getRawParameterValue("release"));

            voice->setLFOFreq((float)*parametrs.getRawParameterValue("freqLFO"));
            voice->setLFOAmount((float)*parametrs.getRawParameterValue("amountLFO"));
        }
    }

    lastFilterMode = filterMode;
    
    midiMessageCollector.removeNextBlockOfMessages (midiMessages, buffer.getNumSamples());

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    audioEngine.renderNextBlock (buffer, midiMessages, 0, buffer.getNumSamples());
    scopeDataCollector.process(buffer.getReadPointer(0), (size_t)buffer.getNumSamples());
    
    midiMessages.clear();
}

//==============================================================================
bool MooderAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MooderAudioProcessor::createEditor()
{
    return new MooderAudioProcessorEditor (*this);
}

//==============================================================================
void MooderAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MooderAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
MidiMessageCollector& MooderAudioProcessor::getMidiMessageCollector() noexcept { return midiMessageCollector; }

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MooderAudioProcessor();
}
