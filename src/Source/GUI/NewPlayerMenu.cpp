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
    //Return to main menu
    mReturnButton = new NiceComponent("Return To Main Menu");
    mReturnButton->SetTextToDisplay("< Retour");
    mReturnButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mReturnButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mReturnButton->setBounds(20, 20, 100, 25);
    mReturnButton->AddListener(this);
    
    //TODO
    //Player's name
    
    //Difficulty
    
    //List
    
    //Start game
    mStartButton = new NiceComponent("Start New Game");
    mStartButton->SetTextToDisplay("COMMENCER");
    mStartButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mStartButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mStartButton->setBounds(200, 330, 200, 55);
    mStartButton->AddListener(this);
    //mStartButton->SetFont(FontUtils::OrangeJuice);
    
    addAndMakeVisible(mReturnButton);
    addAndMakeVisible(mStartButton);

    
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
    inG.drawText("Nouvelle Partie", 0, 0, getWidth(), 150, juce::Justification::centred);
}


void NewPlayerMenu::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mReturnButton){
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        if(parent)
            parent->DisplayMainMenu();
    }
    else if(inComp == mStartButton){
        
        //TODO : fill the player attributes with the missing data
        mNewPlayerAttributes.mName = "test";
        mNewPlayerAttributes.mReputation = 0.f;
        mNewPlayerAttributes.mChoppes.resize(0);
        
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        if(parent)
            parent->LaunchNewGame(mNewPlayerAttributes);
        
    }
}
