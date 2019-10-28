#include <iostream>
#include <iomanip>

using namespace std;

void printmap();

int main(){

    printmap();
    return 0;
}

void printmap(){

    cout << "===================" << endl;
    for(int i = 0; i < 3; i++){
        cout << "|     |     |     |"  << endl;
        cout << " ----- ----- -----" << endl;
    }
    cout << "===================" << endl;

    
}
