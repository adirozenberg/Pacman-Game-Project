
#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include "Pacman.h"
#include "Ghost.h"
#include "NoviceGhost.h"
#include "GoodGhost.h"
#include "BestGhost.h"
#include "Fruit.h"
//#include "GameBoard.h"
#include "Screen.h"


using std::cout;
using std::cin;
using std::endl;

class Game {
	enum {maxNumOfGhost=4};
	bool _win = false;
	bool _lose = false;
	int level= -1 ;
	Pacman pacman;
	int numOfGhosts=0;
	Ghost* ghosts[maxNumOfGhost]{};
	GameBoard board;
	Fruit fruit;
	Position posOfScoreAndLives;
	string specificFile = "0";

public:
	Game() {} // empty ctor
	Game(int _level,string _fileName) { // ctor
		level = _level;
		specificFile = _fileName;
	} 
	void runGame();
	int getLevel() {
		return level;
	}
	void setLevel(int _level) {
		level = _level;
	}

	~Game() { // dtor
		for (int i = 0; i < maxNumOfGhost; i++)
			delete ghosts[i];
	}

private:
	void printGameOver() const;
	void printWinner() const;
	void printLivesAndScore() const;
	void pacmanIsEaten();
	void isLose();
	void isWin();
	void fruitIsEaten();
	bool screenToGame(Position positionOfGhosts[]);
	void convertScreenToGameBoard(int& numberOfFile,vector<string>files, Position FirstpositionOfGhosts[]);
	void resetsGhosts(Position FirstpositionOfGhosts[]);
	void printInvalidMessage(string object);
	void readNextFile(GameBoard& board, vector<string>& files, int numberOfFile, Position FirstpositionOfGhosts[]);

	
};
#endif

