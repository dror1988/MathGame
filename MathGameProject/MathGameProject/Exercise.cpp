//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Exercise.cpp
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

#include "Exercise.h"

//==========================================================
// in the constructor we create an exercise that will be the 
// player goal to finish. we do it by randomly choose 2 
// numbers and an arithmetic operator. using the data we get
// we build the exercise according to the expected logic in 
// EX1 instructions and create a string that will be used to 
// present the exercise to the players
//==========================================================
Exercise::Exercise(int currentLvl){
	//temp variable to help and choose the "+,-,/,*" according to rand function
	int chooseAction = rand() % 4;

	// place to store itoa_s result
	char strNumber1[4];
	char strNumber2[4];

	// which number should be hidden
	numToHide = rand() % 2;
	// randomly choose 2 numbers using 10 + current level
	leftNum = rand() % (10 + currentLvl) + 1;
	rightNum = rand() % (10 + currentLvl) + 1;

	// create an exercise according to the operator
	switch (chooseAction){
	// case the operator should be +
	case 0:
		action = '+';
		result = leftNum + rightNum;
		if (numToHide == 0){
			_itoa_s(rightNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(result, strNumber2, sizeof(strNumber2), 10);
			strExercise = "_" + string(1, action) + strNumber1 + "=" + strNumber2;
			hiddenNumber = leftNum;
		}
		else{
			_itoa_s(leftNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(result, strNumber2, sizeof(strNumber2), 10);
			strExercise = strNumber1 + string(1, action) + "_" + "=" + strNumber2;
			hiddenNumber = rightNum;
		}
		break;
	// case the operator should be -
	case 1:
		action = '-';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result + rightNum; // according to the "targil" logic
		if (numToHide == 0){
			_itoa_s(leftNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(rightNum, strNumber2, sizeof(strNumber2), 10);
			strExercise = strNumber1 + string(1, action) + strNumber2 + "=" + "_";
			hiddenNumber = result;
		}
		else{
			_itoa_s(leftNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(result, strNumber2, sizeof(strNumber2), 10);
			strExercise = strNumber1 + string(1, action) + "_" + "=" + strNumber2;
			hiddenNumber = rightNum;
		}
		break;
	// case the operator should be *
	case 2:
		action = '*';
		result = leftNum * rightNum;
		if (numToHide == 0){
			_itoa_s(rightNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(result, strNumber2, sizeof(strNumber2), 10);
			strExercise = "_" + string(1, action) + strNumber1 + "=" + strNumber2;
			hiddenNumber = leftNum;
		}
		else{
			_itoa_s(leftNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(result, strNumber2, sizeof(strNumber2), 10);
			strExercise = strNumber1 + string(1, action) + "_" + "=" + strNumber2;
			hiddenNumber = rightNum;
		}
		break;
	// case the operator should be /
	case 3:
		action = '/';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result * rightNum; // according to the "targil" logic
		if (numToHide == 0){
			_itoa_s(leftNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(rightNum, strNumber2, sizeof(strNumber2), 10);
			strExercise = strNumber1 + string(1, action) + strNumber2 + "=" + "_";
			hiddenNumber = result;
		}
		else{
			_itoa_s(leftNum, strNumber1, sizeof(strNumber1), 10);
			_itoa_s(result, strNumber2, sizeof(strNumber2), 10);
			strExercise = strNumber1 + string(1, action) + "_" + "=" + strNumber2;
			hiddenNumber = rightNum;
		}
		break;
	default:
		break;
	}

}

//======================
// implementation of the
// exercise getter
//======================
string Exercise::getExercise(){
	return strExercise;
}

//====================================
// when user eats a number, check if 
// the number completes the exercise
//====================================
bool Exercise::isExerciseComplete(unsigned int tryNum){
	if (tryNum == hiddenNumber)
		return true;
	else
		return false;
}

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
