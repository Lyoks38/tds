//
//  Player.cpp
//  TDS
//
//  Created by Corentin Comte on 01/06/2016.
//
//

#include "GlobalEnums.h"
#include "Player.h"


///////////////////////////////////////////////////
// Creators
//////////////////////////////////////////////////

Player::Player()
{
    mName = "";
    mGenre = POLARD;
    mListe = NON_LISTE;
    mReputation = 0;
    
    for(int i = 0; i < GIRL_DATABASE_SIZE; i++)
        mChoppes[i] = 0;
}

/////////////////////////////////////////
Player::Player(PlayerAttributes inAttributes)
{
    mName = inAttributes.mName;
    mGenre = inAttributes.mGenre;
    mListe = inAttributes.mListe;
    mReputation = inAttributes.mReputation;
    
    for(int i = 0; i < GIRL_DATABASE_SIZE; i++)
        mChoppes[i] = inAttributes.mChoppes[i];
}


///////////////////////////////////////////////////
//Other stuff
///////////////////////////////////////////////////

void Player::SetAttack(int inAttack)
{
    int attack = std::min(100, inAttack);
    attack = std::max(0, attack);
    mAttack = attack;
}

///////////////////////////////////////
void Player::SetReputation(int inReputation)
{
    int reputation = std::min(100, inReputation);
    reputation = std::max(0, reputation);
    mReputation = reputation;
}

/////////////////////////////////////
void Player::AddChoppe(int inChoppeID)
{
    //Sanity check to complete
    if(inChoppeID < 0 || inChoppeID >= GIRL_DATABASE_SIZE)
        return;
    
    mChoppes[inChoppeID]++;
    
    SetReputation(mReputation + 5);
}

/////////////////////////////////////
int Player::GetNbChoppeForID(int inChoppeID)
{
    //Sanity check to complete
    if(inChoppeID < 0 || inChoppeID >= GIRL_DATABASE_SIZE)
        return -1;
    
    return mChoppes[inChoppeID];
}






