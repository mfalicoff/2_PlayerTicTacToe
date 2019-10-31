#include <iostream>
#include <iomanip>

using namespace std;

bool player; //if player == 0, then player 1 is playing
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
        //palyer1
        cout << "Player 1, enter coordinates: ", cin >> posX >> posY;
        cout << endl;
        player = 0;
        nextmove(posX, posY, player);
        printmap();

        cout << "Player 2, enter coordinates: ", cin >> posX >> posY;
        cout << endl;
        player = 1;
        nextmove(posX, posY, player);
        printmap();
        round++;
        cout << "------------------------------------------" << endl;

    }
    
    cout << "game ended";
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
        if(isNextMovePoss(posX, PosY)){
            if(map[spotX][spotY] == '_')
                map[spotX][spotY] = 'X';
            else
                cout << "Error, position already occupied";
        }else
            cout << "Move out of boundary";
    }else{
        if(isNextMovePoss(posX, PosY)){
            if(map[spotX][spotY] == '_')
                map[spotX][spotY] = 'O';
        else
            cout << "Error, position already occupied";
        }else
        cout << "Move out of boundary";
    }

   


}

bool isNextMovePoss(int posX, int PosY){
    if(posX > 3 || posX <= 0 || PosY > 3 || PosY <= 0)
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