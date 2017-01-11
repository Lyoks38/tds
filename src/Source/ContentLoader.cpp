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
    
    attr.mName = "Marie";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));
    
    attr.mName = "Julie";
    attr.mGenre = GEM;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Laura";
    attr.mGenre = LISTEE;
    attr.mListe = TOP;
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
    attack.SetDiceThreshold(50);
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
    attack.SetDiceThreshold(-1);
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
    attack.SetDiceThreshold(70);
    attack.SetAttackText1(AttackStrings::PasBelleEffect1);
    attack.SetAttackText2(AttackStrings::PasBelleEffect2);
    attack.SetAttackText3(AttackStrings::PasBelleEffect3);
    attack.SetFailedText1(AttackStrings::PasBelleFailed1);
    attack.SetFailedText2(AttackStrings::PasBelleFailed2);
    attack.SetFailedText3(AttackStrings::PasBelleFailed3);
    output.push_back(attack);

    attack = Attack("“Viens avec moi si tu veux vivre !“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(25);
    attack.SetDiceThreshold(50);
    attack.SetAttackText1(AttackStrings::TerminatorEffect1);
    attack.SetAttackText2(AttackStrings::TerminatorEffect2);
    attack.SetAttackText3(AttackStrings::TerminatorEffect3);
    attack.SetFailedText1(AttackStrings::TerminatorFailed1);
    attack.SetFailedText2(AttackStrings::TerminatorFailed2);
    attack.SetFailedText3(AttackStrings::TerminatorFailed3);
    output.push_back(attack);
    
    attack = Attack("Trempette");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(0);
    attack.SetDiceThreshold(-1);
    attack.SetAttackText1(AttackStrings::TrempetteEffect1);
    attack.SetAttackText2(AttackStrings::TrempetteEffect2);
    attack.SetAttackText3(AttackStrings::TrempetteEffect3);
    attack.SetFailedText1(AttackStrings::TrempetteFailed1);
    attack.SetFailedText2(AttackStrings::TrempetteFailed2);
    attack.SetFailedText3(AttackStrings::TrempetteFailed3);
    output.push_back(attack);
    
    attack = Attack("“T'aimes le pain de mie ?“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(15);
    attack.SetDiceThreshold(40);
    attack.SetAttackText1(AttackStrings::PainMieEffect1);
    attack.SetAttackText2(AttackStrings::PainMieEffect2);
    attack.SetAttackText3(AttackStrings::PainMieEffect3);
    attack.SetFailedText1(AttackStrings::PainMieFailed1);
    attack.SetFailedText2(AttackStrings::PainMieFailed2);
    attack.SetFailedText3(AttackStrings::PainMieFailed3);
    output.push_back(attack);
    
    attack = Attack("“Dis camion !“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(30);
    attack.SetDiceThreshold(65);
    attack.SetAttackText1(AttackStrings::CamionEffect1);
    attack.SetAttackText2(AttackStrings::CamionEffect2);
    attack.SetAttackText3(AttackStrings::CamionEffect3);
    attack.SetFailedText1(AttackStrings::CamionFailed1);
    attack.SetFailedText2(AttackStrings::CamionFailed2);
    attack.SetFailedText3(AttackStrings::CamionFailed3);
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
