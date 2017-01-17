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

    attr.mName = "Elise";
    attr.mGenre = LISTEE;
    attr.mListe = PEARL;
    attr.mID = id;
    id++;

    output.push_back(Girl(attr));
    
    attr.mName = "Floriane";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = PLAY;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));
    
    attr.mName = "Emma";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));
    
    attr.mName = "Agathe";
    attr.mGenre = LISTEE;
    attr.mListe = PEUF;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Morgane";
    attr.mGenre = LISTEE;
    attr.mListe = FOX;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));
    
    attr.mName = "Mathilde";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));
    
    attr.mName = "Pauline";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = FRAP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));
    
    attr.mName = "Sarah";
    attr.mGenre = LISTEE;
    attr.mListe = SPACE;
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

    attack = Attack("Lui mettre la main au cul");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(20);
    attack.SetDiceThreshold(20);
    attack.SetAttackText1(AttackStrings::MainsCulEffect1);
    attack.SetAttackText2(AttackStrings::MainsCulEffect2);
    attack.SetAttackText3(AttackStrings::MainsCulEffect3);
    attack.SetFailedText1(AttackStrings::MainsCulFailed1);
    attack.SetFailedText2(AttackStrings::MainsCulFailed2);
    attack.SetFailedText3(AttackStrings::MainsCulFailed3);
    output.push_back(attack);

    attack = Attack("Danser avec elle");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(10);
    attack.SetDiceThreshold(-1);
    attack.SetAttackText1(AttackStrings::DanserEffect1);
    attack.SetAttackText2(AttackStrings::DanserEffect2);
    attack.SetAttackText3(AttackStrings::DanserEffect3);
    attack.SetFailedText1(AttackStrings::DanserFailed1);
    attack.SetFailedText2(AttackStrings::DanserFailed2);
    attack.SetFailedText3(AttackStrings::DanserFailed3);
    output.push_back(attack);

    attack = Attack("Danser collé-serré avec elle");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(20);
    attack.SetDiceThreshold(20);
    attack.SetAttackText1(AttackStrings::DanserSerreEffect1);
    attack.SetAttackText2(AttackStrings::DanserSerreEffect2);
    attack.SetAttackText3(AttackStrings::DanserSerreEffect3);
    attack.SetFailedText1(AttackStrings::DanserSerreFailed1);
    attack.SetFailedText2(AttackStrings::DanserSerreFailed2);
    attack.SetFailedText3(AttackStrings::DanserSerreFailed3);
    output.push_back(attack);
    
    attack = Attack("“J'ai le Syndrôme de l'Enorme Pénis !“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(30);
    attack.SetDiceThreshold(60);
    attack.SetAttackText1(AttackStrings::SepEffect1);
    attack.SetAttackText2(AttackStrings::SepEffect2);
    attack.SetAttackText3(AttackStrings::SepEffect3);
    attack.SetFailedText1(AttackStrings::SepFailed1);
    attack.SetFailedText2(AttackStrings::SepFailed2);
    attack.SetFailedText3(AttackStrings::SepFailed3);
    output.push_back(attack);
    
    attack = Attack("“I'm Batman !“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(30);
    attack.SetDiceThreshold(50);
    attack.SetAttackText1(AttackStrings::BatmanEffect1);
    attack.SetAttackText2(AttackStrings::BatmanEffect2);
    attack.SetAttackText3(AttackStrings::BatmanEffect3);
    attack.SetFailedText1(AttackStrings::BatmanFailed1);
    attack.SetFailedText2(AttackStrings::BatmanFailed2);
    attack.SetFailedText3(AttackStrings::BatmanFailed3);
    output.push_back(attack);
    
    attack = Attack("Mettre du GHB dans son verre");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(80);
    attack.SetDiceThreshold(99);
    attack.SetAttackText1(AttackStrings::GhbEffect1);
    attack.SetAttackText2(AttackStrings::GhbEffect2);
    attack.SetAttackText3(AttackStrings::GhbEffect3);
    attack.SetFailedText1(AttackStrings::GhbFailed1);
    attack.SetFailedText2(AttackStrings::GhbFailed2);
    attack.SetFailedText3(AttackStrings::GhbFailed3);
    output.push_back(attack);
    
    attack = Attack("“T'sais que la fin du monde est dans 3 jours ?“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(40);
    attack.SetDiceThreshold(65);
    attack.SetAttackText1(AttackStrings::FinMondeEffect1);
    attack.SetAttackText2(AttackStrings::FinMondeEffect2);
    attack.SetAttackText3(AttackStrings::FinMondeEffect3);
    attack.SetFailedText1(AttackStrings::FinMondeFailed1);
    attack.SetFailedText2(AttackStrings::FinMondeFailed2);
    attack.SetFailedText3(AttackStrings::FinMondeFailed3);
    output.push_back(attack);

    return output;
}


std::vector<Event> ContentLoader::LoadEvents()
{
    std::vector<Event> output;
    output.clear();
    
    Event newEvent = Event("Barbecue GC", true, ImageUtils::BarbecueGC, "MINP");
    output.push_back(newEvent);
    
    newEvent = Event("Kfet Inté Phelma", true, ImageUtils::BarbecueGC, "MINP");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée Inté GC", false, ImageUtils::BarbecueGC, "Chapiteau");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée Inté Phelma", false, ImageUtils::BarbecueGC, "Cham'");
    output.push_back(newEvent);
    
    return output;
}
