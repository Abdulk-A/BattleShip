#include <iostream>
#include <stdlib.h>  
#include "Generators/boardGenerator.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

using namespace std;

void printBoard(vector<string>&board);

int main() {

    vector<string> board = getBoard();
    cout << GREEN << "You have 5 ships to attack!\n" << RESET;

    // for(int i = 0; i < board.size(); i++){
    //     cout << board[i] << "\n";
    // }

    int i = 0;

    int x, y;
    char choice;

    while(i < 100) {
        cout << "enter X coordinate: ";
        cin >> x;
        cout << "enter Y coordinate: ";
        cin >> y;
        
        while(x < 0 || y < 0 || x >= BOARD_HEIGHT || y >= BOARD_WIDTH) {

            cout << "make sure your coordinates are both between 1-" << BOARD_WIDTH << "!\n";
            cout << "enter X coordinate: ";
            cin >> x;
            cout << "enter Y coordinate: ";
            cin >> y; 
        }
        
        if(board[x][y] == '#' || board[x][y] == 'X') cout << RED << "MISS!\n" << RESET; 
        else {
            cout << GREEN << "HIT!\n" << RESET;
            board[x][y] = 'X';
        }
        
        cout << "Show enemy board and forfit (Y/N): ";
        cin >> choice;

        while(true){
            if(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') break;
            cout << "Please enter (Y/N): ";
            cin >> choice;
        }

        if(choice == 'Y' || choice == 'y') break;
        
        i++;
    }

    printBoard(board);
    
    return 0;
}

void printBoard(vector<string>&board){
    for(int i = 0; i < board.size(); i++){
        cout << board[i] << endl;
    }
}