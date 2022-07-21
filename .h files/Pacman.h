#ifndef PACMAN_H
#define PACMAN_H

#include "Objects.h"

class Pacman : public Objects  {

	enum { ESC = 27, speed = 300 };
	Position firstPos=Position(0,0);
	int lives = 3;
	int score = 0;
	int breadCrumsScore = 0;

public:

	Pacman() : Objects( '@', Color::GREEN) {}
	Position getFirstPos()
	{
		return firstPos;
	}
	void setFirstPos(Position pos)
	{
		firstPos = pos;
	}
	int getBreadCrumsScore() const {
		return breadCrumsScore;
	}
	void setBreadCrumsScore(int _breadScore)
	{
		breadCrumsScore = _breadScore;
	}
	int getScore() const {
		return score;
	}
	void setScore(int _score)
	{
		score = _score;
	}
	int getLives() const {
		return lives;
	}
	void setLives(int _lives)
	{
		lives = _lives;
	}

	void resetPacmanPos()
	{
		setPosition(firstPos);
	}
	bool isValidDirection(char dir) const;
	void move(GameBoard& board);
	Position getNextPosition( GameBoard& board);
	void deletePacmanMove(Position curXY) const;

private:
	bool isNextPosValid(Position nextpoint, GameBoard& board) const;
	void hitESC();


};



#endif
