//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// screenMatrix.h
// -----------
// This file declares a class to manage the creation, apperaence and disapperaence of numbers and players exist on the screen.
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

#ifndef __SCREEN_MATRIX_H
#define __SCREEN_MATRIX_H

#include <string>
#include "Player.h"
#include "Number.h"
#include "Point.h"
#include "io_utils.h"

//=====================================
// this class implements the use of a 
// Screen Matrix
//=====================================

class screenMatrix
{
	Player &p1,&p2;
	Number *matrix[24][80];
public:
	// screenMatrix constructor
	screenMatrix(Player &player1,Player &player2):p1(player1),p2(player2){
			for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			matrix[i][j] = NULL;
		}
	}
	}

	// screenMatrix destructor
	~screenMatrix();

	//Returns true if number exist in the matrix
	bool isNumberExist(Point numberPosition);

	//Creates number if all conditions are fulfilled
	void createNumber(int currentLevel);

	//prints the Players and Numbers exist (not NULL)
	void printMatrix();

	//deletes all Numbers in the Matrix
	void eraseMatrix();

	//Return the number in position and deletes it from screen
	unsigned int getNumberInPos(Point numberPosition);

	//Deletes a number in a specific position on the screen
	void eraseNumberInPos(Point numberPosition);

};

#endif

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++