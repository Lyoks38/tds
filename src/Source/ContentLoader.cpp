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
    
    attr.mName = "Amélie";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Sophie";
    attr.mGenre = LISTEE;
    attr.mListe = PULP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Léa";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = TOP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Camille";
    attr.mGenre = LISTEE;
    attr.mListe = FRAP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Fanny";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Andréa";
    attr.mGenre = LISTEE;
    attr.mListe = PULP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Laurine";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = PEARL;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Carole";
    attr.mGenre = LISTEE;
    attr.mListe = PEUF;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Claire";
    attr.mGenre = LISTEE;
    attr.mListe = PLAY;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Alexandra";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = SPACE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Emilie";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Juliette";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Laetitia";
    attr.mGenre = LISTEE;
    attr.mListe = WHOOP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Estelle";
    attr.mGenre = LISTEE;
    attr.mListe = TOP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Aline";
    attr.mGenre = LISTEE;
    attr.mListe = FRAP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Lucile";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = PEUF;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Marion";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Noémie";
    attr.mGenre = LISTEE;
    attr.mListe = PLAY;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Océane";
    attr.mGenre = LISTEE;
    attr.mListe = FOX;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Mélanie";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Tiffany";
    attr.mGenre = LISTEE;
    attr.mListe = PLAY;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Andréa";
    attr.mGenre = LISTEE;
    attr.mListe = PULP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Stéphanie";
    attr.mGenre = LISTEE;
    attr.mListe = WHOOP;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Valentine";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Gabrielle";
    attr.mGenre = LISTEE;
    attr.mListe = PEARL;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Aurélie";
    attr.mGenre = POLARDE;
    attr.mListe = NON_LISTE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Chloé";
    attr.mGenre = LISTEE;
    attr.mListe = SPACE;
    attr.mID = id;
    id++;
    
    output.push_back(Girl(attr));

    attr.mName = "Justine";
    attr.mGenre = AMIE_DE_LISTE;
    attr.mListe = FOX;
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
    
    attack = Attack("Montrer tes abdos");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(30);
    attack.SetDiceThreshold(30);
    attack.SetAttackText1(AttackStrings::AbdosEffect1);
    attack.SetAttackText2(AttackStrings::AbdosEffect2);
    attack.SetAttackText3(AttackStrings::AbdosEffect3);
    attack.SetFailedText1(AttackStrings::AbdosFailed1);
    attack.SetFailedText2(AttackStrings::AbdosFailed2);
    attack.SetFailedText3(AttackStrings::AbdosFailed3);
    output.push_back(attack);
    
    attack = Attack("“T'sais que je suis musicien ?“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(20);
    attack.SetDiceThreshold(20);
    attack.SetAttackText1(AttackStrings::MusicienEffect1);
    attack.SetAttackText2(AttackStrings::MusicienEffect2);
    attack.SetAttackText3(AttackStrings::MusicienEffect3);
    attack.SetFailedText1(AttackStrings::MusicienFailed1);
    attack.SetFailedText2(AttackStrings::MusicienFailed2);
    attack.SetFailedText3(AttackStrings::MusicienFailed3);
    output.push_back(attack);
    
    attack = Attack("“On échange nos MSTs ?“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(20);
    attack.SetDiceThreshold(40);
    attack.SetAttackText1(AttackStrings::EchangeMstEffect1);
    attack.SetAttackText2(AttackStrings::EchangeMstEffect2);
    attack.SetAttackText3(AttackStrings::EchangeMstEffect3);
    attack.SetFailedText1(AttackStrings::EchangeMstFailed1);
    attack.SetFailedText2(AttackStrings::EchangeMstFailed2);
    attack.SetFailedText3(AttackStrings::EchangeMstFailed3);
    output.push_back(attack);
    
    attack = Attack("“Tu veux voir ma bite ?“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(25);
    attack.SetDiceThreshold(60);
    attack.SetAttackText1(AttackStrings::CoucouEffect1);
    attack.SetAttackText2(AttackStrings::CoucouEffect2);
    attack.SetAttackText3(AttackStrings::CoucouEffect3);
    attack.SetFailedText1(AttackStrings::CoucouFailed1);
    attack.SetFailedText2(AttackStrings::CoucouFailed2);
    attack.SetFailedText3(AttackStrings::CoucouFailed3);
    output.push_back(attack);
    
    attack = Attack("Dire que tu es sportif");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(25);
    attack.SetDiceThreshold(20);
    attack.SetAttackText1(AttackStrings::SportifEffect1);
    attack.SetAttackText2(AttackStrings::SportifEffect2);
    attack.SetAttackText3(AttackStrings::SportifEffect3);
    attack.SetFailedText1(AttackStrings::SportifFailed1);
    attack.SetFailedText2(AttackStrings::SportifFailed2);
    attack.SetFailedText3(AttackStrings::SportifFailed3);
    output.push_back(attack);
    
    attack = Attack("Dire que tu es écrivain");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(30);
    attack.SetDiceThreshold(50);
    attack.SetAttackText1(AttackStrings::EcrivainEffect1);
    attack.SetAttackText2(AttackStrings::EcrivainEffect2);
    attack.SetAttackText3(AttackStrings::EcrivainEffect3);
    attack.SetFailedText1(AttackStrings::EcrivainFailed1);
    attack.SetFailedText2(AttackStrings::EcrivainFailed2);
    attack.SetFailedText3(AttackStrings::EcrivainFailed3);
    output.push_back(attack);

    attack = Attack("“Tu suces ?“");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(15);
    attack.SetDiceThreshold(40);
    attack.SetAttackText1(AttackStrings::SuceEffect1);
    attack.SetAttackText2(AttackStrings::SuceEffect2);
    attack.SetAttackText3(AttackStrings::SuceEffect3);
    attack.SetFailedText1(AttackStrings::SuceFailed1);
    attack.SetFailedText2(AttackStrings::SuceFailed2);
    attack.SetFailedText3(AttackStrings::SuceFailed3);
    output.push_back(attack);
    
    attack = Attack("Proposer un proto");
    attack.SetImpactsPlayer(true);
    attack.SetPlayerImpact(15);
    attack.SetBaseDamages(20);
    attack.SetDiceThreshold(-1);
    attack.SetAttackText1(AttackStrings::ProtoEffect1);
    attack.SetAttackText2(AttackStrings::ProtoEffect2);
    attack.SetAttackText3(AttackStrings::ProtoEffect3);
    attack.SetFailedText1(AttackStrings::ProtoFailed1);
    attack.SetFailedText2(AttackStrings::ProtoFailed2);
    attack.SetFailedText3(AttackStrings::ProtoFailed3);
    output.push_back(attack);
    
    attack = Attack("Être un beau gosse");
    attack.SetImpactsPlayer(false);
    attack.SetBaseDamages(35);
    attack.SetDiceThreshold(50);
    attack.SetAttackText1(AttackStrings::BGEffect1);
    attack.SetAttackText2(AttackStrings::BGEffect2);
    attack.SetAttackText3(AttackStrings::BGEffect3);
    attack.SetFailedText1(AttackStrings::BGFailed1);
    attack.SetFailedText2(AttackStrings::BGFailed2);
    attack.SetFailedText3(AttackStrings::BGFailed3);
    output.push_back(attack);


    return output;
}


std::vector<Event> ContentLoader::LoadEvents()
{
    std::vector<Event> output;
    output.clear();
    
    Event newEvent = Event("Barbecue GC", true, ImageUtils::BarbecueGC, "MINP");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée Inté GC", false, ImageUtils::InteGC, "Chapiteau");
    output.push_back(newEvent);

    newEvent = Event("Kfet Inté Phelma", true, ImageUtils::KfetIntePhelma, "MINP");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée Papet - Phelma", false, ImageUtils::PapetPhelma, "Cham'");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée Ol'INPiades", false, ImageUtils::SoireeOlinp, "Apo'");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée d'automne", false, ImageUtils::SoireeAutomne, "Apo'");
    output.push_back(newEvent);

    newEvent = Event("Kfet 1A", true, ImageUtils::Kfet1A, "MINP");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée de campagne 1", false, ImageUtils::SoireeCamp1, "Ambiance Café");
    output.push_back(newEvent);
    
    newEvent = Event("Kfet de campagne", true, ImageUtils::KfetCamp, "MINP");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée de campagne 2", false, ImageUtils::SoireeCamp2, "Evénement'ciel");
    output.push_back(newEvent);
    
    newEvent = Event("Kfet Awards", true, ImageUtils::KfetAwards, "MINP");
    output.push_back(newEvent);
    
    newEvent = Event("Soirée de fin d'année GC", false, ImageUtils::FinAnnee, "2 Colombes");
    output.push_back(newEvent);
    
    return output;
}
