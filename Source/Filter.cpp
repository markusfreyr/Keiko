/*
  ==============================================================================

    Filter.cpp
    Created: 18 Apr 2019 1:05:10pm
    Author:  Markús Freyr

  ==============================================================================
*/

#include "DSP.h"


double Filter::lopass(double input, double cutoff)
{
    output=outputs[0] + cutoff*(input-outputs[0]);
    outputs[0]=output;
    return(output);
}

double Filter::hipass(double input, double cutoff)
{
    output=input-(outputs[0] + cutoff*(input-outputs[0]));
    outputs[0]=output;
    return(output);
    
}

double Filter::lores(double input, double cutoff1, double resonance)
{
    cutoff=cutoff1;
    if (cutoff<10) cutoff=10;
    if (cutoff>(SAMPLERATE)) cutoff=(SAMPLERATE);
    if (resonance<1.) resonance = 1.;
    z=cos(TWOPI*cutoff/SAMPLERATE);
    c=2-2*z;
    double r=(sqrt(2.0)*sqrt(-pow((z-1.0),3.0))+resonance*(z-1))/(resonance*(z-1));
    x=x+(input-y)*c;
    y=y+x;
    x=x*r;
    output=y;
    return(output);
    
}

double Filter::hires(double input, double cutoff1, double resonance)
{
    cutoff=cutoff1;
    if (cutoff<10) cutoff=10;
    if (cutoff>(SAMPLERATE)) cutoff=(SAMPLERATE);
    if (resonance<1.) resonance = 1.;
    z=cos(TWOPI*cutoff/SAMPLERATE);
    c=2-2*z;
    double r=(sqrt(2.0)*sqrt(-pow((z-1.0),3.0))+resonance*(z-1))/(resonance*(z-1));
    x=x+(input-y)*c;
    y=y+x;
    x=x*r;
    output=input-y;
    return(output);
    
}
