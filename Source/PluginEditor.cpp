/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Parameters.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

	mMainPanel = new MainPanel(&processor);
	addAndMakeVisible(mMainPanel);

	//addAndMakeVisible(mOscillatorComboBox);


	/*
	//Add Envelope Parameter Sliders in a row
	mSliders.clear();

	const int slider_size = 56;
	int x = 130;
	int y = (getHeight() * 0.5) - (slider_size * 0.5);

		//construct the slider
		ParameterSlider* attack = new ParameterSlider(processor.parameterTree, ParameterID[kParameter_Attack], ParameterLabel[kParameter_Attack]);
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
		ParameterSlider* decay = new ParameterSlider(processor.parameterTree, ParameterID[kParameter_Decay], ParameterLabel[kParameter_Decay]);
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
		ParameterSlider* sustain = new ParameterSlider(processor.parameterTree, ParameterID[kParameter_Sustain], ParameterLabel[kParameter_Sustain]);
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
		ParameterSlider* release = new ParameterSlider(processor.parameterTree, ParameterID[kParameter_Release], ParameterLabel[kParameter_Release]);
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
		*/
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{

}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("It's the synth framework!", 0, MAIN_PANEL_HEIGHT-20, getWidth(), 20, Justification::right, 1);

}

void SynthFrameworkAudioProcessorEditor::resized()
{

	juce::Rectangle<int> area = getLocalBounds();

}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider* slider)
{

}