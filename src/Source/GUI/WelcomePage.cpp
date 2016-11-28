//
//  WelcomePage.cpp
//  TDS
//
//  Created by Corentin Comte on 24/11/2016.
//
//

#include "WelcomePage.h"
#include "Utils/FontUtils.h"
#include "../MainComponent.h"

WelcomePage::WelcomePage(const std::string& inPlayerName): juce::Component("Welcome Page")
{
    mPlayerName = inPlayerName;
    
    mNextButton = new NiceComponent("Welcome Next Button");
    
    mNextButton->SetTextToDisplay("Suivant");
    
    mNextButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mNextButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mNextButton->SetTextColor(juce::Colours::white);
    mNextButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mNextButton->setBounds(700, 540, 70, 25);
    mNextButton->AddListener(this);
    addAndMakeVisible(mNextButton);
    
    mStartButton = new NiceComponent("Start New Game");
    mStartButton->SetTextToDisplay("COMMENCER");
    mStartButton->SetBgColor(juce::Colour((uint8)255,255,255,0.2f));
    mStartButton->SetBgHoverColor(juce::Colour((uint8)255,255,255,0.5f));
    mStartButton->SetTextColor(juce::Colours::white);
    mStartButton->SetTextHoverColor(juce::Colour(230, 230, 230));
    mStartButton->setBounds(200, 530, 400, 55);
    mStartButton->AddListener(this);
    addChildComponent(mStartButton);
    mStartButton->setVisible(false);
    mStartButton->setEnabled(false);

    
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(60.f);
}

WelcomePage::~WelcomePage()
{
    removeAllChildren();
}

void WelcomePage::paint(juce::Graphics &inG)
{
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText("Bienvenue dans TDS !", 0, 0, getWidth(), 150, juce::Justification::centred);
    
    inG.setFont(juce::Font(20.f));
    
    switch (mCurrentPage) {
        case INTRO:
            inG.drawMultiLineText("Bienvenue à Phelma, " + mPlayerName + "! " + kIntroText, 200, 170, 400);
            break;
        case GOALS:
            inG.drawMultiLineText(kGoalsText, 200, 170, 400);
            break;
        case GAMEPLAY:
            inG.drawMultiLineText(kGameplayText, 200, 170, 400);
            break;
        case COMMANDE:
            inG.drawMultiLineText(kCommandeText, 200, 170, 400);
            break;
        case START:
            inG.drawText("Pret a te lancer ?", 200, 170, 400, 120, juce::Justification::centred);
            break;
        default:
            break;
    }
    
}


void WelcomePage::onNiceComponentClicked(NiceComponent *inComp)
{
    if(inComp == mNextButton){
        mCurrentPage++;
        if(mCurrentPage > START)
            mCurrentPage = 0;
        else if(mCurrentPage == START){
            mNextButton->setVisible(false);
            mNextButton->setEnabled(false);
            mStartButton->setVisible(true);
            mStartButton->setEnabled(true);
        }
        
        repaint();
    }
    else if(inComp == mStartButton){
        
        //TODO : launch the game !
    }
}


const std::string WelcomePage::kIntroText = "Tu as fait le bon choix en venant dans cette école.\n"
"Tu vas voir, les cours sont super intéressants, les profs sont compétents, on est vraiment à la pointe "
"de la technologie... Nan, je déconne ! On est là pour picoler comme des enculés ! Et pour picoler, "
"on a tout ce qu'il faut : soirées, kfets, afters chez Bouvet...\n"
"Et qui dit soirées, dit chasse à la gazelle ! Parce bon, on va pas se mentir, t'es célibataire, hein ? La prépa scientifique tout ça... "
"Ouais ouais, on la connaît l'excuse. Bref, maintenant tu vas pouvoir enfin te lâcher et choper de la zouz ! Ou du moins essayer... "
"Et puis si ça se trouve, tu vas peut-être même pouvoir te trouver une copine ! Mais bon, on commencer doucement, hein.\n"
"Allez, viens. Ton intégration va commencer !";

const std::string WelcomePage::kGoalsText = "A la fin de l'année, le Cercle organise une kfet Awards, qui permet de récompenser "
"les 1A ayant eu un comportement exemplaire durant l'année écoulée : Mister Pichet, Miss Boobs, Mister Blague pas drôles, etc. "
"Mais si tu es ici, c'est parce que tu convoites le titre prestigieux de... Mister Chope ! Laisse moi t'expliquer comment y arriver...";

const std::string WelcomePage::kGameplayText = "Tu vas participer à plusieurs évènements tout au long de cette année. Ceux-ci se "
"décomposent en deux catégories : les soirées et les kfets. Durant ces évènements, tu vas aller aborder différentes filles, "
"dans l'espoir d'un échange de salive par lèvres interposées. Les choper quoi.\n"
"Seulement, attention ! On ne chope pas de l'ingée comme ça ! Il faut quand même la séduire un peu, sinon rien ne l'empêchera "
"d'aller choper ton pote qui lui va à la salle tous les deux jours et qui mange pas tacos toutes les semaines comme toi.";

const std::string WelcomePage::kCommandeText = "Lors d'un événement, tu auras droit à un nombre d'actions fixes : 30 actions par soirée, "
"10 par kfet. Ces actions te serviront à séduire les différentes ”targets” possibles de l'événement.\nMais fais très attention ! "
"Ces actions peuvent être à double tranchant : si tu es trop direct avec la gente demoiselle, ne t'étonne pas de te prendre une baffe ! "
"Ou si tu tentes trop de la saoûler, elle finira peut-être par te vomir sur les pieds...\nAh oui, et ne bois pas trop, ça serait con de finir "
"en PLS...";
