/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

class GameEngine;

#include "../JuceLibraryCode/JuceHeader.h"
#include "GameEngine.h"
#include "Player.h"
#include "GUI/GuiHeader.h"
#include "Event.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
    
    //Display methods
    bool DisplayMainMenu();
    bool DisplayNewPlayer();
    bool DisplayNewEvent(const Event inEvent);
    bool DisplayNewTarget(const Girl inTarget){};
    
    bool LaunchNewGame(Player::PlayerAttributes inAttributes);

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
    
    std::unique_ptr<GameEngine> mEngine;
    
    std::unique_ptr<MainMenu> mMainMenu = nullptr;
    std::unique_ptr<NewPlayerMenu> mNewPlayerMenu = nullptr;
    std::unique_ptr<WelcomePage> mWelcomePage = nullptr;
    
    
    juce::Component* mCurrentPage = nullptr; //maybe not useful
};


#endif  // MAINCOMPONENT_H_INCLUDED
