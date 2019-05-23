#include "stdafx.h"
#include "Rules.h"
#include <iostream>

Rules::Rules() {}
Rules::~Rules() {}
void Rules::Main(int actx, int acty, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	if (actx == 0 && acty == 0 && MainEngine.EmptySlot(newx, newy)) {}					//Jesli nie jest zaznaczone nic i klikamy na puste pole to nie dzieje sie nic
	else if (actx != 0 && acty != 0 && MainEngine.EmptySlot(newx, newy)) {				//jesli jest cos zaznaczone i klikamy na puste pole...
		if( TestMove(actx, acty, newx, newy)) {											//...tesujemy ruch, jesli ruch bedzie zgodny z zasadami gry...
			MainEngine.ChangeXY(actx, acty, newx, newy);								//...zmieniamy koordynaty aktywnej biergi
			MainEngine.ChangeActXY(0, 0);												//"odznaczamy" bierke
			MainEngine.ChangePlayer();													//zmieniamy gracza
		}
	}
	else if (actx != 0 && acty != 0 && MainEngine.ReturnPlayer() != MainEngine.ReturnPiece(newx, newy).ReturnColor()) {	//jesli mamy cos zaznaczone i klikamy na pole na ktorym jest bierak o innym kolorze...
		if(TestCapture(actx, acty, newx, newy)) {																		//... testujemy bicie, jesli bicie bedzie zgodne z zasadami gry...
			MainEngine.DelPiece(newx, newy);																			//... usuwamy bitego pionka i dalej postepujemy jak przy ruchu
			MainEngine.ChangeXY(actx, acty, newx, newy);
			MainEngine.ChangeActXY(0, 0);
			MainEngine.ChangePlayer();
		}
	}
	else if (MainEngine.ReturnPlayer() == MainEngine.ReturnPiece(newx, newy).ReturnColor()) {	//jesli klikamy na pole na ktorym jest nasz pionek...
		MainEngine.ChangeActXY(newx, newy);														//... zmienamy aktywna bierke
	}
}
bool Rules::TestMove(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	int type = MainEngine.ReturnPiece(x, y).ReturnType();
	switch (type) {
	case 1: {
		return TestMovePawn(x, y, newx, newy);
		break;
	}
	case 2: {
		return TestKnight(x, y, newx, newy);
		break;
	}
	case 3: {
		return TestBishop(x, y, newx, newy);
		break;
	}
	case 4: {
		return TestRock(x, y, newx, newy);
		break;
	}
	case 5: {
		return TestQueen(x, y, newx, newy);
		break;
	}
	case 6: {
		return TestKing(x, y, newx, newy);
		break;
	}
	}
}
bool Rules::TestCapture(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	bool test = 0;
	int type = MainEngine.ReturnPiece(x, y).ReturnType();
	switch (type) {
	case 1: {
		return TestCapturePawn(x, y, newx, newy);
		break;
	}
	case 2: {
		return TestKnight(x, y, newx, newy);
		break;
	}
	case 3: {
		return TestBishop(x, y, newx, newy);
		break;
	}
	case 4: {
		return TestRock(x, y, newx, newy);
		break;
	}
	case 5: {
		return TestQueen(x, y, newx, newy);
		break;
	}
	case 6: {
		return TestKing(x, y, newx, newy);
		break;
	}
	}
}
bool Rules::TestMovePawn(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	bool onefieldwhite = (MainEngine.ReturnPlayer() == 'w' && newy == y - 1 && newx == x);
	bool onefieldblack = (MainEngine.ReturnPlayer() == 'b' && newy == y + 1 && newx == x);
	bool twofieldwhite = (MainEngine.ReturnPlayer() == 'w' && y == 7 && newy == y - 2 && newx == x);
	bool twofieldblack = (MainEngine.ReturnPlayer() == 'b' && y == 2 && newy == y + 2 && newx == x);
	return (onefieldwhite || onefieldblack || twofieldwhite || twofieldblack);
}
bool Rules::TestCapturePawn(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	bool capturewhite = MainEngine.ReturnPlayer() == 'w' && newy == y - 1 && (newx == x - 1 || newx == x + 1);
	bool captureblack = (MainEngine.ReturnPlayer() == 'b' && newy == y + 1 && (newx == x - 1 || newx == x + 1));
	return ((capturewhite || captureblack));
}
bool Rules::TestKnight(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	bool bool1 = newx == x - 2 && (newy == y - 1 || newy == y + 1);
	bool bool2 = newx == x + 2 && (newy == y - 1 || newy == y + 1);
	bool bool3 = newx == x - 1 && (newy == y - 2 || newy == y + 2);
	bool bool4 = newx == x + 1 && (newy == y - 2 || newy == y + 2);
	return (bool1 || bool2 || bool3 || bool4);
}
bool Rules::TestBishop(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	bool test = 0;
	int ix = x;
	int iy = y;
	if (newx > x && newy > y) {
		while (ix != 9 || iy != 9) {
			ix++; iy++;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newx > x && newy < y) {
		while (ix != 9 || iy != 0) {
			ix++; iy--;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newx < x && newy < y) {
		while (ix != 0 || iy != 0) {
			ix--; iy--;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;

			}
		}
	}
	else if (newx < x && newy > y) {
		while (ix != 0 || iy != 9) {
			ix--; iy++;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;
			}
		}
	}
	return test;
}
bool Rules::TestRock(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	bool test = 0;
	int ix = x;
	int iy = y;
	if (newx == x && newy > y) {
		while (iy != 9) {
			iy++;
			if (iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(newx, iy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newx == x && newy < y) {
		while (iy != 0) {
			iy--;
			if (iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(newx, iy)) {
				test = 0;
				break;
			}

		}
	}
	else if (newy == y && newx < x) {
		while (ix != 0) {
			ix--;
			if (ix == newx) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, newy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newy == y && newx > x) {
		while (ix != 9) {
			ix++;
			if (ix == newx) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, newy)) {
				test = 0;
				break;
			}
		}
	}
	return test;
}
bool Rules::TestQueen(int x, int y, int newx, int newy) {
	Engine &MainEngine = Engine::getInstance();
	bool test = 0;
	int ix = x;
	int iy = y;
	if (newx == x && newy > y) {
		while (iy != 9) {
			iy++;
			if (iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(newx, iy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newx == x && newy < y) {
		while (iy != 0) {
			iy--;
			if (iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(newx, iy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newy == y && newx < x) {
		while (ix != 0) {
			ix--;
			if (ix == newx) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, newy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newy == y && newx > x) {
		while (ix != 9) {
			ix++;
			if (ix == newx) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, newy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newx > x && newy > y) {
		while (ix != 9 || iy != 9) {
			ix++; iy++;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newx > x && newy < y) {
		while (ix != 9 || iy != 0) {
			ix++; iy--;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;
			}
		}
	}
	else if (newx < x && newy < y) {
		while (ix != 0 || iy != 0) {
			ix--; iy--;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;

			}
		}
	}
	else if (newx < x && newy > y) {
		while (ix != 0 || iy != 9) {
			ix--; iy++;
			if (ix == newx && iy == newy) {
				test = 1;
				break;
			}
			if (!MainEngine.EmptySlot(ix, iy)) {
				test = 0;
				break;
			}
		}
	}
	return (test);
}
bool Rules::TestKing(int x, int y, int newx, int newy) {
	bool bool1 = newx == x - 1 && (newy == y - 1 || newy == y || newy == y + 1);
	bool bool2 = newx == x + 1 && (newy == y - 1 || newy == y || newy == y + 1);
	bool bool3 = newx == x && (newy == y - 1 || newy == y || newy == y + 1);
	return (bool1 || bool2 || bool3);
}