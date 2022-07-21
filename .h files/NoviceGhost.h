
#ifndef NOVICEGHOST_H
#define NOVICEGHOST_H

#include "Ghost.h"

/*
NOVICE Ghost - just move on screen with a direction selected randomly every 20 moves
*/

class NoviceGhost : public Ghost {

public:
	NoviceGhost() : Ghost(Position(0, 0)) {}
	virtual void move(GameBoard& board, Position pacmanPos) override;
};


#endif