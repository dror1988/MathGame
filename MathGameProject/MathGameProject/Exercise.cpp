#include "Exercise.h"

Exercise::Exercise(int currentLvl){
	//temp variable to help and choose the "+,-,/,*" according to rand function
	int chooseAction = rand() % 4;

	char strNumber1[4];
	char strNumber2[4];

	numToHide = rand() % 2;
	leftNum = rand() % (10 + currentLvl) + 1;
	rightNum = rand() % (10 + currentLvl) + 1;

	switch (chooseAction){
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

string Exercise::getExercise(){
	return strExercise;
}

bool Exercise::isExerciseComplete(unsigned int tryNum){
	if (tryNum == hiddenNumber)
		return true;
	else
		return false;
}
