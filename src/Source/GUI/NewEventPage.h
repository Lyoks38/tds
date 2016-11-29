//
//  NewEventPage.h
//  TDS
//
//  Created by Corentin Comte on 29/11/2016.
//
//

#ifndef NewEventPage_h
#define NewEventPage_h

#include "GuiUtils.h"
#include "Utils/NiceComponent.h"
#include "Utils/NiceComponentListener.h"
#include "../Event.h"


class NewEventPage: public juce::Component, public NiceComponentListener
{
  
public:
    
    NewEventPage();
    
    ~NewEventPage();
    
    bool LoadEventInfos(const Event inEvent);
    
    void paint(juce::Graphics& inG) override;
    
protected:
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    juce::Image* mBanner;
    std::string mEventName;
    bool mIsKfet;
    
    NiceComponent* mStartEventButton;
    
    juce::Font mMainFont;
    
};

#endif /* NewEventPage_h */
