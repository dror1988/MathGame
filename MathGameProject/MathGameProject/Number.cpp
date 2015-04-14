//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Number.cpp
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


#include "Number.h"
#include "io_utils.h"

//===================================
// Number getter
//===================================
unsigned int Number::getNum()const{
	return Num;
}

//===================================
// isTens getter
//===================================
bool Number::getIsTens()const{
	return isTens;
}

//===================================
// isOnes getter
//===================================
bool Number::getIsOnes()const{
	return isOnes;
}

//===================================
// numberPosition getter
//===================================
Point Number::getNumberPosition()const{
	return numberPosition;
}

//===================================
// Number setter
//===================================
unsigned int Number::setNum(unsigned int newNum){
	Num = newNum;
	return Num;
}

//===================================
// isTens setter
//===================================
bool Number::setIsTens(bool newIsTensValue){
	isTens = newIsTensValue;
	return isTens;
}

//===================================
// isOnes setter
//===================================
bool Number::setIsOnes(bool newIsOnesValue){
	isOnes = newIsOnesValue;
	return isOnes;
}

//===================================
// numberPosition setter
//===================================
Point Number::setNumberPosition(Point newPosition){
	numberPosition = newPosition;
	return numberPosition;
}

//===================================
//Prints a numbe in position
//===================================
void Number::Print(){
	gotoxy(numberPosition.x, numberPosition.y);
	cout << Num << endl;
}

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
