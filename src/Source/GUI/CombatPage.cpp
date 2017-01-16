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
    mAttack1->setBounds(0, 0, 275, 55);
    mAttack1->AddListener(this);
    
    mAttack2 = new NiceComponent("Attack 2");
    mAttack2->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mAttack2->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mAttack2->SetTextColor(juce::Colours::white);
    mAttack2->SetTextHoverColor(juce::Colour(230, 230, 230));
    mAttack2->setBounds(325, 0, 275, 55);
    mAttack2->AddListener(this);
    
    mAttack3 = new NiceComponent("Attack 3");
    mAttack3->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mAttack3->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mAttack3->SetTextColor(juce::Colours::white);
    mAttack3->SetTextHoverColor(juce::Colour(230, 230, 230));
    mAttack3->setBounds(0, 80, 275, 55);
    mAttack3->AddListener(this);
    
    mAttack4 = new NiceComponent("Attack 4");
    mAttack4->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mAttack4->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mAttack4->SetTextColor(juce::Colours::white);
    mAttack4->SetTextHoverColor(juce::Colour(230, 230, 230));
    mAttack4->setBounds(325, 80, 275, 55);
    mAttack4->AddListener(this);

    mCatchButton = new NiceComponent("Catch Button");
    mCatchButton->SetTextToDisplay("Essayer de la choper");
    mCatchButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mCatchButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mCatchButton->SetTextColor(juce::Colours::white);
    mCatchButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mCatchButton->setBounds(100, 200, 400, 60);
    mCatchButton->AddListener(this);
    
    mNextTarget = new NiceComponent("Skip Target");
    mNextTarget->SetTextToDisplay("Passer à la target suivante");
    mNextTarget->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mNextTarget->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mNextTarget->SetTextColor(juce::Colours::white);
    mNextTarget->SetTextHoverColor(juce::Colour(230, 230, 230));
    mNextTarget->setBounds(200, 270, 200, 40);
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
    deleteAllChildren();
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
    mContinueButton = new NiceComponent("Next Action");
    mContinueButton->SetTextToDisplay("Continuer");
    mContinueButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mContinueButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mContinueButton->SetTextColor(juce::Colours::white);
    mContinueButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mContinueButton->setBounds(200, 270, 200, 40);
    mContinueButton->AddListener(this);
    
    addAndMakeVisible(mContinueButton);
}

AttackResultPanel::~AttackResultPanel()
{
    deleteAllChildren();
}

void AttackResultPanel::paint(juce::Graphics& inG)
{
    inG.setColour(juce::Colours::white);
    inG.setFont(juce::Font(20));
    
    inG.drawMultiLineText(mTextToDisplay, 100, 50, 400);
    
}


void AttackResultPanel::onNiceComponentClicked(NiceComponent *inComp)
{
    switch (mWhereToGo) {
        case END_EVENT:{
            CombatPage* parent = dynamic_cast<CombatPage*>(getParentComponent());
            if(parent){
                parent->SendEndEventToManager();
            }
            break;
        }
        case NEW_ATTACK:{
            CombatPage* parent = dynamic_cast<CombatPage*>(getParentComponent());
            if(parent){
                parent->LoadInfos();
                parent->DisplayAttacks();
            }
        }
            break;
        case NEW_TARGET:{
            CombatPage* parent = dynamic_cast<CombatPage*>(getParentComponent());
            if(parent)
                parent->SendNextTargetToManager();
        }
            break;
            
        default:
            break;
    }
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
    mMainFont.setHeight(70.f);

}

CombatPage::~CombatPage()
{
    deleteAllChildren();
}


void CombatPage::paint(juce::Graphics &inG)
{
    juce::Image banner = mManager->GetBanner();
    
    inG.drawImage(banner, 0, 0, getWidth(), 200, 0, 0, banner.getWidth(), 200);
    
    inG.setColour(juce::Colours::white.withAlpha(0.4f));
    inG.fillRect(0, 0, getWidth(), 200);
    
    juce::ColourGradient grad = juce::ColourGradient(Colour (0xff001F36), 0, 200, Colour (0xff001F36).withAlpha(0.f), 0, 0, false);
    inG.setGradientFill(grad);
    inG.fillRect(0, 0, getWidth(), 200);
    
    const Girl* currentTarget = mManager->GetCurrentTarget();
    
    std::string subtitle = GirlGenreToString(currentTarget->GetGenre()) + ", " + ListToString(currentTarget->GetListe());
    
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText(currentTarget->GetName(), 0, 10, getWidth(), 100, juce::Justification::centred);
    inG.setFont(35.f);
    inG.drawText(subtitle, 0, 80, getWidth(), 100, juce::Justification::centred);

    int nbActions = mManager->GetRemainingActions();
    inG.setFont(Font(16.f));
    inG.drawText("Actions restantes :", 620, 450, 150, 30, juce::Justification::centred);
    inG.drawText(std::to_string(nbActions), 620, 475, 150, 30, juce::Justification::centred);
    
    //Barre de sobriété du joueur
    float sober = mManager->GetDrunkIndex() / 100.f;
    juce::Colour colour;
    if(sober >= 0.4f)
        colour = juce::Colour(0xff25c73a);
    else if(sober >= 0.15f)
        colour = juce::Colour(0xffffb429);
    else
        colour = juce::Colour(0xfff44e47);
    
    inG.setColour(colour);
    inG.fillRoundedRectangle(30.f, 486.f, 120.f * sober, 12.f, 5.f);
    inG.setColour(juce::Colours::white);
    inG.drawRoundedRectangle(30.f, 486.f, 120.f, 12.f, 5.f, 2.f);

    inG.drawText("Sobriete :", 30, 450, 120, 30, juce::Justification::centred);
    
    sober = currentTarget->GetDefense() / 100.f;
    if(sober >= 0.4f)
        colour = juce::Colour(0xff25c73a);
    else if(sober >= 0.15f)
        colour = juce::Colour(0xffffb429);
    else
        colour = juce::Colour(0xfff44e47);
    
    inG.setColour(colour);
    inG.fillRoundedRectangle(100.f, 220.f, 600.f * sober, 12.f, 5.f);
    inG.setColour(juce::Colours::white);
    inG.drawRoundedRectangle(100, 220.f, 600.f, 12.f, 5.f, 2.f);
    
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

void CombatPage::SendEndEventToManager()
{
    if(mManager)
        mManager->EndEvent();
}

void CombatPage::DisplayAttacks()
{
    mAttackResultPanel->setEnabled(false);
    mAttackResultPanel->setVisible(false);
    
    mAttackTabbedPanel->setEnabled(true);
    mAttackTabbedPanel->setVisible(true);
    
    repaint();
}

void CombatPage::DisplayResult(std::string inText, GoTo inWhereToGo)
{
    mAttackTabbedPanel->setEnabled(false);
    mAttackTabbedPanel->setVisible(false);
    
    mAttackResultPanel->SetText(inText);
    mAttackResultPanel->SetGoTo(inWhereToGo);
    mAttackResultPanel->setEnabled(true);
    mAttackResultPanel->setVisible(true);
    
    repaint();
}










