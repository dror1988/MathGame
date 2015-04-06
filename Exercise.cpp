#include "Exercise.h"

Exercise::Exercise(int currentLvl){
	//temp variable to help and choose the "+,-,/,*" according to rand function
	int chooseAction = rand() % 4;
	
	numToHide = rand() % 2;
	leftNum = rand() % (10 + currentLvl) + 1;
	rightNum = rand() % (10 + currentLvl) + 1;

	switch (chooseAction){
	case 0:
		action = '+';
		result = leftNum + rightNum;
		if (numToHide == 0){
			strExercise = "_" + to_string(action) + to_string(rightNum) + "=" + to_string(result);
			hiddenNumber = leftNum;
		}
		else{
			strExercise = to_string(leftNum) + to_string(action) + "_" + "=" + to_string(result);
			hiddenNumber = rightNum;
		}
		break;
	case 1:
		action = '-';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result + rightNum; // according to the "targil" logic
		if (numToHide == 0){
			strExercise = to_string(leftNum) + to_string(action) + to_string(rightNum) + "=" + "_";
			hiddenNumber = result;
		}
		else{
			strExercise = to_string(leftNum) + to_string(action) + "_" + "=" + to_string(result);
			hiddenNumber = rightNum;
		}
		break;
	case 2:
		action = '*';
		result = leftNum * rightNum;
		if (numToHide == 0){
			strExercise = "_" + to_string(action) + to_string(rightNum) + "=" + to_string(result);
			hiddenNumber = leftNum;
		}
		else{
			strExercise = to_string(leftNum) + to_string(action) + "_" + "=" + to_string(result);
			hiddenNumber = rightNum;
		}
		break;
	case 3:
		action = '/';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result * rightNum; // according to the "targil" logic
		if (numToHide == 0){
			strExercise = to_string(leftNum) + to_string(action) + to_string(rightNum) + "=" + "_";
			hiddenNumber = result;
		}
		else{
			strExercise = to_string(leftNum) + to_string(action) + "_" + "=" + to_string(result);
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