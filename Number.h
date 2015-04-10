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
	Number(unsigned int num, bool isTens, bool isOnes, Point numberPosition)
		: Num(Num), isTens(false), isOnes(false), numberPosition(numberPosition){
	}

	~Number() {
		isTens = false;
		isOnes = false;
	}


	unsigned int getNum()const;
	bool getIsTens()const;
	bool getIsOnes()const;
	Point getNumberPosition()const;

	unsigned int setNum(unsigned int newNum);
	bool setIsTens(bool newIsTensValue);
	bool setIsOnes(bool newIsOnesValue);
	Point setNumberPosition(Point newPosition);

	void Print();
	
};


#endif
