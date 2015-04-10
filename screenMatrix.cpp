#include"screenMatrix.h"
#include "io_utils.h"


screenMatrix::screenMatrix(Player p1, Player p2):p1(p1), p2(p2){
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			matrix[i][j] = NULL;
		}
	}
}

screenMatrix::~screenMatrix(){
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if(matrix[i][j] != NULL)
				matrix[i][j] = NULL;
		}
	}
}

void screenMatrix::createNumber(int currentLevel){
	int triesCounter = 0;
	bool isSuccess = false;
	int num = rand() % (10 + currentLevel) + 1;
	
	if (num < 10)
	{
		while (isSuccess == false && triesCounter <= 10)
		{
			Point numPosition;
			if (numPosition != p1.getPosition && numPosition != p2.getPosition && matrix[numPosition.y][numPosition.x] == NULL
				&& matrix[numPosition.y + 1][numPosition.x] == NULL && matrix[numPosition.y][numPosition.x + 1] == NULL)
			{
				Number *newOne = new Number;
				*newOne->setIsOnes = true;
				*newOne->setNum = num;
				*newOne->setNumberPosition = numPosition;
				isSuccess = true;
			}
			else
				triesCounter++;
		}
	}
	else if (num >= 10)
	{
		while (isSuccess == false && triesCounter <= 10)

	}
}

void screenMatrix::printMatrix(){
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (matrix[i][j] != NULL)
			{
				gotoxy(j,i);
				cout << *matrix[i][j]->getNum;
			}
		}
	}
	p1.playerDraw;
	p2.playerDraw;
}

void screenMatrix::eraseMatrix(){
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (matrix[i][j] != NULL)
			{
				gotoxy(j, i);
				cout << ' ';
			}
		}
	}
	p1.playerErase;
	p2.playerErase;
}