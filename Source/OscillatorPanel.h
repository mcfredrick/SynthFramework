/*
  ==============================================================================

    OscillatorPanel.h
    Created: 30 Aug 2019 1:38:30pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "ParameterComboBox.h"

//==============================================================================
/*
*/
class OscillatorPanel    : public PanelBase,
	public ComboBox::Listener
{
public:
    OscillatorPanel(SynthFrameworkAudioProcessor* inProcessor);
    ~OscillatorPanel();

	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;

	void addWaveTypeComboBoxListener(ComboBox::Listener* inListener);

	void removeWaveTypeComboBoxListener(ComboBox::Listener* inListener);

private:
	
	ScopedPointer<ParameterComboBox> mOscillatorComboBox;

	ScopedPointer<ParameterComboBox> mFilterComboBox;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorPanel)
};
