#ifndef __EXERCISE_H
#define __EXERCISE_H

#include <stdlib.h>
#include <string>

class Exercise{
	unsigned int leftNum;
	unsigned int rightNum;
	unsigned int result;
	unsigned char action;
	int numToHide;
	string strExercise;

public:
	Exercise(int currentLvl);

	string getExercise();
	bool isExerciseComplete(unsigned int tryNum);
};

#endif