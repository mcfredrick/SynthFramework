/*
  ==============================================================================

    ParameterSlider.h
    Created: 29 Aug 2019 8:19:44pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "JUCEHeader.h"

class ParameterSlider
	: public Slider
{
public:

	ParameterSlider(AudioProcessorValueTreeState& stateToControl,
		const String& parameterID,
		const String& parameterLabel);

	~ParameterSlider();

private:

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mAttachment;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterSlider);
};