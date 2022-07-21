#include "Ghost.h"
extern bool isColor;

///*-----------------------------------------------------------------------------------------------------------------------------------------*/
//void Ghost::moveNoviceGhost(int countMovesOfGhosts, GameBoard& board) {
//		if (countMovesOfGhosts % 20 == 0) /* every 20 times, the function change the ghosts' runGame */
//			newMove = randomMove();
//		/* returns the next position of each ghost */
//		Position nextPositionOfGhost = getNextPosition(board);
//		/* check if next runGame of each ghost is possible */
//		while (!(board.isNextPosValid(nextPositionOfGhost))) {
//			newMove = randomMove();
//			nextPositionOfGhost = getNextPosition(board);
//		}
//		if (countMovesOfGhosts % 20 == 0)
//			currMove = newMove;
//		lastCharInBoard = board.board[position.getY()][position.getX()];
//		deletePrevMove();
//		position = nextPositionOfGhost;
//		draw();
//}
//
///*-----------------------------------------------------------------------------------------------------------------------------------------*/
//
//
//int Ghost::DetectDirection(int dir, Position ghostPos, GameBoard& board, Position pacmanPos)
//{
//	int dirArr[4];
//	int sizeOfDirArr = 0;
//	int newDircetion;
//
//	if (dir == 2)// dir==up
//	{
//
//		if (board.isNextPosValid(Position(ghostPos.getX(), ghostPos.getY() - 1)))//up
//		{
//			dirArr[sizeOfDirArr] = 2;
//			sizeOfDirArr++;
//
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX() - 1, ghostPos.getY())))//left
//		{
//			dirArr[sizeOfDirArr] = 0;
//			sizeOfDirArr++;
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX() + 1, ghostPos.getY())))//right
//		{
//			dirArr[sizeOfDirArr] = 1;
//			sizeOfDirArr++;
//		}
//	}
//	else if (dir == 3)//down
//	{
//		if (board.isNextPosValid(Position(ghostPos.getX(), ghostPos.getY() + 1)))//down
//		{
//			dirArr[sizeOfDirArr] = 2;
//			sizeOfDirArr++;
//
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX() - 1, ghostPos.getY())))//left
//		{
//			dirArr[sizeOfDirArr] = 0;
//			sizeOfDirArr++;
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX() + 1, ghostPos.getY())))//right
//		{
//			dirArr[sizeOfDirArr] = 1;
//			sizeOfDirArr++;
//		}
//	}
//	else if (dir == 0)//left
//	{
//		if (board.isNextPosValid(Position(ghostPos.getX() - 1, ghostPos.getY())))//left
//		{
//			dirArr[sizeOfDirArr] = 0;
//			sizeOfDirArr++;
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX(), ghostPos.getY() + 1)))//down
//		{
//			dirArr[sizeOfDirArr] = 3;
//			sizeOfDirArr++;
//
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX(), ghostPos.getY() - 1)))//up
//		{
//			dirArr[sizeOfDirArr] = 2;
//			sizeOfDirArr++;
//		}
//
//
//	}
//	else
//	{
//		if (board.isNextPosValid(Position(ghostPos.getX() + 1, ghostPos.getY())))//right
//		{
//			dirArr[sizeOfDirArr] = 1;
//			sizeOfDirArr++;
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX(), ghostPos.getY() + 1)))//down
//		{
//			dirArr[sizeOfDirArr] = 3;
//			sizeOfDirArr++;
//
//		}
//		if (board.isNextPosValid(Position(ghostPos.getX(), ghostPos.getY() - 1)))//up
//		{
//			dirArr[sizeOfDirArr] = 2;
//			sizeOfDirArr++;
//		}
//	}
//	if (ghostPos.getX() < pacmanPos.getX() && dir != 0 && isFoundInArr(dirArr, sizeOfDirArr, 1))
//	{
//		newDircetion = 1;//right
//	}
//	else if (ghostPos.getX() > pacmanPos.getX() && dir != 1 && isFoundInArr(dirArr, sizeOfDirArr, 0))
//	{
//		newDircetion = 0;//left
//	}
//	else if (ghostPos.getY() > pacmanPos.getY() && dir != 3 && isFoundInArr(dirArr, sizeOfDirArr, 2))
//	{
//		newDircetion = 2;//up
//	}
//	else if (ghostPos.getY() < pacmanPos.getY() && dir != 2 && isFoundInArr(dirArr, sizeOfDirArr, 3))
//	{
//		newDircetion = 3;//down
//	}
//	else
//	{
//		newDircetion = randomMove();
//	}
//
//	return newDircetion;
//}
//
//
/////*this function runGame smart ghost on game board*/
////void Ghost::moveSmartGhost(GameBoard& board, Position pacmanPos)
////{
////	//int nextDirOfGhost = smartNextMove(ghosts[i]);
////	int bestNextDir = smartNextMove(board, pacmanPos);
////	newMove = convertNumToMove(DetectDirection(bestNextDir, position, board, pacmanPos));
////	Position nextPosOfGhost = getNextPosition(board);
////	lastCharInBoard = board.board[nextPosOfGhost.getY()][nextPosOfGhost.getX()];
////	deletePrevMove();
////	position = nextPosOfGhost;
////
////
////	draw();
////}
////
/////*this function recives current pacman positionand returns the best next position of chasing pacman */
////int Ghost::smartNextMove(GameBoard& board, Position pacmanPos) {
////
////	Position nextOptPos;
////	double minDistance = -1, currDistance;
////	Position bestNextOptPos;
////	int bestDir;
////	for (int i = 0; i < 4; i++)//check all 4 Direction
////	{
////		newMove = convertNumToMove(i);
////		nextOptPos = getNextPosition(board);
////		//nextOptPos = ghost.getPosition().getNextPacmanPosition(ghost.convertNumToMove(i));
////		if (board.isNextPosValid(nextOptPos))
////		{
////			currDistance = nextOptPos.distanceBtw2Points(pacmanPos);
////			if (minDistance == -1 || minDistance > currDistance) // first iteration or found minimum
////			{
////				minDistance = currDistance;
////				bestNextOptPos = nextOptPos;
////				bestDir = i;
////			}
////			else
////				if (minDistance == currDistance)
////				{
////					int randomChoose = (rand() % 1);// random chose 
////
////					if (randomChoose == 0)
////					{
////						minDistance = currDistance;
////						bestNextOptPos = nextOptPos;
////						bestDir = i;
////					}
////					//else: stay currDistance as minDistance
////
////				}
////		}
////	}
////
////	return bestDir;
////
////}
///*-----------------------------------------------------------------------------------------------------------------------------------------*/
//
//bool Ghost::isFoundInArr(int arr[], int size, int num)
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] == num)
//			return true;
//	}
//	return false;


void move(GameBoard& board, Position pacmanPos)
{

}
