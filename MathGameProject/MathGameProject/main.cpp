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
// In the file itself, add above each change/addition a remark saying: "NEW CODE EX1, author=<name>, date=<YYYY-MM-DD>"
// and close it at the end with a remark saying "END of NEW CODE EX1" 
// Add these remarks also at the beginning and end of any new file that you add.
//
// Below lines are an example, replace it with your own if you make any changes (one entry per relevant change!)
// NOTE: the lines shall be added in the file that was changed only!
//
// 2014-12-15     Yovav Ben-Shimshon      implemented the menu
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

// this is for example only!
// delete this class and implement your own properly!
class TheMathGame: public ISpecificGame
{
	Player player1;
	Player player2;
	unsigned int currentLevel;
	screenMatrix myScreen;
	StatusBar stBar;
	const static unsigned int CLOCK_TICKS_PER_LEVEL = 1500;
	const static unsigned int MAX_LEVEL = 20;
	unsigned int clockTicksCurrentLevel;
public:
	TheMathGame():
		player1('@', Direction::RIGHT, Point(10, 9)),
		player2('#', Direction::LEFT, Point(70, 9)),
		currentLevel(0),myScreen(player1,player2),stBar(player1,player2){
	}
	void printCurrentScreen(){
		clear_screen();
		setTextColor(WHITE);
		stBar.drawStatusBar();
		myScreen.printMatrix();
	}
	virtual void resetAll(){
		player1.setScore(0);
		player2.setScore(0);
		currentLevel = 0;
	}
	virtual bool isLevelDone(){
		bool alivePlayer = player1.isPlayerAlive() || player2.isPlayerAlive();
		bool playerNotDone = player1.getPlayerDone() || player2.getPlayerDone();
		if (clockTicksCurrentLevel < CLOCK_TICKS_PER_LEVEL && alivePlayer && !playerNotDone)
			return false;
		else{
			clear_screen();
			setTextColor(YELLOW);
			if (clockTicksCurrentLevel >= CLOCK_TICKS_PER_LEVEL){
				gotoxy(33, 12);
				cout << "Time is up!!!";
				gotoxy(29, 13);
				cout<< "Try better next time!!";
			}
			else if (!alivePlayer){
				gotoxy(28, 12);
				cout << "Both Players are dead!!!";
				gotoxy(29, 13);
				cout<< "Try better next time!!";
			}
			else if (player1.getPlayerDone() && !player2.getPlayerDone()){
				gotoxy(33, 12);
				cout << "Player1 WIN!!";
			}
			else if (player2.getPlayerDone() && !player1.getPlayerDone()){
				gotoxy(33, 12);
				cout << "Player2 WIN!!";
			}
			else{
				gotoxy(35, 12);
				cout << "Its a TIE";
			}
			setTextColor(WHITE);
			return true;
		}
	}
	virtual bool hasNextLevel()const{
		if (currentLevel < MAX_LEVEL)
			return true;
		else
			return false;
	}
	virtual void startLevel(int level){
		clear_screen();
		currentLevel = level;
		clockTicksCurrentLevel = 0;
		player1.setLives(3);
		player2.setLives(3);
		player1.setPosition(Point(10,9));
		player2.setPosition(Point(70,9));
		player1.changeDirection(Direction::RIGHT);
		player2.changeDirection(Direction::LEFT);
		player1.resetExercise();
		player2.resetExercise();
		player1.createExercise(currentLevel);
		player2.createExercise(currentLevel);
		player1.resetPlayerAlive();
		player1.resetPlayerDone();
		player2.resetPlayerAlive();
		player2.resetPlayerDone();
		stBar.setTimeLeft(300);
		stBar.setCurrentLevel(currentLevel);
		stBar.drawStatusBar();
		myScreen.eraseMatrix();
	}
	virtual void doIteration(const list<char>& keyHits){
		//=================================================================
		//this is the code for running on the keyhits
		++clockTicksCurrentLevel;
		if (clockTicksCurrentLevel%5==0){
			stBar.decTimeLeft();
			stBar.updateTimeLeft();
		}
		for (list<char>::const_iterator itr=keyHits.begin(); itr!=keyHits.end(); ++itr){
			char ch=*itr; //need to change from cout to actual action
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
			
			myScreen.createNumber(currentLevel);

			if (player1.isMoveLegal(player2.getPosition())&&player1.isPlayerAlive()){
				player1.playerErase();
				player1.playerMove();
				player1.playerDraw();

				if (myScreen.isNumberExist(player1.getPosition()))
					if (!player1.isPlayerDone(myScreen.getNumberInPos(player1.getPosition()))){
						player1.setLives(player1.getLives()-1);
						stBar.updatePlayerLife(1);
						if (!player1.isPlayerAlive())
							player1.playerErase();
					}
					else{
						player1.setScore(player1.getScore()+1);
					}

			}

			if (player2.isMoveLegal(player1.getPosition())&&player2.isPlayerAlive()){
				player2.playerErase();
				player2.playerMove();
				player2.playerDraw();

				if (myScreen.isNumberExist(player2.getPosition()))
					if (!player2.isPlayerDone(myScreen.getNumberInPos(player2.getPosition()))){
						player2.setLives(player2.getLives()-1);
						stBar.updatePlayerLife(2);
						if (!player2.isPlayerAlive())
							player2.playerErase();
					}
					else{
						player2.setScore(player2.getScore()+1);
					}

			}
		}
	virtual void doSubIteration(){}
};


//==========================
//  M  A  I  N
//==========================
int main(){
	clear_screen();
	hideCursor();
	srand((unsigned int)time(NULL));
	/*
	//===================
	//  T E S T
	//===================

	Exercise ex1(1);
	cout << ex1.getExercise() << endl;
	int res;
	cin >> res;
	if (ex1.isExerciseComplete(res) == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	Player p1('@', Direction::DOWN, Point(0, 0));
	Player p2('#', Direction::DOWN, Point(0, 20));
	cout << "Score: "<<p1.getScore() << " Lives:" << p1.getLives() << endl;
	switch (p1.getDirection()){
	case Direction::UP:
		cout << "Direction is UP" << endl;
		break;
	case Direction::DOWN:
		cout << "Direction is DOWN" << endl;
		break;
	case Direction::LEFT:
		cout << "Direction is LEFT" << endl;
		break;
	case Direction::RIGHT:
		cout << "Direction is RIGHT" << endl;
		break;
	}

	Point po1;
	cout << "po1.x=" << po1.x << " po1.y=" << po1.y << endl;
	po1 = p1.getPosition();
	cout << "p1.x=" << po1.x << " p1.y=" << po1.y << endl;

	cout << "Exercise " << p1.getExercise() << endl;
	p1.createExercise(20);
	cout << "Exercise " << p1.getExercise() << endl;

	p1.setScore(21);
	p1.setLives(6);
	p1.setPosition(Point(9,8));
	p1.changeDirection(Direction::LEFT);

	p1.setPosition(Point(20,20));
	po1 = p1.getPosition();
	cout << "p1.x=" << po1.x << " p1.y=" << po1.y << endl;


	cout << "Score: " << p1.getScore() << " Lives:" << p1.getLives() << endl;
	switch (p1.getDirection()){
	case Direction::UP:
		cout << "Direction is UP" << endl;
		break;
	case Direction::DOWN:
		cout << "Direction is DOWN" << endl;
		break;
	case Direction::LEFT:
		cout << "Direction is LEFT" << endl;
		break;
	case Direction::RIGHT:
		cout << "Direction is RIGHT" << endl;
		break;
	}
	
	_getch();

	//run on screen code
	//clear_screen();
	char ch = 0;
	while (ch != 27){
		if (_kbhit()){
			ch = _getch();
			switch (ch){
			case 'i':
				//p2.changeDirection(Direction::UP);
			case 'w':
				p1.changeDirection(Direction::UP);
				break;
			case 'j':
				//p2.changeDirection(Direction::LEFT);
			case 'a':
				p1.changeDirection(Direction::LEFT);
				break;
			case 'm':
				//p2.changeDirection(Direction::DOWN);
			case 'x':
				p1.changeDirection(Direction::DOWN);
				break;
			case 'l':
				//p2.changeDirection(Direction::RIGHT);
			case 'd':
				p1.changeDirection(Direction::RIGHT);
				break;
			default:
				break;
			}
		}
		p1.playerErase();
		p1.playerMove();
		p1.playerDraw();
		Sleep(100);
	}
	clear_screen();

	screenMatrix myScreen(p1,p2);

	for (int i=0; i<1; ++i){
		myScreen.createNumber(20);
		Sleep(1000);
	}

	_getch();
	myScreen.eraseMatrix();
	myScreen.printMatrix();
	_getch();

	for (int i=0; i<1; ++i){
		myScreen.createNumber(120);
		Sleep(1000);
	}

	p2.createExercise(30);
	p2.setScore(33);
	p2.setLives(9);
	
	clear_screen();
	StatusBar stBar(p1,p2,int(1));
	stBar.drawStatusBar();

	for (int i=0; i<100; ++i){
		stBar.setTimeLeft(i);
		stBar.updateTimeLeft();
		p1.setLives(i);
		stBar.updatePlayerLife(1);
		Sleep(1000);
	}

	
	//end of run on screen code

	//run reverse on screen code
	
	clear_screen();
	ch = 0;
	while (ch != 27){
		if (_kbhit()){
			ch = _getch();
			switch (ch){
			case 'i':
				//p2.changeDirection(Direction::UP);
			case 'w':
				p1.changeDirection(Direction::UP);
				break;
			case 'j':
				//p2.changeDirection(Direction::LEFT);
			case 'a':
				p1.changeDirection(Direction::LEFT);
				break;
			case 'm':
				//p2.changeDirection(Direction::DOWN);
			case 'x':
				p1.changeDirection(Direction::DOWN);
				break;
			case 'l':
				//p2.changeDirection(Direction::RIGHT);
			case 'd':
				p1.changeDirection(Direction::RIGHT);
				break;
			default:
				break;
			}
		}
		p1.playerErase();
		p1.playerReverseMove();
		p1.playerDraw();
		Sleep(100);
	}

	//end of run reverse on screen code
	
	//===================
	// E N D   T E S T
	//===================
*/
	TheMathGame MyGame;
	GameManager(MyGame, (unsigned int)200, (unsigned int)2).run();
	return 0;
}
//==========================
// E n d   o f   M  A  I  N
//==========================
