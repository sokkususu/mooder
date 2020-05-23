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

#include "FilterGraph.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FilterGraph::FilterGraph (MooderAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (415, 144);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FilterGraph::~FilterGraph()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FilterGraph::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = 415.0f, height = 144.0f;
        Colour fillColour = Colour (0xff191c23);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    {
        float x = 0.0f, y = 0.0f, width = 415.0f, height = 144.0f;

        Colour lineColour = Colour(0xff9471E8);
        Colour dotColour = Colours::white;

        float freq = (float)*processor.parametrs.getRawParameterValue("freqFilterLP");
        float rez = (float)*processor.parametrs.getRawParameterValue("rezFilterLP");

        float jfreq = jmap(freq, 20.f, 20000.f, 0.f, 1.f);
        jfreq = jfreq != 0 ? (log(jfreq) + 10) / 10 : 0;

        Point<float> startPoint1{ width * jfreq - height / 2, height };
        Point<float> endPoint1{ width * jfreq, height / 2 };
        Point<float> controlPoint1{ width * jfreq - height / 4, height / 2 - 150 * rez };
        Point<float> controlPoint2{ width * jfreq - height / 4, height / 2 };

        Point<float> startPoint2{ width * jfreq, height / 2 };
        Point<float> endPoint2{ width * jfreq + height / 2, height };
        Point<float> controlPoint3{ width * jfreq + height / 4, height / 2 };
        Point<float> controlPoint4{ width * jfreq + height / 4, height / 2 - 150 * rez };

        Point<float> startPoint{ 0, height / 2 };
        Point<float> endPoint{ width, height / 2 };

        Path path;

        if (processor.getFilterMode() != juce::dsp::LadderFilter<float>::Mode::LPF24)
        {
            path.startNewSubPath(startPoint1);
            path.cubicTo(controlPoint1, controlPoint2, endPoint1);
            path.lineTo(endPoint);
        }
        else
        {
            path.startNewSubPath(startPoint);
            path.lineTo(startPoint2);
            path.cubicTo(controlPoint3, controlPoint4, endPoint2);
        }

        g.setColour(lineColour);
        g.strokePath(path, PathStrokeType(3.0f));

        repaint();
    }
    //[/UserPaint]
}

void FilterGraph::resized()
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

<JUCER_COMPONENT documentType="Component" className="FilterGraph" componentName=""
                 parentClasses="public Component" constructorParams="MooderAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="415"
                 initialHeight="144">
  <BACKGROUND backgroundColour="323e44">
    <ROUNDRECT pos="0 0 415 144" cornerSize="10.0" fill="solid: ff191c23" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

