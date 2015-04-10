#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include "Direction.h"
#include "Exercise.h"
#include "Point.h"

using namespace std;

class Player{
	unsigned char playerChar;
	unsigned int playerScore;
	unsigned int playerLives;
	bool playerAlive;
	bool playerDone;
	Direction::VALUE playerDirection;
	Exercise* playerExercise;
	Point playerPosition;
public:
	Player(unsigned char playerChar, Direction::VALUE playerDirection, Point playerPosition)
		:playerChar(playerChar), playerScore(0), playerLives(3), playerAlive(true), playerDone(false), playerDirection(playerDirection),
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

	bool isPlayerAlive();
	bool isPlayerDone();

	void playerDraw()const;
	void playerErase()const;
	
	//Function that computes the movement of a player according to the players direction
	void playerMove();
	//Function used to go back if the 2 players colide
	void playerReverseMove();
	/*The use of the functions above are is something like this:
	
	p1.playerMove();
	if (p1.getPosition()==p2.getPosition())
		p1.playerReverseMove();
	p1.playerDraw();

	*/

};

#endif