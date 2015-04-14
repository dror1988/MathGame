//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exercise.h
// -----------
// This file declares a class to manage an exercise. 
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
// 2015-04-07     Dror Moyal      implemented the Execise class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Dror Moyal, date=2015-04-07
// +++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef __EXERCISE_H
#define __EXERCISE_H

#include <stdlib.h>
#include <string>
#include "io_utils.h"

using namespace std;

//=====================================
// this class implements the use of an 
// exercise or "targil"
//=====================================
class Exercise{
	unsigned int leftNum;
	unsigned int rightNum;
	unsigned int result;
	unsigned char action;
	unsigned int numToHide;
	unsigned int hiddenNumber;
	string strExercise;
public:
	// exercise constructor
	Exercise(int currentLvl);

	// "targil getter
	string getExercise();
	// check if a number completes the exercise
	bool isExerciseComplete(unsigned int tryNum);
};

#endif

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
