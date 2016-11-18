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
    mReturnButton->SetTextToDisplay("Retour");
    mReturnButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mReturnButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mReturnButton->SetTextColor(juce::Colours::white);
    mReturnButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mReturnButton->setBounds(20, 20, 70, 25);
    mReturnButton->AddListener(this);
    
    //TODO
    //Player's name
    mPlayerNameEditor = new juce::TextEditor("Player Name Editor");
    mPlayerNameEditor->setBounds(70, 190, 200, 23);
    
    //Difficulty
    mPolardButton = new TDS::Button("Polard Button");
    mPolardButton->SetTextToDisplay("Polard");
    mPolardButton->SetBgColor(juce::Colour (0xff001F36).brighter(0.2f));
    mPolardButton->SetBgHoverColor(juce::Colour (0xff001F36).brighter(0.3f));
    mPolardButton->SetActiveBgColor(juce::Colour (0xff001F36).brighter(0.4f));
    mPolardButton->SetTextColor(juce::Colours::white);
    mPolardButton->SetTextHoverColor(juce::Colours::white);

    
    
    //List
    
    //Start game
    mStartButton = new NiceComponent("Start New Game");
    mStartButton->SetTextToDisplay("COMMENCER");
    mStartButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mStartButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mStartButton->SetTextColor(juce::Colours::white);
    mStartButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mStartButton->setBounds(200, 530, 400, 55);
    mStartButton->AddListener(this);
    //mStartButton->SetFont(FontUtils::OrangeJuice);
    
    addAndMakeVisible(mReturnButton);
    addAndMakeVisible(mStartButton);
    addAndMakeVisible(mPlayerNameEditor);

    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(50.f);
}

NewPlayerMenu::~NewPlayerMenu()
{
    removeAllChildren();
}

void NewPlayerMenu::paint(juce::Graphics& inG)
{
    //Header
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText("Nouvelle Partie", 0, 0, getWidth(), 150, juce::Justification::centred);
    
    //Labels
    inG.setFont(juce::Font(20.f));
    inG.drawText("Entrez votre nom", 65, 150, 240, 30, juce::Justification::topLeft);
    inG.drawText("Niveau de difficulte", 65, 240, 240, 30, juce::Justification::topLeft);
    inG.drawText("Choisissez votre liste", 65, 360, 240, 30, juce::Justification::topLeft);

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
        mNewPlayerAttributes.mName = mPlayerNameEditor->getText().toStdString();
        mNewPlayerAttributes.mReputation = 0.f;
        mNewPlayerAttributes.mChoppes.resize(0);
        
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        if(parent)
            parent->LaunchNewGame(mNewPlayerAttributes);
        
    }
}
