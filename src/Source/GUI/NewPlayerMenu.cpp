//
//  NewPlayerMenu.cpp
//  TDS
//
//  Created by Corentin Comte on 14/11/2016.
//
//

#include "NewPlayerMenu.h"
#include "FontUtils.h"
#include "../MainComponent.h"



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
    mPolardButton = new NiceButton("Polard Button");
    mPolardButton->SetTextToDisplay("Polard");
    mPolardButton->SetBgColor(juce::Colour (0xff001F36).brighter(0.2f));
    mPolardButton->SetBgHoverColor(juce::Colour (0xff001F36).brighter(0.3f));
    mPolardButton->SetActiveBgColor(juce::Colour (0xff001F36).brighter(0.7f));
    mPolardButton->SetActiveBgHoverColor(juce::Colour (0xff001F36).brighter(0.7f));
    mPolardButton->SetTextColor(juce::Colours::white);
    mPolardButton->SetTextHoverColor(juce::Colours::white);
    mPolardButton->SetActiveTextColor(juce::Colours::white);
    mPolardButton->SetActiveTextHoverColor(juce::Colours::white);
    mPolardButton->setBounds(70, 280, 100, 30);
    mPolardButton->AddListener(this);
    
    mAmiButton = new NiceButton("Ami de liste Button");
    mAmiButton->SetTextToDisplay("Ami de liste");
    mAmiButton->SetBgColor(juce::Colour (0xff001F36).brighter(0.2f));
    mAmiButton->SetBgHoverColor(juce::Colour (0xff001F36).brighter(0.3f));
    mAmiButton->SetActiveBgColor(juce::Colour (0xff001F36).brighter(0.7f));
    mAmiButton->SetActiveBgHoverColor(juce::Colour (0xff001F36).brighter(0.7f));
    mAmiButton->SetTextColor(juce::Colours::white);
    mAmiButton->SetTextHoverColor(juce::Colours::white);
    mAmiButton->SetActiveTextColor(juce::Colours::white);
    mAmiButton->SetActiveTextHoverColor(juce::Colours::white);
    mAmiButton->setBounds(200, 280, 100, 30);
    mAmiButton->AddListener(this);
    
    mListeButton = new NiceButton("Liste Button");
    mListeButton->SetTextToDisplay("Liste");
    mListeButton->SetBgColor(juce::Colour (0xff001F36).brighter(0.2f));
    mListeButton->SetBgHoverColor(juce::Colour (0xff001F36).brighter(0.3f));
    mListeButton->SetActiveBgColor(juce::Colour (0xff001F36).brighter(0.7f));
    mListeButton->SetActiveBgHoverColor(juce::Colour (0xff001F36).brighter(0.7f));
    mListeButton->SetTextColor(juce::Colours::white);
    mListeButton->SetTextHoverColor(juce::Colours::white);
    mListeButton->SetActiveTextColor(juce::Colours::white);
    mListeButton->SetActiveTextHoverColor(juce::Colours::white);
    mListeButton->setBounds(330, 280, 100, 30);
    mListeButton->AddListener(this);
    
    mMorueButton = new NiceButton("Morue Button");
    mMorueButton->SetTextToDisplay("Morue");
    mMorueButton->SetBgColor(juce::Colour (0xff001F36).brighter(0.2f));
    mMorueButton->SetBgHoverColor(juce::Colour (0xff001F36).brighter(0.3f));
    mMorueButton->SetActiveBgColor(juce::Colour (0xff001F36).brighter(0.7f));
    mMorueButton->SetActiveBgHoverColor(juce::Colour (0xff001F36).brighter(0.7f));
    mMorueButton->SetTextColor(juce::Colours::white);
    mMorueButton->SetTextHoverColor(juce::Colours::white);
    mMorueButton->SetActiveTextColor(juce::Colours::white);
    mMorueButton->SetActiveTextHoverColor(juce::Colours::white);
    mMorueButton->setBounds(460, 280, 100, 30);
    mMorueButton->AddListener(this);
    
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
    addAndMakeVisible(mPolardButton);
    addAndMakeVisible(mAmiButton);
    addAndMakeVisible(mListeButton);
    addAndMakeVisible(mMorueButton);

    
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
    
    //Difficulty explained
    inG.setFont(juce::Font(14.f));
    inG.drawText(mDifficultyExplained, 610, 530, 190, 30, juce::Justification::topLeft);

}


void NewPlayerMenu::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mReturnButton){
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        if(parent)
            parent->DisplayMainMenu();
    }
    //Difficulty buttons
    else if(inComp == mPolardButton){
        mNewPlayerAttributes.mGenre = POLARD;
        mAmiButton->SetToggleState(false);
        mListeButton->SetToggleState(false);
        mMorueButton->SetToggleState(false);
        mDifficultyExplained = "C'est chaud, gros.";
    }
    else if(inComp == mAmiButton){
        mNewPlayerAttributes.mGenre = AMI_DE_LISTE;
        //TO DO : deselect other buttons & display some explaining text
        mPolardButton->SetToggleState(false);
        mListeButton->SetToggleState(false);
        mMorueButton->SetToggleState(false);
        mDifficultyExplained = "Ca passe.";
    }
    else if(inComp == mListeButton){
        mNewPlayerAttributes.mGenre = LISTE;
        //TO DO : deselect other buttons & display some explaining text
        mPolardButton->SetToggleState(false);
        mAmiButton->SetToggleState(false);
        mMorueButton->SetToggleState(false);
        mDifficultyExplained = "Au calme.";
    }
    else if(inComp == mMorueButton){
        mNewPlayerAttributes.mGenre = MORUE;
        //TO DO : deselect other buttons & display some explaining text
        mPolardButton->SetToggleState(false);
        mAmiButton->SetToggleState(false);
        mListeButton->SetToggleState(false);
        mDifficultyExplained="On va niquer ce soir !";
    }
    //Start Button
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
