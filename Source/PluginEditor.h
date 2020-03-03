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
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "ScopeComponent.h"
//[/Headers]

#include "OscillatorComponent.h"
#include "Oscillator2Component.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MooderAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    //==============================================================================
    MooderAudioProcessorEditor (MooderAudioProcessor &p);
    ~MooderAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MooderAudioProcessor& processor;

    MidiKeyboardState midiKeyboardState;
    MidiKeyboardComponent midiKeyboardComponent { midiKeyboardState,
        MidiKeyboardComponent::horizontalKeyboard };
    ScopeComponent<float> scopeComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OscillatorComponent> component;
    std::unique_ptr<Oscillator2Component> component2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MooderAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

