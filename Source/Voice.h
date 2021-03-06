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

        freqFilter = 20000.0f;
        rezFilter = 0.0f;

        env = 0;
        velocity = 0;

        freqLFO = 3.0f;
        amountLFO = 0.0f;

        auto &masterGain = processorChain.get<masterGainIndex>();
        masterGain.setGainLinear(0.7f);

        auto &filterLP = processorChain.get<filterIndex>();
        filterLP.setCutoffFrequencyHz(freqFilter);
        filterLP.setResonance(rezFilter);
        filterLP.setMode(juce::dsp::LadderFilter<float>::Mode::LPF24);

        lfo.initialise([](float x) { return std::sin(x); }, 128);
        lfo.setFrequency(freqLFO);
    }

    //==============================================================================
    void prepare(const juce::dsp::ProcessSpec &spec)
    {
        tempBlock = juce::dsp::AudioBlock<float>(heapBlock, spec.numChannels, spec.maximumBlockSize);
        processorChain.prepare(spec);

        lfo.prepare({ spec.sampleRate / lfoUpdateRate, spec.maximumBlockSize, spec.numChannels });
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

        auto& filterLP = processorChain.get<filterIndex>();
        filterLP.setCutoffFrequencyHz(freqFilter);
        filterLP.setResonance(rezFilter);

        lfo.setFrequency(freqLFO);

        for (size_t pos = 0; pos < (size_t)numSamples;)
        {
            auto max = jmin((size_t)numSamples - pos, lfoUpdateCounter);

            pos += max;
            lfoUpdateCounter -= max;

            if (lfoUpdateCounter == 0)
            {
                lfoUpdateCounter = lfoUpdateRate;
                auto lfoOut = lfo.processSample(0.0f);
                auto lfoMod = jmap(lfoOut, -1.0f, 1.0f, 0.5f - amountLFO / 2, 0.5f + amountLFO / 2);
                processorChain.get<osc2Index>().setLevel(velocity * level2 * env * lfoMod);
            }
        }

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

    void setFreqFilter(float freq) { freqFilter = freq; }
    void setRezFilter(float rez) { rezFilter = rez; }
    void setModeFilter(juce::dsp::LadderFilter<float>::Mode mode) { processorChain.get<filterIndex>().setMode(mode); }

    void setADSRSampleRate(double sampleRate) { adsr.setSampleRate(sampleRate); }
    void setADSRSParams(float attack, float decay, float sustain, float release)
    {
        adsrParams.attack = attack;
        adsrParams.decay = decay;
        adsrParams.sustain = sustain;
        adsrParams.release = release;
    }

    void setLFOFreq(float freq) { freqLFO = freq; }
    void setLFOAmount(float amount) { amountLFO = amount; }

private:
    float velocity, env;

    int octave1, octave2;
    float transp1, transp2;
    float tune1, tune2;
    float level1, level2;

    float freqFilter, rezFilter;

    float freqLFO;
    float amountLFO;

    //==============================================================================
    juce::HeapBlock<char> heapBlock;
    juce::dsp::AudioBlock<float> tempBlock;

    ADSR adsr;
    ADSR::Parameters adsrParams;

    enum
    {
        osc1Index,
        osc2Index,
        filterIndex,
        masterGainIndex
    };

    juce::dsp::ProcessorChain<
        CustomOscillator<float>,
        CustomOscillator<float>,
        juce::dsp::LadderFilter<float>,
        juce::dsp::Gain<float>>
        processorChain;

    static constexpr size_t lfoUpdateRate = 100;
    size_t lfoUpdateCounter = lfoUpdateRate;
    juce::dsp::Oscillator<float> lfo;
};
