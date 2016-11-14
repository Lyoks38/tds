//
//  NewPlayerMenu.h
//  TDS
//
//  Created by Corentin Comte on 14/11/2016.
//
//

#ifndef NewPlayerMenu_h
#define NewPlayerMenu_h

class NiceComponent;

#include "GuiUtils.h"
#include "Utils/NiceComponent.h"

class NewPlayerMenu: public juce::Component
{
  
public:
    
    NewPlayerMenu();
    
    ~NewPlayerMenu(){};
    
     virtual void paint(juce::Graphics& inG) override;
    
private:
    
    juce::Font mMainFont;

};

#endif /* NewPlayerMenu_h */
