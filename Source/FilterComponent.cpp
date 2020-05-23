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

#include "FilterComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FilterComponent::FilterComponent (MooderAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    rezLPSlider.reset (new Slider ("rezLPSlider"));
    addAndMakeVisible (rezLPSlider.get());
    rezLPSlider->setRange (0, 100, 1);
    rezLPSlider->setSliderStyle (Slider::Rotary);
    rezLPSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    rezLPSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    rezLPSlider->addListener (this);

    rezLPSlider->setBounds (166, 200, 55, 85);

    label2.reset (new Label ("label",
                             TRANS("Res")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (166, 178, 55, 18);

    label1.reset (new Label ("label",
                             TRANS("Filter")));
    addAndMakeVisible (label1.get());
    label1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label1->setJustificationType (Justification::centred);
    label1->setEditable (false, false, false);
    label1->setColour (TextEditor::textColourId, Colours::black);
    label1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label1->setBounds (212, 3, 50, 18);

    freqLPSlider.reset (new Slider ("freqLPSlider"));
    addAndMakeVisible (freqLPSlider.get());
    freqLPSlider->setRange (20, 20000, 1);
    freqLPSlider->setSliderStyle (Slider::Rotary);
    freqLPSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    freqLPSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    freqLPSlider->addListener (this);

    freqLPSlider->setBounds (251, 200, 55, 85);

    label3.reset (new Label ("label",
                             TRANS("Freq")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (251, 178, 55, 18);

    component.reset (new FilterGraph (p));
    addAndMakeVisible (component.get());
    component->setBounds (25, 24, 415, 144);

    lowpassButton.reset (new TextButton ("lowpassButton"));
    addAndMakeVisible (lowpassButton.get());
    lowpassButton->setButtonText (TRANS("low"));
    lowpassButton->setRadioGroupId (1);
    lowpassButton->addListener (this);
    lowpassButton->setColour (TextButton::buttonColourId, Colour (0xffa45c94));
    lowpassButton->setColour (TextButton::buttonOnColourId, Colour (0xff68707b));

    lowpassButton->setBounds (27, 209, 55, 22);

    highpassButton.reset (new TextButton ("highpassButton"));
    addAndMakeVisible (highpassButton.get());
    highpassButton->setButtonText (TRANS("high"));
    highpassButton->setRadioGroupId (1);
    highpassButton->addListener (this);

    highpassButton->setBounds (27, 234, 55, 22);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (466, 295);


    //[Constructor] You can add your own custom stuff here..
    freqLPSlider->setValue(20000.0f);
    freqLPSlider->setSkewFactorFromMidPoint(500);
    //[/Constructor]
}

FilterComponent::~FilterComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rezLPSlider = nullptr;
    label2 = nullptr;
    label1 = nullptr;
    freqLPSlider = nullptr;
    label3 = nullptr;
    component = nullptr;
    lowpassButton = nullptr;
    highpassButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FilterComponent::paint (Graphics& g)
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

void FilterComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FilterComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == rezLPSlider.get())
    {
        //[UserSliderCode_rezLPSlider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(9, sliderThatWasMoved->getValue() / 100);
        //[/UserSliderCode_rezLPSlider]
    }
    else if (sliderThatWasMoved == freqLPSlider.get())
    {
        //[UserSliderCode_freqLPSlider] -- add your slider handling code here..
        float value = sliderThatWasMoved->getValue();
        float jvalue = jmap(value, (float)sliderThatWasMoved->getMinimum(), (float)sliderThatWasMoved->getMaximum(), 0.f, 1.f);
        processor.setParameterNotifyingHost(8, jvalue);
        //[/UserSliderCode_freqLPSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void FilterComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == lowpassButton.get())
    {
        //[UserButtonCode_lowpassButton] -- add your button handler code here..
        processor.setFilterMode(juce::dsp::LadderFilter<float>::Mode::LPF24);
        //[/UserButtonCode_lowpassButton]
    }
    else if (buttonThatWasClicked == highpassButton.get())
    {
        //[UserButtonCode_highpassButton] -- add your button handler code here..
        processor.setFilterMode(juce::dsp::LadderFilter<float>::Mode::HPF24);
        //[/UserButtonCode_highpassButton]
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

<JUCER_COMPONENT documentType="Component" className="FilterComponent" componentName=""
                 parentClasses="public Component" constructorParams="MooderAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="466"
                 initialHeight="295">
  <BACKGROUND backgroundColour="43786c">
    <ROUNDRECT pos="0 0 466 295" cornerSize="10.0" fill="solid: ff373e46" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="rezLPSlider" id="56f2a6e81fe5f959" memberName="rezLPSlider"
          virtualName="" explicitFocusOrder="0" pos="166 200 55 85" textboxoutline="8e989b"
          min="0.0" max="100.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="fc4b9114d12d20a0" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="166 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Res" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="label" id="a12fe4645558f25c" memberName="label1" virtualName=""
         explicitFocusOrder="0" pos="212 3 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Filter" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="freqLPSlider" id="bef96203430a69c3" memberName="freqLPSlider"
          virtualName="" explicitFocusOrder="0" pos="251 200 55 85" textboxoutline="8e989b"
          min="20.0" max="20000.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="5af8dfe48cce0964" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="251 178 55 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="ff4a36b937af9f1a" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="25 24 415 144" sourceFile="FilterGraph.cpp"
             constructorParams="p"/>
  <TEXTBUTTON name="lowpassButton" id="3fc0debbaf133902" memberName="lowpassButton"
              virtualName="" explicitFocusOrder="0" pos="27 209 55 22" bgColOff="ffa45c94"
              bgColOn="ff68707b" buttonText="low" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <TEXTBUTTON name="highpassButton" id="a6a275cc2c04a8e3" memberName="highpassButton"
              virtualName="" explicitFocusOrder="0" pos="27 234 55 22" buttonText="high"
              connectedEdges="0" needsCallback="1" radioGroupId="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

