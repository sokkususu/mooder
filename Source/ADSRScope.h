/*
  ==============================================================================

    ADSRScope.h
    Created: 9 Apr 2020 7:51:37am
    Author:  sokku

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
class ADSRScope : public juce::Component,
    private Timer
{
public:

    //==============================================================================
    ADSRScope()
    {
        setFramesPerSecond(60);
    }

    //==============================================================================
    void setFramesPerSecond(int framesPerSecond)
    {
        jassert(framesPerSecond > 0 && framesPerSecond < 1000);
        startTimerHz(framesPerSecond);
    }

    //==============================================================================
    void paint(Graphics& g) override
    {
        g.fillAll(juce::Colours::black);
        g.setColour(juce::Colours::white);
    }

    //==============================================================================
    void resized() override {}

private:

    //==============================================================================
    void timerCallback() override
    {
        repaint();
    }
};