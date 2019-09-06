/*
  ==============================================================================

    ParameterSlider.cpp
    Created: 29 Aug 2019 8:19:44pm
    Author:  mattc

  ==============================================================================
*/

#include "ParameterSlider.h"

ParameterSlider::ParameterSlider(AudioProcessorValueTreeState& stateToControl,
	const String& parameterID,
	const String& parameterLabel)
	: juce::Slider(parameterLabel)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);

	setRange(0.0f, 1.0f, 0.001f);

	mAttachment =
		new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterID, *this);
}

ParameterSlider::~ParameterSlider()
{

}
