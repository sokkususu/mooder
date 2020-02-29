/*
  ==============================================================================

    Voice.h
    Created: 7 Feb 2020 1:06:27am
    Author:  Дмитрий Шуляк

  ==============================================================================
*/

#pragma once

#include "CustomOscillator.h"
class Voice : public juce::MPESynthesiserVoice
{
public:
    Voice()
    {
        auto& masterGain = processorChain.get<masterGainIndex>();
        masterGain.setGainLinear(0.7f);

        level1 = 0.7f;
        tune1 = 1.0f;
        octave1 = 0;
        transp1 = 0;

        level2 = 0.7f;
        tune2 = 1.0f;
        octave2 = 0;
        transp2 = 0;
    }

    //==============================================================================
    void prepare(const juce::dsp::ProcessSpec& spec)
    {
        tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
        processorChain.prepare(spec);
    }

    //==============================================================================
    void noteStarted() override
    {
        auto velocity = getCurrentlyPlayingNote().noteOnVelocity.asUnsignedFloat();
        auto freqHz = (float)getCurrentlyPlayingNote().getFrequencyInHertz();

        float freq1 = freqHz * pow(2, octave1 + (tune1 + transp1) / 12);
        float freq2 = freqHz * pow(2, octave2 + (tune2 + transp2) / 12);

        Logger::writeToLog((String)freq2 + " " + (String)octave1 + " " + (String)transp1 + " " + (String)tune1);
    }

    //==============================================================================
    void notePitchbendChanged() override
    {
        auto freqHz = (float)getCurrentlyPlayingNote().getFrequencyInHertz();

        float freq1 = freqHz * pow(2, octave1 + (tune1 + transp1) / 12);
        float freq2 = freqHz * pow(2, octave2 + (tune2 + transp2) / 12);

        processorChain.get<osc1Index>().setFrequency(freq1, true);
        processorChain.get<osc2Index>().setFrequency(freq2, true);
    }

    //==============================================================================
    void noteStopped(bool) override
    {
        clearCurrentNote();
    }

    //==============================================================================
    void notePressureChanged() override {}
    void noteTimbreChanged()   override {}
    void noteKeyStateChanged() override {}

    //==============================================================================
    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override
    {
        auto block = tempBlock.getSubBlock (0, (size_t) numSamples);
        block.clear();
        juce::dsp::ProcessContextReplacing<float> context (block);
        processorChain.process (context);

        auto velocity = getCurrentlyPlayingNote().noteOnVelocity.asUnsignedFloat();
        auto freqHz = (float)getCurrentlyPlayingNote().getFrequencyInHertz();

        float freq1 = freqHz * pow(2, octave1 + (tune1 + transp1) / 12);
        float freq2 = freqHz * pow(2, octave2 + (tune2 + transp2) / 12);

        processorChain.get<osc1Index>().setFrequency(freq1, true);
        processorChain.get<osc1Index>().setLevel(velocity * level1);

        processorChain.get<osc2Index>().setFrequency(freq2, true);
        processorChain.get<osc2Index>().setLevel(velocity * level2);

        juce::dsp::AudioBlock<float> (outputBuffer)
            .getSubBlock ((size_t) startSample, (size_t) numSamples)
            .add (tempBlock);
    }

    void setWaveForm1(int waveForm) { processorChain.get<osc1Index>().setWaveForm(waveForm); }
    void setOctave1(int oct) { octave1 = oct; }
    void setTranspose1(float t) { transp1 = t; }
    void setTune1(float t) { tune1 = t; }
    void setLevel1(float lvl) { level1 = lvl; }

    void setWaveForm2(int waveForm) { processorChain.get<osc2Index>().setWaveForm(waveForm); }
    void setOctave2(int oct) { octave2 = oct; }
    void setTranspose2(float t) { transp2 = t; }
    void setTune2(float t) { tune2 = t; }
    void setLevel2(float lvl) { level2 = lvl; }

private:
    int octave1, octave2;
    float transp1, transp2;
    float tune1, tune2;
    float level1, level2;

    //==============================================================================
    juce::HeapBlock<char> heapBlock;
    juce::dsp::AudioBlock<float> tempBlock;

    enum
    {
        osc1Index,
        osc2Index,
        masterGainIndex
    };

    juce::dsp::ProcessorChain<CustomOscillator<float>, CustomOscillator<float>, juce::dsp::Gain<float>> processorChain;
};
