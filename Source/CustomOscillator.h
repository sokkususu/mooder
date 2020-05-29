/*
  ==============================================================================

    CustomOscillator.h
    Created: 7 Feb 2020 1:05:39am
    Author:  Дмитрий Шуляк

  ==============================================================================
*/

#pragma once

template <typename Type>
class CustomOscillator
{
public:
    //==============================================================================
    CustomOscillator()
    {
        auto& osc = processorChain.template get<oscIndex>();
        osc.initialise([](Type x) { return std::sin(x); }, 128);
    }

    void setWaveForm(int waveForm)
    {
        auto& osc = processorChain.template get<oscIndex>();
        if (waveForm == 1)
            osc.initialise([](Type x) { return std::sin(x); }, 128);
        if (waveForm == 2)
            osc.initialise([](Type x) { return  jmap(x, Type(-MathConstants <double>::pi), 
                Type(MathConstants<double>::pi), Type(-1), Type(1)); }, 2);
        if (waveForm == 3)
            osc.initialise([](Type x) { return std::sin(x); }, 4);
        if (waveForm == 4)
            osc.initialise([](Type x) { return std::tanh(20 * std::sin(x)); }, 128);
    }

    //==============================================================================
    void setFrequency(Type newValue, bool force = false)
    {
        auto& osc = processorChain.template get<oscIndex>();
        osc.setFrequency(newValue, force);
    }

    //==============================================================================
    void setLevel(Type newValue)
    {
        auto& gain = processorChain.template get<gainIndex>();
        gain.setGainLinear(newValue);
    }

    //==============================================================================
    void reset() noexcept
    {
        processorChain.reset();
    }

    //==============================================================================
    template <typename ProcessContext>
    void process(const ProcessContext& context) noexcept
    {
        processorChain.process(context);
    }

    //==============================================================================
    void prepare(const juce::dsp::ProcessSpec& spec)
    {
        processorChain.prepare(spec);
    }

private:
    //==============================================================================
    enum
    {
        oscIndex,
        gainIndex
    };

    juce::dsp::ProcessorChain<juce::dsp::Oscillator<Type>, juce::dsp::Gain<Type>> processorChain;
};


//osc.initialise([](Type x) { return std::sin(x); }, 128);
//osc.initialise ([] (Type x) { return  jmap(x, Type(-MathConstants <double> ::pi), Type(MathConstants <double> ::pi), Type(-1), Type(1));}, 2);