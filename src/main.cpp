/*
 * Filename: tic_tac.cpp
 * Created Date: Monday, October 28th 2019, 3:03:26 pm
 * Author: mfalicoff
 * Copyright (c) 2019
 * 
 * Simple Tic Tac Toe game that requieres two player to play, plan to add computer opponent in the future
 * 
 */

#include <iostream>
#include <iomanip>

using namespace std;

bool player;      //bool value 0 is player 2 and bool value 1 is player 1
char map[3][3] ;


void printmap();
void nextmove(int posX, int PosY, bool player);
bool isNextMovePoss(int posX, int PosY);
bool isgamewon();

int main(){

    int round = 1;
    //Initalizing map to underscrores
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            map[i][j] = '_';
        }
        
    }
    
    while (!isgamewon()){
        
        cout  << "-----------------" << "Round " << round << "-----------------" << endl;
        int posX, posY;
        cout << "Player 1, enter coordinates: ", cin >> posX >> posY;
        cout << endl;
        player = 1;
        nextmove(posX, posY, player);
        printmap();

        if(round == 5){
            break;
        }

        if(isgamewon())
            break;

        cout << "Player 2, enter coordinates: ", cin >> posX >> posY;
        cout << endl;
        player = 0;
        nextmove(posX, posY, player);
        printmap();
        
        cout << "------------------------------------------" << endl;


        round++;
        if(isgamewon())
            break;
    }
    
    cout << "Game ended, ";
    if(player && round < 5)
        cout << "Player 1 won the game in " << round - 1 << " rounds!!!!" << endl;
    else if(player == 0)
        cout << "Player 2 won the game in " << round - 1  << " rounds!!!!" << endl;
    else if (round == 5) cout << "in a tie" << endl;
}

void printmap(){

    cout << "=============" << endl;
    
    for(int i = 0; i < 3; i++){
        cout << "|" << setw(2) << map[i][0] << setw(2) <<  "|" << setw(2) << map[i][1] << setw(2) << "|" 
        << setw(2) << map[i][2] << setw(2) << "|" << endl;
        if(i < 2)
            cout << endl;
    }    
    cout << "=============" << endl;
    
}


void nextmove(int posX, int PosY, bool player){

    int spotX = posX - 1;
    int spotY = PosY - 1;

    if(player){
        while (!isNextMovePoss(posX, PosY))
        {
            cout << "Error, enter another set of coordiantes: ", cin >> posX >> PosY;
            spotX = posX - 1;
            spotY = PosY - 1;
        }
        map[spotX][spotY] = 'X';
            
       
    }else{

     while (!isNextMovePoss(posX, PosY))
        {
            cout << "Error, enter another set of coordiantes: ", cin >> posX >> PosY;
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
    else if((map[0][0] == map[1][0]) && (map[0][0] == map[2][0]) && (map[0][0] != '_' )) // first line down
        return true;
    else if ((map[0][0] == map[1][1]) && (map[0][0] == map[2][2]) && (map[0][0] != '_' )) // diagonal
        return true;
    else if( (map[2][0] == map[2][1]) && (map[2][0] == map[2][2]) && (map[2][0] != '_' )) //bottom line across
        return true;
    else if( (map[0][2] == map[1][2]) && (map[0][2] == map[2][2]) && (map[0][2] != '_' )) //line right down
        return true;
    else if( (map[1][0] == map[1][1]) && (map[1][0] == map[1][2]) && (map[1][0] != '_' )) //middle line
        return true;
    else
        return false;
}