//
//  WelcomePage.cpp
//  TDS
//
//  Created by Corentin Comte on 24/11/2016.
//
//

#include "WelcomePage.h"
#include "Utils/FontUtils.h"
#include "../MainComponent.h"

WelcomePage::WelcomePage(): juce::Component("Welcome Page")
{
    mNextButton = new NiceComponent("Welcome Next Button");
    
    mNextButton->SetTextToDisplay("Suivant");
    
    mNextButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mNextButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mNextButton->SetTextColor(juce::Colours::white);
    mNextButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mNextButton->setBounds(700, 540, 70, 25);
    mNextButton->AddListener(this);
    addAndMakeVisible(mNextButton);
    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(60.f);
}

WelcomePage::~WelcomePage()
{
    removeChildComponent(mNextButton);
}

void WelcomePage::paint(juce::Graphics &inG)
{
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText("Bienvenue dans TDS !", 0, 0, getWidth(), 150, juce::Justification::centred);
}

