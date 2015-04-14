//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Player.cpp
// -----------
// This file declares a class to manage a player includeing its score, number of lives, position, direction etc.
//
// Author: Dror Moyal
// First version: 2015-04-11
// 
// This code is part of a solution for "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// 2015-04-08     Dror Moyal      implemented the Player class

// +++++++++++++++++++++++++++++++++++++++++++++++++
// "NEW CODE EX1, author=Dror Moyal, date=2015-04-08
// +++++++++++++++++++++++++++++++++++++++++++++++++

#include "Player.h"

//===================================
// score getter
//===================================
unsigned int Player::getScore()const{
	return playerScore;
}

//===================================
// lives getter
//===================================
unsigned int Player::getLives()const{
	return playerLives;
}

//===================================
// position getter
//===================================
Point Player::getPosition()const{
	return playerPosition;
}

//===================================
// direction getter
//===================================
Direction::VALUE Player::getDirection()const{
	return playerDirection;
}

//===================================
// exercise getter
//===================================
string Player::getExercise()const{
	if (playerExercise != NULL)
		return playerExercise->getExercise();
	else
		return "";
}

//===================================
// score setter
//===================================
unsigned int Player::setScore(unsigned int newScore){
	playerScore = newScore;
	return playerScore;
}

//===================================
// lives setter
//===================================
unsigned int Player::setLives(unsigned int newLives){
	playerLives = newLives;
	return playerLives;
}

//===================================
// position setter
//===================================
Point Player::setPosition(Point newPosition){
	playerPosition = newPosition;
	return playerPosition;
}

//===================================
// direction setter
//===================================
Direction::VALUE Player::changeDirection(Direction::VALUE newDirection){
	playerDirection = newDirection;
	return playerDirection;
}

//===================================
// exercise creator
//===================================
Exercise* Player::createExercise(int currentLevel){
	if (playerExercise == NULL){
		playerExercise = new Exercise(currentLevel);
		return playerExercise;
	}
	else
		return NULL;
}

//===================================
// verify if player is alive 
// according to the number
// of lives he has left
//===================================
bool Player::isPlayerAlive(){
	if (playerLives==0)
		playerAlive=false;
	return playerAlive;
}

//===================================
// verify if a player is done 
// according to the number he ate
//===================================
bool Player::isPlayerDone(unsigned int eatenNumber){
	playerDone=playerExercise->isExerciseComplete(eatenNumber);
	return playerDone;
}

//===================================
// player done getter
//===================================
bool Player::getPlayerDone(){
	return playerDone;
}

//===================================
// print a player in his 
// position on screen
//===================================
void Player::playerDraw() const{
	setTextColor(LIGHTGREEN);
	gotoxy(playerPosition.x, playerPosition.y);
	cout << playerChar;
	setTextColor(WHITE);
}

//===================================
// erase a player from his position 
// on screen
//===================================
void Player::playerErase()const{
	gotoxy(playerPosition.x, playerPosition.y);
	cout << ' ';
}

//===================================
// computes the movement of a player 
// according to the players direction
//===================================
void Player::playerMove(){
	// use direction as a case
	// make sure player will no go out
	// of screen borders
	switch (playerDirection){
	case Direction::UP:
		if (playerPosition.y > Point::minY)
			playerPosition.y--;
		else
			playerPosition.y = Point::maxY;
		break;
	case Direction::DOWN:
		if (playerPosition.y < Point::maxY)
			playerPosition.y++;
		else
			playerPosition.y = Point::minY;
		break;
	case Direction::LEFT:
		if (playerPosition.x > Point::minX)
			playerPosition.x--;
		else
			playerPosition.x = Point::maxX;
		break;
	case Direction::RIGHT:
		if (playerPosition.x < Point::maxX)
			playerPosition.x++;
		else
			playerPosition.x = Point::minX;
		break;
	case Direction::STAY:
		break;
	}
}

//===================================
// verify if a move is legal 
// according to the other 
// players position
//===================================
bool Player::isMoveLegal(Point otherPlayerPos){
	// create a temp position to 
	// compute the position of the
	// player after movment
	Point tempPoint=playerPosition;

	// use direction as a case
	switch (playerDirection){
	case Direction::UP:
		if (tempPoint.y > Point::minY)
			tempPoint.y--;
		else
			tempPoint.y = Point::maxY;
		break;
	case Direction::DOWN:
		if (tempPoint.y < Point::maxY)
			tempPoint.y++;
		else
			tempPoint.y = Point::minY;
		break;
	case Direction::LEFT:
		if (tempPoint.x > Point::minX)
			tempPoint.x--;
		else
			tempPoint.x = Point::maxX;
		break;
	case Direction::RIGHT:
		if (tempPoint.x < Point::maxX)
			tempPoint.x++;
		else
			tempPoint.x = Point::minX;
		break;
	default:
		break;
	}

	// if the new position of the player is not in the
	// same position as the other player then the move
	// is legal
	if (tempPoint.x == otherPlayerPos.x && tempPoint.y == otherPlayerPos.y)
		return false;
	else
		return true;
}

//+++++++++++++++++++++
// END of NEW CODE EX1
//+++++++++++++++++++++
