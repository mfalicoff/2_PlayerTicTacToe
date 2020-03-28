#pragma once
#include <iostream>
#include <iomanip>
#include "include.h"
#include "position.h"

class player {

public:

    player(char sign, int playerNum);
    position nextMove();
    position nextMoveMulTries();
    
    char getSign() const;
    int getPlayerNum() const;

private:
    char sign_;
    int playerNumber_;

};