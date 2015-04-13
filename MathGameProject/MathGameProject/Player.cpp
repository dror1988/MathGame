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

bool Player::isPlayerAlive(){
	if (playerLives==0)
		playerAlive=false;
	return playerAlive;
}
bool Player::isPlayerDone(unsigned int eatenNumber){
	playerDone=playerExercise->isExerciseComplete(eatenNumber);
	return playerDone;
}
bool Player::getPlayerDone(){
	return playerDone;
}

void Player::playerDraw() const{
	setTextColor(LIGHTGREEN);
	gotoxy(playerPosition.x, playerPosition.y);
	cout << playerChar;
	setTextColor(WHITE);
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

bool Player::isMoveLegal(Point otherPlayerPos){
	Point tempPoint=playerPosition;
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

	if (tempPoint.x == otherPlayerPos.x && tempPoint.y == otherPlayerPos.y)
		return false;
	else
		return true;
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
	default:
		break;
	}

	//playerDraw();
}
