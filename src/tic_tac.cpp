#include <iostream>
#include <iomanip>

using namespace std;
const char map[2][2] = {'O'};

void printmap();
void nextmove(int posX, int PosY);
bool isNextMovePoss(int posX, int PosY);

int main(){

    cout << isNextMovePoss(0, 2);    
    
}

void printmap(){

    cout << "===================" << endl;
    for(int i = 0; i < 3; i++){
        cout << "|     |     |     |"  << endl;
        cout << " ----- ----- -----" << endl;
    }
    cout << "===================" << endl;

    
}

/*
void nextmove(int posX, int PosY){

}*/

bool isNextMovePoss(int posX, int PosY){
    if(posX > 3 || posX <= 0 || PosY > 3 || PosY <= 0)
        return false;
    else
        return true;
        
}