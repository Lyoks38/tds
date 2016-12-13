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
    mAttack1 = new NiceComponent("Attack 1");
    mAttack1->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mAttack1->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mAttack1->SetTextColor(juce::Colours::white);
    mAttack1->SetTextHoverColor(juce::Colour(230, 230, 230));
    mAttack1->setBounds(50, 0, 225, 55);
    mAttack1->AddListener(this);
    
    mAttack2 = new NiceComponent("Attack 2");
    mAttack2->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mAttack2->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mAttack2->SetTextColor(juce::Colours::white);
    mAttack2->SetTextHoverColor(juce::Colour(230, 230, 230));
    mAttack2->setBounds(325, 0, 225, 55);
    mAttack2->AddListener(this);
    
    mAttack3 = new NiceComponent("Attack 3");
    mAttack3->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mAttack3->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mAttack3->SetTextColor(juce::Colours::white);
    mAttack3->SetTextHoverColor(juce::Colour(230, 230, 230));
    mAttack3->setBounds(50, 80, 225, 55);
    mAttack3->AddListener(this);
    
    mAttack4 = new NiceComponent("Attack 4");
    mAttack4->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mAttack4->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mAttack4->SetTextColor(juce::Colours::white);
    mAttack4->SetTextHoverColor(juce::Colour(230, 230, 230));
    mAttack4->setBounds(325, 80, 225, 55);
    mAttack4->AddListener(this);

    mCatchButton = new NiceComponent("Catch Button");
    mCatchButton->SetTextToDisplay("Essayer de la choper");
    mCatchButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mCatchButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mCatchButton->SetTextColor(juce::Colours::white);
    mCatchButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mCatchButton->setBounds(100, 230, 400, 60);
    mCatchButton->AddListener(this);
    
    mNextTarget = new NiceComponent("Skip Target");
    mNextTarget->SetTextToDisplay("Passer à la target suivante");
    mNextTarget->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mNextTarget->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mNextTarget->SetTextColor(juce::Colours::white);
    mNextTarget->SetTextHoverColor(juce::Colour(230, 230, 230));
    mNextTarget->setBounds(200, 300, 200, 40);
    mNextTarget->AddListener(this);
    
    addAndMakeVisible(mAttack1);
    addAndMakeVisible(mAttack2);
    addAndMakeVisible(mAttack3);
    addAndMakeVisible(mAttack4);
    addAndMakeVisible(mCatchButton);
    addAndMakeVisible(mNextTarget);

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
AttackResultPanel::AttackResultPanel()
{
    
}

AttackResultPanel::~AttackResultPanel()
{
    
}




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


void CombatPage::LoadInfos()
{
    mAttackTabbedPanel->SetAttacks(mManager->DeliverAttacks());
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










