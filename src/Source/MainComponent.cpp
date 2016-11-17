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
    
    //We open the Main Menu of the game at opening
    mMainMenu.reset(new MainMenu());
    addAndMakeVisible(mMainMenu.get());
    mMainMenu->setBounds(0, 0, getWidth(), getHeight());
    mCurrentPage = mMainMenu.get();
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
    
    mCurrentPage->setEnabled(false);
    mCurrentPage->setVisible(false);
    
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
    
    mCurrentPage->setEnabled(false);
    mCurrentPage->setVisible(false);
    
    mMainMenu->setEnabled(true);
    mMainMenu->setVisible(true);
    
    mCurrentPage = mMainMenu.get();
    
    return true;
}


bool MainContentComponent::LaunchNewGame(Player::PlayerAttributes inAttributes)
{
    if(mEngine != nullptr){
        
        mEngine->NewGame(inAttributes);
        
        //TODO : open panel
    }
    
    return false;
}






