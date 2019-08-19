/*
  ==============================================================================

    SynthSound.h
    Created: 8 Apr 2019 3:16:48pm
    Author:  Markús Freyr

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
    
public:

    bool appliesToNote    (int midiNoteNumber)
    {
        return true;
    }
    bool appliesToChannel (int midiChannel)
    {
        return true;
    }
    
private:
    
    
    
};
