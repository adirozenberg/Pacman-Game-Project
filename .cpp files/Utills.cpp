#include "Utills.h"

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* This function recives x,y on board, and moves the cursor to this point */
void gotoxy(int x, int y) {

	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void hideCursor() {
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void clearScreen() {
	system("CLS");
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}