//
//  Button.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef NiceButton_h
#define NiceButton_h

#include "NiceComponent.h"


class NiceButton: public NiceComponent
{
    
public:
    
    NiceButton(const std::string& inName);
    
    ~NiceButton(){};
    
    
    virtual void paint(juce::Graphics& inG) override;
    
    void SetToggleState(uint8_t inState);
    uint8_t GetToggleState() const { return mToggleState; }
    
    void SetActiveText(std::string inText) { mTextActive = inText; }
    void SetActiveBgColor(const juce::Colour& inColour) { mBgActiveColor = inColour; }
    
private:
    
    uint8_t mToggleState = 0;
    
    std::string mTextActive;
    
    juce::Colour mBgActiveColor = juce::Colours::transparentWhite;
    juce::Colour mBgActiveHoverColor = juce::Colours::transparentWhite;
    juce::Colour mTextActiveColor = juce::Colours::black;
    juce::Colour mTextActiveHoverColor = juce::Colours::black;
    
};

#endif /* Button_h */
