//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// GameManager.cpp
// ---------------
// GameManager is the top level manager, the game starts from here.
// This class manages the game iterations, menus etc., but WITHOUT knowing anything about the actual game itself.
//
// Author: Amir Kirsh
// First version: 2014-12-09
// 
// This code is part of "the math game" excercise in C++ course, Semester B 2015
// at the Academic College of Tel-Aviv-Yaffo.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Changes and additions:
// ------------------------
// DATE           Authors                 Change / Addition
// ----           --------                -----------------
// In the file itself, add above each change/addition a remark saying: "NEW CODE EX1, author=<name>, date=<YYYY-MM-DD>"
// and close it at the end with a remark saying "END of NEW CODE EX1" 
//
//

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <list>
#include "GameManager.h"
#include "ISpecificGame.h"
#include "io_utils.h"
#include "Player.h"
#include "screenMatrix.h"

using namespace std;

char GameManager::mainMenu()const
{
	setTextColor(CYAN);
	clear_screen();

	{
		cout << "	Math Game - Main Menu" << endl;
		cout << "	=====================" << endl << endl;
		cout << "1. Game Instructions" << endl;
		cout << "2. Start A New Game" << endl;
		cout << "3. Start A New Game From A Specific Level" << endl;
		cout << "9. Exit" << endl;
	}

	char selection = 0;
	do {
		selection = _getch();
	} while(!GameManager::MainMenuOptions::isValidOption(selection));

	setTextColor(WHITE);

	return selection;
}

void GameManager::run()
{
	bool userWantsToPlay = true;
	// we run as long as the user wants
	Player player1('@', Direction::RIGHT, Point(10, 9)), player2('#', Direction::LEFT, Point(70, 9));
	screenMatrix myScreen(player1,player2);

	while(userWantsToPlay) {
		char menuSelection = mainMenu();
		// TODO: handle here all the different menu options
		switch(menuSelection)
		{
		case GameManager::MainMenuOptions::PLAY_GAME:
			init();
			userWantsToPlay = playGame();
			break;
		case GameManager::MainMenuOptions::PLAY_FROM_SELECTED_SCREEN:
			//should use chooseLevelToStart() function to print a dialog from which level to start the game
			//and to init GameManager::currentLevel to the specific level
			//We need to add creation of 2 players in here
			chooseLevelToStart();
			userWantsToPlay = playGame();
			break;
		case GameManager::MainMenuOptions::PRESENT_INSTRUCTIONS:
			printInstructions();
			break;
		case GameManager::MainMenuOptions::EXIT_APPLICATION:
			userWantsToPlay = false;
			break;
		case GameManager::MainMenuOptions::PRINT_SUB_MENU:
			subMenu();
			break;
		default: // normally we shouldn't get to here...
			userWantsToPlay = false;
		};
	}
}

char  GameManager::subMenu() const{
	setTextColor(RED);
	gotoxy(28, 9);

	{
		cout << " ========================= ";
		gotoxy(28, 10);
		cout << "|       PAUSE GAME        |";
		gotoxy(28, 11);
		cout << "| 1.Exit                  |";
		gotoxy(28, 12);
		cout << "| 2.Back to Main Menu     |";
		gotoxy(28, 13);
		cout << "| 3.Continue              |";
		gotoxy(28, 14);
		cout << "| 4.Replay Current Level  |";
		gotoxy(28, 15);
		cout << "| 5.Skip Level            |";
		gotoxy(28, 16);
		cout << " ========================= ";
	}

	char selection = 0;
	do {
		selection = _getch();
	} while(!GameManager::LevelOptions::isValidOption(selection));

	setTextColor(WHITE);
	clear_screen();

	return selection;
}

