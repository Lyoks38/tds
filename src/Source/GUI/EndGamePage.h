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
    
    EndGamePage();
    
    ~EndGamePage();
    
    void LoadPlayerInfos(Player* inPlayer);
    
    void paint(juce::Graphics& inG) override;
    
protected:
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    std::string mPlayerName;
    PlayerGenre mPlayerGenre;
    List mPlayerList;
    int mNbChoppe;
    
    NiceComponent* mReturnToMainMenuButton;
    
    juce::Font mMainFont;
    
};


#endif /* EndGamePage_h */
