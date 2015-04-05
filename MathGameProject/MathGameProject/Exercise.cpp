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
		if (numToHide==0)
			strExercise = '_' + action + to_string(rightNum) + '=' + to_string(result) + endl;
		else
			strExercise = to_string(leftNum) + action + '_' + '=' + to_string(result) + endl;
		break;
	case 1:
		action = '-';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result + rightNum; // according to the "targil" logic
		if (numToHide == 0)
			strExercise = to_string(leftNum) + action + to_string(rightNum) + '=' + '_' + endl;
		else
			strExercise = to_string(leftNum) + action + '_' + '=' + to_string(result) + endl;
		break;
		break;
	case 2:
		action = '*';
		result = leftNum * rightNum;
		if (numToHide == 0)
			strExercise = '_' + action + to_string(rightNum) + '=' + to_string(result) + endl;
		else
			strExercise = to_string(leftNum) + action + '_' + '=' + to_string(result) + endl;
		break;
		break;
	case 3:
		action = '/';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result * rightNum; // according to the "targil" logic
		if (numToHide == 0)
			strExercise = to_string(leftNum) + action + to_string(rightNum) + '=' + '_' + endl;
		else
			strExercise = to_string(leftNum) + action + '_' + '=' + to_string(result) + endl;
		break;
		break;
	default:
		break;
	}

}

string Exercise::getExercise(){

}

bool Exercise::isExerciseComplete(unsigned int tryNum){

}