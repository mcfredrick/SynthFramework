/*
  ==============================================================================

    MainPanel.cpp
    Created: 30 Aug 2019 5:00:23pm
    Author:  mattc

  ==============================================================================
*/

#include "MainPanel.h"

MainPanel::MainPanel(SynthFrameworkAudioProcessor* inProcessor)
	: PanelBase(inProcessor)
{

	setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

	mOscillatorPanel = new OscillatorPanel(inProcessor);
	mOscillatorPanel->setTopLeftPosition(0, 0);
	addAndMakeVisible(mOscillatorPanel);

	mOscillatorPanel->addWaveTypeComboBoxListener(mOscillatorPanel);

	mADSRPanel = new ADSRPanel(inProcessor);
	mADSRPanel->setTopLeftPosition(0, OSCILLATOR_PANEL_HEIGHT);
	addAndMakeVisible(mADSRPanel);

	mFilterPanel = new FilterPanel(inProcessor);
	mFilterPanel->setTopLeftPosition(ADSR_PANEL_WIDTH, OSCILLATOR_PANEL_HEIGHT);
	addAndMakeVisible(mFilterPanel);
	
	mVisualiserPanel = new VisualiserPanel(inProcessor);
	mFilterPanel->setTopLeftPosition(100, 300);
	addAndMakeVisible(mVisualiserPanel);
	
}

MainPanel::~MainPanel()
{
	mOscillatorPanel->removeWaveTypeComboBoxListener(mOscillatorPanel);
}