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

    attackSlider.reset (new Slider ("attackSlider"));
    addAndMakeVisible (attackSlider.get());
    attackSlider->setRange (0, 5, 0.1);
    attackSlider->setSliderStyle (Slider::Rotary);
    attackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    attackSlider->addListener (this);

    attackSlider->setBounds (78, 200, 55, 85);

    label2.reset (new Label ("label",
                             TRANS("Attack")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (78, 178, 55, 18);

    label1.reset (new Label ("label",
                             TRANS("ADSR")));
    addAndMakeVisible (label1.get());
    label1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label1->setJustificationType (Justification::centred);
    label1->setEditable (false, false, false);
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label1->setBounds (212, 3, 50, 18);

    decaySlider.reset (new Slider ("decaySlider"));
    addAndMakeVisible (decaySlider.get());
    decaySlider->setRange (0, 2, 0.1);
    decaySlider->setSliderStyle (Slider::Rotary);
    decaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    decaySlider->addListener (this);

    decaySlider->setBounds (163, 200, 55, 85);

    label3.reset (new Label ("label",
                             TRANS("Decay")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (163, 178, 55, 18);

    sustainSlider.reset (new Slider ("sustainSlider"));
    addAndMakeVisible (sustainSlider.get());
    sustainSlider->setRange (0, 1, 0.1);
    sustainSlider->setSliderStyle (Slider::Rotary);
    sustainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    sustainSlider->addListener (this);

    sustainSlider->setBounds (247, 200, 55, 85);

    label4.reset (new Label ("label",
                             TRANS("Sustain")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (247, 178, 55, 18);

    releaseSlider.reset (new Slider ("releaseSlider"));
    addAndMakeVisible (releaseSlider.get());
    releaseSlider->setRange (0, 5, 0.1);
    releaseSlider->setSliderStyle (Slider::Rotary);
    releaseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    releaseSlider->addListener (this);

    releaseSlider->setBounds (333, 200, 55, 85);

    label5.reset (new Label ("label",
                             TRANS("Release")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (333, 178, 55, 18);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (466, 295);


    //[Constructor] You can add your own custom stuff here..
    attackSlider->setValue(0.1);
    decaySlider->setValue(0.0);
    sustainSlider->setValue(1.0);
    releaseSlider->setValue(0.1);
    //[/Constructor]
}

ADSRComponent::~ADSRComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    attackSlider = nullptr;
    label2 = nullptr;
    label1 = nullptr;
    decaySlider = nullptr;
    label3 = nullptr;
    sustainSlider = nullptr;
    label4 = nullptr;
    releaseSlider = nullptr;
    label5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ADSRComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = 466.0f, height = 295.0f;
        Colour fillColour = Colour (0xff373e46);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 25.0f, y = 24.0f, width = 415.0f, height = 144.0f;
        Colour fillColour = Colour (0xff191c23);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    {
        float x = 25.0f, y = 24.0f, width = 415.0f, height = 144.0f;
        float attack = attackSlider->getValue() / 5;
        Colour lineColour = Colours::green;
        
        g.setColour(lineColour);
        g.drawLine(x, y + height * attack,
                x+width, y + height * attack);
        
        
    }
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

    if (sliderThatWasMoved == attackSlider.get())
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(12, sliderThatWasMoved->getValue() / 5);
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == decaySlider.get())
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(13, sliderThatWasMoved->getValue() / 2);
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == sustainSlider.get())
    {
        //[UserSliderCode_sustainSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(14, sliderThatWasMoved->getValue());
        //[/UserSliderCode_sustainSlider]
    }
    else if (sliderThatWasMoved == releaseSlider.get())
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(15, sliderThatWasMoved->getValue() / 5);
        //[/UserSliderCode_releaseSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
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
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="466"
                 initialHeight="295">
  <BACKGROUND backgroundColour="233d6a">
    <ROUNDRECT pos="0 0 466 295" cornerSize="10.0" fill="solid: ff373e46" hasStroke="0"/>
    <ROUNDRECT pos="25 24 415 144" cornerSize="10.0" fill="solid: ff191c23"
               hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="attackSlider" id="56f2a6e81fe5f959" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="78 200 55 85" textboxoutline="8e989b"
          min="0.0" max="5.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="fc4b9114d12d20a0" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="78 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="label" id="a12fe4645558f25c" memberName="label1" virtualName=""
         explicitFocusOrder="0" pos="212 3 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="ADSR" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="decaySlider" id="bef96203430a69c3" memberName="decaySlider"
          virtualName="" explicitFocusOrder="0" pos="163 200 55 85" textboxoutline="8e989b"
          min="0.0" max="2.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="5af8dfe48cce0964" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="163 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="sustainSlider" id="4f1fb4ab86f17cd7" memberName="sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="247 200 55 85" textboxoutline="8e989b"
          min="0.0" max="1.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="ebeda905bdad0cb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="247 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="releaseSlider" id="b78d17951dec2b84" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="333 200 55 85" textboxoutline="8e989b"
          min="0.0" max="5.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="a0556e081db737b8" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="333 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

