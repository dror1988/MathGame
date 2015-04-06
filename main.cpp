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

#include "Exercise.h"
#include "Player.h"
#include "Point.h"


using namespace std;

// this is for example only!
// delete this class and implement your own properly!
class TheMathGame: public ISpecificGame
{
public:
	virtual bool isLevelDone()const{return false;}
	virtual bool hasNextLevel()const{return true;}
	virtual void startLevel(){}
	virtual void doIteration(const list<char>& keyHits){}
	virtual void doSubIteration(){}
};


//==========================
//  M  A  I  N
//==========================
int main(){
	clear_screen();
	hideCursor();
	srand((unsigned int)time(NULL));

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

	Player p1('#', Direction::DOWN, Point(0, 0));
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
	p1.setLives(14);
	p1.setPosition(Point(9,8));
	p1.changeDirection(Direction::LEFT);

	po1.x=79;
	po1.y = 23;
	p1.setPosition(po1);
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
	

	//run on screen code
	clear_screen();
	char ch=0;
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
		p1.playerMove();
		Sleep(50);
	}

	//end of run on screen code
	
	//===================
	// E N D   T E S T
	//===================

	GameManager(TheMathGame(), 200, 2).run();
	return 0;
}
//==========================
// E n d   o f   M  A  I  N
//==========================



//Maya Change