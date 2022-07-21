#include "GameBoard.h"
extern bool isColor;


/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function initialize board to ' ' */
void GameBoard::initBoard()
{
	for(int i = 0; i < maxRow; i++)
		for (int j = 0; j < maxCol; j++)
			board[i][j] = ' '; 
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function reads screen from a text file and copy all of rows and cols to board.
it also updates logicalRowSize and logicalColSize data members */
bool GameBoard::readScreen(string fileName)
{
	int sizeOfRow = 0, sizeOfFirstCol = -1, i;
	string tmpline;
	ifstream inFile(fileName);

	if (!inFile)
	{
		return false;
	
	}
	while (getline(inFile, tmpline)) {
		{
			if (sizeOfFirstCol == -1) { // if this the first row 
				sizeOfFirstCol = (int)(tmpline.length());

				//check if & in first row 
				for (i = 0; i < sizeOfFirstCol; i++)
				{
					if (tmpline[i] == '&') 
					{
						if (i + 20 > sizeOfFirstCol)
							sizeOfFirstCol = i + 20;
						break;
					}

				}
			}
			strcpy(board[sizeOfRow], tmpline.c_str());
			sizeOfRow++;
		}
	}

	logicalColSize = sizeOfFirstCol;
	logicalRowSize = sizeOfRow;
	inFile.close();
	return true;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void GameBoard::printBoard() const {


	for (int i = 0; i < logicalRowSize; i++) {
		for (int j = 0; j < logicalColSize; j++) {
			if (isColor) {
				if (board[i][j] == '.')
					setTextColor(Color::WHITE);
				else
					setTextColor(Color::LIGHTBLUE);
			}

			cout << board[i][j];
		}
		cout << endl;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function gets a point in board and updates this point to backspace (pacman ate the food at this point) */
void GameBoard::updateBoardAfterEaten(Position point) {

	int x = point.getX();
	int y = point.getY();
	board[y][x] = ' ';
}


/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*this function check if the next position of ghost is valid */
bool GameBoard::isNextPosValid(Position nextpoint) const {

	if ((nextpoint.getX() == Position::min_x) || (nextpoint.getX() == logicalColSize + 1)
		|| (nextpoint.getY() == Position::min_y) || (nextpoint.getY() == logicalRowSize))
		return false;
	else
	{
		char ch = board[nextpoint.getY()][nextpoint.getX()];
		if (ch == '.' || ch == ' ' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
			return true;
		else
			return false;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function calculates the number of food in board, and returns it */
int GameBoard::countNumOfFood() {

	int count = 0;

	for (int i = 0; i < logicalRowSize; i++) {
		for (int j = 0; j < logicalColSize; j++) {

			if (board[i][j] == '.')
				count++;

		}
	}

	return count;
}

