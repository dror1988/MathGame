//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// main.cpp
// --------
// This is the main entry point of the program.
// Keep the main short!
//
// Author: Amir Kirsh
// First version: 2014-12-09
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-13     Dror Moyal      implemented the TheMathGame

// In the file itself, add above each change/addition a remark saying: "NEW CODE EX1, author=<name>, date=<YYYY-MM-DD>"
// and close it at the end with a remark saying "END of NEW CODE EX1" 
// Add these remarks also at the beginning and end of any new file that you add.
//
// Below lines are an example, replace it with your own if you make any changes (one entry per relevant change!)
// NOTE: the lines shall be added in the file that was changed only!
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "GameManager.h"
#include "io_utils.h"
#include "Direction.h"
#include "screenMatrix.h"
#include "Exercise.h"
#include "Player.h"
#include "Point.h"
#include "StatusBar.h"

using namespace std;

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Dror Moyal, date=2015-04-13
// +++++++++++++++++++++++++++++++++++++++++++++++++

//================================================================================================
// This claas will inherint from ISpecificGame and will implement the abstract functions
// In addition we added 2 functions to help and manage the game by printing a game "Snap shot"
// and reseting the game neccesary variables for a totaly new game
//================================================================================================

class TheMathGame: public ISpecificGame
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
	TheMathGame():
		player1('@', Direction::RIGHT, Point(10, 9)),
		player2('#', Direction::LEFT, Point(70, 9)),
		currentLevel(0),myScreen(player1,player2),stBar(player1,player2){
	}

	//=================================================
	// Printing a snaphot of the current game
	//=================================================
		void printCurrentScreen(){
		clear_screen();
		setTextColor(WHITE);
		stBar.drawStatusBar();
		myScreen.printMatrix();
	}

	//=================================================
	// Reset the game necessary variables for a new game
	//=================================================
	virtual void resetAll(){
		player1.setScore(0);
		player2.setScore(0);
		currentLevel = 0;
	}

	//=================================================
	// Check if a level is done and print a message 
	// regarding  the way the level was ended
	//=================================================
	virtual bool isLevelDone(){
		// at least 1 player is still alive
		bool alivePlayer = player1.isPlayerAlive() || player2.isPlayerAlive();
		// one of the players or the two of them are done
		bool playerNotDone = player1.getPlayerDone() || player2.getPlayerDone();

		// in case time is not up, at least 1 player is a live and players are not done yet
		if (clockTicksCurrentLevel < CLOCK_TICKS_PER_LEVEL && alivePlayer && !playerNotDone)
			return false;
		else{
			clear_screen();
			setTextColor(YELLOW);

			//=======================================================
			// according to the reason of ending the level, print
			// the appropriet message to the screen
			//=======================================================

			// case the times run out
			if (clockTicksCurrentLevel >= CLOCK_TICKS_PER_LEVEL){
				gotoxy(33, 12);
				cout << "Time is up!!!";
				gotoxy(29, 13);
				cout<< "Try better next time!!";
			}
			// case both players are dead
			else if (!alivePlayer){
				gotoxy(28, 12);
				cout << "Both Players are dead!!!";
				gotoxy(29, 13);
				cout<< "Try better next time!!";
			}
			// case that player 1 is done and player 2 not
			else if (player1.getPlayerDone() && !player2.getPlayerDone()){
				gotoxy(33, 12);
				cout << "Player1 WIN!!";
			}
			// case that player 2 is done and player 1 not
			else if (player2.getPlayerDone() && !player1.getPlayerDone()){
				gotoxy(33, 12);
				cout << "Player2 WIN!!";
			}
			// case that bothe players finished at the same time
			else{
				gotoxy(35, 12);
				cout << "Its a TIE";
			}

			setTextColor(WHITE);
			return true;
		}
	}
	
	//=================================================
	// Check if there are more levels to play
	//=================================================
	virtual bool hasNextLevel()const{
		// check if reached to max level
		if (currentLevel < MAX_LEVEL)
			return true;
		else
			return false;
	}

	//=================================================
	// setting up all the necessary things for the 
	// start of a new level
	//=================================================
	virtual void startLevel(int level){
		clear_screen();
		currentLevel = level;
		clockTicksCurrentLevel = 0;

		// setting up player1 for a new level
		player1.setLives(3);
		player1.setPosition(Point(10,9));
		player1.changeDirection(Direction::RIGHT);
		player1.resetExercise();
		player1.createExercise(currentLevel);
		player1.resetPlayerAlive();
		player1.resetPlayerDone();
		
		// setting up player2 for a new level
		player2.setLives(3);
		player2.setPosition(Point(70,9));
		player2.changeDirection(Direction::LEFT);
		player2.resetExercise();
		player2.createExercise(currentLevel);
		player2.resetPlayerAlive();
		player2.resetPlayerDone();
		
		//settinp up status bar for a new level
		stBar.setTimeLeft(300);
		stBar.setCurrentLevel(currentLevel);
		stBar.drawStatusBar();
		
		// erasing the screen matrix
		myScreen.eraseMatrix();
	}

	//=================================================
	// this is the actual game itteration. in this 
	// we move the players on the screen, creates numbers
	// and all other actions that are used in
	// a game itteration
	//=================================================
	virtual void doIteration(const list<char>& keyHits){
		// counting seconds in a leve and printing
		// the time left for each level
		++clockTicksCurrentLevel;
		if (clockTicksCurrentLevel%5==0){
			stBar.decTimeLeft();
			stBar.updateTimeLeft();
		}

		// using the input from the users keyboard hits
		for (list<char>::const_iterator itr=keyHits.begin(); itr!=keyHits.end(); ++itr){
			char ch=*itr;
			// according to the users key hits change the direction if needed
			switch (ch){
				case 'i':
					player2.changeDirection(Direction::UP);
					break;
				case 'w':
					player1.changeDirection(Direction::UP);
					break;
				case 'j':
					player2.changeDirection(Direction::LEFT);
					break;
				case 'a':
					player1.changeDirection(Direction::LEFT);
					break;
				case 'm':
					player2.changeDirection(Direction::DOWN);
					break;
				case 'x':
					player1.changeDirection(Direction::DOWN);
					break;
				case 'l':
					player2.changeDirection(Direction::RIGHT);
					break;
				case 'd':
					player1.changeDirection(Direction::RIGHT);
					break;
				default:
					break;
				}
			}
			
			// create a number, if successful print to screen
			myScreen.createNumber(currentLevel);

			// check if the player is still alive and according to the direction of its
			// movment and the position of the oponent player see if the player can move
			if (player1.isMoveLegal(player2.getPosition())&&player1.isPlayerAlive()){
				player1.playerErase();
				player1.playerMove();
				player1.playerDraw();

				// check if the player is now eating a number
				if (myScreen.isNumberExist(player1.getPosition()))
					// check if the number that the player is eating is the sulotion for his "targil"
					if (!player1.isPlayerDone(myScreen.getNumberInPos(player1.getPosition()))){
						player1.setLives(player1.getLives()-1);
						stBar.updatePlayerLife(1);
						// if user ran out of lives
						if (!player1.isPlayerAlive())
							player1.playerErase();
					}
					else{
						player1.setScore(player1.getScore()+1);
					}

			}

			// check if the player is still alive and according to the direction of its
			// movment and the position of the oponent player see if the player can move
			if (player2.isMoveLegal(player1.getPosition())&&player2.isPlayerAlive()){
				player2.playerErase();
				player2.playerMove();
				player2.playerDraw();

				// check if the player is now eating a number
				if (myScreen.isNumberExist(player2.getPosition()))
					// check if the number that the player is eating is the sulotion for his "targil"
					if (!player2.isPlayerDone(myScreen.getNumberInPos(player2.getPosition()))){
						player2.setLives(player2.getLives()-1);
						stBar.updatePlayerLife(2);
						// if user ran out of lives
						if (!player2.isPlayerAlive())
							player2.playerErase();
					}
					else{
						player2.setScore(player2.getScore()+1);
					}

			}
		}

	//=================================================
	// will not be used in this exercise
	//=================================================
	virtual void doSubIteration(){}
};

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++

//==========================
//  M  A  I  N
//==========================
int main(){
	clear_screen();
	hideCursor();

	// +++++++++++++++++++++++++++++++++++++++++++++++++
	// "NEW CODE EX1, author=Dror Moyal, date=2015-04-13
	// +++++++++++++++++++++++++++++++++++++++++++++++++

	TheMathGame MyGame;
	srand((unsigned int)time(NULL));

	GameManager(MyGame, (unsigned int)200, (unsigned int)2).run();

	//+++++++++++++++++++++
	// END of NEW CODE EX1
	//+++++++++++++++++++++

	return 0;
}
//==========================
// E n d   o f   M  A  I  N
//==========================
