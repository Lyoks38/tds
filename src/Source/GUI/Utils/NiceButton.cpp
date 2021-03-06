//
//  Button.cpp
//  TDS
//
//  Created by Corentin Comte on 08/11/2016.
//
//

#include "NiceButton.h"


    
NiceButton::NiceButton(const std::string& inName):
NiceComponent(inName)
{
}
    
    
void NiceButton::paint(juce::Graphics &inG)
{
    if(mToggleState == false || !isEnabled()){
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
        mFont.setHeight(mFontSize);
        inG.setFont (mFont);
        inG.setColour(textColor);
        inG.drawText(mTextActive, 0, 0, getWidth(), getHeight(), mJustification);
    }
            
}


void NiceButton::mouseDown(const juce::MouseEvent& e)
{
    if(!isEnabled())
        return;
    
    NiceComponent::mouseDown(e);
    
    SetToggleState(!mToggleState);
    repaint();
}
