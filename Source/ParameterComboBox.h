/*
  ==============================================================================

    ParameterComboBox.h
    Created: 30 Aug 2019 3:17:41pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "JUCEHeader.h"

class ParameterComboBox
	: public ComboBox
{
public:

	ParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID);

	~ParameterComboBox();

private:

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterComboBox);
};
