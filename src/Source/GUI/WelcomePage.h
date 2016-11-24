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
    
    WelcomePage();
    
    ~WelcomePage();
    
    virtual void paint(juce::Graphics& inG) override;

protected:
    
    virtual void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    juce::Font mMainFont;
    
    NiceComponent* mNextButton;
    
};


#endif /* WelcomePage_h */
