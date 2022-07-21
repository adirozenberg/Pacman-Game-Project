#ifndef CREATURE_H
#define CREATURE_H

#include "Objects.h"
using std::cout;
using std::cin;
using std::endl;


class Creature :public Objects {

public:
	Creature(char _figure, Color _color) :Objects( _figure, _color) {}
	Creature(Position _pos,char _figure, Color _color) :Objects(_pos,_figure, _color) {}
	void deletePrevMove() const;

protected:
	char randomMove();
	char convertNumToMove(int num);
	Position getNextPosition(GameBoard& board);

	// this function changes and updates the movement of creature
	void movement(GameBoard& board) {

		Position nextPosOfGhost =getNextPosition(board);
		lastCharInBoard = board.board[nextPosOfGhost.getY()][nextPosOfGhost.getX()];
		deletePrevMove();
		position = nextPosOfGhost;
		draw();
	}
};



#endif
