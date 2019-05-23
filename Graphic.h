#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Engine.h"
#include "Rules.h"
#include "ChessClock.h"
#include <sstream>
using namespace sf;

class Graphic
{
	int actx;
	int acty;
	void Menu(RenderWindow& window, Sprite boardsprite);				//wyswietlanie opcji menu i obsluga eventow
	void Game(RenderWindow& window, Sprite boardsprite);				//wyswietlanie i obsluga eventow gry
	void DrawPiece(RenderWindow& window, int i);						//rysowanie jednej bierki
	void SetCord(int x, int y);											//zmiana coordynatow myszki z pixelowych na odpowiadaj¹ce polom szachowm
	void DrawActive(RenderWindow& window);								//rysowanie kwadratu innym kolorem dla przedstawienia ktora bierka jest aktywna
	void DrawTimers(RenderWindow& window);								//przedstawieine zegarow
	void MenuText(RenderWindow& window, int menuchoose, int gamechoose);//przedstawienie napisow opcji w menu
	void WinText(RenderWindow& window);
	void Draw_Text(RenderWindow& window);
public:
	Graphic();
	~Graphic();
	void MainLoop();
	
};

