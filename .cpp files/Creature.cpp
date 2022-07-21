#include "Creature.h"
extern bool isColor;

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function choose a randomlly number between 0-3 */
char Creature::randomMove() {

	int num;
	num = (rand() % 4);
	return convertNumToMove(num);

}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*this function recives a number between 0-3 that choosen randomlly, and changes it to a valid move (a,w,d,x) */
char Creature::convertNumToMove(int num) {


	char ch = ' ';

	switch (num) {

	case 0:
		ch = LEFT; 
		break;

	case 1:
		ch = RIGHT; 
		break;

	case 2:
		ch = UP;
		break;

	case 3:
		ch = DOWN;
		break;
	}


	return ch;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function recives next move of ghost and returns next position on board */
Position Creature::getNextPosition(GameBoard& board)
{

	Position nextXY; // variable of next position of x,y
	int x = position.getX();
	int y = position.getY();
	nextXY.setX(x);
	nextXY.setY(y);


	switch (newMove) {
	case LEFT: // left
		nextXY.setX(x - 1);
		break;
	case RIGHT: // right
		nextXY.setX(x + 1);
		break;
	case UP: // up
		nextXY.setY(y - 1);

		break;
	case DOWN: // down
		nextXY.setY(y + 1);
		break;
	default:
		break;
	}
	return nextXY;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void Creature::deletePrevMove() const
{
	gotoxy(position.getX(), position.getY());
	if (lastCharInBoard == '.') {
		if (isColor)
			setTextColor(Color::WHITE);
		cout << '.';
	}
	else
		cout << ' ';
}