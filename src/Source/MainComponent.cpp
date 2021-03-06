/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (800, 600);
    
    // Creates the engine and attach it to GUI
    mEngine.reset(new GameEngine());
    mEngine->AttachGUI(this);
    
    ResetGame();
    //We open the Main Menu of the game at opening
    /*mMainMenu.reset(new MainMenu());
    addAndMakeVisible(mMainMenu.get());
    mMainMenu->setBounds(0, 0, getWidth(), getHeight());
    mCurrentPage = mMainMenu.get();*/
}

MainContentComponent::~MainContentComponent()
{
    mEngine.reset(nullptr);
    
    removeAllChildren();
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));
    
    g.setColour(juce::Colours::white);
    g.setFont(Font(8.f));
    g.drawText("A game by Lyoks, all rights reserved, 2016", 600, 580, 190, 20, juce::Justification::right);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}



//////////////////////////////////////////////////////////////////
// DISPLAY METHODS
/////////////////////////////////////////////////////////////////
bool MainContentComponent::DisplayNewPlayer()
{
    if(mNewPlayerMenu == nullptr){
        mNewPlayerMenu.reset(new NewPlayerMenu());
        addChildComponent(mNewPlayerMenu.get());
        mNewPlayerMenu->setBounds(0, 0, getWidth(), getHeight());
    }
    
    if(mCurrentPage != nullptr){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
    }
    mNewPlayerMenu->setEnabled(true);
    mNewPlayerMenu->setVisible(true);
    
    mCurrentPage = mNewPlayerMenu.get();
    
    return true;
}

bool MainContentComponent::DisplayMainMenu()
{
    if(mMainMenu == nullptr){
        mMainMenu.reset(new MainMenu());
        addChildComponent(mMainMenu.get());
        mMainMenu->setBounds(0, 0, getWidth(), getHeight());
    }
    
    if(mCurrentPage != nullptr){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
    }
    
    mMainMenu->setEnabled(true);
    mMainMenu->setVisible(true);
    
    mCurrentPage = mMainMenu.get();
    
    return true;
}


bool MainContentComponent::DisplayNewEvent(const Event inEvent)
{
    if(mNewEventPage == nullptr){
        
        mNewEventPage.reset(new NewEventPage());
        addChildComponent(mNewEventPage.get());
        mNewEventPage->setBounds(0, 0, getWidth(), getHeight());
    }
    
    mNewEventPage->LoadEventInfos(inEvent);
    
    if(mCurrentPage != nullptr){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
    }
    
    mNewEventPage->setEnabled(true);
    mNewEventPage->setVisible(true);
    
    mCurrentPage = mNewEventPage.get();
    
    return true;
}


bool MainContentComponent::DisplayNewTarget(const Girl inTarget, juce::Image inBanner, std::string inEventName)
{
    if(mNewTargetPage == nullptr){
        
        mNewTargetPage.reset(new NewTargetPage());
        addChildComponent(mNewTargetPage.get());
        mNewTargetPage->setBounds(0, 0, getWidth(), getHeight());
    }
    
    mNewTargetPage->LoadTargetInfos(inTarget, inBanner, inEventName);
    
    if(mCurrentPage != nullptr){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
    }
    
    mNewTargetPage->setEnabled(true);
    mNewTargetPage->setVisible(true);
    
    mCurrentPage = mNewTargetPage.get();
    
    return true;
}

bool MainContentComponent::DisplayCombatPage()
{
    if(mCombatPage == nullptr){
        
        mCombatPage.reset(new CombatPage());
        addChildComponent(mCombatPage.get());
        mCombatPage->setBounds(0, 0, getWidth(), getHeight());
    }
    
    if(!mCombatPage->IsCombatManagerLinked())
        mCombatPage->LinkToCombatManager(mEngine->GetCombatManager());
    
    if(mCurrentPage != nullptr){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
    }
    
    mCombatPage->LoadInfos();
    mCombatPage->DisplayAttacks();
    
    mCombatPage->setEnabled(true);
    mCombatPage->setVisible(true);
    
    mCurrentPage = mCombatPage.get();
    
    return true;
}


bool MainContentComponent::CombatPageDisplayResult(std::string inText, GoTo inWhereToGo)
{
    if(mCurrentPage != mCombatPage.get()){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
        mCombatPage->setEnabled(true);
        mCombatPage->setVisible(true);
        mCurrentPage = mCombatPage.get();
    }
    
    mCombatPage->DisplayResult(inText, inWhereToGo);
    
    return true;
}


bool MainContentComponent::DisplayEndEvent(const Event inEvent, int inNbChoppes, bool inWasNotFailed)
{
    if(mEndEventPage == nullptr){
        
        mEndEventPage.reset(new EndEventPage());
        addChildComponent(mEndEventPage.get());
        mEndEventPage->setBounds(0, 0, getWidth(), getHeight());
    }
    
    mEndEventPage->LoadEventInfos(inEvent, inNbChoppes, inWasNotFailed);
    
    if(mCurrentPage != nullptr){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
    }
    
    mEndEventPage->setEnabled(true);
    mEndEventPage->setVisible(true);
    
    mCurrentPage = mEndEventPage.get();
    
    return true;
}


bool MainContentComponent::DisplayEndGame(const ScoreData inData, const EndGame inGame)
{
    if(mEndGamePage == nullptr){
        
        mEndGamePage.reset(new EndGamePage());
        addChildComponent(mEndGamePage.get());
        mEndGamePage->setBounds(0, 0, getWidth(), getHeight());
    }
    
    mEndGamePage->LoadPlayerInfos(mEngine->GetPlayer(), inGame, inData);
    
    if(mCurrentPage != nullptr){
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
    }
    
    mEndGamePage->setEnabled(true);
    mEndGamePage->setVisible(true);
    
    mCurrentPage = mEndGamePage.get();
    
    return true;
}



///////////////////////////////////////////////////////////////
// Interactions with the engine


bool MainContentComponent::ResetGame()
{
    if(mEngine)
        mEngine->Reset();
    
    mCurrentPage = nullptr;
    mNewPlayerMenu.reset(nullptr);
    mWelcomePage.reset(nullptr);
    mNewEventPage.reset(nullptr);
    mNewTargetPage.reset(nullptr);
    mCombatPage.reset(nullptr);
    mEndEventPage.reset(nullptr);
    mEndGamePage.reset(nullptr);
    
    DisplayMainMenu();
    
    return true;
}


bool MainContentComponent::LaunchNewGame(Player::PlayerAttributes inAttributes)
{
    if(mEngine != nullptr){
        
        mEngine->NewGame(inAttributes);
        
        if(mWelcomePage == nullptr){
            mWelcomePage.reset(new WelcomePage(inAttributes.mName));
            addChildComponent(mWelcomePage.get());
            mWelcomePage->setBounds(0, 0, getWidth(), getHeight());
        }
        
        mCurrentPage->setEnabled(false);
        mCurrentPage->setVisible(false);
        
        mWelcomePage->setEnabled(true);
        mWelcomePage->setVisible(true);
        
        mCurrentPage = mWelcomePage.get();
        
        return true;
    }
    
    return false;
}


bool MainContentComponent::GoToNextEvent()
{
    if(mEngine != nullptr){
        
        mEngine->GetScenarioManager()->GoToNextEvent();
        
        return true;
    }
    
    return false;
}


bool MainContentComponent::GoToFirstTarget()
{
    if(mEngine != nullptr){
        
        mEngine->GetCombatManager()->GoToNextTarget();
        
        return true;
    }
    
    return false;
}

