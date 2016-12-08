//
//  ToString.cpp
//  TDS
//
//  Created by Corentin Comte on 08/12/2016.
//
//

#include "GlobalEnums.h"

std::string ListToString(List inList)
{
    std::string liste;
    
    switch (inList) {
        case FOX:
            liste = "FOX";
            break;
        case TOP:
            liste = "TOP";
            break;
        case PLAY:
            liste = "PLAY";
            break;
        case WHOOP:
            liste = "WHOOP";
            break;
        case SPACE:
            liste = "SPACE";
            break;
        case PULP:
            liste = "PULP";
            break;
        case FRAP:
            liste = "FRAP";
            break;
        case PEUF:
            liste = "PEUF";
            break;
        case PEARL:
            liste = "PEARL";
            break;
            
        default:
            liste = "Non listée";
            break;
    }
    
    return liste;
}


std::string GirlGenreToString(GirlGenre inGenre)
{
    std::string genre;
    
    switch (inGenre) {
        case GEM:
            genre = "GEM";
            break;
        case POLARDE:
            genre = "Polarde";
            break;
        case LISTEE:
            genre = "Listée";
            break;
        case AMIE_DE_LISTE:
            genre = "Amie de liste";
            break;
            
        default:
            break;
    }
    
    return genre;
}
