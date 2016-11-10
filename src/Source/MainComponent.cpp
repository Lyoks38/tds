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
}

MainContentComponent::~MainContentComponent()
{
    mEngine.reset(nullptr);
    
    removeChildComponent(mMainMenu.get());
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    /*g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Ceci est le premier build du jeu TDS !", getLocalBounds(), Justification::centred, true);*/
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
