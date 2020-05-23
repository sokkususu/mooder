/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioEngine.h"
#include "AudioBufferQueue.h"
#include "ScopeDataCollector.h"

//==============================================================================
/**
*/
class MooderAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MooderAudioProcessor();
    ~MooderAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================
    MidiMessageCollector& getMidiMessageCollector() noexcept;
    AudioBufferQueue<float>& getAudioBufferQueue() noexcept  { return audioBufferQueue; }
    
    //==============================================================================

    AudioProcessorValueTreeState parametrs;

    void setWaveForm1(int wf) { waveForm1 = wf; }
    void setWaveForm2(int wf) { waveForm2 = wf; }

    void setFilterMode(juce::dsp::LadderFilter<float>::Mode mode) { filterMode = mode; }

    juce::dsp::LadderFilter<float>::Mode getFilterMode() { return filterMode; }
private:
    int waveForm1, waveForm2;
    double lastSampleRate;
    

    AudioEngine audioEngine;
    MidiMessageCollector midiMessageCollector;
    AudioBufferQueue<float> audioBufferQueue;
    ScopeDataCollector<float> scopeDataCollector{ audioBufferQueue };

    juce::dsp::LadderFilter<float>::Mode filterMode;
    juce::dsp::LadderFilter<float>::Mode lastFilterMode;
    //==============================================================================

    //==============================================================================

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MooderAudioProcessor)
};
