//
//  NiceComponentListener.h
//  TDS
//
//  Created by Corentin Comte on 14/11/2016.
//
//

#ifndef NiceComponentListener_h
#define NiceComponentListener_h

class NiceComponent;

class NiceComponentListener
{
public:
    
    NiceComponentListener(){};
    
    virtual ~NiceComponentListener(){};

    virtual void onNiceComponentClicked(NiceComponent* inComp) = 0;
};


#endif /* NiceComponentListener_h */
