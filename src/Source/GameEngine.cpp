//
//  GameEngine.cpp
//  TDS
//
//  Created by Corentin Comte on 05/06/2016.
//
//

#include "GameEngine.h"



GameEngine::GameEngine()
{
    mScenarioManager.reset(new ScenarioManager());
}

GameEngine::~GameEngine()
{
    mScenarioManager.reset(nullptr);
    //mMainGUI.reset(nullptr); //error when closing app
}

void GameEngine::AttachGUI(MainContentComponent *inGUI)
{
    mMainGUI.reset(inGUI);
    
    mScenarioManager->AttachToGUI(inGUI);
}
