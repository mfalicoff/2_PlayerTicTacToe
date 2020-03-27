#include "include.h"
#include "game.h"

void printmap(char (&map)[3][3])
{

    std::cout << "=============" << std::endl;
    
    for(int i = 0; i < 3; i++){
        std::cout << "|" << std::setw(2) << map[i][0] << std::setw(2) <<  "|" << std::setw(2) << map[i][1] << std::setw(2) << "|" 
        << std::setw(2) << map[i][2] << std::setw(2) << "|" << std::endl;
        if(i < 2)
            std::cout << std::endl;
    }    
    std::cout << "=============" << std::endl;
    
}


void nextmove(int posX, int PosY, bool player, char (&map)[3][3])
{

    int spotX = posX - 1;
    int spotY = PosY - 1;

    if(player){
        while (!isNextMovePoss(posX, PosY, map))
        {
            std::cout << "Error, enter another set of coordiantes: ", std::cin >> posX >> PosY;
            spotX = posX - 1;
            spotY = PosY - 1;
        }
        map[spotX][spotY] = 'X';
            
       
    }else{

     while (!isNextMovePoss(posX, PosY, map))
        {
            std::cout << "Error, enter another set of coordiantes: ", std::cin >> posX >> PosY;
            spotX = posX - 1;
            spotY = PosY - 1;
        }
        map[spotX][spotY] = 'O';
            
    }

   


}

bool isNextMovePoss(int posX, int PosY, char (&map)[3][3]){
    if(posX > 3 || posX <= 0 || PosY > 3 || PosY <= 0 || map[posX-1][PosY-1]  == 'O' || map[posX-1][PosY-1] == 'X')
        return false;
    else
        return true;
        
}

bool isgamewon(char (&map)[3][3])
{
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