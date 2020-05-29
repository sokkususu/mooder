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

#include "Oscillator2Component.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Oscillator2Component::Oscillator2Component (MooderAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    octaveSlider.reset (new Slider ("octaveSlider"));
    addAndMakeVisible (octaveSlider.get());
    octaveSlider->setRange (-3, 3, 1);
    octaveSlider->setSliderStyle (Slider::Rotary);
    octaveSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    octaveSlider->setColour (Slider::textBoxTextColourId, Colour (0xffdedede));
    octaveSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    octaveSlider->addListener (this);

    octaveSlider->setBounds (113, 48, 55, 85);

    label2.reset (new Label ("label",
                             TRANS("Octave")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colour (0xffdedede));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (113, 28, 55, 18);

    sinButton.reset (new TextButton ("sinButton"));
    addAndMakeVisible (sinButton.get());
    sinButton->setButtonText (TRANS("sin"));
    sinButton->setRadioGroupId (1);
    sinButton->addListener (this);
    sinButton->setColour (TextButton::buttonColourId, Colour (0xff68707b));
    sinButton->setColour (TextButton::buttonOnColourId, Colour (0xff9471e8));

    sinButton->setBounds (18, 33, 55, 22);

    sawButton.reset (new TextButton ("sawButton"));
    addAndMakeVisible (sawButton.get());
    sawButton->setButtonText (TRANS("saw"));
    sawButton->setRadioGroupId (1);
    sawButton->addListener (this);
    sawButton->setColour (TextButton::buttonColourId, Colour (0xff68707b));
    sawButton->setColour (TextButton::buttonOnColourId, Colour (0xff9471e8));

    sawButton->setBounds (18, 58, 55, 22);

    triButton.reset (new TextButton ("triButton"));
    addAndMakeVisible (triButton.get());
    triButton->setButtonText (TRANS("tri"));
    triButton->setRadioGroupId (1);
    triButton->addListener (this);
    triButton->setColour (TextButton::buttonColourId, Colour (0xff68707b));
    triButton->setColour (TextButton::buttonOnColourId, Colour (0xff9471e8));

    triButton->setBounds (18, 83, 55, 22);

    sqrButton.reset (new TextButton ("sqrButton"));
    addAndMakeVisible (sqrButton.get());
    sqrButton->setButtonText (TRANS("sqr"));
    sqrButton->setRadioGroupId (1);
    sqrButton->addListener (this);
    sqrButton->setColour (TextButton::buttonColourId, Colour (0xff68707b));
    sqrButton->setColour (TextButton::buttonOnColourId, Colour (0xff9471e8));

    sqrButton->setBounds (18, 108, 55, 22);

    label1.reset (new Label ("label",
                             TRANS("OSC2")));
    addAndMakeVisible (label1.get());
    label1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label1->setJustificationType (Justification::centred);
    label1->setEditable (false, false, false);
    label1->setColour (Label::textColourId, Colour (0xffdedede));
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label1->setBounds (208, 3, 50, 18);

    transSlider.reset (new Slider ("transSlider"));
    addAndMakeVisible (transSlider.get());
    transSlider->setRange (-12, 12, 1);
    transSlider->setSliderStyle (Slider::Rotary);
    transSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    transSlider->setColour (Slider::textBoxTextColourId, Colour (0xffdedede));
    transSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    transSlider->addListener (this);

    transSlider->setBounds (198, 48, 55, 85);

    label3.reset (new Label ("label",
                             TRANS("Trans")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colour (0xffdedede));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (198, 28, 55, 18);

    tuneSlider.reset (new Slider ("tuneSlider"));
    addAndMakeVisible (tuneSlider.get());
    tuneSlider->setRange (-1, 1, 0.01);
    tuneSlider->setSliderStyle (Slider::Rotary);
    tuneSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    tuneSlider->setColour (Slider::textBoxTextColourId, Colour (0xffdedede));
    tuneSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    tuneSlider->addListener (this);

    tuneSlider->setBounds (282, 48, 55, 85);

    label4.reset (new Label ("label",
                             TRANS("Tune")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colour (0xffdedede));
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (282, 28, 55, 18);

    levelSlider.reset (new Slider ("levelSlider"));
    addAndMakeVisible (levelSlider.get());
    levelSlider->setRange (0, 1, 0.01);
    levelSlider->setSliderStyle (Slider::Rotary);
    levelSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    levelSlider->setColour (Slider::textBoxTextColourId, Colour (0xffdedede));
    levelSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    levelSlider->addListener (this);

    levelSlider->setBounds (368, 48, 55, 85);

    label5.reset (new Label ("label",
                             TRANS("Level")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colour (0xffdedede));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (368, 28, 55, 18);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (466, 144);


    //[Constructor] You can add your own custom stuff here..
    levelSlider->setValue(0.7);

    sinButton->setClickingTogglesState(true);
    triButton->setClickingTogglesState(true);
    sawButton->setClickingTogglesState(true);
    sqrButton->setClickingTogglesState(true);

    sinButton->setToggleState(true, false);
    //[/Constructor]
}

Oscillator2Component::~Oscillator2Component()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    octaveSlider = nullptr;
    label2 = nullptr;
    sinButton = nullptr;
    sawButton = nullptr;
    triButton = nullptr;
    sqrButton = nullptr;
    label1 = nullptr;
    transSlider = nullptr;
    label3 = nullptr;
    tuneSlider = nullptr;
    label4 = nullptr;
    levelSlider = nullptr;
    label5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Oscillator2Component::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = 466.0f, height = 144.0f;
        Colour fillColour = Colour (0xff373e46);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Oscillator2Component::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Oscillator2Component::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == octaveSlider.get())
    {
        //[UserSliderCode_octaveSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(4, (sliderThatWasMoved->getValue() + 3) / 6);
        //[/UserSliderCode_octaveSlider]
    }
    else if (sliderThatWasMoved == transSlider.get())
    {
        //[UserSliderCode_transSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(5, (sliderThatWasMoved->getValue() + 12) / 24);
        //[/UserSliderCode_transSlider]
    }
    else if (sliderThatWasMoved == tuneSlider.get())
    {
        //[UserSliderCode_tuneSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(6, (sliderThatWasMoved->getValue() + 1) / 2);
        //[/UserSliderCode_tuneSlider]
    }
    else if (sliderThatWasMoved == levelSlider.get())
    {
        //[UserSliderCode_levelSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(7, sliderThatWasMoved->getValue());
        //[/UserSliderCode_levelSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Oscillator2Component::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == sinButton.get())
    {
        //[UserButtonCode_sinButton] -- add your button handler code here..
        processor.setWaveForm2(1);
        //[/UserButtonCode_sinButton]
    }
    else if (buttonThatWasClicked == sawButton.get())
    {
        //[UserButtonCode_sawButton] -- add your button handler code here..
        processor.setWaveForm2(2);
        //[/UserButtonCode_sawButton]
    }
    else if (buttonThatWasClicked == triButton.get())
    {
        //[UserButtonCode_triButton] -- add your button handler code here..
        processor.setWaveForm2(3);
        //[/UserButtonCode_triButton]
    }
    else if (buttonThatWasClicked == sqrButton.get())
    {
        //[UserButtonCode_sqrButton] -- add your button handler code here..
        processor.setWaveForm2(4);
        //[/UserButtonCode_sqrButton]
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

<JUCER_COMPONENT documentType="Component" className="Oscillator2Component" componentName=""
                 parentClasses="public Component" constructorParams="MooderAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="466"
                 initialHeight="144">
  <BACKGROUND backgroundColour="465f59">
    <ROUNDRECT pos="0 0 466 144" cornerSize="10.0" fill="solid: ff373e46" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="octaveSlider" id="56f2a6e81fe5f959" memberName="octaveSlider"
          virtualName="" explicitFocusOrder="0" pos="113 48 55 85" textboxtext="ffdedede"
          textboxoutline="8e989b" min="-3.0" max="3.0" int="1.0" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="label" id="fc4b9114d12d20a0" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="113 28 55 18" textCol="ffdedede"
         edTextCol="ff000000" edBkgCol="0" labelText="Octave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="sinButton" id="3fc0debbaf133902" memberName="sinButton"
              virtualName="" explicitFocusOrder="0" pos="18 33 55 22" bgColOff="ff68707b"
              bgColOn="ff9471e8" buttonText="sin" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <TEXTBUTTON name="sawButton" id="a6a275cc2c04a8e3" memberName="sawButton"
              virtualName="" explicitFocusOrder="0" pos="18 58 55 22" bgColOff="ff68707b"
              bgColOn="ff9471e8" buttonText="saw" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <TEXTBUTTON name="triButton" id="468fb96311d92778" memberName="triButton"
              virtualName="" explicitFocusOrder="0" pos="18 83 55 22" bgColOff="ff68707b"
              bgColOn="ff9471e8" buttonText="tri" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <TEXTBUTTON name="sqrButton" id="9198417e1a65f8c" memberName="sqrButton"
              virtualName="" explicitFocusOrder="0" pos="18 108 55 22" bgColOff="ff68707b"
              bgColOn="ff9471e8" buttonText="sqr" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <LABEL name="label" id="a12fe4645558f25c" memberName="label1" virtualName=""
         explicitFocusOrder="0" pos="208 3 50 18" textCol="ffdedede" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="transSlider" id="bef96203430a69c3" memberName="transSlider"
          virtualName="" explicitFocusOrder="0" pos="198 48 55 85" textboxtext="ffdedede"
          textboxoutline="8e989b" min="-12.0" max="12.0" int="1.0" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="label" id="5af8dfe48cce0964" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="198 28 55 18" textCol="ffdedede"
         edTextCol="ff000000" edBkgCol="0" labelText="Trans" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="tuneSlider" id="4f1fb4ab86f17cd7" memberName="tuneSlider"
          virtualName="" explicitFocusOrder="0" pos="282 48 55 85" textboxtext="ffdedede"
          textboxoutline="8e989b" min="-1.0" max="1.0" int="0.01" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="label" id="ebeda905bdad0cb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="282 28 55 18" textCol="ffdedede"
         edTextCol="ff000000" edBkgCol="0" labelText="Tune" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="levelSlider" id="b78d17951dec2b84" memberName="levelSlider"
          virtualName="" explicitFocusOrder="0" pos="368 48 55 85" textboxtext="ffdedede"
          textboxoutline="8e989b" min="0.0" max="1.0" int="0.01" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="label" id="a0556e081db737b8" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="368 28 55 18" textCol="ffdedede"
         edTextCol="ff000000" edBkgCol="0" labelText="Level" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

