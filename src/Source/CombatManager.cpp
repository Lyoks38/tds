//
//  CombatManager.cpp
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#include "CombatManager.h"


CombatManager::CombatManager()
{
    
}

////////////////////////////////////////
CombatManager::~CombatManager()
{
    
}

///////////////////////////////////////
void CombatManager::SetScenarioManager(ScenarioManager* inScenarioManager)
{
    mScenarioManager.reset(inScenarioManager);
}

///////////////////////////////////////
void CombatManager::LoadNewCombat(Event inEvent)
{
    if(inEvent.IsKfet()){
        mRemainingActions = 10;
    }
    else{
        mRemainingActions = 20;
    }
    
    mTargets = inEvent.GetTargets();
    
    mCurrentTarget = 0;
    
    //TO BE COMPLETED
}

//////////////////////////////////////
int CombatManager::ComputeAttackEffect(Attack inAttack){
    
    int basic_attack = 25;
    float coeff = 1.f;
    float coeff_reputation = 1.f;
    
    // Compute reputation first
    GirlGenre target_genre = mTargets[mCurrentTarget].GetGenre();
    if(target_genre == POLARDE){
        coeff_reputation += mPlayer->GetReputation() / 100.f;
    }
    else if (target_genre == GEM){
        // Les gems s'en battent de la réput, par contre elles aiment pas les ingé de base...
        coeff *= 0.5f;
    }
    else {
        coeff_reputation -= std::max(mPlayer->GetReputation() / 100.f, 0.f); //std::max to be sure we do not go negative
    }

    // Compute now with player genre
    switch(mPlayer->GetGenre()){
        case POLARD:{
            if(target_genre == AMIE_DE_LISTE || target_genre == LISTEE){
                coeff *= 0.7f;
            }
            else if(target_genre == POLARDE){
                coeff *= 1.1f;
            }
        }
        case AMI_DE_LISTE:{
            coeff *= 0.9f;
            if(target_genre == AMIE_DE_LISTE || target_genre == LISTEE){
                coeff *= ComputeListCoeff();
            }
        }
        case LISTE:{
            coeff *= 1.2f;
            if(target_genre == AMIE_DE_LISTE || target_genre == LISTEE){
                coeff *= ComputeListCoeff();
            }
        }
        case MORUE:{
            coeff *= 1.5f;
            if(target_genre == GEM){
                coeff *= 2.f;
            }
        }
        default:{
            break;
        }
    }
    
    int final_coeff = basic_attack*coeff + 5*coeff_reputation;
    if(inAttack.IsImpactingTarget())
        final_coeff += inAttack.GetTargetMalus();
    
    return final_coeff;
}

////////////////////////////////////////////////////////////////////////
float CombatManager::ComputeListCoeff()
{
    List target_list = mTargets[mCurrentTarget].GetListe();
    float coeff = 1.f;
    
    switch(mPlayer->GetListe()){
        case FOX:
        case TOP:{
            if(target_list == PLAY)
                coeff *= 0.6f;
            break;
        }
        case PLAY:{
            if(target_list == PLAY)
                coeff *= 1.3f;
            break;
        }
        case WHOOP:{
            if(target_list == WHOOP)
                coeff *= 2.f;
            else if(target_list == PULP)
                coeff *= 0.7f;
            break;
        }
        case SPACE:{
            if(target_list == PULP)
                coeff *= 0.9f;
            break;
        }
        case FRAP:{
            if(target_list == PEUF)
                coeff = 1.2f;
        }
        case PEUF:{
            if(target_list == PEUF || target_list == FRAP)
                coeff = 1.2f;
        }
        case PEARL:{
            if(target_list == FRAP || target_list == PEUF)
                coeff = 0.8f;
            break;
        }
        default:{
            break;
        }
    }
    
    return coeff;
}


/////////////////////////////////////////////////////////
void CombatManager::HandleAttack(Attack inAttack)
{
    if(inAttack.IsImpactingPlayer()){
        int previous_attack = mPlayer->GetAttack();
        if(previous_attack + inAttack.GetPlayerBonus() < 0){
            // End level with ScenarioManager
        }
        else{
            mPlayer->SetAttack(previous_attack + inAttack.GetPlayerBonus());
        }
    }
    
    
    int result = ComputeAttackEffect(inAttack);
    int previous_defense = mTargets[mCurrentTarget].GetDefense();
    
    if(previous_defense - result > 0){
        mTargets[mCurrentTarget].SetDefense(previous_defense - result);
        DisplayAttackEffect(inAttack);
    }
    else {
        DisplayFailedAttack(inAttack);
    }
    mRemainingActions--;
}


/////////////////////////////////////////////////////////
bool CombatManager::CanTargetBeCatched()
{
    int girl_defense = mTargets[mCurrentTarget].GetDefense();
    
    if(girl_defense <= 15 && mPlayer->GetAttack() >= girl_defense)
        return true;
    else
        return false;
}


/////////////////////////////////////////////////////////
void CombatManager::TryToCatch()
{
    if(CanTargetBeCatched()){
        int dices = std::rand() %4;
        if(dices >= 1){
            mPlayer->AddChoppe(mTargets[mCurrentTarget].GetID());
            DisplaySuccesPanel();
        }
        else
            DisplayFailPanel();
    }
}

/////////////////////////////////////////////////////////
void CombatManager::GoToNextTarget()
{
    mCurrentTarget++;
    
    if(mCurrentTarget == static_cast<int>(mTargets.size())){
        DisplayNormalEvent();
    }
    else{
        DisplayNextTarget();
    }
}


