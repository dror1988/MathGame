#ifndef __SCREEN_MATRIX_H
#define __SCREEN_MATRIX_H

#include <string>
#include"Player.h"
#include"Number.h"
#include"Point.h"

using namespace std;

class screenMatrix
{
	Player p1, p2;
	Number *matrix[24][80];
public:
	screenMatrix(Player p1, Player p2);
	~screenMatrix();

	bool isNumberExist(Point numberPosition);
	void createNumber(int currentLevel);
	void printMatrix();
	void eraseMatrix();

};

#endif
