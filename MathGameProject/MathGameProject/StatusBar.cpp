#include "StatusBar.h"

void StatusBar::drawStatusBar(){
	setTextColor(LIGHTCYAN);
	{ //Print 1st Line in Status Bar
		gotoxy(0,0);
		cout<<"Player-@ ,Lives:"<<p1.getLives()<<" ,Score:"<<p1.getScore();
		gotoxy(28,0);
		cout<<"|        Time:"<<timeLeft;
		gotoxy(51,0);
		cout<<"| Player-# ,Lives:"<<p2.getLives()<<" ,Score:"<<p2.getScore();
	}

	{ //Print 2nd Line in Status Bar
		gotoxy(0,1);
		cout<<"Targil: "<<p1.getExercise();
		gotoxy(28,1);
		cout<<"|        Level:"<<currentLevel;
		gotoxy(51,1);
		cout<<"| Targil: "<<p2.getExercise();
	}

	{
		gotoxy(0,2);
		cout<<"================================================================================";
	}

	setTextColor(WHITE);

}
void StatusBar::updatePlayerLife(unsigned int playerNumber){
	setTextColor(LIGHTCYAN);
	if (playerNumber==1){
		gotoxy(16,0);
		cout<<p1.getLives();
	}
	else if (playerNumber==2){
		gotoxy(69,0);
		cout<<p2.getLives();
	}
	setTextColor(WHITE);
}

void StatusBar::updateTimeLeft(){
	setTextColor(LIGHTCYAN);
	gotoxy(42,0);
	cout<< "   ";
	gotoxy(42,0);
	cout<<timeLeft;
	setTextColor(WHITE);
}