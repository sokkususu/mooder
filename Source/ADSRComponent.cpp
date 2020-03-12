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

#include "ADSRComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ADSRComponent::ADSRComponent (MooderAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    rezLPSlider.reset (new Slider ("rezLPSlider"));
    addAndMakeVisible (rezLPSlider.get());
    rezLPSlider->setRange (0, 1, 0.01);
    rezLPSlider->setSliderStyle (Slider::Rotary);
    rezLPSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    rezLPSlider->addListener (this);

    rezLPSlider->setBounds (80, 50, 65, 85);

    label2.reset (new Label ("label",
                             TRANS("Attack")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (80, 35, 65, 18);

    label1.reset (new Label ("label",
                             TRANS("ADSR")));
    addAndMakeVisible (label1.get());
    label1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label1->setJustificationType (Justification::centred);
    label1->setEditable (false, false, false);
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label1->setBounds (215, 3, 50, 18);

    freqLPSlider.reset (new Slider ("freqLPSlider"));
    addAndMakeVisible (freqLPSlider.get());
    freqLPSlider->setRange (0, 1, 0.01);
    freqLPSlider->setSliderStyle (Slider::Rotary);
    freqLPSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    freqLPSlider->addListener (this);

    freqLPSlider->setBounds (165, 50, 65, 85);

    label3.reset (new Label ("label",
                             TRANS("Decay")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (165, 35, 65, 18);

    tuneSlider.reset (new Slider ("tuneSlider"));
    addAndMakeVisible (tuneSlider.get());
    tuneSlider->setRange (0, 1, 0.01);
    tuneSlider->setSliderStyle (Slider::Rotary);
    tuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    tuneSlider->addListener (this);

    tuneSlider->setBounds (249, 50, 65, 85);

    label4.reset (new Label ("label",
                             TRANS("Sustain")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (249, 35, 65, 18);

    levelSlider.reset (new Slider ("levelSlider"));
    addAndMakeVisible (levelSlider.get());
    levelSlider->setRange (0, 1, 0.01);
    levelSlider->setSliderStyle (Slider::Rotary);
    levelSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    levelSlider->addListener (this);

    levelSlider->setBounds (335, 50, 65, 85);

    label5.reset (new Label ("label",
                             TRANS("Release")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (335, 35, 65, 18);

    activateButton.reset (new ToggleButton ("activateButton"));
    addAndMakeVisible (activateButton.get());
    activateButton->setButtonText (String());
    activateButton->addListener (this);
    activateButton->setToggleState (true, dontSendNotification);

    activateButton->setBounds (456, 0, 24, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (480, 160);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ADSRComponent::~ADSRComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rezLPSlider = nullptr;
    label2 = nullptr;
    label1 = nullptr;
    freqLPSlider = nullptr;
    label3 = nullptr;
    tuneSlider = nullptr;
    label4 = nullptr;
    levelSlider = nullptr;
    label5 = nullptr;
    activateButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ADSRComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff233d6a));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ADSRComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ADSRComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == rezLPSlider.get())
    {
        //[UserSliderCode_rezLPSlider] -- add your slider handling code here..
        //[/UserSliderCode_rezLPSlider]
    }
    else if (sliderThatWasMoved == freqLPSlider.get())
    {
        //[UserSliderCode_freqLPSlider] -- add your slider handling code here..
        //[/UserSliderCode_freqLPSlider]
    }
    else if (sliderThatWasMoved == tuneSlider.get())
    {
        //[UserSliderCode_tuneSlider] -- add your slider handling code here..
        //[/UserSliderCode_tuneSlider]
    }
    else if (sliderThatWasMoved == levelSlider.get())
    {
        //[UserSliderCode_levelSlider] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ADSRComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == activateButton.get())
    {
        //[UserButtonCode_activateButton] -- add your button handler code here..
        //[/UserButtonCode_activateButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ADSRComponent" componentName=""
                 parentClasses="public Component" constructorParams="MooderAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="480"
                 initialHeight="160">
  <BACKGROUND backgroundColour="ff233d6a"/>
  <SLIDER name="rezLPSlider" id="56f2a6e81fe5f959" memberName="rezLPSlider"
          virtualName="" explicitFocusOrder="0" pos="80 50 65 85" min="0.0"
          max="1.0" int="0.01" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="fc4b9114d12d20a0" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="80 35 65 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="label" id="a12fe4645558f25c" memberName="label1" virtualName=""
         explicitFocusOrder="0" pos="215 3 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="ADSR" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="freqLPSlider" id="bef96203430a69c3" memberName="freqLPSlider"
          virtualName="" explicitFocusOrder="0" pos="165 50 65 85" min="0.0"
          max="1.0" int="0.01" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="5af8dfe48cce0964" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="165 35 65 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="tuneSlider" id="4f1fb4ab86f17cd7" memberName="tuneSlider"
          virtualName="" explicitFocusOrder="0" pos="249 50 65 85" min="0.0"
          max="1.0" int="0.01" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="ebeda905bdad0cb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="249 35 65 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="levelSlider" id="b78d17951dec2b84" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="335 50 65 85" min="0.0"
          max="1.0" int="0.01" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="a0556e081db737b8" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="335 35 65 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="activateButton" id="cf4fb079af3e6ec6" memberName="activateButton"
                virtualName="" explicitFocusOrder="0" pos="456 0 24 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
