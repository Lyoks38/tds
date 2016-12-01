//
//  Event.h
//  TDS
//
//  Created by Corentin Comte on 28/11/2016.
//
//

#ifndef Event_h
#define Event_h

#include "Girl.h"
#include "GUI/GuiUtils.h"


class Event
{
    
public:
    
    Event(const std::string inName, bool inIsKfet, const juce::Image inBanner);
    
    Event(Event const &other);
    
    ~Event(){};
    
    std::string GetName() const { return mName; }
    bool IsKfet() const { return mIsKfet; }
    std::vector<Girl> GetTargets() const { return mPossibleTargets; }
    juce::Image GetBanner() const { return mBanner; }
    
    void SetBanner(juce::Image inImage) { mBanner = inImage; }
    
private:
    
    std::string mName;
    
    bool mIsKfet;
    
    std::vector<Girl> mPossibleTargets;
    
    juce::Image mBanner;
};

#endif /* Event_h */
