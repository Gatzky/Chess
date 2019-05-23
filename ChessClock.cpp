#include "stdafx.h"
#include "ChessClock.h"


ChessClock::ChessClock(int white, int black){
	WhiteClock = white;
	BlackClock = black;
}
ChessClock::~ChessClock(){}
ChessClock& ChessClock::getInstance(int white, int black){
	static ChessClock instance(white, black);
	return instance;
}
void ChessClock::SetClock(int white, int black){
	WhiteClock = white;
	BlackClock = black;
}
void ChessClock::TestTime(char player) {
	Time temptimer = Timer.getElapsedTime();			//zmierz czas od ostatniego resetu
	if (temptimer.asSeconds() >= 1) {					//jesli wiecej niz jedna sekunda
		if (player == 'w') {							//dla aktywnego gracza
			WhiteClock--;								//dekrementuj liczbe sekund
			Timer.restart();							//restartuj licznik
		}
		else if (player == 'b') {
			BlackClock--;
			Timer.restart();
		}
	}
}
int ChessClock::ReturnWhiteClock() {
	return WhiteClock;
}
int ChessClock::ReturnBlackClock() {
	return BlackClock;
}
bool ChessClock::TestEndTime(char player) {
	if ((player == 'w' && WhiteClock == 0) || (player == 'b' && BlackClock == 0))	//dla aktywnego gracza
		return 1;
	else
		return 0;
}