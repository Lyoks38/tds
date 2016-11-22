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
    
    if(!isEnabled()){
        inG.setColour(mDisabledColor);
        inG.fillRect(0, 0, getWidth(), getHeight());
    }
}


void NiceComponent::AddListener(NiceComponentListener *inListener)
{
    if(inListener == nullptr)
        return;
    
    auto it = std::find(mListeners.begin(), mListeners.end(), inListener);
    
    if(it == mListeners.end() && it != mListeners.begin())
        return;
    
    mListeners.emplace_back(inListener);
}

void NiceComponent::mouseDown(const juce::MouseEvent &e)
{
    for(auto it : mListeners)
        it->onNiceComponentClicked(this);
}
