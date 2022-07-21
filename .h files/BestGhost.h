
#ifndef BESTGHOST_H
#define BESTGHOST_H

#include "NoviceGhost.h"
#include <queue>

/* BEST Ghost - try to chase the pacman */

struct Node {
	Position pt;
	int dist;
};


class BestGhost : public NoviceGhost {

	bool isCellInBoard(GameBoard& board, int row, int col);
	string nextMoveOfBestGhost(GameBoard& board, Position ghostPos, Position pacmanPos);
public:
	BestGhost() : NoviceGhost() {}
	virtual void move(GameBoard& board, Position pacmanPos) override;
};

#endif