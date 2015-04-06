#ifndef __PLAYER_H
#define __PLAYER_H

#include <string>
#include "Direction.h"
#include "Exercise.h"
#include "Point.h"

using namespace std;

class Player{
	unsigned char playerChar;
	unsigned int playerScore;
	unsigned int playerLives;
	bool isPlayerAlive;
	Direction::VALUE playerDirection;
	Exercise* playerExercise;
	Point playerPosition;
public:
	Player(unsigned char playerChar, Direction::VALUE playerDirection, Point playerPosition)
		:playerChar(playerChar), playerScore(0), playerLives(3), isPlayerAlive(true), playerDirection(playerDirection),
		playerPosition(playerPosition), playerExercise(NULL){
	}
	~Player(){
		if (playerExercise != NULL)
			delete playerExercise;
	}

	unsigned int getScore()const;
	unsigned int getLives()const;
	Point getPosition()const;
	Direction::VALUE getDirection()const;
	string getExercise()const;

	unsigned int setScore(unsigned int newScore);
	unsigned int setLives(unsigned int newLives);
	Point setPosition(Point newPosition);
	void changeDirection(Direction::VALUE newDirection);
	Exercise* createExercise(int currentLevel);

	void playerDraw()const;
	void playerErase()const;
	void playerMove();
};

#endif