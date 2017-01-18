//
//  EndGamePage.cpp
//  TDS
//
//  Created by Corentin Comte on 17/01/2017.
//
//

#include "EndGamePage.h"
#include "FontUtils.h"
#include "MainComponent.h"

EndGamePage::EndGamePage():
juce::Component("End Game Page")
{
    mReturnToMainMenuButton = new NiceComponent("Go To Next Event");
    mReturnToMainMenuButton->SetTextToDisplay("CONTINUER");
    mReturnToMainMenuButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mReturnToMainMenuButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mReturnToMainMenuButton->SetTextColor(juce::Colours::white);
    mReturnToMainMenuButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mReturnToMainMenuButton->setBounds(200, 530, 400, 55);
    mReturnToMainMenuButton->AddListener(this);
    
    addAndMakeVisible(mReturnToMainMenuButton);
    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(60.f);
}

EndGamePage::~EndGamePage()
{
    deleteAllChildren();
}


void EndGamePage::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mReturnToMainMenuButton){
        MainContentComponent* parent = dynamic_cast<MainContentComponent*>(getParentComponent());
        /*if(parent)
            parent->GoToNextEvent();*/
    }
}

void EndGamePage::LoadPlayerInfos(Player *inPlayer, EndGame inGame)
{
    mPlayerName = inPlayer->GetName();
    mPlayerList = inPlayer->GetListe();
    mPlayerGenre = inPlayer->GetGenre();
    
    mNbChoppesTotal = 0;
    mNbChoppesPerso = 0;
    
    for(int i = 0; i < GIRL_DATABASE_SIZE; i ++){
        
        int choppe = inPlayer->GetNbChoppeForID(i);
        if(choppe > 0){
            mNbChoppesTotal += choppe;
            mNbChoppesPerso++;
        }
    }
    
    mEnd = inGame;
}

void EndGamePage::paint(juce::Graphics& inG)
{
    switch(mEnd){
        case CLASSIC:
            PaintClassicResult(inG);
            break;
        case DEFEAT:
            PaintDefeatResult(inG);
            break;
        case VICTORY:
            PaintVictoryResult(inG);
            break;
        default:
            break;
    }
}


void EndGamePage::PaintClassicResult(juce::Graphics& inG)
{
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText("Fin de la partie", 0, 0, getWidth(), 150, juce::Justification::centred);

    inG.setFont(Font(24.f));
    inG.drawMultiLineText("Felicitations " + mPlayerName + " ! " + kClassicText1, 200, 170, 400);
    
    inG.setFont(Font(16.f));
}

void EndGamePage::PaintDefeatResult(juce::Graphics& inG)
{
    
}

void EndGamePage::PaintVictoryResult(juce::Graphics& inG)
{
    
}


const std::string EndGamePage::kClassicText1 = "Tu viens de passer une année entière à Phelma, et tu n'as pas chômé ! Voyons voir tes résultats.";
