/*
  ==============================================================================

    ADSRPanel.cpp
    Created: 30 Aug 2019 6:18:24pm
    Author:  mattc

  ==============================================================================
*/

#include "ADSRPanel.h"
#include "InterfaceDefines.h"
#include "Parameters.h"

ADSRPanel::ADSRPanel(SynthFrameworkAudioProcessor* inProcessor)
	: PanelBase(inProcessor)
{
	setSize(ADSR_PANEL_WIDTH, ADSR_PANEL_HEIGHT);

	mSliders.clear();

	const int slider_size = 56;
	int x = 56;												//first slider x position
	int y = (getHeight() * 0.5) - (slider_size * 0.5);		//first slider y position

	//construct the slider
	ParameterSlider* attack = new ParameterSlider(inProcessor->parameterTree, ParameterID[kParameter_Attack], ParameterLabel[kParameter_Attack]);
	attack->setBounds(x, y, slider_size, slider_size);
	//add to the parent and make visible
	addAndMakeVisible(attack);
	//add slider to the array mSliders
	mSliders.add(attack);
	//increment the x position of each knob
	x = x + (slider_size * 2);
	//create a label
	attackLabel.setText(ParameterLabel[kParameter_Attack], dontSendNotification);
	attackLabel.attachToComponent(attack, false);
	addAndMakeVisible(attackLabel);

	//construct the slider
	ParameterSlider* decay = new ParameterSlider(inProcessor->parameterTree, ParameterID[kParameter_Decay], ParameterLabel[kParameter_Decay]);
	decay->setBounds(x, y, slider_size, slider_size);
	//add to the parent and make visible
	addAndMakeVisible(decay);
	//add slider to the array mSliders
	mSliders.add(decay);
	//increment the x position of each knob
	x = x + (slider_size * 2);
	//create a label
	decayLabel.setText(ParameterLabel[kParameter_Decay], dontSendNotification);
	decayLabel.attachToComponent(decay, false);
	addAndMakeVisible(decayLabel);

	//construct the slider
	ParameterSlider* sustain = new ParameterSlider(inProcessor->parameterTree, ParameterID[kParameter_Sustain], ParameterLabel[kParameter_Sustain]);
	sustain->setBounds(x, y, slider_size, slider_size);
	//add to the parent and make visible
	addAndMakeVisible(sustain);
	//add slider to the array mSliders
	mSliders.add(sustain);
	//increment the x position of each knob
	x = x + (slider_size * 2);
	//create a label
	sustainLabel.setText(ParameterLabel[kParameter_Sustain], dontSendNotification);
	sustainLabel.attachToComponent(sustain, false);
	addAndMakeVisible(sustainLabel);

	//construct the slider
	ParameterSlider* release = new ParameterSlider(inProcessor->parameterTree, ParameterID[kParameter_Release], ParameterLabel[kParameter_Release]);
	release->setBounds(x, y, slider_size, slider_size);
	//add to the parent and make visible
	addAndMakeVisible(release);
	//add slider to the array mSliders
	mSliders.add(release);
	//increment the x position of each knob
	x = x + (slider_size * 2);
	//create a label
	releaseLabel.setText(ParameterLabel[kParameter_Release], dontSendNotification);
	releaseLabel.attachToComponent(release, false);
	addAndMakeVisible(releaseLabel);
}

ADSRPanel::~ADSRPanel()
{

}

void ADSRPanel::paint(Graphics& g)
{
	PanelBase::paint(g);

	g.fillAll(Colours::dimgrey);
	//if (mSlider) {
	//	g.paintComponentLabel(g, mSlider);
	//};
}

void ADSRPanel::setParameterID(int inParameterID)
{
	/*
	mSlider = new ParameterSlider(mProcessor->parameterTree, ParameterID[inParameterID], ParameterLabel[inParameterID]);

	const int slider_size = 54;

	mSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5),
		(getHeight() * 0.20) - (slider_size * 0.5) - 10,
		slider_size,
		slider_size);

	addAndMakeVisible(mSlider);
	*/
}