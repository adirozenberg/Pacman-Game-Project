#include "Position.h"
extern bool isColor;

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/* these functions get and set x,y accordingly */
void Position::setX(int x) {
	_x = x;
}

void Position::setY(int y) {
	_y = y;
}

int Position::getX() const {
	return _x;
}

int Position::getY() const {
	return _y;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/



///* this function is not used in this exercise. we will use it in exercise 2 */
///* this function calculates the distance between two points on board */
//double Position::distanceBtw2Points(Position pos) const {
//
//	double diff1, diff2;
//
//	diff1 = pow((_x - pos.getX()), 2);
//	diff2 = pow((_y - pos.getY()), 2);
//	return sqrt(diff1 + diff2);
//
//}
