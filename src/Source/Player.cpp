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
    mChoppes.resize(0);
}

/////////////////////////////////////////
Player::Player(PlayerAttributes inAttributes)
{
    mName = inAttributes.mName;
    mGenre = inAttributes.mGenre;
    mListe = inAttributes.mListe;
    mReputation = inAttributes.mReputation;
    mChoppes = inAttributes.mChoppes;
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
    /*if(inChoppeID < 0 || inChoppeID >= MAX_GIRLS_)
        return;*/
    
    mChoppes.push_back(inChoppeID);
    
    SetReputation(mReputation + 5);
}







