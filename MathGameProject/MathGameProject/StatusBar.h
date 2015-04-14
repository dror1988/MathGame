//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// StatusBar.h
// -----------
// This file declares a class presents and updates the first 3 rows in the play screen.
//
// Author: Dror Moyal
// First version: 2015-04-11
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-08     Dror Moyal      implemented the Player class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Dror Moyal, date=2015-04-08
// +++++++++++++++++++++++++++++++++++++++++++++++++


#ifndef __STATUS_BAR_H
#define __STATUS_BAR_H

#include <iostream>
#include "io_utils.h"
#include "Player.h"
#include "Color.h"

using namespace std;

//=====================================
// this class implements the use of a 
// StatusBar
//=====================================

class StatusBar{
	unsigned int timeLeft;
	unsigned int currentLevel;
	const Player &p1;
	const Player &p2;
public:
	// StatusBar constructor
	StatusBar(const Player &player1, const Player &player2)
		:p1(player1),p2(player2),currentLevel(0),timeLeft(300){
	}

	//update the time left
	void setTimeLeft(unsigned int newTimeLeft){
		timeLeft=newTimeLeft;
	}

	//update current level
	void setCurrentLevel(unsigned int newCurrentLevel){
		currentLevel = newCurrentLevel;
	}

	//Reduces the time left
	void decTimeLeft(){
		--timeLeft;
	}

	//TimeLeft getter
	unsigned int getTimeLeft(){
		return timeLeft;
	}

	//Prints Status Bar
	void drawStatusBar();

	//update the player life amount
	void updatePlayerLife(unsigned int playerNumber);

	//update time left value
	void updateTimeLeft();
};

#endif

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
