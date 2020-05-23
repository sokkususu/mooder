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

#include "LFOGraph.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LFOGraph::LFOGraph (MooderAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    setFramesPerSecond(60);
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (415, 144);


    //[Constructor] You can add your own custom stuff here..

    lastFreq = 0.0f;
    lastAmount = 0.0f;
    //[/Constructor]
}

LFOGraph::~LFOGraph()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LFOGraph::paint (Graphics& g)
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

        float freq = (float)*processor.parametrs.getRawParameterValue("freqLFO");
        float amount = (float)*processor.parametrs.getRawParameterValue("amountLFO");

        float centrY = height / 2;
        float widthSin = 0;
        if (freq != 0)
            widthSin = width / freq;
        else
            widthSin = width / 0.001f;

        float startX = x;
        float endX = widthSin;
        float c = widthSin / 2;

        for (int i = 0; i < 10; i++)
        {

            Point<float> startPoint{ startX, centrY };
            Point<float> endPoint{ endX, centrY };
            Point<float> controlPoint1{ c, centrY - (height + 50) * amount };
            Point<float> controlPoint2{ c, centrY + (height + 50) * amount };


            Path path;
            path.startNewSubPath(startPoint);
            path.cubicTo(controlPoint1, controlPoint2, endPoint);

            g.setColour(lineColour);
            g.strokePath(path, PathStrokeType(3.0f));

            startX += widthSin;
            endX += widthSin;
            c += widthSin;
        }
    }
    //[/UserPaint]
}

void LFOGraph::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void LFOGraph::timerCallback()
{
    repaint();
}

void LFOGraph::setFramesPerSecond(int framesPerSecond)
{
    jassert(framesPerSecond > 0 && framesPerSecond < 1000);
    startTimerHz(framesPerSecond);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LFOGraph" componentName=""
                 parentClasses="public Component, public Timer" constructorParams="MooderAudioProcessor&amp; p"
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

