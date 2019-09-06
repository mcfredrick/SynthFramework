/*
  ==============================================================================

    MainPanel.h
    Created: 30 Aug 2019 5:00:23pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

#include "OscillatorPanel.h"

#include "ADSRPanel.h"


class MainPanel
	:	public PanelBase
{
public:

	MainPanel(SynthFrameworkAudioProcessor* inProcessor);
	~MainPanel();

private:

	ScopedPointer<OscillatorPanel> mOscillatorPanel;
	ScopedPointer<ADSRPanel> mADSRPanel;

};