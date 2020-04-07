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
        level1 = 0.0f;
        tune1 = 1.0f;
        octave1 = 0;
        transp1 = 0;

        level2 = 0.0f;
        tune2 = 1.0f;
        octave2 = 0;
        transp2 = 0;

        freqFilterLP = 20000.0f;
        rezFilterLP = 0.0f;

        freqFilterHP = 20.0f;
        rezFilterHP = 0.0f;
        
        env = 0;

        auto &masterGain = processorChain.get<masterGainIndex>();
        masterGain.setGainLinear(0.7f);

        auto &filterLP = processorChain.get<filterLPIndex>();
        filterLP.setCutoffFrequencyHz(freqFilterLP);
        filterLP.setResonance(rezFilterLP);
        filterLP.setMode(juce::dsp::LadderFilter<float>::Mode::LPF24);

        auto &filterHP = processorChain.get<filterHPIndex>();
        filterHP.setCutoffFrequencyHz(freqFilterHP);
        filterHP.setResonance(rezFilterHP);
        filterHP.setMode(juce::dsp::LadderFilter<float>::Mode::HPF24);
    }

    //==============================================================================
    void prepare(const juce::dsp::ProcessSpec &spec)
    {
        tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
        processorChain.prepare(spec);
    }

    //==============================================================================
    void noteStarted() override
    {
        adsr.noteOn();
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
        adsr.noteOff();

        if (velocity == 0)
            clearCurrentNote();
    }

    //==============================================================================
    void notePressureChanged() override {}
    void noteTimbreChanged() override {}
    void noteKeyStateChanged() override {}

    //==============================================================================
    void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override
    {
        adsr.setParameters(adsrParams);

        velocity = getCurrentlyPlayingNote().noteOnVelocity.asUnsignedFloat();
        auto freqHz = (float)getCurrentlyPlayingNote().getFrequencyInHertz();

        float freq1 = freqHz * pow(2, octave1 + (tune1 + transp1) / 12);
        float freq2 = freqHz * pow(2, octave2 + (tune2 + transp2) / 12);

        processorChain.get<osc1Index>().setFrequency(freq1, true);
        processorChain.get<osc1Index>().setLevel(velocity * level1 * env);

        processorChain.get<osc2Index>().setFrequency(freq2, true);
        processorChain.get<osc2Index>().setLevel(velocity * level2 * env);

        auto& filterLP = processorChain.get<filterLPIndex>();
        filterLP.setCutoffFrequencyHz(freqFilterLP);
        filterLP.setResonance(rezFilterLP);

        auto& filterHP = processorChain.get<filterHPIndex>();
        filterHP.setCutoffFrequencyHz(freqFilterHP);
        filterHP.setResonance(rezFilterHP);

        auto block = tempBlock.getSubBlock(0, (size_t)numSamples);

        juce::dsp::ProcessContextReplacing<float> context(block);
        processorChain.process(context);

        juce::dsp::AudioBlock<float>(outputBuffer)
            .getSubBlock((size_t)startSample, (size_t)numSamples)
            .add(tempBlock);
        block.clear();
        
        while (--numSamples >= 0)
        {
            env = adsr.getNextSample();

            if (env == 0)
            {
                clearCurrentNote();
            }
        }
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

    void setFreqFilterLP(float freq) { freqFilterLP = freq; }
    void setRezFilterLP(float rez) { rezFilterLP = rez; }

    void setFreqFilterHP(float freq) { freqFilterHP = freq; }
    void setRezFilterHP(float rez) { rezFilterHP = rez; }

    void setADSRSampleRate(double sampleRate) { adsr.setSampleRate(sampleRate); }
    void setADSRSParams(float attack, float decay, float sustain, float release)
    {
        adsrParams.attack = attack;
        adsrParams.decay = decay;
        adsrParams.sustain = sustain;
        adsrParams.release = release;
    }

private:
    float velocity, env;

    int octave1, octave2;
    float transp1, transp2;
    float tune1, tune2;
    float level1, level2;

    float freqFilterLP, rezFilterLP;
    float freqFilterHP, rezFilterHP;

    //==============================================================================
    juce::HeapBlock<char> heapBlock;
    juce::dsp::AudioBlock<float> tempBlock;

    ADSR adsr;
    ADSR::Parameters adsrParams;

    enum
    {
        osc1Index,
        osc2Index,
        filterLPIndex,
        filterHPIndex,
        masterGainIndex
    };

    juce::dsp::ProcessorChain<
        CustomOscillator<float>,
        CustomOscillator<float>,
        juce::dsp::LadderFilter<float>,
        juce::dsp::LadderFilter<float>,
        juce::dsp::Gain<float>>
        processorChain;
};
