#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include "Globals.h"
#include "State.h"
#include "AI.h"

class ConnectFour
{
public:
    ConnectFour();
    ~ConnectFour();

    void init();
    void start();
    
private:
    State *state;
    AI *bot;
    int curPlayer;

    void humanTurn();
    void botTurn();
};

#endif
