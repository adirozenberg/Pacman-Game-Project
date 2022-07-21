#ifndef GAMEBOARD_H
#define GAMEBOARD_H

//#include "Pacman.h"
#include "Position.h"
#include"Utills.h"
#include <fstream>
#include <string.h>
#include <istream>
#include <string>
#include <iostream>

using namespace std;

class GameBoard {

	int logicalRowSize;
	int logicalColSize;
	int numOfFood;

public:
	enum{maxRow=25, maxCol=80};
	char board[maxRow][maxCol];

	GameBoard() {
		initBoard();
	}
	int getLogicalRowSize() {
		return logicalRowSize;
	}
	void setLogicalRowSize(int _colSize)
	{
		logicalRowSize = _colSize;
	}
	void setLogicalColSize(int _colSize)
	{
		logicalColSize = _colSize;
	}
	int getLogicalColSize() {
		return logicalColSize;
	}
	int getNumOfFood() const {
		return numOfFood;
	}
	void SetnumOfFood(int _numOfFood)
	{
		numOfFood = _numOfFood;
	}

	void initBoard();
	bool readScreen(string fileName);
	void printBoard() const;
	void updateBoardAfterEaten(Position point);
	bool isNextPosValid(Position nextpoint) const;
	int countNumOfFood();
};



#endif
