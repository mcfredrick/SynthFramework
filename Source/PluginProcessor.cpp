/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "maximilian.h"
#include "Parameters.h"

//==============================================================================
SynthFrameworkAudioProcessor::SynthFrameworkAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
	parameterTree(*this,					//processorToConnectTo
				  nullptr,					//undoManagerToUse
				  juce::Identifier("ADSR"),  //valueTreeType
				  createParameterLayout())	//parameterLayout

#endif
{

	//initialize parameter values
	attackTime = 0.1f;

	//clear out any garbage values that may be left over in memory
	mSynth.clearVoices();

	//intitialize the voices to be used by the synth
	for (int i = 0; i < mNumberOfVoices; i++)
	{
		mSynth.addVoice(new SynthVoice());
	}

	mSynth.clearSounds();
	mSynth.addSound(new SynthSound());
}

SynthFrameworkAudioProcessor::~SynthFrameworkAudioProcessor()
{
}

//==============================================================================
const String SynthFrameworkAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SynthFrameworkAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SynthFrameworkAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SynthFrameworkAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthFrameworkAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SynthFrameworkAudioProcessor::setCurrentProgram (int index)
{
}

const String SynthFrameworkAudioProcessor::getProgramName (int index)
{
    return {};
}

void SynthFrameworkAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SynthFrameworkAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

	//discard any samples that may be remaining from the last key press
	ignoreUnused(samplesPerBlock);
	//store the last sample rate in memory in case something changes
	mLastSampleRate = sampleRate;
	//make sure we're working with the most up to date sample rate
	mSynth.setCurrentPlaybackSampleRate(mLastSampleRate);

}

void SynthFrameworkAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthFrameworkAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SynthFrameworkAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	//clear the buffer
	buffer.clear();

	for (int i = 0; i < mSynth.getNumVoices(); i++)
	{
		if ((mVoice = dynamic_cast<SynthVoice*>(mSynth.getVoice(i))))
		{
			mVoice->getParameters(parameterTree.getRawParameterValue("Attack"),
									parameterTree.getRawParameterValue("Decay"),
									parameterTree.getRawParameterValue("Sustain"),
									parameterTree.getRawParameterValue("Release"));
			mVoice->setOscillatorType(parameterTree.getRawParameterValue("WaveType"));
		}
	}

	//render the samples from the synth and pass midi messages
	mSynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

	/* DISABLED BOILERPLATE FUNCTIONS FOR NOW
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // add any effects algoithms here...
    }
	*/
}

//==============================================================================
bool SynthFrameworkAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SynthFrameworkAudioProcessor::createEditor()
{
    return new SynthFrameworkAudioProcessorEditor (*this);
}

//==============================================================================
void SynthFrameworkAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthFrameworkAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthFrameworkAudioProcessor();
}

AudioProcessorValueTreeState::ParameterLayout SynthFrameworkAudioProcessor::createParameterLayout()
{
	std::vector<std::unique_ptr<AudioParameterFloat>> params;

	//the wavetype parameter will require a range equal to the number of combobox choices minus 1
	//the other parameters will range from 0 to 1
	NormalisableRange<float> parameterRange = NormalisableRange<float>(0.0f, 1.0f);
	NormalisableRange<float> waveRange = NormalisableRange<float>(0, 2);

	for (int i = 0; i < kParameter_TotalNumParameters; i++) 
	{
		if (ParameterID[i] != "WaveType") 
		{

			//all parameters are brought in with a range between 0 and 1 
			//jmap will be used where the parameters are implemented
			//to remap the range to a range that makes sense for the parameter
			params.push_back(std::make_unique<AudioParameterFloat>(ParameterID[i],
				ParameterLabel[i],
				parameterRange,
				ParameterDefaultValue[i]));

		} else {

			params.push_back(std::make_unique<AudioParameterFloat>(ParameterID[i],
				ParameterLabel[i],
				waveRange,
				ParameterDefaultValue[i]));

		}

	}

	return { params.begin(), params.end() };
}