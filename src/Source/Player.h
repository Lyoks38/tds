//
//  Player.h
//  TDS
//
//  Created by Corentin Comte on 01/06/2016.
//
//
#pragma once

#include "GlobalEnums.h"


class Player {
    
public:
    
    struct PlayerAttributes {
        std::string mName;
        PlayerGenre mGenre;
        List mListe;
        int mReputation;
        int mChoppes[GIRL_DATABASE_SIZE];
    };
    
    // Constructors
    Player();
    
    Player(PlayerAttributes inAttributes);
    
    //Destructor
    ~Player(){};
    
    //Getters
    PlayerGenre GetGenre() { return mGenre; }
    List GetListe() { return mListe; }
    int GetAttack() { return mAttack; }
    int GetReputation() { return mReputation; }
    int GetNbChoppeForID(int inID);
    std::string GetName() const { return mName; }
    
    //Setters
    void SetAttack(int inAttack);
    void SetReputation(int inReputation);
    void AddChoppe(int inChoppeID);

    
protected:
    
    int mAttack;
    int mReputation;
    
    int mChoppes[GIRL_DATABASE_SIZE];
    
private:
    
    std::string mName;
    PlayerGenre mGenre;
    List mListe;
};


class ScoreData {
    
public:
    
    ScoreData(){}
    ~ScoreData(){}
    
    int nbChoppeTotal;
    int nbChoppePerso;
    int nbEventPlayed;
    int nbGirlMet;
};
