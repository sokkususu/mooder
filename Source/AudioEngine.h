/*
  ==============================================================================

    AudioEngine.h
    Created: 7 Feb 2020 1:07:10am
    Author:  Дмитрий Шуляк

  ==============================================================================
*/

#pragma once

#include "Voice.h"

//==============================================================================
class AudioEngine : public juce::MPESynthesiser
{
public:
    static constexpr auto maxNumVoices = 4;

    //==============================================================================
    AudioEngine()
    {
        for (auto i = 0; i < maxNumVoices; ++i)
            addVoice(new Voice);

        setVoiceStealingEnabled(true);
    }

    //==============================================================================
    void prepare(const juce::dsp::ProcessSpec& spec) noexcept
    {
        setCurrentPlaybackSampleRate(spec.sampleRate);

        for (auto* v : voices)
            dynamic_cast<Voice*> (v)->prepare(spec);
    }

private:
    //==============================================================================
    void renderNextSubBlock (AudioBuffer<float>& outputAudio, int startSample, int numSamples) override
    {
        MPESynthesiser::renderNextSubBlock (outputAudio, startSample, numSamples);
    }
};
