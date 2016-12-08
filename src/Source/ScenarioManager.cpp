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
    LoadAttacks();
    
    mCombatManager.reset(new CombatManager());
    mCombatManager->SetScenarioManager(this);
    
    srand(time(NULL));
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
        mCombatManager.reset(nullptr);
        mCurrentEvent = -1;
    }
    else{
        mMainGUI->DisplayNewEvent(mEvents[mCurrentEvent]);
        mCombatManager->LoadNewCombat(mEvents[mCurrentEvent]);
    }
}

void ScenarioManager::FillEventWithTargets(Event& inEvent)
{
    inEvent.SetTargets(mGirlDatabase); //just for testing for now
}


void ScenarioManager::LoadEvents()
{
    mEvents.resize(0);
    
    Event newEvent = Event("Barbecue GC", true, ImageUtils::BarbecueGC, "MINP");
    FillEventWithTargets(newEvent);
    
    mEvents.push_back(newEvent);
}


void ScenarioManager::LoadGirls()
{
    mGirlDatabase.resize(0);
    
    Girl::GirlAttributes attr;
    int id = 0;
    
    attr.mName = "Emma";
    attr.mGenre = LISTEE;
    attr.mListe = FOX;
    attr.mID = id;
    id++;
    
    mGirlDatabase.push_back(Girl(attr));
}
