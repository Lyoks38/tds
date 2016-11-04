//
//  Girl.h
//  TDS
//
//  Created by Corentin Comte on 01/06/2016.
//
//
#pragma once


#include "GlobalEnums.h"

class Girl {
  
public:
    
    struct GirlAttributes{
        std::string mName;
        GirlGenre mGenre = POLARDE;
        List mListe = NON_LISTE;
        int mID;
    };
    
    // Constructors
    Girl();
    
    Girl(std::string inName);
    
    Girl(GirlAttributes inAttributes);
    
    //Destructor
    ~Girl(){};
    
    //Setters
    void SetGenre(GirlGenre inGenre) { mGenre = inGenre; };
    void SetName(std::string inName) { mName = inName; };
    void SetListe(List inListe) { mListe = inListe; };
    void SetID(int inID) { mID = inID; };
    void SetDefense(int inDefense);
    
    //Getters
    GirlGenre GetGenre() { return mGenre; };
    std::string GetName() { return mName; };
    List GetListe() { return mListe; };
    int GetID() { return mID; };
    int GetDefense() { return mDefense; }
    
protected:
    
    int mDefense;
    
private:
    
    std::string mName;
    GirlGenre mGenre;
    List mListe;
    
    int mID;
    
};
