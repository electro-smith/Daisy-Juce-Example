#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	// Setup the Slider object
	oscFreq.setSliderStyle(juce::Slider::LinearBarVertical);
	oscFreq.setRange(0.0, 127.0, 0.25);
	oscFreq.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
	oscFreq.setPopupDisplayEnabled(true, false, this);
	oscFreq.setTextValueSuffix(" Frequency");
	oscFreq.setValue(1.0);

	// Add Slider to the editor
	addAndMakeVisible(&oscFreq);
	// Add Listener for slider
	oscFreq.addListener(this);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
	g.drawFittedText("Oscllator Frequency", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	// sets the position and size of the slider with arguments (x, y, width, height)
	oscFreq.setBounds(40, 30, 20, getHeight() - 60);
}

void AudioPluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
	processorRef.noteVal = oscFreq.getValue();
}
