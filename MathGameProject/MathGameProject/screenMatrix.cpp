#include "screenMatrix.h"

screenMatrix::~screenMatrix(){
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (matrix[i][j] != NULL)
				delete matrix[i][j];
				matrix[i][j] = NULL;
		}
	}
}

bool screenMatrix::isNumberExist(Point numberPosition){
	if (matrix[numberPosition.y][numberPosition.x]!=NULL)
		return true;
	return false;
}

void screenMatrix::createNumber(int currentLevel){
	int triesCounter = 0;
	bool isSuccess = false;
	int num = rand() % (10 + currentLevel) + 1;
	
	if (num < 10)
	{
		while (isSuccess == false && triesCounter < 10)
		{
			Point numPosition;
			if (numPosition.x != p1.getPosition().x && numPosition.y != p1.getPosition().y
				&& numPosition.x != p2.getPosition().x && numPosition.y != p2.getPosition().y
				&& matrix[numPosition.y][numPosition.x] == NULL
				&& matrix[numPosition.y + 1][numPosition.x] == NULL && matrix[numPosition.y][numPosition.x + 1] == NULL
				&& matrix[numPosition.y - 1][numPosition.x] == NULL && matrix[numPosition.y][numPosition.x - 1] == NULL)
			{
				Number *newOne = new Number;
				newOne->setIsOnes(false);
				newOne->setIsTens(false);
				newOne->setNum(num);
				newOne->setNumberPosition(numPosition);

				matrix[numPosition.y][numPosition.x]=newOne;
				isSuccess = true;

				if (isSuccess==true){
					gotoxy(numPosition.x,numPosition.y);
					cout<<newOne->getNum();
				}
			}
			else
				++triesCounter;
		}
	}
	else if (num >= 10)
	{
		while (isSuccess == false && triesCounter < 10)
		{
			Point tensPosition;
			Point onesPosition(tensPosition.x + 1, tensPosition.y);
			if ((tensPosition.x != p1.getPosition().x && tensPosition.y != p1.getPosition().y 
				&& tensPosition.x != p2.getPosition().x && tensPosition.y != p2.getPosition().y 
				&& matrix[tensPosition.y][tensPosition.x] == NULL
				&& matrix[tensPosition.y + 1][tensPosition.x] == NULL && matrix[tensPosition.y][tensPosition.x + 1] == NULL
				&& matrix[tensPosition.y - 1][tensPosition.x] == NULL && matrix[tensPosition.y][tensPosition.x - 1] == NULL)
				&& 
					(onesPosition.x != p1.getPosition().x && onesPosition.y != p1.getPosition().y
				&& onesPosition.x != p2.getPosition().x && onesPosition.y != p2.getPosition().y
				&& matrix[onesPosition.y][onesPosition.x] == NULL
				&& matrix[onesPosition.y + 1][onesPosition.x] == NULL && matrix[onesPosition.y][onesPosition.x + 1] == NULL
				&& matrix[onesPosition.y - 1][onesPosition.x] == NULL && matrix[onesPosition.y][onesPosition.x - 1] == NULL)
				&& onesPosition.x <= onesPosition.maxX)
			{
				Number *newTens = new Number;
				Number *newOnes = new Number;
				newTens->setIsTens(true);
				newTens->setIsOnes(false);
				newTens->setNum(num/10);
				newTens->setNumberPosition(tensPosition);
				newOnes->setIsOnes(true);
				newOnes->setIsTens(false);
				newOnes->setNum(num % 10);
				newOnes->setNumberPosition(onesPosition);

				matrix[tensPosition.y][tensPosition.x]=newTens;
				matrix[tensPosition.y][tensPosition.x+1]=newOnes;
				isSuccess = true;

				if (isSuccess==true){
					gotoxy(tensPosition.x,tensPosition.y);
					cout<<newTens->getNum()<<newOnes->getNum();
				}
			}
			else
				++triesCounter;

		}
	}
}

void screenMatrix::printMatrix(){
	setTextColor(LIGHTRED);
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (matrix[i][j] != NULL)
			{
				gotoxy(j,i);
				cout << matrix[i][j]->getNum();
			}
		}
	}

	setTextColor(WHITE);

	p1.playerDraw();
	p2.playerDraw();
}

void screenMatrix::eraseMatrix(){
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (matrix[i][j] != NULL)
			{
				delete matrix[i][j];
				matrix[i][j] = NULL;
				gotoxy(j, i);
				cout << ' ';
			}
		}
	}
}
void screenMatrix::eraseNumberInPos(Point numberPosition){
	delete matrix[numberPosition.y][numberPosition.x];
	matrix[numberPosition.y][numberPosition.x]=NULL;
}
unsigned int screenMatrix::getNumberInPos(Point numberPosition){
	unsigned int returnNum;
	if (!matrix[numberPosition.y][numberPosition.x]->getIsOnes() && !matrix[numberPosition.y][numberPosition.x]->getIsTens()){
		returnNum=matrix[numberPosition.y][numberPosition.x]->getNum();
		eraseNumberInPos(numberPosition);
		return returnNum;
	}
	else {
		if (matrix[numberPosition.y][numberPosition.x]->getIsOnes()){
			returnNum=matrix[numberPosition.y][numberPosition.x]->getNum() + matrix[numberPosition.y][numberPosition.x-1]->getNum()*10;
			eraseNumberInPos(numberPosition);
			eraseNumberInPos(Point(numberPosition.x-1,numberPosition.y));
			gotoxy(numberPosition.x-1,numberPosition.y);
			cout<<" ";
			return returnNum;
		}
		else{
			returnNum=matrix[numberPosition.y][numberPosition.x]->getNum()*10 + matrix[numberPosition.y][numberPosition.x+1]->getNum();
			eraseNumberInPos(numberPosition);
			eraseNumberInPos(Point(numberPosition.x+1,numberPosition.y));
			gotoxy(numberPosition.x+1,numberPosition.y);
			cout<<" ";
			return returnNum;
		}
	}
}
