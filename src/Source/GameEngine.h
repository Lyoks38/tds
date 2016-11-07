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

#include "MainComponent.h"
#include "ScenarioManager.h"

class GameEngine {
    
    
public:
    GameEngine();
    
    ~GameEngine();
    
    void PrepareToClose();
    
    void AttachGUI(MainContentComponent* inGUI);
    
    void SaveGame(){};
    void LoadSavedGame(){};
    
private:
    
    std::unique_ptr<ScenarioManager> mScenarioManager = nullptr;
    
    MainContentComponent* mMainGUI = nullptr;
    
};
