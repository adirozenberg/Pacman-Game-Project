
#ifndef GOODGHOST_H
#define GOODGHOST_H

#include "bestGhost.h"

/*
GOOD Ghost - try to chase the pacman, 
but occasionally (randomly, once in ~20 moves) they just change to a random direction and stay
with it for 5 moves before being smart again
*/

class GoodGhost : public BestGhost {

	// random a number between 20-30 of smart ghost iterations
	int numOfSmartIterations = (rand() % 20) + 10;

public:
	GoodGhost() : BestGhost() {}
	virtual void move(GameBoard& board, Position pacmanPos) override;
};




#endif