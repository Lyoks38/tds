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
    mNewGameButton = new NiceComponent("New Game Button");
    mLoadGameButton = new NiceComponent("Load Game Button");
    
    mNewGameButton->SetTextToDisplay("Start New Game");
    mLoadGameButton->SetTextToDisplay("Load Saved Game");
    
    mNewGameButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mLoadGameButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    
    mNewGameButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mLoadGameButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    
    mNewGameButton->setBounds(200, 133, 200, 70);
    mLoadGameButton->setBounds(200, 266, 200, 70);
    
    addAndMakeVisible(mNewGameButton);
    addAndMakeVisible(mLoadGameButton);
}

MainMenu::~MainMenu()
{
    removeChildComponent(mNewGameButton);
    removeChildComponent(mLoadGameButton);
}

void MainMenu::resized()
{
}

void MainMenu::paint(juce::Graphics& inG)
{
}

