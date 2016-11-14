//
//  MainMenu.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef MainMenu_h
#define MainMenu_h

class NiceComponent;

#include "GuiUtils.h"
#include "Utils/NiceComponent.h"


//Main Menu window
class MainMenu : public juce::Component
{

public:
    
    MainMenu();
    
    ~MainMenu();
    
    virtual void paint(juce::Graphics& inG) override;
    
    virtual void resized() override;
    
    void GoToNewGameMenu(){};
        
protected:
    
    virtual void mouseDown(const juce::MouseEvent& e) override;
    
private:
    
    NiceComponent* mNewGameButton = nullptr;
    NiceComponent* mLoadGameButton = nullptr;
    
    juce::Font mMainFont;
    
};

#endif /* MainMenu_h */
