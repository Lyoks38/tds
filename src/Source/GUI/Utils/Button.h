//
//  Button.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef Button_h
#define Button_h

#include "GuiUtils.h"
#include "NiceComponent.h"

namespace TDS {

class Button: public NiceComponent
{
    
public:
    
    Button(const std::string& inName);
    
    ~Button(){};
    
    
    virtual void paint(juce::Graphics& inG) override;
    
    void SetToggleState(uint8_t inState);
    uint8_t GetToggleState() const { return mToggleState; }
    
    void SetActiveText(std::string inText) { mTextActive = inText; }
    
private:
    
    uint8_t mToggleState = 0;
    
    std::string mTextActive;
    
    juce::Colour mBgActiveColor = juce::Colours::transparentWhite;
    juce::Colour mBgActiveHoverColor = juce::Colours::transparentWhite;
    juce::Colour mTextActiveColor = juce::Colours::black;
    juce::Colour mTextActiveHoverColor = juce::Colours::black;
    
};

}
#endif /* Button_h */
