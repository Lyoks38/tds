//
//  Attack.cpp
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//

#include "Attack.h"

Attack::Attack(std::string inName){
    
    mAttackEffect1 = "";
    mAttackEffect2 = "";
    mAttackEffect3 = "";
    mAttackFailed1 = "";
    mAttackFailed2 = "";
    mAttackFailed3 = "";
    
}

///////////////////////////////////////
std::string Attack::GetName()
{
    return mAttackName;
}

//////////////////////////////////////
bool Attack::IsObvious()
{
    return mIsObvious;
}

//////////////////////////////////////
bool Attack::IsImpactingPlayer()
{
    return mImpactsPlayer;
}

//////////////////////////////////////
bool Attack::IsImpactingTarget()
{
    return mImpactsTarget;
}

//////////////////////////////////////
int Attack::GetPlayerBonus()
{
    return mPlayerBonus;
}

//////////////////////////////////////
int Attack::GetTargetMalus()
{
    return mTargetMalus;
}

/////////////////////////////////////
std::string Attack::GetAttackText(bool inSuccess)
{
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



