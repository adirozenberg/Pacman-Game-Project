#include "Pacman.h"
extern bool isColor;


/*-----------------------------------------------------------------------------------------------------------------------------------------*/
/* this function check if user entered a valid move - up, down, right, left,
and returns true. else, it returns false */
bool Pacman::isValidDirection(char dir) const
{
	if ((dir == 'A' || dir == 'a' || dir == 'D' || dir == 'd' ||
		dir == 'W' || dir == 'w' || dir == 'X' || dir == 'x' || dir == 'S' || dir == 's'))
		return true;

	return false;

}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function delete the last position of pacman */
void Pacman::deletePacmanMove(Position curXY) const {
	gotoxy(curXY.getX(), curXY.getY());
	cout << ' ';
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*this function runGame Pacman on game board*/
void Pacman::move(GameBoard& board)
{
	if (_kbhit()) {

		setNewMove(_getch()); /* gets pacman new runGame from keyboard */
		if (getNewMove() == ESC) { /* check if the user hit ESC */
			hitESC();
			board.printBoard();
		}
		else if (isValidDirection(getNewMove())) /* if it's not ESC, check if new runGame is valid */
			setCurrMove(tolower(getNewMove())); /* updates new runGame to lower case */
		/* else - runGame stay the prev runGame */
	}

	/* check if user press S or s - a case when he wants to stay on board */
	if (getCurrMove() == 's' || getCurrMove() == 'S')
		Sleep(speed);

	else /* a valid runGame, (not an S, s, or ESC) */
	{
		Position nextPositionOfPacman = getNextPosition(board);
		/* check if next position of pacman is valid */
		if (isNextPosValid(nextPositionOfPacman,board)) {
			/* if next position contains breadcrumb */
			setLastCharInBoard(board.board[nextPositionOfPacman.getY()][nextPositionOfPacman.getX()]);
			if (getLastCharInBoard() == '.') {
				setScore(getScore() + 1); /* score++ */
				setBreadCrumsScore(getBreadCrumsScore() + 1); /* score++ */
				board.updateBoardAfterEaten(nextPositionOfPacman); /* updates this point to ' ' */
			}
			Sleep(speed);
			deletePacmanMove(getPosition());
			setPosition(nextPositionOfPacman);
		}
		else
			Sleep(speed);
	}
	draw();
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function returns next position on board by currMove character */
Position Pacman::getNextPosition( GameBoard& board)  {

	// variable of next position of x,y
	Position nextXY = getPosition();

	switch (currMove)
	{
	case LEFT: 
		if (getPosition().getX() - 1 == -1)
			nextXY.setX(board.getLogicalColSize() - 1);
		else
			nextXY.setX(getPosition().getX() - 1);

		break;
	case RIGHT:

		if (getPosition().getX() + 1 == board.getLogicalColSize())
			nextXY.setX(0);
		else
			nextXY.setX(getPosition().getX() + 1);
		break;

	case UP:

		if (getPosition().getY() - 1 == -1)
			nextXY.setY(board.getLogicalRowSize() - 1);
		else
			nextXY.setY(getPosition().getY() - 1);
		break;

	case DOWN:
		if (getPosition().getY() + 1 == board.getLogicalRowSize())
			nextXY.setY(0);
		else
			nextXY.setY(getPosition().getY() + 1);
		break;

	default:
		break;
	}
	return nextXY;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function handles with a case when the user press esc key */
void Pacman::hitESC() {

	Position middleOfBoard;
	middleOfBoard.setX(35);
	middleOfBoard.setY(15);
	char move;

	clearScreen();
	gotoxy(middleOfBoard.getX(), middleOfBoard.getY());
	cout << "the game has stopped! :( press ESC to continue.";
	do {
		move = _getch();
	} while (move != ESC); /* waiting for a second press of ESC for continue game */

	clearScreen();
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*this function check if the next position of pacman in board is valid for pacman to runGame*/
bool Pacman::isNextPosValid(Position nextpoint,GameBoard &board) const {

	char ch = board.board[nextpoint.getY()][nextpoint.getX()];
	if (ch == '#')
		return false;
	else
		return true;
}