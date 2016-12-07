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
    
    Event(){};
    
    Event(const std::string inName, bool inIsKfet, const juce::Image inBanner, const std::string inLocation);
    
    Event(Event const &other);
    
    ~Event(){};
    
    std::string GetName() const { return mName; }
    bool IsKfet() const { return mIsKfet; }
    std::vector<Girl> GetTargets() const { return mPossibleTargets; }
    juce::Image GetBanner() const { return mBanner; }
    std::string GetLocation() const { return mLocation; }
    
    void SetBanner(juce::Image inImage) { mBanner = inImage; }
    void SetTargets(std::vector<Girl> inTargets) { mPossibleTargets = inTargets; }
    
private:
    
    std::string mName;
    
    bool mIsKfet;
    
    std::vector<Girl> mPossibleTargets;
    
    juce::Image mBanner;
    
    std::string mLocation;
};

#endif /* Event_h */
