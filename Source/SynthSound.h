/*
  ==============================================================================

    SynthSound.h
    Created: 26 Aug 2019 1:19:41am
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound 
	: public SynthesiserSound
{
public:

	bool appliesToNote(int midiNoteNumber) 
	{
		return true;
	}

	bool appliesToChannel(int midiChannel)
	{
		return true;
	}

private:
	
};