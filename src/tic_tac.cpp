#include <iostream>
#include <iomanip>

using namespace std;
int map[3][3] = {};

void printmap();
void nextmove(int posX, int PosY);
bool isNextMovePoss(int posX, int PosY);

int main(){

    nextmove(3,2);
    //cout << map[3][2] << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++ ){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    printmap();
    
}

void printmap(){

    cout << "=============" << endl;
    for(int i = 0; i < 3; i++){
        cout << "|" << setw(2) << map[i][0] << setw(2) <<  "|" << setw(2) << map[i][1] << setw(2) << "|" 
        << setw(2) << map[i][2] << setw(2) << "|" << endl;
        cout << " --- --- ---" << endl;
    }
    cout << "=============" << endl;

    
}


void nextmove(int posX, int PosY){

    int spotX = posX - 1;
    int spotY = PosY - 1;
    char X = 'X';

    if(isNextMovePoss(posX, PosY)){
        if(map[spotX][spotY] == 0)
            map[spotX][spotY] = 1;
        else
            cout << "Error, position already occupied";
    }else
        cout << "Move out of boundary";


}

bool isNextMovePoss(int posX, int PosY){
    if(posX > 3 || posX <= 0 || PosY > 3 || PosY <= 0)
        return false;
    else
        return true;
        
}