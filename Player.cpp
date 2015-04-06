#include "Player.h"
#include "io_utils.h"

unsigned int Player::getScore()const{
	return playerScore;
}
unsigned int Player::getLives()const{
	return playerLives;
}
Point Player::getPosition()const{
	return playerPosition;
}
Direction::VALUE Player::getDirection()const{
	return playerDirection;
}
string Player::getExercise()const{
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
void Player::changeDirection(Direction::VALUE newDirection){
	playerDirection = newDirection;
}
Exercise* Player::createExercise(int currentLevel){
	if (playerExercise == NULL){
		playerExercise = new Exercise(currentLevel);
		return playerExercise;
	}
	else
		return NULL;
}

void Player::playerDraw() const{
	gotoxy(playerPosition.x, playerPosition.y);
	cout << playerChar;
}
void Player::playerErase()const{
	gotoxy(playerPosition.x, playerPosition.y);
	cout << ' ';
}
void Player::playerMove(){
	//playerErase();

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

	//playerDraw();
}
void Player::playerReverseMove(){
	//playerErase();

	switch (playerDirection){
	case Direction::UP:
		if (playerPosition.y < Point::maxY)
			playerPosition.y++;
		else
			playerPosition.y = Point::minY;
		break;
	case Direction::DOWN:
		if (playerPosition.y > Point::minY)
			playerPosition.y--;
		else
			playerPosition.y = Point::maxY;
		break;
	case Direction::LEFT:
		if (playerPosition.x < Point::maxX)
			playerPosition.x++;
		else
			playerPosition.x = Point::minX;
		break;
	case Direction::RIGHT:
		if (playerPosition.x > Point::minX)
			playerPosition.x--;
		else
			playerPosition.x = Point::maxX;
		break;
	case Direction::STAY:
		break;
	}

	//playerDraw();
}