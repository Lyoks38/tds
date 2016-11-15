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
#include "GUI/GuiHeader.h"


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

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
    
    std::unique_ptr<GameEngine> mEngine;
    
    std::unique_ptr<MainMenu> mMainMenu = nullptr;
    std::unique_ptr<NewPlayerMenu> mNewPlayerMenu = nullptr;
    
    
    juce::Component* mCurrentPage = nullptr; //maybe not useful
};


#endif  // MAINCOMPONENT_H_INCLUDED
