/*
  ==============================================================================

    OscillatorPanel.cpp
    Created: 30 Aug 2019 1:38:30pm
    Author:  mattc

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "OscillatorPanel.h"
#include "Parameters.h"

//==============================================================================
OscillatorPanel::OscillatorPanel(SynthFrameworkAudioProcessor* inProcessor)
	:	PanelBase(inProcessor)
{
	setSize(OSCILLATOR_PANEL_WIDTH, OSCILLATOR_PANEL_HEIGHT);
	//Create and display the combo box for wave selection

	const int width = 150;								//combo box width
	const int height = OSCILLATOR_PANEL_HEIGHT - 10;	//combo box height

	mOscillatorComboBox = 
		new ParameterComboBox(inProcessor->parameterTree, ParameterID[kParameter_WaveType]);
	mOscillatorComboBox->setBounds(0,0,width, height);
	mOscillatorComboBox->addItem("Sine", 1);
	mOscillatorComboBox->addItem("Saw", 2);
	mOscillatorComboBox->addItem("Square", 3);
	mOscillatorComboBox->setJustificationType(Justification::centred);
	mOscillatorComboBox->setSelectedItemIndex((int)mProcessor->getParameter(kParameter_WaveType),
		dontSendNotification);

	addAndMakeVisible(*mOscillatorComboBox);	
}

OscillatorPanel::~OscillatorPanel()
{

}

void OscillatorPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{

}

void OscillatorPanel::addWaveTypeComboBoxListener(ComboBox::Listener* inListener)
{
	mOscillatorComboBox->addListener(inListener);
}

void OscillatorPanel::removeWaveTypeComboBoxListener(ComboBox::Listener* inListener)
{
	mOscillatorComboBox->removeListener(inListener);
}