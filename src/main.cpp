/*
 * Filename: tic_tac.cpp
 * Created Date: Monday, October 28th 2019, 3:03:26 pm
 * Author: mfalicoff
 * Copyright (c) 2019
 * 
 * Simple Tic Tac Toe game that requieres two player to play, plan to add computer opponent in the future
 * 
 */

#include "game.hpp"

int main()
{
    std::cout << "Hello, welcome to tic tac toe, please plut your signs" << std::endl;

    char sign1, sign2;
    std::cin >> sign1 >> sign2;

    game ticTacToe(sign1, sign2);
    int game = ticTacToe.run();
    return game;
}

