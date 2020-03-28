#pragma once
#include <iostream>
#include <iomanip>
#include<algorithm> 
#include "position.h"
#include "player.hpp"

class game {

public:

    game(char sign1, char sign2);
    int run();

    void printmap();
    bool isNextMovePoss(const position& pos);
    void playNextMovePlayer1();
    void playNextMovePlayer2();
    bool isgamewon();

    int getRound() const;
    void incrementRound();
    void endGame(int winner);

    int minimax(int depth, bool isMax);
    position findbestMove();

private:

    int round_;
    char gameMap_[3][3];
    player player1_;
    player player2_;
    int spaceLeft_;
    int winner_;



};