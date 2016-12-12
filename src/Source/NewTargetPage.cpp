//
//  NewTargetPage.cpp
//  TDS
//
//  Created by Corentin Comte on 08/12/2016.
//
//

#include "NewTargetPage.h"
#include "FontUtils.h"
#include "MainComponent.h"

NewTargetPage::NewTargetPage():
juce::Component("New Target Page")

{
    mStartCombatButton = new NiceComponent("Start New Combat");
    mStartCombatButton->SetTextToDisplay("L'APPROCHER");
    mStartCombatButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mStartCombatButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mStartCombatButton->SetTextColor(juce::Colours::white);
    mStartCombatButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mStartCombatButton->setBounds(200, 530, 400, 55);
    mStartCombatButton->AddListener(this);
    
    addAndMakeVisible(mStartCombatButton);
    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(60.f);
}

NewTargetPage::~NewTargetPage()
{
    removeAllChildren();
}


void NewTargetPage::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mStartCombatButton){
        //GoToCombat !
    }
}

bool NewTargetPage::LoadTargetInfos(const Girl inTarget, const juce::Image inEventBanner, const std::string inEventName)
{
    mEventName = inEventName;
    mBanner = inEventBanner;
    
    mTargetName = inTarget.GetName();
    mGenre = inTarget.GetGenre();
    mList = inTarget.GetListe();
    
    return true;
}


void NewTargetPage::paint(juce::Graphics& inG)
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
    inG.drawText("Nouvelle target", 200, 200, 400, 100, juce::Justification::centred);
    
    inG.setFont(30.f);
    inG.drawText("Nom : " + mTargetName, 200, 260, 400, 100, juce::Justification::centred);
    inG.drawText("Genre : " + GirlGenreToString(mGenre), 200, 320, 400, 100, juce::Justification::centred);
    inG.drawText("Liste : " + ListToString(mList), 200, 380, 400, 100, juce::Justification::centred);
}
