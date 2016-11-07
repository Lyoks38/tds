//
//  MainMenu.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef MainMenu_h
#define MainMenu_h

#include "GuiUtils.h"



class NewGameButton : public juce::Button
{
    
};

class LoadGameButton : public juce::Button
{
    
};




//Main Menu window
class MainMenu : public juce::Component
{

public:
    
    MainMenu(): juce::Component("Main Menu"){};
    
    ~MainMenu(){};
    
    virtual void paint(juce::Graphics& inG) override;
};

#endif /* MainMenu_h */
