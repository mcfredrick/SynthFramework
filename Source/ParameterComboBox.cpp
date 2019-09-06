/*
  ==============================================================================

    ParameterComboBox.cpp
    Created: 30 Aug 2019 3:17:41pm
    Author:  mattc

  ==============================================================================
*/

#include "ParameterComboBox.h"

ParameterComboBox::ParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID)
	: juce::ComboBox(parameterID)
{
	mAttachment =
		new AudioProcessorValueTreeState::ComboBoxAttachment(stateToControl, parameterID, *this);
}

ParameterComboBox::~ParameterComboBox()
{

}