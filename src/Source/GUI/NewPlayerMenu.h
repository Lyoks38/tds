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
#include "Utils/NiceComponentListener.h"


class NewPlayerMenu: public juce::Component, public NiceComponentListener
{
  
public:
    
    NewPlayerMenu();
    
    ~NewPlayerMenu();
    
    virtual void paint(juce::Graphics& inG) override;
    
    virtual void onNiceComponentClicked(NiceComponent* inComp) override {};
    
private:
    
    juce::Font mMainFont;
    
    NiceComponent* mReturnButton;

};

#endif /* NewPlayerMenu_h */
