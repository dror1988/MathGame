#include "Number.h"
#include "io_utils.h"

unsigned int Number::getNum()const{
	return Num;
}
bool Number::getIsTens()const{
	return isTens;
}
bool Number::getIsOnes()const{
	return isOnes;
}
Point Number::getNumberPosition()const{
	return numberPosition;
}

unsigned int Number::setNum(unsigned int newNum){
	Num = newNum;
	return Num;
}
bool Number::setIsTens(bool newIsTensValue){
	isTens = newIsTensValue;
	return isTens;
}
bool Number::setIsOnes(bool newIsOnesValue){
	isOnes = newIsOnesValue;
	return isOnes;
}

Point Number::setNumberPosition(Point newPosition){
	numberPosition = newPosition;
	return numberPosition;
}

void Number::Print(){
	gotoxy(numberPosition.x, numberPosition.y);
	cout << Num << endl;
}