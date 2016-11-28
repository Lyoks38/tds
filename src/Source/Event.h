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
    
    Event(std::string inName, bool inIsKfet, juce::Image* inBanner);
    
    ~Event();
    
    std::string GetName() const { return mName; }
    bool IsKfet() const { return mIsKfet; }
    std::vector<Girl> GetTargets() const { return mPossibleTargets; }
    juce::Image* GetBanner() const { return mBanner; }
    
private:
    
    std::string mName;
    
    bool mIsKfet;
    
    std::vector<Girl> mPossibleTargets;
    
    juce::Image* mBanner;
};

#endif /* Event_h */
