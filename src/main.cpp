/*
 * Filename: tic_tac.cpp
 * Created Date: Monday, October 28th 2019, 3:03:26 pm
 * Author: mfalicoff
 * Copyright (c) 2019
 * 
 * Simple Tic Tac Toe game that requieres two player to play, plan to add computer opponent in the future
 * 
 */

#include "include.h"
#include "game.h"


bool player;      //bool value 0 is player 2 and bool value 1 is player 1
char map[3][3] ;

int main(){

    int round = 1;
    //Initalizing map to underscrores
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            map[i][j] = '_';
        }
    }
    
    while (!isgamewon(map)){
        
        std::cout  << "-----------------" << "Round " << round << "-----------------" << std::endl;
        int posX, posY;
        std::cout << "Player 1, enter coordinates: ", std::cin >> posX >> posY;
        std::cout << std::endl;
        player = 1;
        nextmove(posX, posY, player, map);
        printmap(map);

        if(round == 5){
            break;
        }

        if(isgamewon(map))
            break;

        std::cout << "Player 2, enter coordinates: ", std::cin >> posX >> posY;
        std::cout << std::endl;
        player = 0;
        nextmove(posX, posY, player, map);
        printmap(map);
        
        std::cout << "------------------------------------------" << std::endl;


        round++;
        if(isgamewon(map))
            break;
    }
    
    std::cout << "Game ended, ";
    if(player && round < 5)
        std::cout << "Player 1 won the game in " << round - 1 << " rounds!!!!" << std::endl;
    else if(player == 0)
        std::cout << "Player 2 won the game in " << round - 1  << " rounds!!!!" << std::endl;
    else if (round == 5) std::cout << "in a tie" << std::endl;
}

