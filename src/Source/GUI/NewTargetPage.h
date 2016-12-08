//
//  NewTargetPage.h
//  TDS
//
//  Created by Corentin Comte on 08/12/2016.
//
//

#ifndef NewTargetPage_h
#define NewTargetPage_h

#include "GuiUtils.h"
#include "Utils/NiceComponent.h"
#include "Utils/NiceComponentListener.h"
#include "../Girl.h"


class NewTargetPage: public juce::Component, public NiceComponentListener
{
    
public:
    
    NewTargetPage();
    
    ~NewTargetPage();
    
    bool LoadTargetInfos(const Girl inTarget, const juce::Image inEventBanner, const std::string inEventName);
    
    void paint(juce::Graphics& inG) override;
    
protected:
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
private:
    
    juce::Image mBanner;
    std::string mEventName;
    
    std::string mTargetName;
    GirlGenre mGenre;
    List mList;
        
    NiceComponent* mStartCombatButton;
    
    juce::Font mMainFont;
    
};


#endif /* NewTargetPage_h */
