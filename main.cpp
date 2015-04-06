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

	/*
	Direction dr1;
	dr1.value = Direction::DOWN;
	Player p1('#', dr1,Point(0,0));
	cout << "Score: "<<p1.getScore() << " Lives:" << p1.getLives() << endl;
	dr1 = p1.getDirection();
	switch (dr1.value){
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
	dr1.value = Direction::LEFT;
	p1.setDirection(dr1);

	po1.x=69;
	po1.y = 96;
	p1.setPosition(po1);
	po1 = p1.getPosition();
	cout << "p1.x=" << po1.x << " p1.y=" << po1.y << endl;


	cout << "Score: " << p1.getScore() << " Lives:" << p1.getLives() << endl;
	dr1 = p1.getDirection();
	switch (dr1.value){
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
	*/
	
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