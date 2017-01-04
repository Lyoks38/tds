//
//  ContentLoader.h
//  TDS
//
//  Created by Corentin Comte on 04/01/2017.
//
//

#ifndef ContentLoader_h
#define ContentLoader_h

#include "Event.h"
//#include "Girl.h"
#include "Attack.h"

class ContentLoader {
    
public:
    
    ContentLoader(){}
    ~ContentLoader(){}
    
    std::vector<Girl> LoadGirlDatabase();
    std::vector<Attack> LoadAttackDatabase();
    std::vector<Event> LoadEvents();
    
    
};

#endif /* ContentLoader_h */
