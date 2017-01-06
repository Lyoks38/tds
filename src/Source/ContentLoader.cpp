//
//  ContentLoader.cpp
//  TDS
//
//  Created by Corentin Comte on 04/01/2017.
//
//

#include "ContentLoader.h"
#include "ImageUtils.h"
#include "AttackStrings.h"


std::vector<Girl> ContentLoader::LoadGirlDatabase()
{
    std::vector<Girl> output;
    output.clear();
    
    Girl::GirlAttributes attr;
    int id = 0;
    
    attr.mName = "Delphine";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = WHOOP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));
    
    return output;
}



std::vector<Attack> ContentLoader::LoadAttackDatabase()
{
    std::vector<Attack> output;
    output.clear();
    
    Attack attack = Attack("Lui offrir un verre");
    attack.SetImpactsPlayer(true);
    attack.SetPlayerImpact(25);
    attack.SetBaseDamages(20);
    attack.SetAttackText1(AttackStrings::BoireEffect1);
    attack.SetAttackText2(AttackStrings::BoireEffect2);
    attack.SetAttackText3(AttackStrings::BoireEffect3);
    attack.SetFailedText1(AttackStrings::BoireFailed1);
    attack.SetFailedText2(AttackStrings::BoireFailed2);
    attack.SetFailedText3(AttackStrings::BoireFailed3);
    output.push_back(attack);
    
    attack = Attack("Lui faire le coup de la Lamborghini");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(30);
    attack.SetDiceThreshold(60);
    attack.SetAttackText1(AttackStrings::LamborghiniEffect1);
    attack.SetAttackText2(AttackStrings::LamborghiniEffect2);
    attack.SetAttackText3(AttackStrings::LamborghiniEffect3);
    attack.SetFailedText1(AttackStrings::LamborghiniFailed1);
    attack.SetFailedText2(AttackStrings::LamborghiniFailed2);
    attack.SetFailedText3(AttackStrings::LamborghiniFailed3);
    output.push_back(attack);
    
    attack = Attack("Mettre ta main sur sa hanche");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(15);
    attack.SetDiceThreshold(20);
    attack.SetAttackText1(AttackStrings::HancheEffect1);
    attack.SetAttackText2(AttackStrings::HancheEffect2);
    attack.SetAttackText3(AttackStrings::HancheEffect3);
    attack.SetFailedText1(AttackStrings::HancheFailed1);
    attack.SetFailedText2(AttackStrings::HancheFailed2);
    attack.SetFailedText3(AttackStrings::HancheFailed3);
    output.push_back(attack);
    
    attack = Attack("Lui crier : “T'es pas belle !“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(20);
    attack.SetDiceThreshold(80);
    attack.SetAttackText1(AttackStrings::PasBelleEffect1);
    attack.SetAttackText2(AttackStrings::PasBelleEffect2);
    attack.SetAttackText3(AttackStrings::PasBelleEffect3);
    attack.SetFailedText1(AttackStrings::PasBelleFailed1);
    attack.SetFailedText2(AttackStrings::PasBelleFailed2);
    attack.SetFailedText3(AttackStrings::PasBelleFailed3);
    output.push_back(attack);

    return output;
}


std::vector<Event> ContentLoader::LoadEvents()
{
    std::vector<Event> output;
    output.clear();
    
    Event newEvent = Event("Barbecue GC", true, ImageUtils::BarbecueGC, "MINP");
    output.push_back(newEvent);
    
    return output;
}
