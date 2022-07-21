#include "Game.h"
#include "Menu.h"
extern bool isColor;

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function manages all the movements on board in game */
void Game::runGame() {

	srand((unsigned)time(NULL));
	hideCursor();
	vector<string> files;
	Position FirstpositionOfGhosts[4];
	bool isSecondItretion = false; /* pacman is faster X2 than the ghosts and the fruit */

	if (specificFile != "0") 
		files.push_back(specificFile);
	else // all files in directory
		readFiles(files);

	int numberOfFile = int(files.capacity());
	string name = files.at(files.capacity() - numberOfFile);// first file in files
	readNextFile(board, files, numberOfFile, FirstpositionOfGhosts);
	board.SetnumOfFood(board.countNumOfFood());
	fruit.setPosition(fruit.randomPos(board));
	
	while (_lose == false && _win == false)
	{
		if (isSecondItretion == false) {
			fruit.move(board);

			for (int i = 0; i < numOfGhosts; i++)
				ghosts[i]->move(board, pacman.getPosition());
			isSecondItretion = true;
		}
		else
			isSecondItretion = false;

		pacman.move(board);
		pacmanIsEaten();  /* check if ghost ate pacman*/
		fruitIsEaten(); /* check if ghost or pacman ate fruit*/
		printLivesAndScore();
		isLose();
		isWin();

		// check if we won in this file, but we still have more files to win the whole game
		if (_win == true && (numberOfFile - 1 != 0)) 
		{
			numberOfFile--;
			_win = false;
			readNextFile(board, files, numberOfFile, FirstpositionOfGhosts);
			board.SetnumOfFood(board.countNumOfFood() + pacman.getBreadCrumsScore());
		
		}
		else if (_win == true)
			printWinner();
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

void Game::readNextFile(GameBoard& board, vector<string>& files, int numberOfFile, Position FirstpositionOfGhosts[]) {

	string name = files.at(files.capacity() - numberOfFile );

	if (!board.readScreen(name)) //check if file not found in folder
	{
		cout << endl << "File did not Found!" << endl;
		cout << "please press any key to menu" << endl;
		_getch();
		clearScreen();
		startGame();
	}

	convertScreenToGameBoard(numberOfFile, files, FirstpositionOfGhosts);
	resetsGhosts(FirstpositionOfGhosts);
	clearScreen();
	board.printBoard();
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function prints a message when user lose the game */
void Game::printGameOver() const {
	clearScreen();
	gotoxy(50, 15);

	cout << " GAME OVER " << endl;

	if (isColor)
		system("color 4F");

}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function prints a message when user win the game */
void Game::printWinner() const {
	clearScreen();
	gotoxy(50, 15);
	cout << " YOU WON! " << endl;
	if (isColor)
		system("color 2F");
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function prints lives and score on board */
void Game::printLivesAndScore() const {

	
	gotoxy(posOfScoreAndLives.getX(), posOfScoreAndLives.getY());
	if (isColor)
		setTextColor(Color::LIGHTMAGENTA);
	cout << "SCORE: ";
	if (isColor)
		setTextColor(Color::WHITE);
	cout << pacman.getScore()<<endl;
	gotoxy(posOfScoreAndLives.getX(), posOfScoreAndLives.getY()+1);

	if (isColor)
		setTextColor(Color::LIGHTMAGENTA);
	cout << "LIVES: ";
	if (isColor)
		setTextColor(Color::WHITE);
	cout <<pacman.getLives() << endl;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function check if ghost and pacman are on the same position on board and updates the game acoordinly */
void Game::pacmanIsEaten() {

	for (int i = 0; i < numOfGhosts; i++)
	{
		if (comparePos(ghosts[i]->getPosition(), pacman.getPosition()))
		{
			pacman.setCurrMove(' ');
			pacman.deletePacmanMove(pacman.getPosition());
			pacman.setPosition(pacman.getFirstPos());
			pacman.setLives(pacman.getLives() - 1); /* lives-- */
			for (int i = 0; i < numOfGhosts; i++)
			{
				ghosts[i]->setCurrMove(' ');
				ghosts[i]->deletePrevMove();
				ghosts[i]->resetGhostPos();
			}

			Sleep(1000);

		}
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function check if the pacman lost all his lives. if it is, the function pause the game */
void Game::isLose() {

	if (pacman.getLives() == 0) {
		_lose = true;
		printGameOver();
	}

}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function check if pacman win the game */
void Game::isWin() {

	if (board.getNumOfFood() - pacman.getBreadCrumsScore() == 1)
		_win = true;
	
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function check if pacman or ghost ate fruit */
void Game::fruitIsEaten() {
	if (comparePos(pacman.getPosition(), fruit.getPosition())) { // check if pacman ate fruit
		pacman.setScore(pacman.getScore() + (int)(fruit.getFigure() - '0'));
		fruit.setPosition(Position(-1, -1));
		fruit.setIsEaten(true);
	}
	else // check if fruit eaten by ghost
	{
		for (int i = 0; i < numOfGhosts; i++)
		{
			if (comparePos(ghosts[i]->getPosition(), fruit.getPosition()))
			{
				fruit.setPosition(Position(-1, -1));
				fruit.setIsEaten(true);
				return;
			}
		}
	}

}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function convert symbols from board to characters of game:
'%' - converted to ' ' 
' ' - converted to '.' 

this function also updates starting positions of pacman and ghosts on board, and fills the array of positionOfGhosts with those positions
the function also check if the file is valid, and return true if it is, ele returns false */
bool Game::screenToGame(Position positionOfGhosts[])
{
	bool scoreAndLivesPosIsAppear = false;
	bool PacmanIsApear = false;
	bool isValidscreen = true;

	numOfGhosts = 0;

	// check if board is too large. if it is, we resize it to maximal row and col
	if (board.getLogicalRowSize() > GameBoard::maxRow)
		board.setLogicalRowSize(GameBoard::maxRow);
	if (board.getLogicalColSize() > GameBoard::maxCol)
		board.setLogicalColSize(GameBoard::maxCol);

	for (int i = 0; i < board.getLogicalRowSize(); i++)
	{
		for (int j = 0; j < board.getLogicalColSize(); j++)
		{
			if (board.board[i][j] == '&') {
				if (!scoreAndLivesPosIsAppear)
				{
					scoreAndLivesPosIsAppear = true;
					posOfScoreAndLives.setX(j);
					posOfScoreAndLives.setY(i);
				}
				else // & appear twice in board
				{
					printInvalidMessage("ampersand");
					return false; // invalid screen
				}
			}
			else if (board.board[i][j] == '%')
				board.board[i][j] = ' ';
			else if (board.board[i][j] == '$') {
				if (numOfGhosts == 5)
				{
					printInvalidMessage("ghost");
					return false; // invalid screen
				}

				board.board[i][j] = '.';
				positionOfGhosts[numOfGhosts] = Position(j, i);
				numOfGhosts++;
			}
			else if (board.board[i][j] == '@')
			{
				if (!PacmanIsApear) // is the first time pacmn apeaer
				{
					PacmanIsApear = true;
					board.board[i][j] = ' ';
					pacman.setFirstPos(Position(j, i));
					pacman.setPosition(Position(j, i));
				}
				else // pacman appears twice
				{
					printInvalidMessage("pacman");
					return false; // invalid screen
				}
			}

			else if (board.board[i][j] == ' ')
				board.board[i][j] = '.';

		}
	}
		return isValidscreen;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function prints a message to screen when file is not valid */
void Game::printInvalidMessage(string object) {

	clearScreen();
	cout << object <<" appears too many times in this file - this file is not valid!" << endl;
	cout << "please enter any key to move to next screen";
	_getch();
	clearScreen();
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function reads files from folder until it mets with a valid file. it handles the case when a file is invalid,
and moves on to next screen */
void Game::convertScreenToGameBoard(int& numberOfFile, vector<string>files, Position FirstpositionOfGhosts[])
{

	while (!screenToGame(FirstpositionOfGhosts)) //check if the screen are valid
	{
		if (numberOfFile - 1 != 0)// if we have more files move to next files
		{
			numberOfFile--;
			string name = files.at(files.capacity() - numberOfFile);
			board.readScreen(name);
		}
		else
		{
			cout << "all the files not valid- GoodBye";
		}
	}

}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function defines an array of ghost from ghost level that user entered, and sets ghosts' positions */
void Game::resetsGhosts(Position FirstpositionOfGhosts[])
{
	for (int i = 0; i < numOfGhosts; i++)
	{
		if (ghosts[i] == NULL)// if ghosts not intialize yet
		{
			switch (level) {

			case 'a': // BEST
				ghosts[i] = new BestGhost;
				break;

			case 'b': // GOOD
				ghosts[i] = new GoodGhost;
				break;

			case 'c': // NOVICE
				ghosts[i] = new NoviceGhost;
				break;
			} 

		}

		ghosts[i]->setfirstPosOfGhost(FirstpositionOfGhosts[i]);
		ghosts[i]->setPosition(FirstpositionOfGhosts[i]);	
	}
}
