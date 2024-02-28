
#ifndef BOARD_GENERATOR
#define BOARD_GENERATOR

#include <vector>

const int BOARD_WIDTH = 25;
const int BOARD_HEIGHT = 25;
const int SHIP_LENGTH = 5;
const int NUM_SHIPS = 5;

bool checkForConflicts(std::vector<std::vector<int> >&ships, std::vector<int>&ship);
// bool checkForConflictsHelper(std::vector<int>&ship, int start, int stop);

int getX();
int flip();
int getDirection(int point);
int randomDirection(int x, int y);


std::vector<int> makeShip1(int x, int y, int axis, int dir);

// void txtGenerator();
std::vector<std::string> generateBoardWithShips();
void makeShipHelper(std::vector<int>&ship, int k, int dir);
std::vector<std::vector<int> > shipGenerator();
std::vector<std::string> getBoard();



#endif