//
//  Player.h
//  TDS
//
//  Created by Corentin Comte on 01/06/2016.
//
//
#pragma once


class Player {
    
public:
    
    struct PlayerAttributes {
        std::string mName;
        PlayerGenre mGenre;
        List mListe;
        int mReputation;
        std::vector<int> mChoppes;
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
    
    
    //Setters
    void SetAttack(int inAttack);
    void SetReputation(int inReputation);
    void AddChoppe(int inChoppeID);

    
protected:
    
    int mAttack;
    int mReputation;
    
    std::vector<int> mChoppes;
    
private:
    
    std::string mName;
    PlayerGenre mGenre;
    List mListe;
};
