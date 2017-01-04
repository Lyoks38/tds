//
//  ScenarioManager.h
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#pragma once

#define MAX_ACTIONS_SOIREE 30
#define MAX_ACTIONS_KFET 10

#define MAX_TARGETS_SOIREE 6
#define MAX_TARGETS_KFET 3

class MainContentComponent;

#include "CombatManager.h"
#include "Girl.h"
#include "Player.h"

#include "ContentLoader.h"


class ScenarioManager {
    
public:
    
    ScenarioManager();
    
    ~ScenarioManager();
    
    //Getters
    CombatManager* GetCombatManager() const { return mCombatManager.get(); }
    MainContentComponent* GetMainGUI() const { return mMainGUI; }
    Player* GetPlayer() const { return mPlayer.get(); }

    
    //Load infos
    void LoadPlayer(Player::PlayerAttributes inAttributes) { mPlayer.reset(new Player(inAttributes)); mCombatManager->SetPlayer(mPlayer.get()); }
    
    void LoadDatabase();
    
    void LoadEvents();
    
    void LoadAttacks(){ if(mCombatManager) mCombatManager->LoadAttacks(); };
    
    void LoadGirls();

    void AttachToGUI(MainContentComponent* inGUI) { mMainGUI = inGUI; };
    
    //Manage Events
    void GoToNextEvent();
    void FillEventWithTargets(Event& inEvent);
    
    //GUI
    void DisplayResults(){};
    void DisplayVictory(){};
    void DisplayDefeat(){};
    
protected:
    
    std::vector<Event> mEvents;
    int mCurrentEvent = -1;
    std::vector<Girl> mGirlDatabase;
    
    
private:
    
    MainContentComponent* mMainGUI = nullptr;
    
    std::unique_ptr<CombatManager> mCombatManager = nullptr;
    
    std::unique_ptr<Player> mPlayer = nullptr;
    
    
    ContentLoader mLoader;
    
};
