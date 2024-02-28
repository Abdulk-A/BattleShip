//g++ makingTxt.cpp -o board1

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int BOARD_WIDTH = 25;
const int BOARD_HEIGHT = 25;
const int SHIP_LENGTH = 5;
const int NUM_SHIPS = 5;

vector<string> board;
vector<vector<int> > ships;


bool checkForConflicts(vector<int>&ship);
bool checkForConflictsHelper(vector<int>&ship, int start, int stop);

int getX();
int flip();
int getDirection(int point);
int randomDirection(int x, int y);

vector<int> makeShip(int x, int y, int axis, int dir);

void txtGenerator();
void generateBoardWithShips();
void makeShipHelper(vector<int>&ship, int k, int dir);
void shipGenerator();

int main() {

	srand(time(NULL));
	generateBoardWithShips();

    return 0;
}

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

void txtGenerator(){
	ofstream out("board.txt");

	if(out.is_open()){
		for(int i = 0; i < board.size(); i++){
			out << board[i] << "\n"; 
		}

		out.close();
	}
}

void generateBoardWithShips(){

	int i = 0;
	string row(BOARD_WIDTH,'#');

	while(i < BOARD_HEIGHT) {
		board.push_back(row);
		i++;
	}
	
	shipGenerator();

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
	txtGenerator();
}
	
void shipGenerator() {

    int i = 0;
    
    while(i < NUM_SHIPS){

        //x = 0-24, y = 0-24
        int x = getXY(), y = getXY(), xDir, yDir;
     
        xDir = getDirection(x); //0 or 1 right or left
        yDir = getDirection(y); //0 or 1 down or up

        int axis = flip(); //xDir or yDir

		vector<int> ship = makeShip(x,y,axis, axis ? xDir : yDir);

		if(checkForConflicts(ship)) {
			ships.push_back(ship);
			i++;
		}
    }
}

vector<int> makeShip(int x, int y, int axis, int dir){

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

bool checkForConflicts(vector<int>&ship){

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