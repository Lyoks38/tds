//
//  NewPlayerMenu.h
//  TDS
//
//  Created by Corentin Comte on 14/11/2016.
//
//

#ifndef NewPlayerMenu_h
#define NewPlayerMenu_h

#include "GuiUtils.h"
#include "Player.h"
#include "Utils/NiceComponentListener.h"
#include "Utils/NiceButton.h"



class NewPlayerMenu: public juce::Component, public NiceComponentListener
{
  
public:
    
    NewPlayerMenu();
    
    ~NewPlayerMenu();
    
    virtual void paint(juce::Graphics& inG) override;
    
    virtual void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    void EnableLists(bool inEnabled);
    
    std::string mDifficultyExplained = "";
    
    juce::Font mMainFont;
    
    NiceComponent* mReturnButton;
    NiceComponent* mStartButton;
    juce::TextEditor* mPlayerNameEditor;
    
    //Difficulty buttons
    NiceButton* mPolardButton;
    NiceButton* mAmiButton;
    NiceButton* mListeButton;
    NiceButton* mMorueButton;
    
    //List Buttons
    NiceButton* mFoxButton;
    NiceButton* mTopButton;
    NiceButton* mPlayButton;
    NiceButton* mWhoopButton;
    NiceButton* mPulpButton;
    NiceButton* mSpaceButton;
    NiceButton* mPeufButton;
    NiceButton* mFrapButton;
    NiceButton* mPearlButton;


    
    Player::PlayerAttributes mNewPlayerAttributes;

};

#endif /* NewPlayerMenu_h */
