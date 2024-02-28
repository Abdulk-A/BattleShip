

#include "boardGenerator.h"
#include <fstream>
#include <iostream>

using namespace std;

//number between 0-24
int getXY(){
    return rand() % 25;
}

int flip(){
    return rand() % 2; // 0 1
}

int getDirection(int point){
    if(point >= 4 && point <= 20) return flip(); //return 0 or 1
    else if(point < 4) return 1;

    return 0; 
}

// void txtGenerator(){
// 	ofstream out("board.txt");

// 	if(out.is_open()){
// 		for(int i = 0; i < board.size(); i++){
// 			out << board[i] << "\n"; 
// 		}

// 		out.close();
// 	}
// }

vector<string> generateBoardWithShips(){

    vector<string> board;

	int i = 0;
	string row(BOARD_WIDTH,'#');

	while(i < BOARD_HEIGHT) {
		board.push_back(row);
		i++;
	}
	
    vector<vector<int> > ships = shipGenerator();

	int x, y;

	for(i = 0; i < ships.size(); i++) {

		if(ships[i][0] == 1){
			y = ships[i][1];
			for(int k = 2; k < ships[i].size(); k++){
				board[ships[i][k]][y] = 'O';
			}
		}
		else{
			x = ships[i][1];
			for(int k = 2; k < ships[i].size(); k++){
				board[x][ships[i][k]] = 'O';
			}
		}
	}
	// txtGenerator();

    return board;
}

vector<vector<int> > shipGenerator() {

    vector<vector<int> > ships;

    int i = 0;
    
    while(i < NUM_SHIPS){

        //x = 0-24, y = 0-24
        int x = getXY(), y = getXY(), xDir, yDir;
     
        xDir = getDirection(x); //0 or 1 right or left
        yDir = getDirection(y); //0 or 1 down or up

        int axis = flip(); //xDir or yDir

		vector<int> ship = makeShip1(x,y,axis, axis ? xDir : yDir);

		if(checkForConflicts(ships, ship)) {
			ships.push_back(ship);
			i++;
		}
    }

    return ships;
}

vector<int> makeShip1(int x, int y, int axis, int dir){

    vector<int>ship;
    ship.push_back(axis);

    if(axis) {
		ship.push_back(y);
		makeShipHelper(ship, x, dir);
    }
    else {
		ship.push_back(x);
		makeShipHelper(ship, y, dir);
    }

	return ship;
}

void makeShipHelper(vector<int>&ship, int k, int dir){

	int i = 0;

	if(dir == 1) {

		while(i < SHIP_LENGTH) {
			ship.push_back(k + i);
			i++;
		}
	}
	else{
		while(i < SHIP_LENGTH) {
			ship.push_back(k - i);
			i++;
		}
	}

}

bool checkForConflicts(vector<vector<int> >&ships, vector<int>&ship){

	if (ships.size() == 0) return true;

	int x, y, shipX, shipY;

	if(ship[0] == 1) { //x axis increases/decreases
		shipY = ship[1];
		
		for(int k = 2; k < ship.size(); k++){
			shipX = ship[k];
			for(int i = 0; i < ships.size(); i++){

				if(ships[i][0] == 1) {
					y = ships[i][1];
					
					for(int j = 2; j < ships[i].size(); j++) {
						if (ships[i][j] == shipX && y == shipY) return false;
					}
				}
				else{
					x = ships[i][1];
			
					for(int j = 2; j < ships[i].size(); j++) {
						if (x == shipX && ships[i][j] == shipY) return false;
					}
				}				

			}
		}

	}
	else{ //y axis increases/decreases
		shipX = ship[1];

		for(int k = 2; k < ship.size(); k++){
			shipY = ship[k];
			for(int i = 0; i < ships.size(); i++){

				if(ships[i][0] == 1) {
					y = ships[i][1];
					
					for(int j = 2; j < ships[i].size(); j++) {
						if (ships[i][j] == shipX && y == shipY) return false;
					}
				}
				else{
					x = ships[i][1];
			
					for(int j = 2; j < ships[i].size(); j++) {
						if (x == shipX && ships[i][j] == shipY) return false;
					}
				}				

			}
		}
	}

	return true;
}

vector<string> getBoard(){
    return generateBoardWithShips();
}