#include "stdafx.h"
#include "Engine.h"

Engine::Engine(){
	for (int i = 1; i < 9; i++) {
		Pieces.push_back(Piece(i, 2, 1, 'b'));			//blackpawns
	}
	for (int i = 1; i < 9; i++) {
		Pieces.push_back(Piece(i, 7, 1, 'w'));			//whitepawns
	}
	Pieces.push_back(Piece(1, 1, 4, 'b'));
	Pieces.push_back(Piece(8, 1, 4, 'b'));	
	Pieces.push_back(Piece(1, 8, 4, 'w'));		
	Pieces.push_back(Piece(8, 8, 4, 'w'));			
	Pieces.push_back(Piece(2, 1, 2, 'b'));			
	Pieces.push_back(Piece(7, 1, 2, 'b'));			
	Pieces.push_back(Piece(2, 8, 2, 'w'));			
	Pieces.push_back(Piece(7, 8, 2, 'w'));			
	Pieces.push_back(Piece(3, 1, 3, 'b'));			
	Pieces.push_back(Piece(6, 1, 3, 'b'));			
	Pieces.push_back(Piece(3, 8, 3, 'w'));		
	Pieces.push_back(Piece(6, 8, 3, 'w'));			
	Pieces.push_back(Piece(4, 1, 5, 'b'));	
	Pieces.push_back(Piece(4, 8, 5, 'w'));
	Pieces.push_back(Piece(5, 1, 6, 'b'));
	Pieces.push_back(Piece(5, 8, 6, 'w'));
	activeplayer = 'w';
	endgame = 0;
}
Engine::~Engine(){}
void Engine::DelPiece(int x, int y) {
	for (int i = 0; i < Pieces.size(); i++) {
		if (Pieces.at(i).ReturnX() == x && Pieces.at(i).ReturnY() == y)
			Pieces.erase(Pieces.begin() + i);
	}
}
Piece Engine::ReturnPiece(int x, int y) {
	for (int i = 0; i < Pieces.size(); i++) {
		if (Pieces.at(i).ReturnX() == x && Pieces.at(i).ReturnY() == y)
			return Pieces.at(i);
	}
}
Piece Engine::ReturnPiece(int n) {
	return Pieces.at(n);
}
int Engine::ReturnSize() {
	return Pieces.size();
}
char Engine::ReturnPlayer() {
	return activeplayer;
}
bool Engine::ReturnEnd() {
	return endgame;
}
void Engine::SetEnd() {
	endgame = 1;
}
void Engine::ChangePlayer() {
	if (activeplayer == 'w')
		activeplayer = 'b';
	else
		activeplayer = 'w';
}
bool Engine::EmptySlot(int x, int y){
	bool result = 1;
	for (int i = 0; i < Pieces.size(); i++) {
		if (Pieces.at(i).ReturnX() == x && Pieces.at(i).ReturnY() == y){
			result = 0;
		break;
	}
	}
	return result;
}
void Engine::ChangeXY(int piecex, int piecey, int newx, int newy) {
	for (int i = 0; i < Pieces.size(); i++) {
		if (Pieces.at(i).ReturnX() == piecex && Pieces.at(i).ReturnY() == piecey)
			Pieces.at(i).ChangeXY(newx, newy);
	}
}
int Engine::ReturnActX() {
	return actx;
}
int Engine::ReturnActY() {
	return acty;
}
void Engine::ChangeActXY(int x, int y) {
	actx = x;
	acty = y;
}
void Engine::Reset() {
	Pieces.clear();
	for (int i = 1; i < 9; i++) {
		Pieces.push_back(Piece(i, 2, 1, 'b'));			//blackpawns
	}
	for (int i = 1; i < 9; i++) {
		Pieces.push_back(Piece(i, 7, 1, 'w'));			//whitepawns
	}
	Pieces.push_back(Piece(1, 1, 4, 'b'));
	Pieces.push_back(Piece(8, 1, 4, 'b'));
	Pieces.push_back(Piece(1, 8, 4, 'w'));
	Pieces.push_back(Piece(8, 8, 4, 'w'));
	Pieces.push_back(Piece(2, 1, 2, 'b'));
	Pieces.push_back(Piece(7, 1, 2, 'b'));
	Pieces.push_back(Piece(2, 8, 2, 'w'));
	Pieces.push_back(Piece(7, 8, 2, 'w'));
	Pieces.push_back(Piece(3, 1, 3, 'b'));
	Pieces.push_back(Piece(6, 1, 3, 'b'));
	Pieces.push_back(Piece(3, 8, 3, 'w'));
	Pieces.push_back(Piece(6, 8, 3, 'w'));
	Pieces.push_back(Piece(4, 1, 5, 'b'));
	Pieces.push_back(Piece(4, 8, 5, 'w'));
	Pieces.push_back(Piece(5, 1, 6, 'b'));
	Pieces.push_back(Piece(5, 8, 6, 'w'));
	activeplayer = 'w';
	endgame = 0;
}