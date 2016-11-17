//
//  MainMenu.cpp
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#include "MainMenu.h"
#include "Utils/FontUtils.h"

MainMenu::MainMenu(): juce::Component("Main Menu")
{
    mNewGameButton = new NiceComponent("New Game Button");
    mLoadGameButton = new NiceComponent("Load Game Button");
    
    mNewGameButton->SetTextToDisplay("Nouvelle Partie");
    mLoadGameButton->SetTextToDisplay("Charger Partie");
    
    mNewGameButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mNewGameButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mNewGameButton->SetTextColor(juce::Colours::white);
    mNewGameButton->SetTextHoverColor(juce::Colour(230, 230, 230));


    mLoadGameButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mLoadGameButton->SetTextColor(juce::Colours::white);
    mLoadGameButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    
    mNewGameButton->setBounds(250, 200, 300, 70);
    mLoadGameButton->setBounds(250, 320, 300, 70);
    
    mNewGameButton->AddListener(this);
    
    addAndMakeVisible(mNewGameButton);
    addAndMakeVisible(mLoadGameButton);
    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(75.f);
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

void MainMenu::onNiceComponentClicked(NiceComponent *inComp){
    
    if(inComp == mNewGameButton){
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        if(parent)
            parent->DisplayNewPlayer();
    }
    
}

