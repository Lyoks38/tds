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
    mMainGUI.reset(nullptr);
    mCombatManager.reset(nullptr);
    mPlayer.reset(nullptr);
}
