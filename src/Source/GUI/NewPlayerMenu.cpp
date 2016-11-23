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
    mFoxButton = new NiceButton("Fox Button");
    mFoxButton->SetTextToDisplay("FOX");
    mFoxButton->SetBgColor(juce::Colour (0x885d2a80));
    mFoxButton->SetBgHoverColor(juce::Colour (0xbb5d2a80));
    mFoxButton->SetActiveBgColor(juce::Colour (0xff5d2a80));
    mFoxButton->SetActiveBgHoverColor(juce::Colour (0xff5d2a80));
    mFoxButton->SetTextColor(juce::Colour(0xffffe04c));
    mFoxButton->SetTextHoverColor(juce::Colour(0xffffe04c));
    mFoxButton->SetActiveTextColor(juce::Colour(0xffffe04c));
    mFoxButton->SetActiveTextHoverColor(juce::Colour(0xffffe04c));
    mFoxButton->setBounds(70, 400, 60, 30);
    mFoxButton->AddListener(this);
    
    mTopButton = new NiceButton("Top Button");
    mTopButton->SetTextToDisplay("TOP");
    mTopButton->SetBgColor(juce::Colour (0x8814a038));
    mTopButton->SetBgHoverColor(juce::Colour (0xbb14a038));
    mTopButton->SetActiveBgColor(juce::Colour (0xff14a038));
    mTopButton->SetActiveBgHoverColor(juce::Colour (0xff14a038));
    mTopButton->SetTextColor(juce::Colours::white);
    mTopButton->SetTextHoverColor(juce::Colours::white);
    mTopButton->SetActiveTextColor(juce::Colours::white);
    mTopButton->SetActiveTextHoverColor(juce::Colours::white);
    mTopButton->setBounds(140, 400, 60, 30);
    mTopButton->AddListener(this);
    
    mPlayButton = new NiceButton("Play Button");
    mPlayButton->SetTextToDisplay("PLAY");
    mPlayButton->SetBgColor(juce::Colour (0x88e71247));
    mPlayButton->SetBgHoverColor(juce::Colour (0xbbe71247));
    mPlayButton->SetActiveBgColor(juce::Colour (0xffe71247));
    mPlayButton->SetActiveBgHoverColor(juce::Colour (0xffe71247));
    mPlayButton->SetTextColor(juce::Colour(0xffcccccc));
    mPlayButton->SetTextHoverColor(juce::Colour(0xffcccccc));
    mPlayButton->SetActiveTextColor(juce::Colour(0xffcccccc));
    mPlayButton->SetActiveTextHoverColor(juce::Colour(0xffcccccc));
    mPlayButton->setBounds(210, 400, 60, 30);
    mPlayButton->AddListener(this);
    
    mWhoopButton = new NiceButton("Whhop Button");
    mWhoopButton->SetTextToDisplay("WHOOP");
    mWhoopButton->SetBgColor(juce::Colour (0x883769ba));
    mWhoopButton->SetBgHoverColor(juce::Colour (0xbb3769ba));
    mWhoopButton->SetActiveBgColor(juce::Colour (0xff3769ba));
    mWhoopButton->SetActiveBgHoverColor(juce::Colour (0xff3769ba));
    mWhoopButton->SetTextColor(juce::Colours::white);
    mWhoopButton->SetTextHoverColor(juce::Colours::white);
    mWhoopButton->SetActiveTextColor(juce::Colours::white);
    mWhoopButton->SetActiveTextHoverColor(juce::Colours::white);
    mWhoopButton->setBounds(280, 400, 60, 30);
    mWhoopButton->AddListener(this);

    
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
    addAndMakeVisible(mFoxButton);
    addAndMakeVisible(mTopButton);
    addAndMakeVisible(mPlayButton);
    addAndMakeVisible(mWhoopButton);

    
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
    inG.drawText(mDifficultyExplained, 590, 280, 190, 30, juce::Justification::centredLeft);

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
        EnableLists(false);
        repaint();
    }
    else if(inComp == mAmiButton){
        mNewPlayerAttributes.mGenre = AMI_DE_LISTE;
        mPolardButton->SetToggleState(false);
        mListeButton->SetToggleState(false);
        mMorueButton->SetToggleState(false);
        mDifficultyExplained = "Ca passe.";
        EnableLists(true);
        repaint();
    }
    else if(inComp == mListeButton){
        mNewPlayerAttributes.mGenre = LISTE;
        mPolardButton->SetToggleState(false);
        mAmiButton->SetToggleState(false);
        mMorueButton->SetToggleState(false);
        mDifficultyExplained = "Au calme.";
        EnableLists(true);
        repaint();
    }
    else if(inComp == mMorueButton){
        mNewPlayerAttributes.mGenre = MORUE;
        mPolardButton->SetToggleState(false);
        mAmiButton->SetToggleState(false);
        mListeButton->SetToggleState(false);
        mDifficultyExplained="On va niquer ce soir !";
        EnableLists(false);
        repaint();
    }
    //Lists
    else if(inComp == mFoxButton){
        mNewPlayerAttributes.mListe = FOX;
        mTopButton->SetToggleState(false);
        mPlayButton->SetToggleState(false);
        mWhoopButton->SetToggleState(false);
    }
    else if(inComp == mTopButton){
        mNewPlayerAttributes.mListe = TOP;
        mFoxButton->SetToggleState(false);
        mPlayButton->SetToggleState(false);
        mWhoopButton->SetToggleState(false);
    }
    else if(inComp == mPlayButton){
        mNewPlayerAttributes.mListe = PLAY;
        mFoxButton->SetToggleState(false);
        mTopButton->SetToggleState(false);
        mWhoopButton->SetToggleState(false);
    }
    else if(inComp == mWhoopButton){
        mNewPlayerAttributes.mListe = WHOOP;
        mFoxButton->SetToggleState(false);
        mTopButton->SetToggleState(false);
        mPlayButton->SetToggleState(false);
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


void NewPlayerMenu::EnableLists(bool inEnabled)
{
    mFoxButton->setEnabled(inEnabled);
    mTopButton->setEnabled(inEnabled);
    mPlayButton->setEnabled(inEnabled);
    mWhoopButton->setEnabled(inEnabled);
}

