/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
_5k_boostAudioProcessorEditor::_5k_boostAudioProcessorEditor (_5k_boostAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (700, 700);

    before_img = juce::ImageCache::getFromMemory(BinaryData::_5k_boost_before_jpg, BinaryData::_5k_boost_before_jpgSize);
    after_img = juce::ImageCache::getFromMemory(BinaryData::_5k_boost_unbelievable_jpg, BinaryData::_5k_boost_unbelievable_jpgSize);

    boost->setClickingTogglesState(true);
    boost->onClick = [this] { repaint(); };
    boost->setBounds(0, 0, 700, 700);

    attachment = new juce::ButtonParameterAttachment(*(audioProcessor.enabled), *boost);
    
    addAndMakeVisible(boost);
}

_5k_boostAudioProcessorEditor::~_5k_boostAudioProcessorEditor()
{
}

//==============================================================================
void _5k_boostAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::white);
    g.setColour(juce::Colours::black);

    if (*(audioProcessor.enabled)) {
        g.drawImageAt(after_img, 0, 0);
    }
    else {
        g.drawImageAt(before_img, 0, 0);
    }
}

void _5k_boostAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
