//
//  CombatManager.cpp
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#include "CombatManager.h"
#include "ScenarioManager.h"
#include "MainComponent.h"
#include "ChoppeStrings.h"


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
    mScenarioManager = inScenarioManager;
}

///////////////////////////////////////
void CombatManager::LoadNewCombat(const Event inEvent)
{
    if(inEvent.IsKfet()){
        mRemainingActions = MAX_ACTIONS_KFET;
        mAlcoolEffect = 5;
    }
    else{
        mRemainingActions = MAX_ACTIONS_SOIREE;
        mAlcoolEffect = 3;
    }
    
    mTargets = inEvent.GetTargets();
    
    mCurrentTarget = -1;
    mNbChoppe = 0;
    
    mEventBanner = inEvent.GetBanner();
    mEventName = inEvent.GetName();
    
    mPlayer->SetAttack(100);
}

//////////////////////////////////////
int CombatManager::ComputeAttackEffect(Attack inAttack){
    
    int basic_attack = inAttack.GetBaseDamages();
    float coeff = 1.f;
    float coeff_reputation = 1.f;
    
    // Compute reputation first
    GirlGenre target_genre = mTargets[mCurrentTarget].GetGenre();
    if(target_genre == POLARDE){
        coeff_reputation += mPlayer->GetReputation() / 100.f;
    }
    else if (target_genre == GEM){
        // Les gems s'en battent de la réput, par contre elles aiment pas les ingé de base...
        coeff *= 0.2f;
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
    if(!ApplyAlcoholOnEveryone()){
        DisplayEndEvent(false);
    }
    
    //Si l'attaque inflige des dégats au joueur
    if(inAttack.IsImpactingPlayer()){
        int previous_attack = mPlayer->GetAttack();
        if(previous_attack - inAttack.GetPlayerImpact() <= 0){
            DisplayEndEvent(false);
        }
        else{
            mPlayer->SetAttack(previous_attack - inAttack.GetPlayerImpact());
        }
    }
    
    //Calcul des dégats sur la cible
    int result = ComputeAttackEffect(inAttack);
    int previous_defense = mTargets[mCurrentTarget].GetDefense();
    
    //Si l'attaque nécessite un jet de dés
    bool attack_effective = true;
    if(inAttack.GetDiceThreshold() != -1){
        srand(time(NULL));
        int dices = rand() % 100;
        dices += (100 - previous_defense)*0.4f;
        attack_effective = dices >= inAttack.GetDiceThreshold();
    }
    
    //Si le jet de dés a réussi (ou qu'il n'y en avait pas besoin)
    if(attack_effective){
        //La cible a encore assez de défense
        if(previous_defense - result > 0){
            mTargets[mCurrentTarget].SetDefense(previous_defense - result);
            DisplayAttackEffect(inAttack, true);
        }
        //La target atteint les 0
        else {
            DisplayFailedTargetOnAttack(inAttack);
        }
    }
    //Le jet de dés a échoué
    else{
        DisplayAttackEffect(inAttack, false);
    }
    
    mRemainingActions--;
}


/////////////////////////////////////////////////////////
bool CombatManager::ApplyAlcoholOnEveryone()
{
    int new_attack = mPlayer->GetAttack() - mAlcoolEffect;
    
    if(new_attack <= 0)
        return false;
    
    mPlayer->SetAttack(new_attack);
    
    int new_defense;
    for(int i = mCurrentTarget+1; i < mTargets.size(); i++){ //mTarget+1 because the current target does not drink
        new_defense = mTargets[i].GetDefense() - mAlcoolEffect;
        mTargets[i].SetDefense(new_defense);
    }
    return true;
}

/////////////////////////////////////////////////////////
bool CombatManager::CanTargetBeCatched()
{
    int girl_defense = mTargets[mCurrentTarget].GetDefense();
    
    if(girl_defense <= 25 && mPlayer->GetAttack() >= girl_defense)
        return true;
    else
        return false;
}


/////////////////////////////////////////////////////////
void CombatManager::TryToCatch()
{
    if(CanTargetBeCatched()){
        mPlayer->AddChoppe(mTargets[mCurrentTarget].GetID());
        mNbChoppe++;
        DisplayCatchResult(true);
        
        //Check if the catch is valid
        int nbChoppe = mPlayer->GetNbChoppeForID(mTargets[mCurrentTarget].GetID());
        if(nbChoppe >= 3){
            mScenarioManager->DisplayDefeat();
        }
        else if(mTargets[mCurrentTarget].GetGenre() == GEM){
            mScenarioManager->DisplayVictory();
        }
    }
    else
        DisplayCatchResult(false);
}

/////////////////////////////////////////////////////////
void CombatManager::GoToNextTarget()
{
    if(mDisplayDefeat){
        mScenarioManager->DisplayDefeat();
    }
    else if(mDisplayVictory){
        mScenarioManager->DisplayVictory();
    }
    
    mCurrentTarget++;
    
    if(mCurrentTarget >= static_cast<int>(mTargets.size())){
        mCurrentTarget = -1;
        DisplayEndEvent(true);
    }
    else{
        DisplayNextTarget();
    }
}



std::vector<Attack> CombatManager::DeliverAttacks() const
{
    std::vector<Attack> out;
    out.resize(0);
    
    int ind;
    
    srand(time(NULL));
    while(static_cast<int>(out.size()) != 4){
        ind = rand() % mAttackDatabase.size();
        
        bool alreadyIn = false;
        
        for(int i = 0; i < static_cast<int>(out.size()) ; i++){
            if(out[i].GetName() == mAttackDatabase[ind].GetName()){
                alreadyIn = true;
                break;
            }
        }
        
        if(!alreadyIn){
            Attack attack = mAttackDatabase[ind];
            out.push_back(attack);
        }
    }
    
    return out;
}

/////////////////////////////////////////////////////////
// Display calls
/////////////////////////////////////////////////////////
void CombatManager::DisplayNextTarget()
{
    MainContentComponent* mainWindow = mScenarioManager->GetMainGUI();
    
    if(mainWindow)
        mainWindow->DisplayNewTarget(mTargets[mCurrentTarget], mEventBanner, mEventName);
}


void CombatManager::DisplayAttackEffect(Attack inAttack, bool inSuccess)
{
    srand(time(NULL));
    int ind = rand() % 3;
    std::string textToDisplay = "";
    switch (ind) {
        case 0:
            textToDisplay = inSuccess ? inAttack.GetAttackText1() : inAttack.GetFailedText1();
            break;
        case 1:
            textToDisplay = inSuccess ? inAttack.GetAttackText2() : inAttack.GetFailedText2();
            break;
        case 2:
            textToDisplay = inSuccess ? inAttack.GetAttackText3() : inAttack.GetFailedText3();
            break;
        default:
            break;
    }
    
    GoTo whereTo;
    
    if(mRemainingActions == 0)
        whereTo = END_EVENT;
    else if(inSuccess)
        whereTo = NEW_ATTACK;
    else
        whereTo = NEW_TARGET;
    
    MainContentComponent* mainWindow = mScenarioManager->GetMainGUI();
    
    if(mainWindow)
        mainWindow->CombatPageDisplayResult(textToDisplay, whereTo);
}


void CombatManager::DisplayCatchResult(bool inSuccess)
{
    srand(time(NULL));
    int ind = (rand() % 10) + 1;
    
    std::string textToDisplay = "";
    switch (ind) {
        case 1:
            textToDisplay = inSuccess ? ChoppeStrings::Text1 : ChoppeStrings::Fail1;
            break;
        case 2:
            textToDisplay = inSuccess ? ChoppeStrings::Text2 : ChoppeStrings::Fail2;
            break;
        case 3:
            textToDisplay = inSuccess ? ChoppeStrings::Text3 : ChoppeStrings::Fail3;
            break;
        case 4:
            textToDisplay = inSuccess ? ChoppeStrings::Text4 : ChoppeStrings::Fail4;
            break;
        case 5:
            textToDisplay = inSuccess ? ChoppeStrings::Text5 : ChoppeStrings::Fail5;
            break;
        case 6:
            textToDisplay = inSuccess ? ChoppeStrings::Text6 : ChoppeStrings::Fail6;
            break;
        case 7:
            textToDisplay = inSuccess ? ChoppeStrings::Text7 : ChoppeStrings::Fail7;
            break;
        case 8:
            textToDisplay = inSuccess ? ChoppeStrings::Text8 : ChoppeStrings::Fail8;
            break;
        case 9:
            textToDisplay = inSuccess ? ChoppeStrings::Text9 : ChoppeStrings::Fail9;
            break;
        case 10:
            textToDisplay = inSuccess ? ChoppeStrings::Text10 : ChoppeStrings::Fail10;
            break;
        default:
            break;
    }
    
    GoTo whereTo;
    
    if(mCurrentTarget == static_cast<int>(mTargets.size()-1)) //This was the last possible target of the event
        whereTo = END_EVENT;
    else
        whereTo = NEW_TARGET;
    
    MainContentComponent* mainWindow = mScenarioManager->GetMainGUI();
    
    if(mainWindow)
        mainWindow->CombatPageDisplayResult(textToDisplay, whereTo);

}


void CombatManager::DisplayEndEvent(bool inWasNotFailed)
{
    mScenarioManager->EndEvent(mNbChoppe, inWasNotFailed);
}

/////////////////////////////////////////////////////////
// Load Attacks
void CombatManager::LoadAttacks()
{
    mAttackDatabase.resize(0);
    mAttackDatabase = mLoader.LoadAttackDatabase();
}









