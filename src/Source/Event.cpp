//
//  Event.cpp
//  TDS
//
//  Created by Corentin Comte on 28/11/2016.
//
//

#include "Event.h"

Event::Event(const std::string inName, bool inIsKfet, juce::Image inBanner)
{
    mName = inName;
    mIsKfet = inIsKfet;
    mBanner = inBanner;
}
