/*
  ==============================================================================

    FilterPanel.h
    Created: 10 Sep 2019 9:40:19pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "ParameterSlider.h"

//==============================================================================
/*
*/
class FilterPanel    : public PanelBase
{
public:
    FilterPanel(SynthFrameworkAudioProcessor* inProcessor);
    ~FilterPanel();

    void paint (Graphics&) override;
    void resized() override;

	void setParameterID(int inParameterID);

private:

	//ScopedPointer<ParameterSlider> mSlider;
	OwnedArray<ParameterSlider> mSliders;

	Label cutoffLabel;
	Label resonanceLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterPanel)
};
