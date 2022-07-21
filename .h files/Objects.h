
#ifndef OBJECTS_H
#define OBJECTS_H
#include "Utills.h"
#include "GameBoard.h"

using std::cout;
using std::cin;
using std::endl;

extern bool isColor;


/* all of the objects in game represents by this class */

class Objects {
	Color color;


protected:
	Position position = Position(0,0);
	char figure = ' ';
	char currMove = ' ';
	char newMove = ' ';
	char lastCharInBoard = ' ';
	enum { UP = 'w', DOWN = 'x', RIGHT = 'd', LEFT = 'a'};

public:
	Objects(char _figure, Color _color)
	{
	figure = _figure;
	color = _color;
	}
	Objects(Position _position,char _figure, Color _color)
	{
		position = _position;
		figure = _figure;
		color = _color;
	}

	void setPosition(Position newPos)
	{
		position = newPos;
	}
	Position getPosition() {
		return position;
	}
	char getFigure() {
		return figure;
	}
	void setFigure(char _figure) {
		figure = _figure;
	}
	char getCurrMove() {
		return currMove;
	}
	void setCurrMove(char _currMove) {
		currMove = _currMove;
	}
	char getNewMove() {
		return newMove;
	}
	void setNewMove(char _newMove) {
		newMove = _newMove;
	}
	char getLastCharInBoard() {
		return lastCharInBoard;
	}
	void setLastCharInBoard(char _lastCharInBoard) {
		lastCharInBoard = _lastCharInBoard;
	}

	void draw()
	{
			gotoxy(position.getX(), position.getY()); // new coordinate of the pacmen
			if (isColor)
				setTextColor(color);
			cout << figure;
	
	}
};



#endif
