//
//  NiceComponent.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef NiceComponent_h
#define NiceComponent_h

#include "GuiUtils.h"


class NiceComponent: public juce::Component
{
    
public:
    
    NiceComponent(const std::string& inName);
    
    ~NiceComponent();
    
    
    virtual void paint(juce::Graphics& inG) override;
    
    //Setters
    void SetTextToDisplay(std::string inText) { mTextToDisplay = inText; }
    void SetJustification(juce::Justification inJustification) { mJustification = inJustification; }
    void SetBgColor(juce::Colour inColour) { mBgColor = inColour; }
    void SetBgHoverColor(juce::Colour inColour) { mBgHoverColor = inColour; }
    void SetTextColor(juce::Colour inColour) { mTextColor = inColour; }
    void SetTextHoverColor(juce::Colour inColour) { mTextHoverColor = inColour; }
    
protected:
    
    std::string mTextToDisplay;
    juce::Justification mJustification = juce::Justification::centred;
    
    juce::Colour mBgColor = juce::Colours::transparentWhite;
    juce::Colour mBgHoverColor = juce::Colours::transparentWhite;
    juce::Colour mTextColor = juce::Colours::black;
    juce::Colour mTextHoverColor = juce::Colours::black;
};

#endif /* NiceComponent_h */
