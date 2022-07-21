#ifndef FRUIT_H
#define FRUIT_H
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Creature.h"


class Fruit : public Creature {

	bool isEaten=false;
	int numOfIterationToLive; // iterations of fruit on board
	int numOfIterationToPause; // number of iterations that fruit will not appears in board
	
public:
	Fruit() :Creature(Position(0,0), createFruitFigure(), Color::LIGHTMAGENTA) 
	{
		numOfIterationToLive=randomTimeOfLives();
		numOfIterationToPause=randomTimeOfPause();
	}

	void resetNewFruit(GameBoard & board);
	Position randomPos(GameBoard& board);
	void move(GameBoard& board);
	void setIsEaten(bool _isEaten) {
		isEaten = _isEaten;}
	bool getIsEaten() {
		return isEaten;}
	void setNumOfIterationToLive(int _numOfLives) {
		numOfIterationToLive = _numOfLives;}
	int getNumOfIterationToLive() {
		return numOfIterationToLive;
	}
	void setNumOfIterationToPause(int _numOfPause) {
		numOfIterationToPause = _numOfPause;
	}
	int getNumOfIterationToPause() {
		return numOfIterationToPause;
	}

private:
	int randomTimeOfLives();
	int randomTimeOfPause();
	char createFruitFigure();

	

};
#endif