/*
  ==============================================================================

    FilterPanel.cpp
    Created: 10 Sep 2019 9:40:19pm
    Author:  mattc

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilterPanel.h"
#include "InterfaceDefines.h"
#include "Parameters.h"

//==============================================================================
FilterPanel::FilterPanel(SynthFrameworkAudioProcessor* inProcessor)
	: PanelBase(inProcessor)
{
	setSize(FILTER_PANEL_WIDTH, FILTER_PANEL_HEIGHT);

	mSliders.clear();

	const int slider_size = 56;
	int x = 56;												//first slider x position
	int y = (getHeight() * 0.5) - (slider_size * 0.5);		//first slider y position

	//construct the slider
	ParameterSlider* cutoff = new ParameterSlider(inProcessor->parameterTree, ParameterID[kParameter_FilterCutoff], ParameterLabel[kParameter_FilterCutoff]);
	cutoff->setBounds(x, y, slider_size, slider_size);
	//add to the parent and make visible
	addAndMakeVisible(cutoff);
	//add slider to the array mSliders
	mSliders.add(cutoff);
	//increment the x position of each knob
	x = x + (slider_size * 2);
	//create a label
	cutoffLabel.setText(ParameterLabel[kParameter_FilterCutoff], dontSendNotification);
	cutoffLabel.attachToComponent(cutoff, false);
	addAndMakeVisible(cutoffLabel);

	//construct the slider
	ParameterSlider* resonance = new ParameterSlider(inProcessor->parameterTree, ParameterID[kParameter_FilterResonance], ParameterLabel[kParameter_FilterResonance]);
	resonance->setBounds(x, y, slider_size, slider_size);
	//add to the parent and make visible
	addAndMakeVisible(resonance);
	//add slider to the array mSliders
	mSliders.add(resonance);
	//increment the x position of each knob
	x = x + (slider_size * 2);
	//create a label
	resonanceLabel.setText(ParameterLabel[kParameter_FilterResonance], dontSendNotification);
	resonanceLabel.attachToComponent(resonance, false);
	addAndMakeVisible(resonanceLabel);

}

FilterPanel::~FilterPanel()
{
}

void FilterPanel::paint (Graphics& g)
{
	PanelBase::paint(g);

	g.fillAll(Colours::lightgrey);
}

void FilterPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
