#ifndef __STATUS_BAR_H
#define __STATUS_BAR_H

#include <iostream>
#include "io_utils.h"
#include "Player.h"
#include "Color.h"

using namespace std;

class StatusBar{
	unsigned int timeLeft;
	unsigned int currentLevel;
	const Player &p1;
	const Player &p2;
public:
	StatusBar(const Player &player1, const Player &player2)
		:p1(player1),p2(player2),currentLevel(0),timeLeft(300){
	}
	void setTimeLeft(unsigned int newTimeLeft){
		timeLeft=newTimeLeft;
	}
	void setCurrentLevel(unsigned int newCurrentLevel){
		currentLevel = newCurrentLevel;
	}
	void decTimeLeft(){
		--timeLeft;
	}
	unsigned int getTimeLeft(){
		return timeLeft;
	}

	void drawStatusBar();
	void updatePlayerLife(unsigned int playerNumber);
	void updateTimeLeft();
};

#endif