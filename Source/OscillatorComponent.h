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
class OscillatorComponent  : public Component,
                             public Slider::Listener,
                             public Button::Listener
{
public:
    //==============================================================================
    OscillatorComponent (MooderAudioProcessor& p);
    ~OscillatorComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MooderAudioProcessor& processor;

    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> level;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> octaveSlider;
    std::unique_ptr<Label> label2;
    std::unique_ptr<TextButton> sinButton;
    std::unique_ptr<TextButton> sawButton;
    std::unique_ptr<TextButton> triButton;
    std::unique_ptr<TextButton> sqrButton;
    std::unique_ptr<Label> label1;
    std::unique_ptr<Slider> transSlider;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> tuneSlider;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Slider> levelSlider;
    std::unique_ptr<Label> label5;
    std::unique_ptr<ToggleButton> activateButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

