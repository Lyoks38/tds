//
//  ScenarioManager.cpp
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#include "ScenarioManager.h"
#include "ImageUtils.h"


ScenarioManager::ScenarioManager()
{
    LoadGirls();
    LoadEvents();
    LoadAttacks();
    
    mCombatManager.reset(new CombatManager());
}


ScenarioManager::~ScenarioManager()
{
    mCombatManager.reset(nullptr);
    mPlayer.reset(nullptr);
}

void ScenarioManager::GoToNextEvent()
{
    mCurrentEvent++;
    
    if(mCurrentEvent >= static_cast<int>(mEvents.size())){
        DisplayResults();
        mCombatManager.reset(nullptr);
        mCurrentEvent = -1;
    }
    else{
        mMainGUI->DisplayNewEvent(mEvents[mCurrentEvent]);
        mCombatManager->LoadNewCombat(mEvents[mCurrentEvent]);
    }
}


void ScenarioManager::LoadEvents()
{
    mEvents.resize(0);
    
    //Event("Barbecue GC", true, ImageUtils::BarbecueGC);
    
    mEvents.push_back(Event("Barbecue GC", true, ImageUtils::BarbecueGC));
}
