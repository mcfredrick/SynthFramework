/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "ParameterSlider.h"
#include "OscillatorPanel.h"
#include "MainPanel.h"

//==============================================================================
/**
*/
class SynthFrameworkAudioProcessorEditor  : public AudioProcessorEditor,
											public Slider::Listener
{
public:
    SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor&);
    ~SynthFrameworkAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void sliderValueChanged(Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

	ScopedPointer<MainPanel> mMainPanel;

	Label attackLabel;
	Label decayLabel;
	Label sustainLabel;
	Label releaseLabel;

	OwnedArray<ParameterSlider> mSliders;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessorEditor)
};
