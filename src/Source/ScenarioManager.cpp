//
//  ScenarioManager.cpp
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//
#include "MainComponent.h"
#include "ScenarioManager.h"
#include "ImageUtils.h"
#include <time.h>


ScenarioManager::ScenarioManager()
{
    LoadGirls();
    LoadEvents();
    
    mCombatManager.reset(new CombatManager());
    mCombatManager->SetScenarioManager(this);
    
    LoadAttacks();
}


ScenarioManager::~ScenarioManager()
{
    mCombatManager.reset(nullptr);
    mPlayer.reset(nullptr);
}

void ScenarioManager::GoToNextEvent()
{
    mCurrentEvent++;
    
    if(mCurrentEvent >= static_cast<int>(mEvents.size())){
        DisplayResults();
        //mCombatManager.reset(nullptr);
        mCurrentEvent = -1;
    }
    else{
        mMainGUI->DisplayNewEvent(mEvents[mCurrentEvent]);
        mCombatManager->LoadNewCombat(mEvents[mCurrentEvent]);
    }
}

void ScenarioManager::EndEvent(int inNbChoppe, bool inWasNotFailed)
{
    mMainGUI->DisplayEndEvent(mEvents[mCurrentEvent], inNbChoppe, inWasNotFailed);
}

void ScenarioManager::FillEventWithTargets(Event& inEvent)
{
    std::vector<Girl> out;
    out.resize(0);
    
    int ind;
    
    int size = inEvent.IsKfet() ? MAX_TARGETS_KFET : MAX_TARGETS_SOIREE;
    
    while(static_cast<int>(out.size()) != size){
        ind = rand() % mGirlDatabase.size();
        
        bool alreadyIn = false;
        
        for(int i = 0; i < static_cast<int>(out.size()) ; i++){
            if(out[i].GetID() == ind){
                alreadyIn = true;
                break;
            }
        }
        
        if(!alreadyIn){
            Girl target = mGirlDatabase[ind];
            out.push_back(target);
        }
    }
    
    inEvent.SetTargets(out); //just for testing for now
}


void ScenarioManager::LoadEvents()
{
    mEvents.resize(0);
    mEvents = mLoader.LoadEvents();
    
    for(int i = 0; i < mEvents.size(); i++)
        FillEventWithTargets(mEvents[i]);
    
}


void ScenarioManager::LoadGirls()
{
    mGirlDatabase.resize(0);
    mGirlDatabase = mLoader.LoadGirlDatabase();
}



void ScenarioManager::DisplayResults()
{
    ScoreData score;
    
    score.nbEventPlayed = static_cast<int>(mEvents.size());
    
    int nbChoppeTotal = 0;
    int nbChoppePerso = 0;
    
    for(int i = 0; i < GIRL_DATABASE_SIZE; i ++){
        
        int choppe = mPlayer->GetNbChoppeForID(i);
        if(choppe > 0){
            nbChoppeTotal += choppe;
            nbChoppePerso++;
        }
    }
    
    score.nbChoppeTotal = nbChoppeTotal;
    score.nbChoppePerso = nbChoppePerso;
    
    int nbGirlMet = 0;
    for(int i = 0; i < mEvents.size(); i++){
        nbGirlMet += static_cast<int>(mEvents[i].GetTargets().size());
    }
    
    score.nbGirlMet = nbGirlMet;
    
    mMainGUI->DisplayEndGame(score, CLASSIC);
}


void ScenarioManager::DisplayDefeat()
{
    ScoreData fakeScore;
    mMainGUI->DisplayEndGame(fakeScore, DEFEAT);
}

void ScenarioManager::DisplayVictory()
{
    ScoreData fakeScore;
    mMainGUI->DisplayEndGame(fakeScore, VICTORY);
}
