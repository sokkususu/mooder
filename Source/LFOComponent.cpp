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

#include "LFOComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LFOComponent::LFOComponent (MooderAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label1.reset (new Label ("label",
                             TRANS("LFO")));
    addAndMakeVisible (label1.get());
    label1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label1->setJustificationType (Justification::centred);
    label1->setEditable (false, false, false);
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label1->setBounds (212, 3, 50, 18);

    rateSlider.reset (new Slider ("rateSlider"));
    addAndMakeVisible (rateSlider.get());
    rateSlider->setRange (0, 10, 0.1);
    rateSlider->setSliderStyle (Slider::Rotary);
    rateSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    rateSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    rateSlider->addListener (this);

    rateSlider->setBounds (163, 200, 55, 85);

    label3.reset (new Label ("label",
                             TRANS("Rate")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (163, 178, 55, 18);

    amountSlider.reset (new Slider ("amountSlider"));
    addAndMakeVisible (amountSlider.get());
    amountSlider->setRange (0, 1, 0.1);
    amountSlider->setSliderStyle (Slider::Rotary);
    amountSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    amountSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    amountSlider->addListener (this);

    amountSlider->setBounds (247, 200, 55, 85);

    label4.reset (new Label ("label",
                             TRANS("Amount")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (247, 178, 55, 18);

    component.reset (new LFOGraph());
    addAndMakeVisible (component.get());
    component->setBounds (25, 24, 415, 144);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (466, 295);


    //[Constructor] You can add your own custom stuff here..
    rateSlider->setValue(3);
    //[/Constructor]
}

LFOComponent::~LFOComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label1 = nullptr;
    rateSlider = nullptr;
    label3 = nullptr;
    amountSlider = nullptr;
    label4 = nullptr;
    component = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LFOComponent::paint (Graphics& g)
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

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LFOComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LFOComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == rateSlider.get())
    {
        //[UserSliderCode_rateSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(16, sliderThatWasMoved->getValue() / 10);
        //[/UserSliderCode_rateSlider]
    }
    else if (sliderThatWasMoved == amountSlider.get())
    {
        //[UserSliderCode_amountSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(17, sliderThatWasMoved->getValue());
        //[/UserSliderCode_amountSlider]
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

<JUCER_COMPONENT documentType="Component" className="LFOComponent" componentName=""
                 parentClasses="public Component" constructorParams="MooderAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="466"
                 initialHeight="295">
  <BACKGROUND backgroundColour="323e44">
    <ROUNDRECT pos="0 0 466 295" cornerSize="10.0" fill="solid: ff373e46" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="label" id="a12fe4645558f25c" memberName="label1" virtualName=""
         explicitFocusOrder="0" pos="212 3 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="rateSlider" id="bef96203430a69c3" memberName="rateSlider"
          virtualName="" explicitFocusOrder="0" pos="163 200 55 85" textboxoutline="8e989b"
          min="0.0" max="10.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="5af8dfe48cce0964" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="163 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="amountSlider" id="4f1fb4ab86f17cd7" memberName="amountSlider"
          virtualName="" explicitFocusOrder="0" pos="247 200 55 85" textboxoutline="8e989b"
          min="0.0" max="1.0" int="0.1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="ebeda905bdad0cb" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="247 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Amount" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="c3c270a7fb86389" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="25 24 415 144" sourceFile="LFOGraph.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

