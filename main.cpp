#include <iostream>
#include "boardGenerator.h"

//g++ main.cpp -o demo
//g++ -c main.cpp
//g++ -c boardGenerator.cpp

//g++ -o demo boardGenerator.o main.o

using namespace std;

vector<string>board; 

const int WIDTH = 25;
const int HEIGHT = 25;

int main() {

    vector<string> board = getBoard();

    for(int i = 0; i < board.size(); i++){
        cout << board[i] << "\n";
    }

    return 0;
}