#pragma once

#include <JuceHeader.h>

class MainComponent  : public juce::Component
{
public:
    MainComponent()
    {
        addAndMakeVisible(input1);
        addAndMakeVisible(input2);
        addAndMakeVisible(addButton);
        addAndMakeVisible(resultLabel);
        
        addButton.setButtonText("Add");
        addButton.onClick = [this]() { performAddition(); };
        
        setSize (400, 200);
    }

    ~MainComponent() override {}

    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::lightgrey);
    }

    void resized() override
    {
        auto area = getLocalBounds().reduced(20);
        input1.setBounds(area.removeFromTop(40));
        input2.setBounds(area.removeFromTop(40));
        addButton.setBounds(area.removeFromTop(40));
        resultLabel.setBounds(area);
    }

private:
    void performAddition()
    {
        auto value1 = input1.getText().getFloatValue();
        auto value2 = input2.getText().getFloatValue();
        resultLabel.setText("Result: " + juce::String(value1 + value2), juce::dontSendNotification);
    }

    juce::TextEditor input1, input2;
    juce::TextButton addButton;
    juce::Label resultLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
