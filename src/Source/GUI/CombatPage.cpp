//
//  CombatPage.cpp
//  TDS
//
//  Created by Corentin Comte on 09/12/2016.
//
//

#include "CombatPage.h"
#include "FontUtils.h"
#include "MainComponent.h"


////////////////////////////////////////////////////////////////
// AttackTabbedGroup
AttackTabbedGroup::AttackTabbedGroup():
juce::Component("Attack Tabbed Group")
{
    
}

AttackTabbedGroup::~AttackTabbedGroup()
{
    removeAllChildren();
}

void AttackTabbedGroup::SendAttackToManager(Attack inAttack)
{
    CombatPage* parent = dynamic_cast<CombatPage*>(getParentComponent());
    if(parent)
        parent->SendAttackToManager(inAttack);
}

void AttackTabbedGroup::SendTryToCatchToManager()
{
    CombatPage* parent = dynamic_cast<CombatPage*>(getParentComponent());
    if(parent)
        parent->SendTryToCatchToManager();
}

void AttackTabbedGroup::SendNextTargetToManager()
{
    CombatPage* parent = dynamic_cast<CombatPage*>(getParentComponent());
    if(parent)
        parent->SendNextTargetToManager();
}

void AttackTabbedGroup::onNiceComponentClicked(NiceComponent *inComp)
{
    //Attacks
    if(inComp == mAttack1)
        SendAttackToManager(mAttacks[0]);
    else if (inComp == mAttack2)
        SendAttackToManager(mAttacks[1]);
    else if (inComp == mAttack3)
        SendAttackToManager(mAttacks[2]);
    else if (inComp == mAttack4)
        SendAttackToManager(mAttacks[3]);
    //Try to catch
    else if(inComp == mCatchButton)
        SendTryToCatchToManager();
    //Skip target
    else if (inComp == mNextTarget)
        SendNextTargetToManager();
    
}


void AttackTabbedGroup::SetAttacks(std::vector<Attack> inAttacks)
{
    if(inAttacks.size() == 4){
        
        mAttacks = inAttacks;
        
        mAttack1->SetTextToDisplay(mAttacks[0].GetName());
        mAttack2->SetTextToDisplay(mAttacks[1].GetName());
        mAttack3->SetTextToDisplay(mAttacks[2].GetName());
        mAttack4->SetTextToDisplay(mAttacks[3].GetName());
    }
}


void AttackTabbedGroup::paint(juce::Graphics &inG)
{
    //NOTHING TO DO
}

////////////////////////////////////////////////////////////////
// Attack Result Panel





////////////////////////////////////////////////////////////////
// CombatPage
CombatPage::CombatPage():
juce::Component("Combat Page")
{
    
    mAttackTabbedPanel.reset(new AttackTabbedGroup());
    mAttackTabbedPanel->setBounds(100, 250, 600, 350);
    addChildComponent(mAttackTabbedPanel.get());
    
    mAttackResultPanel.reset(new AttackResultPanel());
    mAttackResultPanel->setBounds(100, 250, 600, 350);
    addChildComponent(mAttackResultPanel.get());
    
    mMainFont = FontUtils::OrangeJuice;
}

CombatPage::~CombatPage()
{
    removeAllChildren();
}


void CombatPage::SendAttackToManager(Attack inAttack)
{
    if(mManager)
        mManager->HandleAttack(inAttack);
}

void CombatPage::SendNextTargetToManager()
{
    if(mManager)
        mManager->GoToNextTarget();
}

void CombatPage::SendTryToCatchToManager()
{
    if(mManager)
        mManager->TryToCatch();
}


void CombatPage::DisplayAttacks()
{
    mAttackResultPanel->setEnabled(false);
    mAttackResultPanel->setVisible(false);
    
    mAttackTabbedPanel->setEnabled(true);
    mAttackTabbedPanel->setVisible(true);
}

void CombatPage::DisplayResult()
{
    mAttackTabbedPanel->setEnabled(false);
    mAttackTabbedPanel->setVisible(false);
    
    mAttackResultPanel->setEnabled(true);
    mAttackResultPanel->setVisible(true);

}










