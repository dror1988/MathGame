#ifndef __SCREEN_MATRIX_H
#define __SCREEN_MATRIX_H

#include <string>
#include "Player.h"
#include "Number.h"
#include "Point.h"
#include "io_utils.h"

//using namespace std;

class screenMatrix
{
	Player &p1,&p2;
	Number *matrix[24][80];
public:
	screenMatrix(Player &player1,Player &player2):p1(player1),p2(player2){
			for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			matrix[i][j] = NULL;
		}
	}
	}
	~screenMatrix();

	bool isNumberExist(Point numberPosition);
	void createNumber(int currentLevel);
	void printMatrix();
	void eraseMatrix();
	unsigned int getNumberInPos(Point numberPosition);
	void eraseNumberInPos(Point numberPosition);

};

#endif
