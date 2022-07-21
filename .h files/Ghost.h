#ifndef GHOST_H
#define GHOST_H

#include "Creature.h"
#include "Position.h"


class Ghost : public Creature {
	Position firstPosOfGhost;

protected:
	int countMoveOfGhost = 0;

public:
	Ghost() :Creature( '$', Color::RED){}
	Ghost(Position p):Creature( p, '$', Color::RED) {}
	void setCountMoveOfGhost(int _countMoveOfGhost)
	{
		countMoveOfGhost = _countMoveOfGhost;
	}
	int getCountMoveOfGhost()
	{
		return countMoveOfGhost;
	}

	void resetGhostPos()
	{
		position = firstPosOfGhost; // return ghost to first position
	} 
	void setfirstPosOfGhost(Position _pos)
	{
		firstPosOfGhost = _pos;
	}
	Position getFirstPosOfGhost() {
		return firstPosOfGhost;
	}
	virtual void move(GameBoard& board, Position pacmanPos) {};

};

#endif