/*
  ==============================================================================

    OscillatorGUI.h
    Created: 18 Apr 2019 8:27:37pm
    Author:  Markús Freyr

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class OscillatorGUI    : public Component
{
public:
    OscillatorGUI(KeikoAudioProcessor&);
    ~OscillatorGUI();

    void paint (Graphics&) override;
    void resized() override;
    

private:
    ComboBox oscMenu;
    
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> oscMenuTree;
    
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KeikoAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorGUI)
};
