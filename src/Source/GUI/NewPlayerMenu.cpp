//
//  NewPlayerMenu.cpp
//  TDS
//
//  Created by Corentin Comte on 14/11/2016.
//
//

#include "NewPlayerMenu.h"
#include "FontUtils.h"


NewPlayerMenu::NewPlayerMenu():
juce::Component("New Player Menu")
{
    mReturnButton = new NiceComponent("Return To Main Menu");
    mReturnButton->SetTextToDisplay("< Retour");
    mReturnButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mReturnButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mReturnButton->setBounds(20, 20, 100, 25);
    mReturnButton->AddListener(this);
    
    addAndMakeVisible(mReturnButton);
    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(50.f);
}

NewPlayerMenu::~NewPlayerMenu()
{
    removeAllChildren();
}

void NewPlayerMenu::paint(juce::Graphics& inG)
{
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText("Create Your New Player", 0, 0, getWidth(), 150, juce::Justification::centred);
}


void NewPlayerMenu::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mReturnButton){
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        if(parent)
            parent->DisplayMainMenu();
    }
}
