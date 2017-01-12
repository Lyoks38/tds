//
//  EndEventPage.cpp
//  TDS
//
//  Created by Corentin Comte on 12/01/2017.
//
//

#include "EndEventPage.h"
#include "FontUtils.h"
#include "MainComponent.h"

EndEventPage::EndEventPage():
juce::Component("New Event Page")
{
    mNextEventButton = new NiceComponent("Go To Next Event");
    mNextEventButton->SetTextToDisplay("CONTINUER");
    mNextEventButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mNextEventButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mNextEventButton->SetTextColor(juce::Colours::white);
    mNextEventButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mNextEventButton->setBounds(200, 530, 400, 55);
    mNextEventButton->AddListener(this);
    
    addAndMakeVisible(mNextEventButton);
    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(60.f);
}

EndEventPage::~EndEventPage()
{
    deleteAllChildren();
}


void EndEventPage::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mNextEventButton){
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        if(parent)
            parent->GoToNextEvent();
    }
}

bool EndEventPage::LoadEventInfos(const Event inEvent, int inChoppes, bool inWasNotFailed)
{
    mEventName = inEvent.GetName();
    mIsKfet = inEvent.IsKfet();
    mBanner = inEvent.GetBanner();
    mLocation = inEvent.GetLocation();
    
    mNbTargets = static_cast<int>(inEvent.GetTargets().size());
    mNbChoppes = inChoppes;
    
    mWasNotFailed = inWasNotFailed;
    
    return true;
}

void EndEventPage::paint(juce::Graphics& inG)
{
    if(!mBanner.isNull())
        inG.drawImage(mBanner, 0, 0, getWidth(), 200, 0, 0, mBanner.getWidth(), 200);
    
    inG.setColour(juce::Colours::white.withAlpha(0.4f));
    inG.fillRect(0, 0, getWidth(), 200);
    
    juce::ColourGradient grad = juce::ColourGradient(Colour (0xff001F36), 0, 200, Colour (0xff001F36).withAlpha(0.f), 0, 0, false);
    inG.setGradientFill(grad);
    inG.fillRect(0, 0, getWidth(), 200);
    
    std::string type = mIsKfet ? "Kfet" : "Soirée";
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText(mEventName + "(" + type + ")", 0, 20, getWidth(), 150, juce::Justification::centred);
    
    inG.setFont(Font(40.f));
    inG.drawText("Type : " + type, 200, 200, 400, 100, juce::Justification::centred);
    inG.drawText("Lieu : " + mLocation, 200, 400, 400, 100, juce::Justification::centred);
    inG.drawText("Nombre de choppes : " + std::to_string(mNbChoppes) + " / " + std::to_string(mNbTargets), 200, 300, 400, 100, juce::Justification::centred);
}

