#pragma once
#include "Engine.h"

class Rules
{
	Rules();
	~Rules();
	bool TestMovePawn(int x, int y, int newx, int newy);
	bool TestCapturePawn(int x, int y, int newx, int newy);
	bool TestKnight(int x, int y, int newx, int newy);
	bool TestBishop(int x, int y, int newx, int newy);
	bool TestRock(int x, int y, int newx, int newy);
	bool TestKing(int x, int y, int newx, int newy);
	bool TestQueen(int x, int y, int newx, int newy);
	bool TestMove(int x, int y, int newx, int newy);		//na podstawie typu dokonuje testu charakterystycznego dla danego typu i jesli test byl pomyslny wykonuje ruch
	bool TestCapture(int x, int y, int newx, int newy);		//na podstawie typu dokonuje testu charakterystycznego dla danego typu i jesli test byl pomyslny wykonuje bicie
public:
	static Rules & getInstance(){							//singleton
		static Rules instance;
		return instance;
	}
	void Main(int x, int y, int newx, int newy);			//ta funkcja decyduje do czego nadaje sie proba ruchu, czy nie robi nic, czy jest zmiana aktywnego pionka, czy jest proba bicia, czy jest proba ruchu
};

