/*
  ==============================================================================

    OscillatorGUI.cpp
    Created: 18 Apr 2019 8:27:37pm
    Author:  Markús Freyr

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "OscillatorGUI.h"

//==============================================================================
OscillatorGUI::OscillatorGUI(KeikoAudioProcessor& p) : processor(p)
{
    setSize(200, 200);
    
    oscMenu.addItem("sine",1);
    oscMenu.addItem("square", 2);
    oscMenu.addItem("tri", 3);
    oscMenu.addItem("saw", 4);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    
    oscMenuTree = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.treeState, "wave", oscMenu);
    
}

OscillatorGUI::~OscillatorGUI()
{
}

void OscillatorGUI::paint (Graphics& g)
{
   
}

void OscillatorGUI::resized()
{

    Rectangle<int> area = getLocalBounds().reduced(40);
    
    oscMenu.setBounds(area.removeFromTop(20));
    
}
