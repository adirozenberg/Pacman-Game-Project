#include "Fruit.h"
extern bool isColor;

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function random a character between 5-9, that symbolized the fruit on board */
char Fruit::createFruitFigure() {

	srand((unsigned)time(NULL)); // להוציא ולשים פעם אחת
	int num;
	num = (rand() % 5) + 5; // random fruit between 5-9
	return (char)('0' + num);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function random a position on board, until this position is a valid position */
Position Fruit::randomPos(GameBoard& board)
{
	int sizeX = board.getLogicalColSize(), sizeY = board.getLogicalRowSize();
	int x, y;

	do {
		x = rand() % sizeX;
		y = rand() % sizeY;
	} while (!board.isNextPosValid(Position(x, y)));

	return Position(x, y);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function random a number between 20-40 of time that fruit appears on board */
int Fruit::randomTimeOfLives()
{ 
	int NumOfIterationToLive;
	return 	NumOfIterationToLive = (rand() % 20) + 20; //20-40 iteration
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function random a number between 5-60 of time that fruit desappears on board */
int Fruit::randomTimeOfPause()
{
	int NumOfIterationToPause;
	return 	NumOfIterationToPause = (rand() %55) + 5; // 5-60 iterations
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function resets all data of fruit, prepared to next show of fruit */
void Fruit::resetNewFruit(GameBoard& board) {
	figure = createFruitFigure();
	isEaten = false;
	numOfIterationToLive = randomTimeOfLives();
	numOfIterationToPause = randomTimeOfPause();
	position = randomPos(board);

}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function move fruit on board */
void Fruit::move(GameBoard& board)
{
	// check if fruit is eaten or time of lives has ending
	if (isEaten || numOfIterationToLive == 0)
	{
		deletePrevMove();
		numOfIterationToPause = numOfIterationToPause - 1;
		if (numOfIterationToPause == 0)
			resetNewFruit(board);
	}
	else
	{
		newMove = randomMove();
		if (board.isNextPosValid(getNextPosition(board)))
		{
			currMove = newMove;
			movement(board);
		}
		else
			draw();

		numOfIterationToLive=numOfIterationToLive - 1;

	}
}
