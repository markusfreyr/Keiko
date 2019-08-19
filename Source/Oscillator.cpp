/*
  ==============================================================================

    Oscillator.cpp
    Created: 17 Apr 2019 2:18:47pm
    Author:  Markús Freyr

  ==============================================================================
*/

#include "DSP.h"

Oscillator::Oscillator()
{
    phase = 0.0;
}

double Oscillator::sineWave(double frequency)
{
    output=sin (phase*(TWOPI));
    if ( phase >= 1.0 ) phase -= 1.0;
    phase += (1./(SAMPLERATE/(frequency)));
    return(output);
}

double Oscillator::squareWave(double frequency)
{
    if (phase<0.5) output=-1;
    if (phase>0.5) output=1;
    if ( phase >= 1.0 ) phase -= 1.0;
    phase += (1./(SAMPLERATE/(frequency)));
    return(output);
}

double Oscillator::sawWave(double frequency)
{
    output=phase;
    if ( phase >= 1.0 ) phase -= 2.0;
    phase += (1./(SAMPLERATE/(frequency)));
    return(output);
    
}

double Oscillator::triangleWave(double frequency)
{
    
    if ( phase >= 1.0 ) phase -= 1.0;
    phase += (1./(SAMPLERATE/(frequency)));
    if (phase <= 0.5 ) {
        output =(phase - 0.25) * 4;
    } else {
        output =((1.0-phase) - 0.25) * 4;
    }
    return(output);
    
}


