//
//  GameEngine.h
//  TDS
//
//  Created by Corentin Comte on 05/06/2016.
//
//
#pragma once

class MainContentComponent;
class ScenarioManager;
class CombatManager;

//#include "MainComponent.h"
#include "ScenarioManager.h"

class GameEngine {
    
    
public:
    GameEngine();
    
    ~GameEngine();
    
    void PrepareToClose();
    
    ScenarioManager* GetScenarioManager() const { return mScenarioManager.get(); }
    CombatManager* GetCombatManager() const { return mScenarioManager->GetCombatManager(); }
    
    Player* GetPlayer() const { return mScenarioManager->GetPlayer(); }
    
    void AttachGUI(MainContentComponent* inGUI);
    
    void SaveGame(){};
    void LoadSavedGame(){};
    
    void NewGame(Player::PlayerAttributes inAttributes);
    
    void Reset();
    
private:
    
    std::unique_ptr<ScenarioManager> mScenarioManager = nullptr;
    
    MainContentComponent* mMainGUI = nullptr;
    
};
