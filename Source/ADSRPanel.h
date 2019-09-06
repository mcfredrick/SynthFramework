/*
  ==============================================================================

    ADSRPanel.h
    Created: 30 Aug 2019 6:18:24pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "ParameterSlider.h"

class ADSRPanel
	: public PanelBase
{
public:

	ADSRPanel(SynthFrameworkAudioProcessor* inProcessor);
	~ADSRPanel();

	void paint(Graphics& g) override;

	void setParameterID(int inParameterID);

private:

	//ScopedPointer<ParameterSlider> mSlider;
	OwnedArray<ParameterSlider> mSliders;

	Label attackLabel;
	Label decayLabel;
	Label sustainLabel;
	Label releaseLabel;

};