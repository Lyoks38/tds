//
//  Attack.cpp
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#include "Attack.h"

Attack::Attack(std::string inName){
    
    mAttackName = inName;
    
    mAttackEffect1 = "";
    mAttackEffect2 = "";
    mAttackEffect3 = "";
    mAttackFailed1 = "";
    mAttackFailed2 = "";
    mAttackFailed3 = "";
    
}

Attack::Attack(Attack const& other)
{
    mAttackName = other.GetName();
    mDiceThreshold = other.GetDiceThreshold();
    mImpactsPlayer = other.IsImpactingPlayer();
    mBaseDamages = other.GetBaseDamages();
    mPlayerImpact = other.GetPlayerImpact();
    
    mAttackEffect1 = other.GetAttackText1();
    mAttackEffect2 = other.GetAttackText2();
    mAttackEffect3 = other.GetAttackText3();
    mAttackFailed1 = other.GetFailedText1();
    mAttackFailed2 = other.GetFailedText2();
    mAttackFailed3 = other.GetFailedText3();
}

///////////////////////////////////////
std::string Attack::GetName() const
{
    return mAttackName;
}

//////////////////////////////////////
int Attack::GetDiceThreshold() const
{
    return mDiceThreshold;
}

//////////////////////////////////////
bool Attack::IsImpactingPlayer() const
{
    return mImpactsPlayer;
}

//////////////////////////////////////
int Attack::GetPlayerImpact() const
{
    return mPlayerImpact;
}

//////////////////////////////////////
int Attack::GetBaseDamages() const
{
    return mBaseDamages;
}

/////////////////////////////////////
std::string Attack::GetAttackText(bool inSuccess) const
{
    srand(time(NULL));
    int select = rand()%3;
    std::string output_text;
    
    if(inSuccess){
        switch (select) {
            case 0:{
                output_text = mAttackEffect1;
                break;
            }
            case 1:{
                output_text = mAttackEffect2;
                break;
            }
            case 2:{
                output_text = mAttackEffect3;
                break;
            }
            default:{
                break;
            }
        }
    }
    else {
        switch (select) {
            case 0:{
                output_text = mAttackFailed1;
                break;
            }
            case 1:{
                output_text = mAttackFailed2;
                break;
            }
            case 2:{
                output_text = mAttackFailed3;
                break;
            }
            default:{
                break;
            }
        }
    }
    
    return output_text;
}

////////////////////////////////////////////////////



