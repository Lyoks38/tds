//
//  MainMenu.cpp
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#include "MainMenu.h"

MainMenu::MainMenu(): juce::Component("Main Menu")
{
    mNewGameButton = new Button("New Game Button");
    mLoadGameButton = new Button("Load Game Button");
    
    mNewGameButton->setButtonText("Start New Game");
    mLoadGameButton->setButtonText("Load Saved Game");
    
    addAndMakeVisible(mNewGameButton);
    addAndMakeVisible(mLoadGameButton);
}

void MainMenu::resized()
{
    int w = getWidth();
    int h = getHeight();
    
    mNewGameButton->setBounds(w/3, h/6, w/3, h/3);
    mLoadGameButton->setBounds(w/3, 4*h/6, w/3, h/3);
}

void MainMenu::paint(juce::Graphics& inG)
{
    inG.fillAll(juce::Colour (0xffFF1F36));
}