void GameManager::printInstructions() const{
	char selection = 0;

	{
		clear_screen();
		cout << "              Math Game - Instructions (1)                                 " << endl;
		cout << "              ============================                                 " << endl;
		cout << "This is a game involving both speed, accuracy and quick thinking.          " << endl;
		cout << "In the Main Menu, you can choose from 2 options -                          " << endl;
		cout << "  * Start the game from the very beginning (Level 1)                     " << endl;
		cout << "  * Start the game from a specified level                                 " << endl;
		cout << endl;
		cout << "In each level you will face harder and harder Math Problems.               " << endl;
		cout << "At the beginning of each level, the game will randomly create a Math       " << endl;
		cout << "Problem using the following logic:                                         " << endl;
		cout << "  The game will randomly choose 2 numbers and an operator (+,-,*,/).       " << endl;
		cout << "  If the operator will be \"+\" or \"*\" the Math Problem look like one of the " << endl;
		cout << "  following:                                                               " << endl;
		cout << "     * Num1 (+ or *) ____ = Result                                         " << endl;
		cout << "     * ____ (+ or *) Num2 = Result                                         ";
		gotoxy(0, 23);
		cout << "Press (Space) to see more, Press (q) to quit                               ";
		selection = 0;
		do {
			selection = _getch();
		} while (selection != 32 && selection != 'q');
		if (selection == 'q')
			return;

		clear_screen();
		cout << "              Math Game - Instructions (2)                                 " << endl;
		cout << "              ============================                                 " << endl;
		cout << "  If the operator will be \"-\" or \"/\" the Math Problem look like one of the " << endl;
		cout << "  following:                                                               " << endl;
		cout << "     * Num1 (- or /) ____ = Result                                         " << endl;
		cout << "     * Num1 (- or /) Num2 = ______                                         " << endl;
		cout << endl;
		cout << "Each player will get a different (not promised) Math Problem that he will  " << endl;
		cout << "need to solve by eating the correct number from the numbers that will pop  " << endl;
		cout << "to the screen during the game.                                             " << endl;
		cout << "When a player will eat the correct number, he will get 1 Point and players " << endl;
		cout << "will be forwarded to the next level. There are total of 20 levels.         " << endl;
		cout << endl;
		cout << "Eating a wrong number will cause the player to loose 1 Life. Each player   " << endl;
		cout << "will start each level with 3 lives. If a player will loose all lives during" << endl;
		cout << "a level his character will disappear until the end of the level.           ";
		gotoxy(0, 23);
		cout << "Press (Space) to see more, Press (q) to quit                               ";
		selection = 0;
		do {
			selection = _getch();
		} while (selection != 32 && selection != 'q');
		if (selection == 'q')
			return;

		clear_screen();
		cout << "              Math Game - Instructions (3)                                 " << endl;
		cout << "              ============================                                 " << endl;
		cout << "Players can travel on the screen to all 4 directions:                      " << endl;
		cout << "Up, Down, Left and Right.                                                  " << endl;
		cout << endl;
		cout << "Player Controls:                                                           " << endl;
		cout << " * Player-1 (Using \"@\" character):                                       " << endl;
		cout << "    - UP      = w                                                          " << endl;
		cout << "    - DOWN    = x                                                          " << endl;
		cout << "    - LEFT    = a                                                          " << endl;
		cout << "    - RIGHT   = d                                                          " << endl;
		cout << " * Player-2 (Using \"#\" character):                                       " << endl;
		cout << "    - UP      = i                                                          " << endl;
		cout << "    - DOWN    = m                                                          " << endl;
		cout << "    - LEFT    = j                                                          " << endl;
		cout << "    - RIGHT   = l                                                          " << endl;
		cout << endl;
		cout << "GOOD LUCK!!!!                                                              ";
		gotoxy(0, 23);
		cout << "Press (Space) to see more, Press (q) to quit                               ";
		selection = 0;
		do {
			selection = _getch();
		} while (selection != 32 && selection != 'q');
		if (selection == 'q')
			return;

		clear_screen();
		cout << "                       Math Game - About                                   " << endl;
		cout << "                       =================                                   " << endl;
		cout << "This is \"The Math Game\" - Our very first OOP project implemented in C++.   " << endl;
		cout << endl;
		cout << "                    Authors of the game are:                               " << endl;
		cout << "                     * Dror Moyal 301821682                                " << endl;
		cout << "                     * Maya Bugana                                         " << endl;
		gotoxy(0, 23);
		cout << "Press any key to go back to Main Menu...";
	}

	while (!_kbhit()){
	}
}

void GameManager::chooseLevelToStart(){
	setTextColor(CYAN);
	gotoxy(28, 9);

	{
		cout << " ========================= ";
		gotoxy(28, 10);
		cout << "|     Choose lvl 1-20     |";
		gotoxy(28, 11);
		cout << "|           -  -          |";
		gotoxy(28, 12);
		cout << " ========================= ";
		gotoxy(41, 11);
	}

	unsigned int startLvl=1;
	do {
		gotoxy(41, 11);
		cout << "  ";
		gotoxy(41, 11);
		cin >> startLvl;
	} while (startLvl<1 || startLvl>20);

	currentLevel = startLvl-1;

	setTextColor(WHITE);
	clear_screen();
}

