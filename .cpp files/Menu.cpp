#include "Menu.h"
extern bool isColor;

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void startGame() {

	char choice;
	bool game = true, startGame = false;

	while (game) {

		printManu();
		choice = _getch();


		switch (choice) {
		case '1': // start pacman game without colors
			isColor = false;
			startGame = true;
			break;
		case '2': // start pacman game with colors
			isColor = true;
			startGame = true;
			break;
		case '8': // print games' instructions
			clearScreen();
			printInstructions();
			break;
		case '9': // EXIT
			game = false;
			clearScreen();
			cout << " GOOD BYE!";
			continue;
		default:
			clearScreen();
			cout << choice << " is invalid. please try again." << endl;
			break;
		}

		if (startGame) {

			string specificFileName;
			char level;
			cout << "if you want a specific file- enter the name of file, else enter 0 "<< endl;
			cin >> specificFileName;
			cout << "please enter level a,b,c: a - hard, b - medium, c - easy" << endl;
			level = _getch();

			while (level != 'a' && level != 'b' && level != 'c')
			{
				cout << "please enter a valid level between 1-3" << endl;
				level = _getch();
			}

			Game game(level, specificFileName);
			clearScreen();
			game.runGame(); // this function start the game
			_getch();
			clearScreen();
			startGame = false;
			if (isColor)
				system("color 0F");
		}
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*this function prints the menu of the game*/
void printManu() {
	cout << endl << "*******************************************************" << endl << endl;
	cout << "Wellcome to PACMAN GAME" << endl << "(1) Start a new game " << endl << "(2) Start a new game with color" << endl << "(8) Present instructions and keys" << endl << "(9) EXIT" << endl;
	cout << endl << "*******************************************************" << endl;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* this function prints the instructions of the game*/
void printInstructions() {
	cout << endl << "Keys:" << endl << "Left - press a or A" << endl << "Right - press d or D" << endl;
	cout << "Up - press w or W" << endl << "Down - press x or X" << endl << "Stay - press s or S" << endl;
	cout << "ESC - press ESC" << endl;
}