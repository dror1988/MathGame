// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-08     Dror Moyal      implemented the Player class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Dror Moyal, date=2015-04-08
// +++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include "Direction.h"
#include "Exercise.h"
#include "Point.h"

using namespace std;

//=====================================
// this class implements the use of a 
// player
//=====================================
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
	// player default constructor
	Player()
		:playerChar(0), playerScore(0), playerLives(3), playerAlive(true), playerDone(false), playerDirection(Direction::STAY),
		playerPosition(Point(0,0)), playerExercise(NULL){
	}
	// player constructor
	Player(unsigned char playerChar, Direction::VALUE playerDirection, Point playerPosition)
		:playerChar(playerChar), playerScore(0), playerLives(3), playerAlive(true), playerDone(false), playerDirection(playerDirection),
		playerPosition(playerPosition), playerExercise(NULL){
	}
	// player destructor
	~Player(){
		// if player has an exercise, release it
		if (playerExercise != NULL)
			delete playerExercise;
	}

	// score getter
	unsigned int getScore()const;
	// lives getter
	unsigned int getLives()const;
	// position getter
	Point getPosition()const;
	// direction getter
	Direction::VALUE getDirection()const;
	// exercise getter
	string getExercise()const;

	// score setter
	unsigned int setScore(unsigned int newScore);
	// lives setter
	unsigned int setLives(unsigned int newLives);
	// position setter
	Point setPosition(Point newPosition);
	// direction setter
	Direction::VALUE changeDirection(Direction::VALUE newDirection);
	// exercise creator
	Exercise* createExercise(int currentLevel);

	//===========================
	// delete old exercise and
	// create a new one
	//===========================
	void resetExercise(){
		if (playerExercise!=NULL){
			delete playerExercise;
			playerExercise=NULL;
		}
	}

	bool isPlayerAlive();
	void resetPlayerAlive(){
		playerAlive=true;
	}
	bool isPlayerDone(unsigned int eatenNumber);
	bool getPlayerDone();
	void resetPlayerDone(){
		playerDone=false;
	}

	void playerDraw()const;
	void playerErase()const;
	
	//Function that computes the movement of a player according to the players direction
	void playerMove();
	bool isMoveLegal(Point otherPlayerPos);
};

#endif

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
