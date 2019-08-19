/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KeikoAudioProcessorEditor::KeikoAudioProcessorEditor (KeikoAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGUI(p), envGUI(p), filterGUI(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 200);
    
    addAndMakeVisible(&oscGUI);
    addAndMakeVisible(&envGUI);
    addAndMakeVisible(&filterGUI);
    

}

KeikoAudioProcessorEditor::~KeikoAudioProcessorEditor()
{
}

//==============================================================================
void KeikoAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void KeikoAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    
    const int componentWidht = 200;
    const int componentheight = 200;
    
    oscGUI.setBounds(area.removeFromLeft(componentWidht).removeFromTop(componentheight));
    envGUI.setBounds(area.removeFromLeft(componentWidht).removeFromTop(componentheight));
    filterGUI.setBounds(area.removeFromLeft(componentWidht).removeFromTop(componentheight));
    

    

}


//==============================================================================


