//
//  GlobalEnums.h
//  TDS
//
//  Created by Corentin Comte on 01/06/2016.
//
//
#pragma once

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <memory>

#define GIRL_DATABASE_SIZE 12


//////////////////////////////////////////////////////
// Genre enums
/////////////////////////////////////////////////////

//Player classes
typedef enum PlayerGenre {
    POLARD = 0,
    AMI_DE_LISTE,
    LISTE,
    MORUE
} PlayerGenre;

////////////////////////////////
//Ennemy classes
typedef enum GirlGenre {
    POLARDE = 0,
    AMIE_DE_LISTE,
    LISTEE,
    GEM
} GirlGenre;



/////////////////////////////////////////////////////
// Lists enum:
/////////////////////////////////////////////////////

// Listes 3A
typedef enum List {
    NON_LISTE = 0,
    FOX,
    TOP,
    PLAY,
    WHOOP,
    SPACE,
    PULP,
    FRAP,
    PEARL,
    PEUF
} ThirdYearList;



std::string ListToString(List inList);
std::string GirlGenreToString(GirlGenre inGenre);


