//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Number.h
// -----------
// This file declares a class to manage the numbers on the screen, their type(represents tens digits or ones digits) and their position.
//
// Author: Maya Bugana
// First version: 2015-04-10
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-10    Maya Bugana     implemented the screenMatrix class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Maya Bugana, date=2015-04-10
// +++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef __NUMBER_H
#define __NUMBER_H

#include <string>
#include "io_utils.h"
#include "Point.h"

using namespace std;

class Number
{
	unsigned int Num;
	bool isTens;
	bool isOnes;
	Point numberPosition;
public:
	Number(){};

	// Number constructor
	Number(unsigned int num, bool isTens, bool isOnes, Point numberPosition)
		: Num(Num), isTens(false), isOnes(false), numberPosition(numberPosition){
	}

	// Number destructor
	~Number() {
		isTens = false;
		isOnes = false;
	}

	// Number getter
	unsigned int getNum()const;
	// IsTens getter
	bool getIsTens()const;
	// IsOnes getter
	bool getIsOnes()const;
	// numberPosition getter
	Point getNumberPosition()const;

	// Number setter
	unsigned int setNum(unsigned int newNum);
	// isTens setter
	bool setIsTens(bool newIsTensValue);
	// isOnes setter
	bool setIsOnes(bool newIsOnesValue);
	// numberPosition setter
	Point setNumberPosition(Point newPosition);

	//Prints number in position
	void Print();
	
};


#endif

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
