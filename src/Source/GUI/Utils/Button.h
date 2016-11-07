//
//  Button.h
//  TDS
//
//  Created by Corentin Comte on 07/11/2016.
//
//

#ifndef Button_h
#define Button_h

#include "GuiUtils.h"
#include "NiceComponent.h"


class Button: public NiceComponent
{
    
public:
    
    Button(const std::string& inName);
    
    ~Button(){};
    
    
    virtual void paint(juce::Graphics& inG) override;
    
    void SetToggleState(uint8_t inState);
    
    
private:
    
    uint8_t mToggleState = 0;
    
};


#endif /* Button_h */
