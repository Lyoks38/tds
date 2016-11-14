/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);
    
    // Creates the engine and attach it to GUI
    mEngine.reset(new GameEngine());
    mEngine->AttachGUI(this);
    
    //We open the Main Menu of the game at opening
    mMainMenu.reset(new MainMenu());
    addAndMakeVisible(mMainMenu.get());
    mMainMenu->setBounds(0, 0, getWidth(), getHeight());
    //mMainMenu->SetParentComponent();
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
    g.drawText("A game by Lyoks, all rights reserved, 2016", 400, 380, 190, 20, juce::Justification::right);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}


bool MainContentComponent::DisplayNewPlayer()
{
    if(mNewPlayerMenu == nullptr){
        mNewPlayerMenu.reset(new NewPlayerMenu());
        addChildComponent(mNewPlayerMenu.get());
        mNewPlayerMenu->setBounds(0, 0, getWidth(), getHeight());
    }
    
    mMainMenu->setEnabled(false);
    mMainMenu->setVisible(false);
    
    mNewPlayerMenu->setEnabled(true);
    mNewPlayerMenu->setVisible(true);
    
    return true;
    
}
