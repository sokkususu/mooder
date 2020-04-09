/*
  ==============================================================================

    OtherLookAndFeel.h
    Created: 7 Apr 2020 7:45:52pm
    Author:  sokku

  ==============================================================================
*/

#pragma once

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    OtherLookAndFeel()
    {
        setColour(Slider::thumbColourId, Colour(0xff9471E8));
        setColour(Slider::rotarySliderOutlineColourId, Colour(0xFF68707B));
        setColour(Slider::rotarySliderFillColourId, Colour(0xff9471E8));
    }

    void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override
    {
        auto radius = jmin(width / 2, height / 2) - 2.0f;
        auto centreX = x + width * 0.5f;
        auto centreY = y + height * 0.5f;
        auto rx = centreX - radius;
        auto ry = centreY - radius;
        auto rw = radius * 2.0f;
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

        Path filledOutline;
        filledOutline.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, 8.8, 0.8);
        g.setColour(Colour(0xFF68707B));
        g.fillPath(filledOutline);

        Path filledArc;
        filledArc.addPieSegment(rx, ry, rw, rw, rotaryStartAngle, angle, 0.8);
        g.setColour(Colour(0xff9471E8));
        g.fillPath(filledArc);

        Path p;
        auto pointerLength = radius * 0.8f;
        auto pointerThickness = 4.0f;
        p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

        g.setColour(Colours::white);
        g.fillPath(p);
    }

    void drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour,
        bool isMouseOverButton, bool isButtonDown) override
    {
        auto width = button.getWidth();
        auto height = button.getHeight();

        g.setColour(Colour(0xff68707B));
        g.fillRoundedRectangle(0, 0, width, height, 11);

        if (isMouseOverButton)
        {
            g.setColour(Colour(0xff8D949E));
            g.fillRoundedRectangle(0, 0, width, height, 11);
        }

        if (isButtonDown) 
        {
            g.setColour(Colour(0xff9471E8));
            g.fillRoundedRectangle(0, 0, width, height, 11);
        }
    }
};
