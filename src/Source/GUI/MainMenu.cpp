//
//  MainMenu.cpp
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#include "MainMenu.h"
#include "OrangeJuice.h"

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
    
    juce::Typeface::Ptr t = juce::Typeface::createSystemTypefaceFor(OrangeJuice::orange_juice_2_0_ttf, OrangeJuice::orange_juice_2_0_ttfSize);
    mMainFont = juce::Font(t);
    mMainFont.setHeight(50.f);
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
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText("TDS : Le Jeu !", 0, 0, getWidth(), 150, juce::Justification::centred);
}

