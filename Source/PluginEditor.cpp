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
    setLookAndFeel(&otherLookAndFeel);

    addAndMakeVisible(midiKeyboardComponent);
    addAndMakeVisible(scopeComponent);
    //[/Constructor_pre]

    component.reset (new OscillatorComponent (p));
    addAndMakeVisible (component.get());
    component->setBounds (7, 7, 466, 144);

    component2.reset (new Oscillator2Component (p));
    addAndMakeVisible (component2.get());
    component2->setBounds (7, 158, 466, 144);

    component3.reset (new FilterComponent (p));
    addAndMakeVisible (component3.get());
    component3->setBounds (480, 7, 466, 295);

    component4.reset (new ADSRComponent (p));
    addAndMakeVisible (component4.get());
    component4->setBounds (7, 309, 466, 295);

    component5.reset (new LFOComponent());
    addAndMakeVisible (component5.get());
    component5->setBounds (480, 309, 466, 295);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (953, 710);


    //[Constructor] You can add your own custom stuff here..

    midiKeyboardState.addListener(&processor.getMidiMessageCollector());
    midiKeyboardComponent.setBounds(0, 610, 480, 100);

    scopeComponent.setBounds(480, 610, 480, 100);
    //[/Constructor]
}

MooderAudioProcessorEditor::~MooderAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component = nullptr;
    component2 = nullptr;
    component3 = nullptr;
    component4 = nullptr;
    component5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    midiKeyboardState.removeListener(&processor.getMidiMessageCollector());
    setLookAndFeel(nullptr);
    //[/Destructor]
}

//==============================================================================
void MooderAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff191c23));

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
                 fixedSize="1" initialWidth="953" initialHeight="710">
  <BACKGROUND backgroundColour="ff191c23"/>
  <JUCERCOMP name="" id="74dc897685dd5775" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="7 7 466 144" sourceFile="OscillatorComponent.cpp"
             constructorParams="p"/>
  <JUCERCOMP name="" id="90a5c6d12f7447c2" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="7 158 466 144" sourceFile="Oscillator2Component.cpp"
             constructorParams="p"/>
  <JUCERCOMP name="" id="2f6bdedfd7ffb8a4" memberName="component3" virtualName=""
             explicitFocusOrder="0" pos="480 7 466 295" sourceFile="FilterComponent.cpp"
             constructorParams="p"/>
  <JUCERCOMP name="" id="4b9d246e4d617cb8" memberName="component4" virtualName=""
             explicitFocusOrder="0" pos="7 309 466 295" sourceFile="ADSRComponent.cpp"
             constructorParams="p"/>
  <JUCERCOMP name="" id="ce37b3820bdb183d" memberName="component5" virtualName=""
             explicitFocusOrder="0" pos="480 309 466 295" sourceFile="LFOComponent.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

