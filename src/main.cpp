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
    
    while (!isgamewon()){
        
        std::cout  << "-----------------" << "Round " << round << "-----------------" << std::endl;
        int posX, posY;
        std::cout << "Player 1, enter coordinates: ", std::cin >> posX >> posY;
        std::cout << std::endl;
        player = 1;
        nextmove(posX, posY, player);
        printmap();

        if(round == 5){
            break;
        }

        if(isgamewon())
            break;

        std::cout << "Player 2, enter coordinates: ", std::cin >> posX >> posY;
        std::cout << std::endl;
        player = 0;
        nextmove(posX, posY, player);
        printmap();
        
        std::cout << "------------------------------------------" << std::endl;


        round++;
        if(isgamewon())
            break;
    }
    
    std::cout << "Game ended, ";
    if(player && round < 5)
        std::cout << "Player 1 won the game in " << round - 1 << " rounds!!!!" << std::endl;
    else if(player == 0)
        std::cout << "Player 2 won the game in " << round - 1  << " rounds!!!!" << std::endl;
    else if (round == 5) std::cout << "in a tie" << std::endl;
}

void printmap(){

    std::cout << "=============" << std::endl;
    
    for(int i = 0; i < 3; i++){
        std::cout << "|" << std::setw(2) << map[i][0] << std::setw(2) <<  "|" << std::setw(2) << map[i][1] << std::setw(2) << "|" 
        << std::setw(2) << map[i][2] << std::setw(2) << "|" << std::endl;
        if(i < 2)
            std::cout << std::endl;
    }    
    std::cout << "=============" << std::endl;
    
}


void nextmove(int posX, int PosY, bool player){

    int spotX = posX - 1;
    int spotY = PosY - 1;

    if(player){
        while (!isNextMovePoss(posX, PosY))
        {
            std::cout << "Error, enter another set of coordiantes: ", std::cin >> posX >> PosY;
            spotX = posX - 1;
            spotY = PosY - 1;
        }
        map[spotX][spotY] = 'X';
            
       
    }else{

     while (!isNextMovePoss(posX, PosY))
        {
            std::cout << "Error, enter another set of coordiantes: ", std::cin >> posX >> PosY;
            spotX = posX - 1;
            spotY = PosY - 1;
        }
        map[spotX][spotY] = 'O';
            
    }

   


}

bool isNextMovePoss(int posX, int PosY){
    if(posX > 3 || posX <= 0 || PosY > 3 || PosY <= 0 || map[posX-1][PosY-1]  == 'O' || map[posX-1][PosY-1] == 'X')
        return false;
    else
        return true;
        
}

bool isgamewon(){

    if((map[0][0] == map[0][1]) && (map[0][0] == map[0][2]) && (map[0][0] != '_' )) //First line across
        return true;
    else if( (map[1][0] == map[1][1]) && (map[1][0] == map[1][2]) && (map[1][0] != '_' )) //Second line across
        return true;
    else if( (map[2][0] == map[2][1]) && (map[2][0] == map[2][2]) && (map[2][0] != '_' )) //Third line across
        return true;

    else if((map[0][0] == map[1][0]) && (map[0][0] == map[2][0]) && (map[0][0] != '_' )) // first line down
        return true;
    else if((map[0][1] == map[1][1]) && (map[0][1] == map[2][1]) && (map[0][1] != '_' )) // Second line down
        return true;
    else if( (map[0][2] == map[1][2]) && (map[0][2] == map[2][2]) && (map[0][2] != '_' )) //Third right down
        return true;


    else if ((map[0][0] == map[1][1]) && (map[0][0] == map[2][2]) && (map[0][0] != '_' )) // diagonal right
        return true;
    else if ((map[0][2] == map[1][1]) && (map[0][2] == map[2][0]) && (map[0][2] != '_' )) // diagonal left
        return true;




    return false;
}