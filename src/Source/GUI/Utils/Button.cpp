//
//  Button.cpp
//  TDS
//
//  Created by Corentin Comte on 08/11/2016.
//
//

#include "Button.h"

namespace TDS {
    
    Button::Button(const std::string& inName):
    NiceComponent(inName)
    {
    }
    
    
    void Button::paint(juce::Graphics &inG)
    {
        if(mToggleState == 0){
            NiceComponent::paint(inG);
            return;
        }
        
        juce::Colour bgColor = isMouseOver() ? mBgActiveHoverColor : mBgActiveColor;
        if(!bgColor.isTransparent())
            inG.fillAll(bgColor);
        
        if(mTextActive.empty())
            SetActiveText(mTextToDisplay);
        
        if(mTextActive.empty())
            return;
        
        juce::Colour textColor = isMouseOver() ? mTextActiveHoverColor : mTextActiveColor;
        if(!textColor.isTransparent()){
            inG.setColour(textColor);
            inG.drawText(mTextActive, getBounds(), mJustification);
        }
            
    }
    
    
}
