#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class ChessClock
{
	int WhiteClock;											//liczba sekund na zegarze bialych
	int BlackClock;											//liczba sekund na zegarze czarnych
	Clock Timer;											//potrzebne do zliczania czasu
	ChessClock(int white, int black);	
	~ChessClock();
public:
	static ChessClock & getInstance(int white, int black);	//singleton
	void SetClock(int white, int black);					//ustawianie wartosci zegara
	void TestTime(char player);								//sprawa czy minela sekunda, jesli tak to dekrementuje liczbe sekund w odpowiednim zegarze
	bool TestEndTime(char player);
	int ReturnWhiteClock();
	int ReturnBlackClock();
};

