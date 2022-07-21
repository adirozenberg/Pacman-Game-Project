#include "NoviceGhost.h"


/* this function moves novice ghosts by random a move every 20 times */
void NoviceGhost::move(GameBoard& board, Position pacmanPos) {

	if (countMoveOfGhost % 20 == 0) { /* every 20 times, the function change the ghosts' runGame */
		newMove = randomMove();
	}

	/* check if next runGame of each ghost is possible */
	while (!(board.isNextPosValid(getNextPosition(board)))) {
		setNewMove(randomMove());
	}
	if (countMoveOfGhost % 20 == 0)
		currMove = newMove;

	movement(board);
	if (countMoveOfGhost == 60)
		countMoveOfGhost = 0;
	countMoveOfGhost++;

}





