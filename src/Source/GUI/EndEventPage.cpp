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
    
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText(mEventName, 0, 20, getWidth(), 150, juce::Justification::centred);
    inG.setFont(40.f);
    inG.drawText("Resume :", 200, 300, 400, 100, juce::Justification::centred);

    inG.setFont(Font(26.f));
    
    std::string type = mIsKfet ? "Kfet" : "Soirée";
    std::string catchText;
    if(mWasNotFailed)
        catchText = "Là baaaaaas au Connemaraaaaaaaa ! Allez, fin de la soirée ! Voyons voir un peu ton score !";
    else
        catchText = "Tu es trop saoul et tu finis en PLS. Un pauvre staff est obligé de te ramener chez toi. Voyons quand même ton score...";
    
    inG.setFont(16.f);
    inG.drawMultiLineText(catchText, 100, 270, 600);
    inG.drawText("Type : " + type, 200, 370, 400, 50, juce::Justification::centred);
    inG.drawText("Lieu : " + mLocation, 200, 400, 400, 50, juce::Justification::centred);
    inG.drawText("Nombre de choppes : " + std::to_string(mNbChoppes) + " / " + std::to_string(mNbTargets), 200, 430, 400, 50, juce::Justification::centred);
    inG.drawText("Bonus de reputation : + " + std::to_string(mNbChoppes * 5), 200, 460, 400, 50, juce::Justification::centred);

}

