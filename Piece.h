#pragma once
#include <string>
using namespace std;

class Piece
{
	int corx;
	int cory;
	int type;			//1-pawn, 2-knight, 3-bishop, 4-rock, 5-queen, 6-king
	char color;			//w-white, b-black
public:
	Piece(int corx, int cory, int type, char color);
	~Piece();
	int ReturnX();
	int ReturnY();
	int ReturnType();
	char ReturnColor();
	void ChangeXY(int x, int y); //change corx and cory
};

