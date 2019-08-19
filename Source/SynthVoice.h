/*
  ==============================================================================

    SynthVoice.h
    Created: 8 Apr 2019 3:16:40pm
    Author:  Markús Freyr

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "DSP.h"

class SynthVoice : public SynthesiserVoice
{

public:
    
    
    void getFilterParam(float* cutoff,float* res)
    {
        myCutoff = *cutoff;
        myRes = *res;
    }
    
    double setFilter()
    {
        return myFilt.lores(setEnvelope(),myCutoff,myRes);
    }
    
    void getADSRParam(float* attack,float* decay,float* sustain,float* release)
    {
        myEnv.setAttack(double(*attack));
        if(*decay > 0)
        {
            myEnv.setDecay(double(*decay));
        }
        myEnv.setSustain(double(*sustain));
        myEnv.setRelease(double(*release));
        
        
    }
    
    double setEnvelope()
    {
        return myEnv.adsr(setOscType(), myEnv.trigger);
    }
    
    void getOscType(float* wave)
    {
        waveType = *wave;
     
    }

    double setOscType()
    {
        switch (waveType) {
            case 0:
                return myOsc.sineWave(frequency);
            case 1:
                return myOsc.squareWave(frequency);
            case 2:
                return myOsc.triangleWave(frequency);
            case 3:
                return myOsc.sawWave(frequency);
            default:
                return -1.0;
        }
    }
    
    
    bool canPlaySound (SynthesiserSound* sound)
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        myEnv.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        
    }
    
    void stopNote (float velocity, bool allowTailOff)
    {
        myEnv.trigger = 0;
        allowTailOff = true;
        if(velocity == 0)
        {
            clearCurrentNote();
        }

    }
    
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
        
        for(int samples = 0; samples < numSamples; samples++)
        {
            
            for(int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
            {
                outputBuffer.addSample(channel, startSample, setFilter());
            }
            ++startSample;
        }
        
    }
    
    void pitchWheelMoved (int newPitchWheelValue)
    {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    
    
private:
    double level;
    double frequency;
    
    float myCutoff;
    float myRes;
    
    int waveType;
    
    Oscillator myOsc;
    Envelope myEnv;
    Filter myFilt;
    
    
};
