//
//  NewEventPage.cpp
//  TDS
//
//  Created by Corentin Comte on 29/11/2016.
//
//

#include "NewEventPage.h"
#include "FontUtils.h"

NewEventPage::NewEventPage()
{
    mStartEventButton = new NiceComponent("Start New Event");
    mStartEventButton->SetTextToDisplay("COMMENCER");
    mStartEventButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mStartEventButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mStartEventButton->SetTextColor(juce::Colours::white);
    mStartEventButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mStartEventButton->setBounds(200, 530, 400, 55);
    mStartEventButton->AddListener(this);
    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(60.f);
}

NewEventPage::~NewEventPage()
{
    removeAllChildren();
}


void NewEventPage::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mStartEventButton){
        //GoToNextTarget
    }
}

bool NewEventPage::LoadEventInfos(const Event inEvent)
{
    mEventName = inEvent.GetName();
    mIsKfet = inEvent.IsKfet();
    mBanner = inEvent.GetBanner();
    
    return true;
}

void NewEventPage::paint(juce::Graphics& inG)
{
    if(!mBanner.isNull())
        inG.drawImage(mBanner, 0, 0, getWidth(), 200, 0, 0, mBanner.getWidth(), 200);
    
    inG.setColour(juce::Colours::white.withAlpha(0.4f));
    inG.fillRect(0, 0, getWidth(), 200);
    
    juce::ColourGradient grad = juce::ColourGradient(Colour (0xff001F36), 0, 200, Colour (0xff001F36).withAlpha(0.f), 0, 0, false);
    inG.setGradientFill(grad);
    inG.fillRect(0, 0, getWidth(), 200);
    
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    std::string eventName = mEventName;
    
    if(mIsKfet)
        eventName += " (kfet)";
    else
        eventName += " (soirée)";
    
    inG.drawText(eventName, 0, 20, getWidth(), 150, juce::Justification::centred);
    
    
}
