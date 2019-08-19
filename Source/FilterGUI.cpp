/*
  ==============================================================================

    FilterGUI.cpp
    Created: 19 Apr 2019 4:09:03pm
    Author:  Markús Freyr

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilterGUI.h"

//==============================================================================
FilterGUI::FilterGUI(KeikoAudioProcessor& p) : processor(p)
{
   
    setSize(200, 200);
    
    filterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterCutoff.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    addAndMakeVisible(&filterCutoff);
    //filterCutoff.setSkewFactorFromMidPoint(1000.0);
    
    filterRes.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterRes.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    addAndMakeVisible(&filterRes);
    
    
    filterCutoffSliderTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, "cutoff", filterCutoff);
    filterResSliderTree = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, "res", filterRes);
    
}

FilterGUI::~FilterGUI()
{
}

void FilterGUI::paint (Graphics& g)
{

    
}

void FilterGUI::resized()
{
    
    filterCutoff.setBounds(0, 20, 100, 100);
    filterRes.setBounds(100, 20, 100, 100);
    
    
}
