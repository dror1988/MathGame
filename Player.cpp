#include "Player.h"
#include "io_utils.h"

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
string Player::getExercise(){
	if (playerExercise != NULL)
		return playerExercise->getExercise();
	else
		return "";
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
void Player::changeDirection(char newDirection){
	switch (newDirection){
	case 'i':
	case 'w':
		playerDirection.value = Direction::UP;
		break;
	case 'j':
	case 'a':
		playerDirection.value = Direction::LEFT;
		break;
	case 'm':
	case 'x':
		playerDirection.value = Direction::DOWN;
		break;
	case 'l':
	case 'd':
		playerDirection.value = Direction::RIGHT;
		break;
	default:
		break;
	}
}
Exercise* Player::createExercise(int currentLevel){
	if (playerExercise == NULL){
		playerExercise = new Exercise(currentLevel);
		return playerExercise;
	}
	else
		return NULL;
}

void Player::playerDraw(){
	gotoxy(playerPosition.x, playerPosition.y);
	cout << playerChar;
}
void Player::playerErase(){
	gotoxy(playerPosition.x, playerPosition.y);
	cout << ' ';
}

void Player::playerMove(){
	playerErase();

	switch (playerDirection.value){
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

	playerDraw();
}