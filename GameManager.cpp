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

using namespace std;

char GameManager::mainMenu()const
{
	setTextColor(LIGHTCYAN);
	cout<<"	Math Game - Main Menu"<<endl;
	cout<<"	====================="<<endl<<endl;

	cout << "1. Game Instructions" << endl;
	cout << "2. Start A New Game" << endl;
	cout << "3. Start A New Game From A Specific Level" << endl;
	cout << "9. Exit" << endl;
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
	while(userWantsToPlay) {
		char menuSelection = mainMenu();
		// TODO: handle here all the different menu options
		switch(menuSelection)
		{
		case GameManager::MainMenuOptions::PLAY_GAME:
			init();
			//We need to add creation of 2 players in here
			userWantsToPlay = playGame();
			break;
		case GameManager::MainMenuOptions::PLAY_FROM_SELECTED_SCREEN:
			//should use chooseLevelToStart() function to print a dialog from which level to start the game
			//and to init GameManager::currentLevel to the specific level
			//We need to add creation of 2 players in here
			userWantsToPlay = playGame();
			break;
		case GameManager::MainMenuOptions::PRESENT_INSTRUCTIONS:
			//write instructions to the screen, make the instructions have an ESC char so that the
			//screen will be cleared and the main menu should be printed again
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
	gotoxy(0,17);
	setTextColor(RED);
	cout<<"================================================================================"<<endl;
	cout<<"                                    PAUSE                                       "<<endl;
	cout<<"1.Exit   2.Back to MainMenu   3.Continue   4.Replay Current Level   5.Skip Level"<<endl;
	cout<<"================================================================================";
	char selection = 0;
	do {
		selection = _getch();
	} while(!GameManager::LevelOptions::isValidOption(selection));
	setTextColor(WHITE);
	clear_screen();
	return selection;
}

void GameManager::printInstructions() const{
	clear_screen();
	cout<<"	Math Game - Instructions"<<endl;
	cout<<"	========================"<<endl<<endl;
	cout<<"This game is our first home project in C++"<<endl;
	cout<<"All kind of bull shit"<<endl;
	gotoxy(0,20);
	cout<<"Press ESC to return to the Main Menu"<<endl;
	while (!kbhit()){
		if (getch()==27){
			clear_screen();
			return;
		}
	}
}

bool GameManager::playGame()
{
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
	actualGame.startLevel();
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
			actualGame.startLevel();
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
		// TODO: print here the sub menu options to the proper place in screen
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

	//=================================================================
	//this is the code for running on the keyhits
	for (list<char>::iterator itr=keyHits.begin(); itr!=keyHits.end(); ++itr)
		cout<<*itr; //need to change from cout to actual action

	return shouldContinue;
}

