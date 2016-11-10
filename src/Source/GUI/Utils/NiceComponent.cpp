//
//  NiceComponent.cpp
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#include "NiceComponent.h"


NiceComponent::NiceComponent(const std::string& inName):
juce::Component(inName)
{
    
}


void NiceComponent::paint(juce::Graphics &inG)
{
    juce::Colour bgColor = isMouseOver() ? mBgHoverColor : mBgColor ;
    
    if(!bgColor.isTransparent()){
        inG.setColour(bgColor);
        inG.fillRect(0, 0, getWidth(), getHeight());
    }
    
    if(mTextToDisplay.empty())
        return;
    
    juce::Colour textColour = isMouseOver() ? mTextHoverColor : mTextColor;
    
    if(!textColour.isTransparent()){
        mFont.setHeight(mFontSize);
        inG.setFont (mFont);
        inG.setColour(textColour);
        inG.drawText(mTextToDisplay, 0, 0, getWidth(), getHeight(), mJustification);
    }
}
