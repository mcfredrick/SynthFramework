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

	void getParameters(float* attackTime,
						float* decayTime,
						float* sustainTime,
						float* releaseTime)
	{

		mEnvelope1.setAttack(jmap(*attackTime, 0.0f, 1.0f, 0.0f, 5000.0f));
		mEnvelope1.setDecay(jmap(*decayTime, 0.0f, 1.0f, 1.0f, 500.0f));
		mEnvelope1.setSustain(jmap(*sustainTime, 0.0f, 1.0f, 0.1f, 1.0f));
		mEnvelope1.setRelease(jmap(*releaseTime, 0.0f, 1.0f, 0.0f, 5000.0f));
	
	}

	void setOscillatorType(float* oscillatorType)
	{
		std::cout << *oscillatorType;
		mWaveform = *oscillatorType;
	}

	double getOscillatorType()
	{
		switch ((int)mWaveform)
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
		default: 
			return mOscillator1.sinewave(frequency);
			break;
		}

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
			double envelopedSound = mEnvelope1.adsr(getOscillatorType(), mEnvelope1.trigger) * level;
			double filteredSound = mFilter1.lores(envelopedSound, 100, 0.1f);

			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
			{

				outputBuffer.addSample(channel, startSample, filteredSound);
			
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
	int mWaveform;

	maxiOsc mOscillator1;
	maxiEnv mEnvelope1;
	maxiFilter mFilter1;

};