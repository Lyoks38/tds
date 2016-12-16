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
#include "Girl.h"
#include "Player.h"
#include "Event.h"


class CombatManager {
    
public:
    
    CombatManager();
    
    ~CombatManager();
    
    void SetPlayer(Player* inP) { mPlayer = inP; }
    
    void LoadNewCombat(const Event inEvent);
    
    void GoToNextTarget();
    void TryToCatch();

    void SetScenarioManager(ScenarioManager* inScenarioManager);

    void LoadAttacks();
    
    void HandleAttack(Attack inAttack);
    
    std::vector<Attack> DeliverAttacks();
    juce::Image GetBanner() const { return mEventBanner; }
    std::string GetEventName() const { return mEventName; }
    
    const Girl* GetCurrentTarget() const { return &(mTargets[mCurrentTarget]); }
    int GetRemainingActions() const { return mRemainingActions; }
    int GetDrunkIndex() const { return mPlayer->GetAttack(); }
    
protected:
    
    std::vector<Girl> mTargets;
    int mCurrentTarget = -1;
    int mRemainingActions = 20;
    
    juce::Image mEventBanner;
    std::string mEventName;
    
    
    // Combat functions
    int ComputeAttackEffect(Attack inAttack);
    float ComputeListCoeff();
    bool CanTargetBeCatched();
    
    
    // GUI fonctions
    void DisplayAttackEffect(Attack inAttack){};
    void DisplayFailedAttack(Attack inAttack){};
    void DisplaySuccesPanel(){};
    void DisplayFailPanel(){};
    
    void DisplayFailedEvent(){};
    void DisplayNormalEvent(){};
    
    void DisplayNextTarget();
    
private:
    
    Player* mPlayer;
    ScenarioManager* mScenarioManager;
    
    std::vector<Attack> mAttackDatabase;
        
};
