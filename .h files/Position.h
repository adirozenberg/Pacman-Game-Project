#ifndef POSITION_H
#define POSITION_H

#include "Color.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>


class Position {

	int _x;
	int _y;

public:
	Position() {
		_x = 0;
		_y = 0;
	}
	Position(int x, int y) {
		_x = x;
		_y = y;
	}

	enum { min_x = -1, max_x = 79, min_y = -1, max_y = 20 };

	void setX(int x) {
		_x = x;
	}
	void setY(int y) {
		_y = y;
	}
	int getX() const {
		return _x;
	}
	int getY() const {
		return _y;
	}

	friend bool comparePos(Position pos1, Position pos2) {
		if (pos1.getX() == pos2.getX() && pos1.getY() == pos2.getY())
			return true;
		else
			return false;

	}
	

};




#endif
