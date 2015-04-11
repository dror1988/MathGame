#ifndef __EXERCISE_H
#define __EXERCISE_H

#include <stdlib.h>
#include <string>

using namespace std;

class Exercise{
	unsigned int leftNum;
	unsigned int rightNum;
	unsigned int result;
	unsigned char action;
	unsigned int numToHide;
	unsigned int hiddenNumber;
	string strExercise;

public:
	Exercise(int currentLvl);

	string getExercise();
	bool isExerciseComplete(unsigned int tryNum);
};

#endif