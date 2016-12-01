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
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    std::string eventName = mEventName;
    
    if(mIsKfet)
        eventName += " (kfet)";
    else
        eventName += " (soirée)";
    
    inG.drawText(eventName, 0, 150, getWidth(), 150, juce::Justification::centred);
    
    if(!mBanner.isNull())
        inG.drawImage(mBanner, 0, 0, getWidth(), 100, 0, 0, mBanner.getWidth(), mBanner.getHeight());

}
