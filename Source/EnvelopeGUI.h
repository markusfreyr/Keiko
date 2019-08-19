/*
  ==============================================================================

    EnvelopeGUI.h
    Created: 19 Apr 2019 11:01:30am
    Author:  Markús Freyr

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class EnvelopeGUI    : public Component
{
public:
    EnvelopeGUI(KeikoAudioProcessor&);
    ~EnvelopeGUI();

    void paint (Graphics&) override;
    void resized() override;
    

private:
    
    Slider attackSlider;
    Slider sustainsSlider;
    Slider decaySlider;
    Slider releaseSlider;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackSliderTree;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sustainSliderTree;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> decaySliderTree;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseSliderTree;

    KeikoAudioProcessor& processor;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeGUI)
};
