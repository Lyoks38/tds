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
    
    Attack(){};
    
    Attack(const std::string inName);
    
    Attack(Attack const &other);
    
    ~Attack(){};
        
    // Getters
    std::string GetName() const;
    int GetDiceThreshold() const;
    bool IsImpactingPlayer() const;
    int GetPlayerImpact() const;
    int GetBaseDamages() const;
    std::string GetAttackText1() const { return mAttackEffect1 ; };
    std::string GetAttackText2() const { return mAttackEffect2 ; };
    std::string GetAttackText3() const { return mAttackEffect3 ; };
    std::string GetFailedText1() const { return mAttackFailed1 ; };
    std::string GetFailedText2() const { return mAttackFailed2 ; };
    std::string GetFailedText3() const { return mAttackFailed3 ; };

    
    // Setters
    void SetAttackText1(std::string inText) { mAttackEffect1 = inText; };
    void SetAttackText2(std::string inText) { mAttackEffect2 = inText; };
    void SetAttackText3(std::string inText) { mAttackEffect3 = inText; };
    void SetFailedText1(std::string inText) { mAttackFailed1 = inText; };
    void SetFailedText2(std::string inText) { mAttackFailed2 = inText; };
    void SetFailedText3(std::string inText) { mAttackFailed3 = inText; };
    
    void SetImpactsPlayer(bool inImpact) { mImpactsPlayer = inImpact; };
    void SetPlayerImpact(int inImpact) { mPlayerImpact = inImpact; };
    void SetBaseDamages(int inDamages) { mBaseDamages = inDamages; };
    void SetDiceThreshold(int inThresh) { mDiceThreshold = inThresh; };
    // Tells to GUI the text to be displayed
    std::string GetAttackText(bool inIsSuccess) const;
    
protected:
    
    bool mImpactsPlayer = false;
    int mPlayerImpact = 0;
    
    int mBaseDamages = 0;
    int mDiceThreshold = -1;
    
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
