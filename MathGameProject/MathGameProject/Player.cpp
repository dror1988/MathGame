#include "Player.h"

void Player::printPlayer(){
	gotoxy(playerPosition.x, playerPosition.y);
	cout << playerChar;
}
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
	playerDirection.value = newDirection.value;
	//playerDirection.value = Direction::UP;
	return playerDirection;
}
Exercise* Player::createExercise(){
	if (playerExercise == NULL){
		playerExercise = new Exercise;
		return playerExercise;
	}
	else
		return NULL;
}
