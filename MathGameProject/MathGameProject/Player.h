#ifndef __PLAYER_H
#define __PLAYER_H

#include "Direction.h"
#include "Exercise.h"

class Player{
	unsigned char playerChar;
	unsigned int playerScore;
	unsigned int playerLives;
	bool isPlayerAlive;
	Direction playerDirection;
	Exercise* playerExercise;
	Point playerPosition;
public:
	Player(unsigned char playerChar, Direction playerDirection, Point playerPosition)
		:playerChar(playerChar), playerScore(0), playerLives(3), isPlayerAlive(TRUE), playerDirection(playerDirection),
		playerPosition(playerPosition), playerExercise(NULL){
	}
	~Player(){
		if (playerExercise != NULL)
			delete playerExercise;
	}

	unsigned int getScore();
	unsigned int getLives();
	Point getPosition(); 
	Direction getDirection();
	Exercise* getExercise();

	unsigned int setScore(unsigned int newScore);
	unsigned int setLives(unsigned int newLives);
	Point setPosition(Point newPosition);
	Direction setDirection(Direction newDirection);
	Exercise* createExercise();
};

#endif