/*
  ==============================================================================

    Parameters.h
    Created: 26 Aug 2019 10:44:31pm
    Author:  mattc

  ==============================================================================
*/

#pragma once
#include <string>

enum Parameter
{
	kParameter_Attack,
	kParameter_Decay,
	kParameter_Sustain,
	kParameter_Release,
	kParameter_WaveType,
	kParameter_FilterCutoff,
	kParameter_FilterResonance,
	kParameter_FilterType,
	kParameter_TotalNumParameters
};

static std::string ParameterID[kParameter_TotalNumParameters] =
{
	"Attack",
	"Decay",
	"Sustain",
	"Release",
	"WaveType",
	"FilterCutoff",
	"FilterResonance",
	"FilterType",
};

static std::string ParameterLabel[kParameter_TotalNumParameters] =
{
	"Attack",
	"Decay",
	"Sustain",
	"Release",
	"Wave Type",
	"Cutoff",
	"Resonance",
	"Filter Type",
};

static float ParameterDefaultValue[kParameter_TotalNumParameters] =
{
	0.5f, //Attack Time
	0.5f, //Decay
	0.5f, //Sustain
	0.5f, //Release
	0.0f, //WaveType
	0.5f, //Filter Cutoff
	0.5f, //Filter Resonance
	0.0f, //Filter Type
};