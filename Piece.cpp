#include "stdafx.h"
#include "Piece.h"

Piece::Piece(int x, int y, int t, char c): corx(x), cory(y), type(t), color(c) {}
Piece::~Piece(){}
int Piece::ReturnX() {
	return corx;
}
int Piece::ReturnY() {
	return cory;
}
int Piece::ReturnType() {
	return type;
}
char Piece::ReturnColor() {
	return color;
}
void Piece::ChangeXY(int x, int y) {
	corx = x;
	cory = y;
}