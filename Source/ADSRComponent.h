/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ADSRComponent  : public Component,
                       public Slider::Listener
{
public:
    //==============================================================================
    ADSRComponent (MooderAudioProcessor& p);
    ~ADSRComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MooderAudioProcessor& processor;

    float lastAttack, lastDecay, lastSustain, lastRelease;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> attackSlider;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label1;
    std::unique_ptr<Slider> decaySlider;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> sustainSlider;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Slider> releaseSlider;
    std::unique_ptr<Label> label5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

