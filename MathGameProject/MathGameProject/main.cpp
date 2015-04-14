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
#include "TheMathGame.h"

using namespace std;


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
