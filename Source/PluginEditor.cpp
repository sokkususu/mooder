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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MooderAudioProcessorEditor::MooderAudioProcessorEditor (MooderAudioProcessor &p)
    : AudioProcessorEditor (&p), processor (p), scopeComponent(processor.getAudioBufferQueue())
{
    //[Constructor_pre] You can add your own custom stuff here..
    addAndMakeVisible(midiKeyboardComponent);
    addAndMakeVisible(scopeComponent);
    //[/Constructor_pre]

    component.reset (new OscillatorComponent (p));
    addAndMakeVisible (component.get());
    component->setBounds (0, 0, 480, 160);

    component2.reset (new Oscillator2Component (p));
    addAndMakeVisible (component2.get());
    component2->setBounds (0, 160, 480, 160);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (480, 420);


    //[Constructor] You can add your own custom stuff here..

    midiKeyboardState.addListener(&processor.getMidiMessageCollector());
    midiKeyboardComponent.setBounds(0, 320, 240, 100);

    scopeComponent.setBounds(240, 320, 240, 100);
    //[/Constructor]
}

MooderAudioProcessorEditor::~MooderAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component = nullptr;
    component2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    midiKeyboardState.removeListener(&processor.getMidiMessageCollector());
    //[/Destructor]
}

//==============================================================================
void MooderAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MooderAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MooderAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="MooderAudioProcessor &amp;p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p), scopeComponent(processor.getAudioBufferQueue())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="480" initialHeight="420">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="74dc897685dd5775" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 480 160" sourceFile="OscillatorComponent.cpp"
             constructorParams="p"/>
  <JUCERCOMP name="" id="90a5c6d12f7447c2" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="0 160 480 160" sourceFile="Oscillator2Component.cpp"
             constructorParams="p"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

