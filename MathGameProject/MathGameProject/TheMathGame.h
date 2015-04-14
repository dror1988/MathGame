//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// TheMathGame.h
// -----------
// This file declares a class to implement TheMathGame as expected
// Author: Dror Moyal
// First version: 2015-04-11
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-11     Dror Moyal      implemented the TheMathGame class


#include "io_utils.h"
#include "Direction.h"
#include "screenMatrix.h"
#include "Exercise.h"
#include "Player.h"
#include "Point.h"
#include "StatusBar.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ISpecificGame.h"
class TheMathGame : public ISpecificGame
{
	Player player1;
	Player player2;
	unsigned int currentLevel;
	screenMatrix myScreen;
	StatusBar stBar;
	unsigned int clockTicksCurrentLevel;
	// const variables
	const static unsigned int CLOCK_TICKS_PER_LEVEL = 1500;
	const static unsigned int MAX_LEVEL = 20;
public:
	//=================================================
	// Default constructor
	//=================================================
	TheMathGame() :
		player1('@', Direction::RIGHT, Point(10, 9)),
		player2('#', Direction::LEFT, Point(70, 9)),
		currentLevel(0), myScreen(player1, player2), stBar(player1, player2){
	}

	//=================================================
	// Printing a snaphot of the current game
	//=================================================
	void printCurrentScreen();

	//=================================================
	// Reset the game necessary variables for a new game
	//=================================================
	virtual void resetAll();

	//=================================================
	// Check if a level is done and print a message 
	// regarding  the way the level was ended
	//=================================================
	virtual bool isLevelDone();

	//=================================================
	// Check if there are more levels to play
	//=================================================
	virtual bool hasNextLevel()const;

	//=================================================
	// setting up all the necessary things for the 
	// start of a new level
	//=================================================
	virtual void startLevel(int level);

	//=================================================
	// this is the actual game itteration. in this 
	// we move the players on the screen, creates numbers
	// and all other actions that are used in
	// a game itteration
	//=================================================
	virtual void doIteration(const list<char>& keyHits);

	//=================================================
	// will not be used in this exercise
	//=================================================
	virtual void doSubIteration(){}

};

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++