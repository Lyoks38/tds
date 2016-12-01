//
//  ScenarioManager.h
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#pragma once

class MainContentComponent;
class CombatManager;

#include "CombatManager.h"
#include "Girl.h"
#include "Player.h"
#include "MainComponent.h"

class ScenarioManager {
    
public:
    
    ScenarioManager();
    
    ~ScenarioManager();
    
    //Load infos
    void LoadPlayer(Player::PlayerAttributes inAttributes) { mPlayer.reset(new Player(inAttributes)); }
    
    void LoadDatabase();
    
    void LoadEvents();
    
    void LoadAttacks(){};
    
    void LoadGirls(){};

    void AttachToGUI(MainContentComponent* inGUI) { mMainGUI = inGUI; };
    
    //Manage Events
    void GoToNextEvent();
    
    //GUI
    void DisplayResults();
    void DisplayVictory();
    void DisplayDefeat();
    
protected:
    
    std::vector<Event> mEvents;
    int mCurrentEvent = -1;
    std::vector<Girl> mGirlDatabase;
    
    
private:
    
    MainContentComponent* mMainGUI = nullptr;
    
    std::unique_ptr<CombatManager> mCombatManager = nullptr;
    
    std::unique_ptr<Player> mPlayer = nullptr;
    
    
    
    
};
