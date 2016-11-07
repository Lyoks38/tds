//
//  MainMenu.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef MainMenu_h
#define MainMenu_h

class Button;

#include "GuiUtils.h"
#include "Utils/Button.h"



/*class NewGameButton : public juce::Button
{
    
public:
    
    NewGameButton();
    
    ~NewGameButton();
    
};

class LoadGameButton : public juce::Button
{
    
};*/




//Main Menu window
class MainMenu : public juce::Component
{

public:
    
    MainMenu();
    
    ~MainMenu(){};
    
    virtual void paint(juce::Graphics& inG) override;
    
    virtual void resized() override;
    
    void GoToNewGameMenu(){};
    
private:
    
    Button* mNewGameButton = nullptr;
    Button* mLoadGameButton = nullptr;
};

#endif /* MainMenu_h */
