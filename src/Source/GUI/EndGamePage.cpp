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
        if(parent)
            parent->DisplayMainMenu();
    }
}

void EndGamePage::LoadPlayerInfos(Player *inPlayer, EndGame inGame, ScoreData inScore)
{
    mPlayerName = inPlayer->GetName();
    mPlayerList = inPlayer->GetListe();
    mPlayerGenre = inPlayer->GetGenre();
    
    mNbChoppesTotal = inScore.nbChoppeTotal;
    mNbChoppesPerso = inScore.nbChoppePerso;
    mNbEventPlayed = inScore.nbEventPlayed;
    mNbGirlMet = inScore.nbGirlMet;
    
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
    inG.drawMultiLineText("Felicitations " + mPlayerName + " ! " + kClassicText, 200, 170, 400);
    
    inG.setFont(Font(20.f));
    inG.drawText("Tu as participe a " + std::to_string(mNbEventPlayed) + " evenements.", 200, 240, 400, 50, juce::Justification::centred);
    inG.drawText("Tu as rencontre " + std::to_string(mNbGirlMet) + " filles en tout.", 200, 270, 400, 50, juce::Justification::centred);
    inG.drawText("Tu as choppe " + std::to_string(mNbChoppesTotal) + " fois au total.", 200, 300, 400, 50, juce::Justification::centred);
    inG.drawText("Tu as choppe " + std::to_string(mNbChoppesPerso) + " filles differentes.", 200, 330, 400, 50, juce::Justification::centred);
    
    int reputation = mNbChoppesTotal * 5;
    int reputationMax = mNbGirlMet * 5;
    
    inG.drawText("Reputation : " + std::to_string(reputation) + " / " + std::to_string(reputationMax), 200, 360, 400, 50, juce::Justification::centred);

    float ratio = static_cast<float>(reputation) / reputationMax;
    
    std::string finalRes;
    if(ratio < 0.25f)
        finalRes = kClassicRatio1;
    else if(ratio < 0.5f)
        finalRes = kClassicRatio2;
    else if(ratio < 0.75f)
        finalRes = kClassicRatio3;
    else if(ratio < 1.f)
        finalRes = kClassicRatio4;
    
    inG.drawText("Grade final", 200, 400, 400, 50, juce::Justification::centred);
    inG.setFont(mMainFont.withHeight(40.f));
    inG.drawText(finalRes, 200, 440, 400, 75, juce::Justification::centred);
}

void EndGamePage::PaintDefeatResult(juce::Graphics& inG)
{
    
}

void EndGamePage::PaintVictoryResult(juce::Graphics& inG)
{
    
}


const std::string EndGamePage::kClassicText = "Tu viens de passer une année entière à Phelma, et tu n'as pas chômé ! Voyons voir tes résultats.";
const std::string EndGamePage::kClassicRatio1 = "Puceau";
const std::string EndGamePage::kClassicRatio2 = "Batifoleur";
const std::string EndGamePage::kClassicRatio3 = "Beau gosse";
const std::string EndGamePage::kClassicRatio4 = "Dieu sur Terre";
