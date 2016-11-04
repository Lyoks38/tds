//
//  Girl.cpp
//  TDS
//
//  Created by Corentin Comte on 01/06/2016.
//
//

#include "Girl.h"



/////////////////////////////////////////////////
// Creators
////////////////////////////////////////////////

Girl::Girl():
mDefense(100)
{
    mName = "";
    mGenre = POLARDE;
    mListe = NON_LISTE;
    mID = 0;
}

Girl::Girl(std::string inName):
mDefense(100)
{
    mName = inName;
    mGenre = POLARDE;
    mListe = NON_LISTE;
    mID = 0;
}

Girl::Girl(GirlAttributes inAttributes):
mDefense(100)
{
    mName = inAttributes.mName;
    mGenre = inAttributes.mGenre;
    mListe = inAttributes.mListe;
    mID = inAttributes.mID;
}

/////////////////////////////////////////////////
// Other stuff
/////////////////////////////////////////////////

void Girl::SetDefense(int inDefense)
{
    int defense = std::min(100, inDefense);
    defense = std::max(0, defense);
    mDefense = defense;
}



