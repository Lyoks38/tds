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
}

void GameEngine::PrepareToClose()
{
    mMainGUI = nullptr; //error when closing app
}

void GameEngine::AttachGUI(MainContentComponent *inGUI)
{
    mMainGUI = inGUI;
    
    mScenarioManager->AttachToGUI(inGUI);
}

void GameEngine::Reset()
{
    if(mScenarioManager)
        mScenarioManager.reset(nullptr);
    
    mScenarioManager.reset(new ScenarioManager());
    mScenarioManager->AttachToGUI(mMainGUI);
}

////////////////////////////////////////////////////////////////////////
// Games
////////////////////////////////////////////////////////////////////////

void GameEngine::NewGame(Player::PlayerAttributes inAttributes)
{
    if(mScenarioManager != nullptr)
        mScenarioManager->LoadPlayer(inAttributes);
    
}
