//
//  EndGamePage.h
//  TDS
//
//  Created by Corentin Comte on 17/01/2017.
//
//

#ifndef EndGamePage_h
#define EndGamePage_h


#include "GuiUtils.h"
#include "Utils/NiceComponent.h"
#include "Utils/NiceComponentListener.h"
#include "Player.h"

enum EndGame{
    CLASSIC = 0,
    DEFEAT,
    VICTORY
} typedef EndGame;

class EndGamePage: public juce::Component, public NiceComponentListener
{
    
public:
    
    EndGamePage();
    
    ~EndGamePage();
    
    void LoadPlayerInfos(Player* inPlayer, EndGame inGame, ScoreData inScore);
    
    void paint(juce::Graphics& inG) override;
    
    static const std::string kClassicText;
    static const std::string kClassicRatio1;
    static const std::string kClassicRatio2;
    static const std::string kClassicRatio3;
    static const std::string kClassicRatio4;

protected:
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    std::string mPlayerName;
    PlayerGenre mPlayerGenre;
    List mPlayerList;
    
    int mNbChoppesTotal;
    int mNbChoppesPerso;
    int mNbEventPlayed;
    int mNbGirlMet;
    
    
    EndGame mEnd = CLASSIC;
    
    NiceComponent* mReturnToMainMenuButton;
    
    void PaintClassicResult(juce::Graphics& inG);
    void PaintDefeatResult(juce::Graphics& inG);
    void PaintVictoryResult(juce::Graphics& inG);
    
    juce::Font mMainFont;
    
};


#endif /* EndGamePage_h */
