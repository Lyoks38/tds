//
//  CombatManager.h
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//
#pragma once

class ScenarioManager;

#include "Attack.h"
#include "ScenarioManager.h"
#include "Girl.h"
#include "Player.h"
#include "Event.h"


class CombatManager {
    
public:
    
    CombatManager();
    
    ~CombatManager();
    
    void LoadNewCombat(const Event inEvent);
    
protected:
    
    std::vector<Girl> mTargets;
    int mCurrentTarget = 0;
    int mRemainingActions = 20;
    
    
    // Combat functions
    void HandleAttack(Attack inAttack);
    int ComputeAttackEffect(Attack inAttack);
    float ComputeListCoeff();
    bool CanTargetBeCatched();
    void TryToCatch();
    void GoToNextTarget();
    
    
    // GUI fonctions
    void DisplayAttackEffect(Attack inAttack){};
    void DisplayFailedAttack(Attack inAttack){};
    void DisplaySuccesPanel(){};
    void DisplayFailPanel(){};
    
    void DisplayFailedEvent(){};
    void DisplayNormalEvent(){};
    
    void DisplayNextTarget(){};
    
    void SetScenarioManager(ScenarioManager* inScenarioManager);
    
private:
    
    std::unique_ptr<Player> mPlayer;
    std::unique_ptr<ScenarioManager> mScenarioManager;
    
    std::vector<Attack> mAttackDatabase;
        
};
