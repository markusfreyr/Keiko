/*
  ==============================================================================

    DSP.h
    Created: 17 Apr 2019 3:45:14pm
    Author:  Markús Freyr

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;
#ifndef PI
#define PI  3.1415926535897932384626433832795
#endif
#define TWOPI 6.283185307179586476925286766559
#define SAMPLERATE 44100

//==============================================================================================
class Oscillator
{
    double frequency;
    double phase;
    double startphase;
    double endphase;
    double output;
    double tri;
    double sampleRate;
    
public:
    Oscillator();
    double sineWave(double frequency);
    double squareWave(double frequency);
    double sawWave(double frequency);
    double triangleWave(double frequency);
    
private:
    
};

//==============================================================================================

class Envelope
{

    
public:
    
    double adsr(double input, int trigger);
    void setAttack(double attackMS);
    void setRelease(double releaseMS);
    void setDecay(double decayMS);
    void setSustain(double sustainL);
    
    double input;
    double output;
    double attack;
    double decay;
    double sustain;
    double release;
    double amplitude;
    
    int trigger;
    long holdtime=1;
    long holdcount;
    int attackphase;
    int decayphase;
    int sustainphase;
    int holdphase;
    int releasephase;
    
    
private:
    
};

//==============================================================================================

class Filter
{
    double gain;
    double input;
    double output;
    double inputs[10];
    double outputs[10];
    double cutoff1;
    double x;//speed
    double y;//pos
    double z;//pole
    double c;//filter coefficient
    
public:
    
    Filter():x(0.0), y(0.0), z(0.0), c(0.0){};
    double cutoff;
    double resonance;
    double lopass(double input, double cutoff);
    double hipass(double input, double cutoff);
    double lores(double input,double cutoff1, double resonance);
    double hires(double input,double cutoff1, double resonance);
    
private:
    
    
};
