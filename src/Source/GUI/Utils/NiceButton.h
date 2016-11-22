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
    virtual void mouseDown(const juce::MouseEvent& e) override;
    
    void SetToggleState(bool inState) { mToggleState = inState; repaint();}
    bool GetToggleState() const { return mToggleState; }
    
    void SetActiveText(std::string inText) { mTextActive = inText; }
    void SetActiveBgColor(const juce::Colour& inColour) { mBgActiveColor = inColour; }
    void SetActiveBgHoverColor(const juce::Colour& inColour) { mBgActiveHoverColor = inColour; }
    void SetActiveTextColor(const juce::Colour& inColour) { mTextActiveColor = inColour; }
    void SetActiveTextHoverColor(const juce::Colour& inColour) { mTextActiveHoverColor = inColour; }

    
private:
    
    bool mToggleState = false;
    
    std::string mTextActive;
    
    juce::Colour mBgActiveColor = juce::Colours::transparentWhite;
    juce::Colour mBgActiveHoverColor = juce::Colours::transparentWhite;
    juce::Colour mTextActiveColor = juce::Colours::black;
    juce::Colour mTextActiveHoverColor = juce::Colours::black;
    
};

#endif /* Button_h */
