//
//  ScenarioManager.cpp
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#include "ScenarioManager.h"



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
        mCurrentEvent = 0;
    }
    else{
        mMainGUI->DisplayNewEvent(mEvents[mCurrentEvent]);
        mCombatManager->LoadNewCombat(mEvents[mCurrentEvent]);
    }
}
