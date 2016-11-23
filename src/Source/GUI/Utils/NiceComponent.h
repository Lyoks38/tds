//
//  NiceComponent.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef NiceComponent_h
#define NiceComponent_h


#include "GuiUtils.h"
#include "NiceComponentListener.h"

//class NiceComponentListener;

class NiceComponent: public juce::Component
{
    
public:
    
    NiceComponent(const std::string& inName);
    
    ~NiceComponent(){};
    
    
    virtual void paint(juce::Graphics& inG) override;
    
    virtual void mouseEnter(const juce::MouseEvent& e) override { if(isEnabled()) repaint(); }
    virtual void mouseExit(const juce::MouseEvent& e)  override { if(isEnabled()) repaint(); }
    virtual void mouseDown(const juce::MouseEvent& e)  override;

    //Setters
    void SetTextToDisplay(std::string inText) { mTextToDisplay = inText; }
    void SetJustification(juce::Justification inJustification) { mJustification = inJustification; }
    void SetBgColor(const juce::Colour& inColour) { mBgColor = inColour; }
    void SetBgHoverColor(const juce::Colour& inColour) { mBgHoverColor = inColour; }
    void SetTextColor(const juce::Colour& inColour) { mTextColor = inColour; }
    void SetTextHoverColor(const juce::Colour& inColour) { mTextHoverColor = inColour; }
    void SetFont(juce::Font inFont) { mFont = inFont; }
    
    //Listeners
    void AddListener(NiceComponentListener* inListener);
    
protected:
    
    std::string mTextToDisplay;
    juce::Font mFont;
    float mFontSize = 16.f;
    juce::Justification mJustification = juce::Justification::centred;
    
    juce::Colour mBgColor = juce::Colours::transparentWhite;
    juce::Colour mBgHoverColor = juce::Colours::transparentWhite;
    juce::Colour mTextColor = juce::Colours::black;
    juce::Colour mTextHoverColor = juce::Colours::black;
    juce::Colour mDisabledColor = juce::Colour((uint8)127,127,127,0.5f);
    
private:
    
    std::vector<NiceComponentListener*> mListeners;
};

#endif /* NiceComponent_h */
