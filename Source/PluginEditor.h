/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class _5k_boostAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    _5k_boostAudioProcessorEditor (_5k_boostAudioProcessor&);
    ~_5k_boostAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _5k_boostAudioProcessor& audioProcessor;

    juce::ToggleButton* boost = new juce::ToggleButton();
    juce::ButtonParameterAttachment* attachment;

    juce::Image before_img, after_img;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_5k_boostAudioProcessorEditor)
};
