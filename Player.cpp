#include "Player.h"

unsigned int Player::getScore(){
	return playerScore;
}
unsigned int Player::getLives(){
	return playerLives;
}
Point Player::getPosition(){
	return playerPosition;
}
Direction Player::getDirection(){
	return playerDirection;
}
Exercise* Player::getExercise(){
	return playerExercise;
}

unsigned int Player::setScore(unsigned int newScore){
	playerScore = newScore;
	return playerScore;
}
unsigned int Player::setLives(unsigned int newLives){
	playerLives = newLives;
	return playerLives;
}
Point Player::setPosition(Point newPosition){
	playerPosition = newPosition;
	return playerPosition;
}
Direction Player::setDirection(Direction newDirection){
	playerDirection = newDirection;
	return playerDirection;
}
Exercise* Player::createExercise(int currentLevel){
	if (playerExercise == NULL){
		playerExercise = new Exercise(currentLevel);
		return playerExercise;
	}
	else
		return NULL;
}
