/*
  ==============================================================================

    InterfaceDefines.h
    Created: 30 Aug 2019 5:43:28pm
    Author:  mattc

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define MAIN_PANEL_WIDTH				800
#define MAIN_PANEL_HEIGHT				300

#define OSCILLATOR_PANEL_WIDTH			MAIN_PANEL_WIDTH
#define OSCILLATOR_PANEL_HEIGHT			60

#define ADSR_PANEL_WIDTH				500
#define ADSR_PANEL_HEIGHT				MAIN_PANEL_HEIGHT - OSCILLATOR_PANEL_HEIGHT

#define FILTER_PANEL_WIDTH				MAIN_PANEL_WIDTH - ADSR_PANEL_WIDTH
#define FILTER_PANEL_HEIGHT				MAIN_PANEL_HEIGHT - OSCILLATOR_PANEL_HEIGHT