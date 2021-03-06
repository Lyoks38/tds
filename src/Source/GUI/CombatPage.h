//
//  CombatPage.h
//  TDS
//
//  Created by Corentin Comte on 09/12/2016.
//
//

#ifndef CombatPage_h
#define CombatPage_h

#include "GuiUtils.h"
#include "Utils/NiceComponent.h"
#include "Utils/NiceComponentListener.h"

#include "../CombatManager.h"


/////////////////////////////////////////////////////////////
// AttackTabbedGroup class
class AttackTabbedGroup: public juce::Component, public NiceComponentListener
{
    
public:
    
    AttackTabbedGroup();
    
    ~AttackTabbedGroup();
    
    void paint(juce::Graphics& inG) override;
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
    void SendAttackToManager(Attack inAttack);
    void SendTryToCatchToManager();
    void SendNextTargetToManager();
    
    void SetAttacks(std::vector<Attack> inAttacks); //make sure the size is equal to 4
    
private:
    
    NiceComponent* mAttack1;
    NiceComponent* mAttack2;
    NiceComponent* mAttack3;
    NiceComponent* mAttack4;
    
    std::vector<Attack> mAttacks; //make sure the size is equal to 4
    
    NiceComponent* mCatchButton;
    NiceComponent* mNextTarget;

};



/////////////////////////////////////////////////////////////
// ResultPanel class
enum GoTo {
    NEW_ATTACK = 0,
    NEW_TARGET,
    END_EVENT
} typedef GoTo;

class AttackResultPanel: public juce::Component, public NiceComponentListener
{
    
public:
    
    AttackResultPanel();
    
    ~AttackResultPanel();
    
    void paint(juce::Graphics& inG) override;
    
    void onNiceComponentClicked(NiceComponent* inComp) override;
    
    void SetText(std::string inText) { mTextToDisplay = inText; }
    void SetGoTo(GoTo inWhereToGo) { mWhereToGo = inWhereToGo; }
    
private:
    
    std::string mTextToDisplay;
    
    GoTo mWhereToGo = NEW_ATTACK;
    
    NiceComponent* mContinueButton;
};



/////////////////////////////////////////////////////////////
// Main page class
class CombatPage: public juce::Component
{
    
public:
    
    CombatPage();
    
    ~CombatPage();
    
    void LinkToCombatManager(CombatManager* inManager) { mManager = inManager; }
    bool IsCombatManagerLinked() { return mManager != nullptr; }

    void SendAttackToManager(Attack inAttack);
    void SendTryToCatchToManager();
    void SendNextTargetToManager();
    void SendEndEventToManager();
    
    void DisplayAttacks();
    void DisplayResult(std::string inText, GoTo inWhereToGo);
    
    void LoadInfos();
    
    void paint(juce::Graphics& inG) override;

private:
    
    std::unique_ptr<AttackTabbedGroup> mAttackTabbedPanel = nullptr;
    std::unique_ptr<AttackResultPanel> mAttackResultPanel = nullptr;
    
    CombatManager* mManager = nullptr;
    
    juce::Font mMainFont;

};

#endif /* CombatPage_h */
