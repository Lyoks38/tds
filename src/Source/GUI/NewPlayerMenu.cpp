//
//  NewPlayerMenu.cpp
//  TDS
//
//  Created by Corentin Comte on 14/11/2016.
//
//

#include "NewPlayerMenu.h"
#include "FontUtils.h"


NewPlayerMenu::NewPlayerMenu():
juce::Component("New Player Menu")
{
    mMainFont = FontUtils::OrangeJuice;
    mMainFont.setHeight(50.f);
}

void NewPlayerMenu::paint(juce::Graphics& inG)
{
    inG.setFont(mMainFont);
    inG.setColour(juce::Colours::white);
    inG.drawText("Create New Player Here", 0, 0, getWidth(), 150, juce::Justification::centred);
}
