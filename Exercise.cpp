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
			strExercise = "_" + string(1,action) + to_string(static_cast<long long>(rightNum)) + "=" + to_string(static_cast<long long>(result));
			hiddenNumber = leftNum;
		}
		else{
			strExercise = to_string(static_cast<long long>(leftNum)) + string(1, action) + "_" + "=" + to_string(static_cast<long long>(result));
			hiddenNumber = rightNum;
		}
		break;
	case 1:
		action = '-';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result + rightNum; // according to the "targil" logic
		if (numToHide == 0){
			strExercise = to_string(static_cast<long long>(leftNum)) + string(1, action) + to_string(static_cast<long long>(rightNum)) + "=" + "_";
			hiddenNumber = result;
		}
		else{
			strExercise = to_string(static_cast<long long>(leftNum)) + string(1, action) + "_" + "=" + to_string(static_cast<long long>(result));
			hiddenNumber = rightNum;
		}
		break;
	case 2:
		action = '*';
		result = leftNum * rightNum;
		if (numToHide == 0){
			strExercise = "_" + string(1,action) + to_string(static_cast<long long>(rightNum)) + "=" + to_string(static_cast<long long>(result));
			hiddenNumber = leftNum;
		}
		else{
			strExercise = to_string(static_cast<long long>(leftNum)) + string(1, action) + "_" + "=" + to_string(static_cast<long long>(result));
			hiddenNumber = rightNum;
		}
		break;
	case 3:
		action = '/';
		result = rightNum;
		rightNum = leftNum;
		leftNum = result * rightNum; // according to the "targil" logic
		if (numToHide == 0){
			strExercise = to_string(static_cast<long long>(leftNum)) + string(1, action) + to_string(static_cast<long long>(rightNum)) + "=" + "_";
			hiddenNumber = result;
		}
		else{
			strExercise = to_string(static_cast<long long>(leftNum)) + string(1, action) + "_" + "=" + to_string(static_cast<long long>(result));
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