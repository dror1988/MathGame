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
	Direction playerDirection;
	Exercise* playerExercise;
	Point playerPosition;
public:
	Player(unsigned char playerChar, Direction playerDirection1, Point playerPosition)
		:playerChar(playerChar), playerScore(0), playerLives(3), isPlayerAlive(true), playerDirection(playerDirection1),
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
	string getExercise();

	unsigned int setScore(unsigned int newScore);
	unsigned int setLives(unsigned int newLives);
	Point setPosition(Point newPosition);
	void changeDirection(char newDirection);
	Exercise* createExercise(int currentLevel);

	void playerDraw();
	void playerErase();
	void playerMove();
};

#endif