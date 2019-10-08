/*
  ==============================================================================

    SynthVoice.h
    Created: 26 Aug 2019 1:19:55am
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice
	: public SynthesiserVoice
{
public:
	
	bool canPlaySound(SynthesiserSound* sound)
	{
		//if the sound can be cast to a SynthSound object, return true
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}

	void setOscillatorParameters(float* attackTime,
						float* decayTime,
						float* sustainTime,
						float* releaseTime,
						float* oscillatorType)
	{

		mEnvelope1.setAttack(jmap(*attackTime, 0.0f, 1.0f, 0.0f, 5000.0f));
		mEnvelope1.setDecay(jmap(*decayTime, 0.0f, 1.0f, 1.0f, 500.0f));
		mEnvelope1.setSustain(jmap(*sustainTime, 0.0f, 1.0f, 0.1f, 1.0f));
		mEnvelope1.setRelease(jmap(*releaseTime, 0.0f, 1.0f, 0.0f, 5000.0f));
		mOscillatorType = *oscillatorType;
	
	}

	double getOscillatorType()
	{
		switch ((int)mOscillatorType)
		{
		case 0:
			return mOscillator1.sinewave(frequency);
			break;
		case 1:
			return mOscillator1.saw(frequency);
			break;
		case 2:
			return mOscillator1.square(frequency);
			break;
		case 3:
			return mOscillator1.triangle(frequency);
			break;
		case 4:
			return mOscillator1.phasor(frequency);
			break;
		case 5:
			return mOscillator1.pulse(frequency, 0.5);
			break;
		default: 
			return mOscillator1.sinewave(frequency);
			break;
		}

	}

	void setFilterParameters(float* filterType,
							float* filterCutoff,
							float* filterResonance)
	{
		mFilterType = *filterType;
		mFilterCutoff = jmap(*filterCutoff, 0.0f, 1.0f, 20.0f, 10000.0f);		//map the cutoff values to appropriate frequencies	
		mFilterResonance = jmap(*filterResonance, 0.0f, 1.0f, 1.0f, 5.0f);		//map the resonance to an appropriate range
	}

	double renderVoice()
	{
		//set the filter type based on the combo box choice
			switch ((int) mFilterType)
			{
			case 0:
				return applyEnvelope();
				break;
			case 1:
				return mFilter1.lores(applyEnvelope(), mFilterCutoff, mFilterResonance);
				break;
			case 2:
				return mFilter1.hires(applyEnvelope(), mFilterCutoff, mFilterResonance);
				break;
			case 3:
				return mFilter1.lores(applyEnvelope(), mFilterCutoff, mFilterResonance);
				break;
			default:
				return applyEnvelope();
				break;
			}
		

	}

	double applyEnvelope()
	{
		return mEnvelope1.adsr(getOscillatorType(), mEnvelope1.trigger) * level;
	}

	void startNote(int midiNoteNumber, 
					float velocity, 
					SynthesiserSound* sound, 
					int currentPitchWheelPosition)
	{
		mEnvelope1.trigger = 1;
		level = velocity;
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		//std::cout << midiNoteNumber << "=" << frequency << std::endl;
	}

	void stopNote(float velocity, bool allowTailoff)
	{
		mEnvelope1.trigger = 0;
		allowTailoff = true;

		if (velocity == 0) 
		{
			clearCurrentNote();
		}
		
	}

	void renderNextBlock(AudioBuffer<float>& outputBuffer,
						int startSample,
						int numSamples)
	{

		for (int sample = 0; sample < numSamples; ++sample) 
		{

			//Note: renderVoice() calls applyEnvelope() within the call to the filter class from maximilian. 
			//This cuts out a few steps. But it's not exactly intuitive. 
		
			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
			{

				outputBuffer.addSample(channel, startSample, renderVoice());
			
			}

			++startSample;

		}

	}

	void pitchWheelMoved(int newPitchWheelValue) 
	{

	}

	void controllerMoved(int controllerNumber, int newControllerValue)
	{

	}


private:

	double level;
	double frequency;
	float mOscillatorType;
	float mFilterType;
	float mFilterCutoff;
	float mFilterResonance;

	maxiOsc mOscillator1;
	maxiEnv mEnvelope1;
	maxiFilter mFilter1;

};