bool GameManager::playGame()
{
	clear_screen();
	// we assume that we have multiple levels so there is a need to loop through levels
	// till all levels were played or till user quits - if user quits we do not continue to next level
	//-------------------------------------------------------------
	// this is the game LEVELS loop
	//-------------------------------------------------------------
	char action = GameManager::LevelOptions::NEXT_LEVEL;
	while(actualGame.hasNextLevel() && action == GameManager::LevelOptions::NEXT_LEVEL) {
		action = playNextLevel();
	}
	//-------------------------------------------------------------
	// END of game LEVELS loop
	//-------------------------------------------------------------
	
	// return true if the user wants to keep playing
	return (action != GameManager::LevelOptions::EXIT_APPLICATION);
}

// return action to take in case of ESC
char GameManager::playNextLevel()
{
	++currentLevel;
	actualGame.startLevel(currentLevel);
	//in start level we need to create a new SCREEN object that gets the following for creation:
	//Screen newScreen(int level,Player &p1, Player &p2)

	
	//------------------------------------------------------------------------------
	// here we control the ESC menu
	//------------------------------------------------------------------------------
	bool keepRunning = true;
	char action = 0;
	while(keepRunning)
	{
		//=============================================================================================
		// this is the actual call to play game iterations
		action = doLevelIterations();
		//=============================================================================================
		
		// check action based on game ended (action==BACK_TO_MAIN_MENU) or input from user on ESC menu
		switch(action) {
		case GameManager::LevelOptions::CONTINUE:
			// keepRunning is true, so we only need to set thing right and then - keepRunning!
			//--------------------------------------------------------------------------------
			break;
		case GameManager::LevelOptions::REPLAY_LEVEL:
			// keepRunning is true, so we only need to set thing right and then - keepRunning!
			//--------------------------------------------------------------------------------
			actualGame.startLevel(currentLevel);
			break;
		case GameManager::LevelOptions::BACK_TO_MAIN_MENU:
		case GameManager::LevelOptions::EXIT_APPLICATION:
			// get out from the loop
			clear_screen();
			keepRunning = false;
			break;
		case GameManager::LevelOptions::NEXT_LEVEL:
			// get out from the loop so we get to the next level
			keepRunning = false;
			break;
		}
		//---------------------------------------
		// END of sub menu action switch
		//---------------------------------------
	}
	//------------------------------------------
	// END of Level keepRunning loop (sub menu)
	//------------------------------------------

	// the actions that may get out from this method are: BACK_TO_MAIN_MENU and EXIT_APPLICATION
	return action;
}

// return action to take in case of ESC
char GameManager::doLevelIterations()
{
	char action;
	bool escapePressed = false;
	//---------------------------------------
	// this is the game iterations loop
	//---------------------------------------
	while(!actualGame.isLevelDone() && !escapePressed) {
		escapePressed = !doIteration();
	}
	//-----------------------------------------------------
	// END of game iterations loop or exit on ESC
	//-----------------------------------------------------

	// check why we are here
	if(actualGame.isLevelDone()) {
		clear_screen();
		cout << endl << "WELL DONE" << endl;
		action = GameManager::LevelOptions::NEXT_LEVEL;
	}
	else if(escapePressed) {
		action = 0;
		subMenu();
		do {
			action = _getch();
		} while(!GameManager::LevelOptions::isValidOption(action));
	}
	// end of esc pressed
	// TODO: clear the sub menu options from screen
	return action;
}

bool GameManager::doIteration()
{
	unsigned int sleepLength = clockCycleInMillisec/iterationsPerClockCycle;
	for(unsigned int i=0; i<iterationsPerClockCycle-1; ++i) {
		Sleep(sleepLength);
		actualGame.doSubIteration();
	}
	return doInputIteration();
}

bool GameManager::doInputIteration()
{
	list<char> keyHits(KEYBOARD_HIT_LOOP); // set vector initialize size to the max key strokes that we may collect
	bool shouldContinue = true;
	// get keyboard input in a loop, to get enough keyboard hits
	unsigned int sleepLength = clockCycleInMillisec/iterationsPerClockCycle / KEYBOARD_HIT_LOOP;
	for(unsigned int i=0; i<KEYBOARD_HIT_LOOP; ++i) {
		Sleep(sleepLength);
		if (_kbhit()) {
			char ch = _getch();
			if(ch == ESC) {
				// ESC pressed
				shouldContinue = false;
			}
			else {
				// we got keyHits byref, so we actually set input into the original list sent here
				keyHits.push_front(ch); // we want recent keys to come first, thus we use push_front
			}
		}
	}

	// send the keystrokes to the game
	// (even if ESC was hit, we may still have something in the keystrokes vector and should use it)
	actualGame.doIteration(keyHits);

	return shouldContinue;
}

