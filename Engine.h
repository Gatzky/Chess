#pragma once
#include "Piece.h"
#include <vector>
using namespace std;

class Engine
{
	vector<Piece>Pieces;									//vector w ktorym trzymane sa wszystkie bierki
	char activeplayer;										//ktory gracz jest aktywny
	int actx;												//x aktywnej figury
	int acty;												//y aktywnej figury
	bool endgame;
	Engine();
	~Engine();
public:
	static Engine & getInstance(){							//singleton
		static Engine instance;
		return instance;
	}
	void DelPiece(int x, int y);							//usuwanie bierki znajdujcej sie na polach xy
	Piece ReturnPiece(int x, int y);						//zwraca bierke znajduja sie na koordynatach xy
	Piece ReturnPiece(int i);								//zwraca bierke znajdujaca sie na i miejscu w wektorze
	int ReturnSize();
	int ReturnActX();
	int ReturnActY();
	char ReturnPlayer();
	bool ReturnEnd();
	void SetEnd();
	void ChangeActXY(int actx, int acty);
	void ChangePlayer();
	bool EmptySlot(int x, int y);							//sprawdza czy pole xy jest puste
	void ChangeXY(int x, int y, int newx, int newy);		//zmienia koordynatu bierki na xy na newx i newy
	void Reset();											//resetuje polozenie bierek na poczatkowe
};

