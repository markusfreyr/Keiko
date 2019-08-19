/*
  ==============================================================================

    EnvelopeGUI.cpp
    Created: 19 Apr 2019 11:01:30am
    Author:  Markús Freyr

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "EnvelopeGUI.h"

//==============================================================================
EnvelopeGUI::EnvelopeGUI(KeikoAudioProcessor& p) : processor(p)
{
    
    setSize(200, 200);
    
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    addAndMakeVisible(&attackSlider);
    
    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    addAndMakeVisible(&decaySlider);
    
    sustainsSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainsSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    addAndMakeVisible(&sustainsSlider);
    
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    addAndMakeVisible(&releaseSlider);
    
    
    attackSliderTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, "attack", attackSlider);
    decaySliderTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, "decay", decaySlider);
    sustainSliderTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, "sustain", sustainsSlider);
    releaseSliderTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, "release", releaseSlider);

}

EnvelopeGUI::~EnvelopeGUI()
{
}

void EnvelopeGUI::paint (Graphics& g)
{
    
   
}

void EnvelopeGUI::resized()
{
    
     attackSlider.setBounds(10, 10, 20, 100);
     decaySlider.setBounds(30, 10, 20, 100);
     sustainsSlider.setBounds(50, 10, 20, 100);
     releaseSlider.setBounds(70, 10, 20, 100);
    
    
}


