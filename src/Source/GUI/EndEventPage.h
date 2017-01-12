//
//  EndEventPage.h
//  TDS
//
//  Created by Corentin Comte on 12/01/2017.
//
//

#ifndef EndEventPage_h
#define EndEventPage_h

#include "GuiUtils.h"
#include "Utils/NiceComponent.h"
#include "Utils/NiceComponentListener.h"
#include "../Event.h"


class EndEventPage: public juce::Component, public NiceComponentListener
{
    
public:
    
    EndEventPage();
    
    ~EndEventPage();
    
    bool LoadEventInfos(const Event inEvent, int inChoppes, bool inWasNotFailed);
    
    void paint(juce::Graphics& inG) override;
    
protected:
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    juce::Image mBanner;
    std::string mEventName;
    bool mIsKfet;
    std::string mLocation;
    bool mWasNotFailed;
    
    int mNbTargets;
    int mNbChoppes;
    
    NiceComponent* mNextEventButton;
    
    juce::Font mMainFont;
    
};



#endif /* EndEventPage_h */
