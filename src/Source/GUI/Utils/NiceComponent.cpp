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
    juce::Colour textColour = isMouseOver() ? mTextHoverColor : mTextColor;
    
    inG.fillAll(bgColor);
    
    inG.setColour(textColour);
    inG.drawText(mTextToDisplay, getBounds(), mJustification);
}
