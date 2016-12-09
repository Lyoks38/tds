//
//  Attack.h
//  TDS
//
//  Created by Corentin Comte on 12/06/2016.
//
//
#pragma once

#include "GlobalEnums.h"

class Attack {
    
public:
    
    Attack(std::string inName);
    
    ~Attack(){};
    
    // Getters
    std::string GetName() const;
    bool IsObvious() const;
    bool IsImpactingPlayer() const;
    bool IsImpactingTarget() const;
    int GetPlayerBonus() const;
    int GetTargetMalus() const;
    int GetBaseDamages() const;
    
    // Setters
    void SetAttackText1(std::string inText) { mAttackEffect1 = inText; };
    void SetAttackText2(std::string inText) { mAttackEffect2 = inText; };
    void SetAttackText3(std::string inText) { mAttackEffect3 = inText; };
    void SetFailedText1(std::string inText) { mAttackFailed1 = inText; };
    void SetFailedText2(std::string inText) { mAttackFailed2 = inText; };
    void SetFailedText3(std::string inText) { mAttackFailed3 = inText; };
    
    void SetObvious(bool inObvious) { mIsObvious = inObvious; };
    void SetImpactsPlayer(bool inImpact) { mImpactsPlayer = inImpact; };
    void SetPlayerBonus(int inBonus) { mPlayerBonus = inBonus; };
    
    // Tells to GUI the text to be displayed
    std::string GetAttackText(bool inIsSuccess) const;
    
protected:
    
    bool mIsObvious = false;
    
    bool mImpactsPlayer = false;
    int mPlayerBonus = 0;
    bool mImpactsTarget = false;
    int mTargetMalus = 0;
    
    int mBaseDamages = 0;
    
private:
    
    std::string mAttackName;
    
    // Texts used by the GUI
    std::string mAttackEffect1;
    std::string mAttackEffect2;
    std::string mAttackEffect3;
    
    std::string mAttackFailed1;
    std::string mAttackFailed2;
    std::string mAttackFailed3;
};
