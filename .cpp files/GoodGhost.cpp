#include "GoodGhost.h"

/* this function moves good ghosts on board, by using move function of novice ghosts and move function of best ghost */
void GoodGhost::move(GameBoard& board,Position pacmanPos)
{
	// moves 5 iterations as novice ghost
	if (countMoveOfGhost >= numOfSmartIterations && countMoveOfGhost <= numOfSmartIterations+5)
		NoviceGhost::move(board, pacmanPos);
	else
		BestGhost::move(board, pacmanPos);


	if (countMoveOfGhost == 25)
		countMoveOfGhost = 0;

}