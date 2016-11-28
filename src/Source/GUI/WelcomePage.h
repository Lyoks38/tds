//
//  WelcomePage.h
//  TDS
//
//  Created by Corentin Comte on 24/11/2016.
//
//

#ifndef WelcomePage_h
#define WelcomePage_h

#include "GuiUtils.h"
#include "Utils/NiceComponent.h"
#include "Utils/NiceComponentListener.h"

class WelcomePage: public juce::Component, public NiceComponentListener
{
  
public:
    
    WelcomePage(const std::string& inPlayerName);
    
    ~WelcomePage();
    
    virtual void paint(juce::Graphics& inG) override;
    
    static const std::string kIntroText;
    static const std::string kGoalsText;
    static const std::string kGameplayText;
    static const std::string kCommandeText;
    static const std::string kStartingText;



protected:
    
    virtual void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    juce::Font mMainFont;
    
    NiceComponent* mNextButton;
    NiceComponent* mStartButton;
    std::string mPlayerName;
    
    //TODO : make sure we don't go too far
    int mCurrentPage = 0;
    enum{
        INTRO = 0,
        GOALS,
        GAMEPLAY,
        COMMANDE,
        START
    };
    
};


#endif /* WelcomePage_h */
