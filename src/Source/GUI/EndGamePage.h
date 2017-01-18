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

class EndGamePage: public juce::Component, public NiceComponentListener
{
    
public:
    
    enum EndGame{
        CLASSIC = 0,
        DEFEAT,
        VICTORY
    } typedef EndGame;
    
    EndGamePage();
    
    ~EndGamePage();
    
    void LoadPlayerInfos(Player* inPlayer, EndGame inGame);
    
    void paint(juce::Graphics& inG) override;
    
    static const std::string kClassicText1;
    
protected:
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    std::string mPlayerName;
    PlayerGenre mPlayerGenre;
    List mPlayerList;
    int mNbChoppesTotal;
    int mNbChoppesPerso;
    
    EndGame mEnd = CLASSIC;
    
    NiceComponent* mReturnToMainMenuButton;
    
    void PaintClassicResult(juce::Graphics& inG);
    void PaintDefeatResult(juce::Graphics& inG);
    void PaintVictoryResult(juce::Graphics& inG);
    
    juce::Font mMainFont;
    
};


#endif /* EndGamePage_h */
