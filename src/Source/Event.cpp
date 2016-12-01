//
//  Event.cpp
//  TDS
//
//  Created by Corentin Comte on 28/11/2016.
//
//

#include "Event.h"

Event::Event(const std::string inName, bool inIsKfet, const juce::Image inBanner)
{
    mName = inName;
    mIsKfet = inIsKfet;
    mBanner = inBanner;
}

Event::Event(Event const& other)
{
    mName = other.GetName();
    mIsKfet = other.IsKfet();
    mBanner = other.GetBanner();
    mPossibleTargets = other.GetTargets();
}
