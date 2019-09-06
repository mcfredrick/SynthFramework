/*
  ==============================================================================

    PanelBase.h
    Created: 30 Aug 2019 4:16:48pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#include "PluginProcessor.h"

#include "InterfaceDefines.h"

class PanelBase
	: public Component
{
public:

	PanelBase(SynthFrameworkAudioProcessor* inProcessor);
	~PanelBase();

	void paint(Graphics& g) override;

protected:

	SynthFrameworkAudioProcessor* mProcessor;
};