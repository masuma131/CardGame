//CardGameAdapter.h - class for the cardgame adaptor

#ifndef _CARDGAMEADAPTER_H_
#define _CARDGAMEADAPTER_H_

#include <iostream>


class CardGameAdapter{
public:
    virtual void run() = 0;
    virtual void setMode(int) = 0;
    virtual ~CardGameAdapter() {};
};


#endif //_CARDGAMEADAPTER_H_

