/*
  ==============================================================================

    FilterGUI.h
    Created: 19 Apr 2019 4:09:03pm
    Author:  Markús Freyr

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class FilterGUI    : public Component
{
public:
    FilterGUI(KeikoAudioProcessor&);
    ~FilterGUI();

    void paint (Graphics&) override;
    void resized() override;

private:
    
    Slider filterCutoff;
    Slider filterRes;
    
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filterCutoffSliderTree;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filterResSliderTree;
    
    KeikoAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterGUI)
};
