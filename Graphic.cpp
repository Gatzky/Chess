#include "stdafx.h"
#include "Graphic.h"
#include <windows.h>
using namespace sf;

Graphic::Graphic() {}
Graphic::~Graphic(){}
void Graphic::MainLoop() {
	sf::RenderWindow window(sf::VideoMode(700, 600), "Chess");
	window.setFramerateLimit(60);
	HWND hWnd = GetConsoleWindow();	
	ShowWindow(hWnd, SW_HIDE);
	Texture chessboard_texture;
	chessboard_texture.loadFromFile("Board.png");
	Sprite boardsprite;
	boardsprite.setTexture(chessboard_texture);
	Menu(window, boardsprite);
}
void Graphic::DrawPiece(RenderWindow& window, int i) {
	Engine &MainEngine = Engine::getInstance();
	Texture piece_texture;
	if (MainEngine.ReturnPiece(i).ReturnColor() == 'w') {
		switch (MainEngine.ReturnPiece(i).ReturnType()) {
		case 1: {
			piece_texture.loadFromFile("WhitePawn.png");
			break;
		}
		case 2: {
			piece_texture.loadFromFile("WhiteKnight.png");
			break;
		}
		case 3: {
			piece_texture.loadFromFile("WhiteBishop.png");
			break;
		}
		case 4: {
			piece_texture.loadFromFile("WhiteRock.png");
			break;
		}
		case 5: {
			piece_texture.loadFromFile("WhiteQueen.png");
			break;
		}
		case 6: {
			piece_texture.loadFromFile("WhiteKing.png");
			break;
		}
		}
	}
	else {
		switch (MainEngine.ReturnPiece(i).ReturnType()) {
		case 1: {
			piece_texture.loadFromFile("BlackPawn.png");
			break;
		}
		case 2: {
			piece_texture.loadFromFile("BlackKnight.png");
			break;
		}
		case 3: {
			piece_texture.loadFromFile("BlackBishop.png");
			break;
		}
		case 4: {
			piece_texture.loadFromFile("BlackRock.png");
			break;
		}
		case 5: {
			piece_texture.loadFromFile("BlackQueen.png");
			break;
		}
		case 6: {
			piece_texture.loadFromFile("BlackKing.png");
			break;
		}
		}
	}
	Sprite piece_sprite;
	piece_sprite.setTexture(piece_texture);
	piece_sprite.setOrigin(30, 30);
	piece_sprite.setPosition(70* MainEngine.ReturnPiece(i).ReturnX()-15, 70* MainEngine.ReturnPiece(i).ReturnY()-15);
	window.draw(piece_sprite);
}
void Graphic::SetCord(/*RenderWindow& window,*/ int positionx, int positiony) {	
	Engine &MainEngine = Engine::getInstance();
	int newx, newy;
	if (positionx < 20 || positionx > 580)
		newx = 0;
	if (positiony < 20 || positiony > 580)
		newy = 0;
	for (int i = 0; i < 9; i++) {
		if (positionx > 20 + 70 * i && positionx < 90 + 70 * i) {
			newx = i + 1;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (positiony > 20 + 70 * i && positiony < 90 + 70 * i) {
			newy = i + 1;
		}
	}
	Rules &MainRules = Rules::getInstance();
	MainRules.Main(MainEngine.ReturnActX(), MainEngine.ReturnActY(), newx, newy);
}
void Graphic::DrawActive(RenderWindow& window) {
	Engine &MainEngine = Engine::getInstance();
	RectangleShape drawblock(Vector2f(70, 70));
	drawblock.setOrigin(35, 35);
	if ((MainEngine.ReturnActX() % 2 == 0 && MainEngine.ReturnActY() % 2 == 0 || MainEngine.ReturnActX() % 2 != 0 && MainEngine.ReturnActY() % 2 != 0))
		drawblock.setFillColor(Color(246, 246, 130));
	else
		drawblock.setFillColor(Color(186, 202, 34)); 
	drawblock.setPosition(70* MainEngine.ReturnActX() -15, 70* MainEngine.ReturnActY() -15);
	window.draw(drawblock);
}
void Graphic::DrawTimers(RenderWindow& window) {
	Engine &MainEngine = Engine::getInstance();
	ChessClock &MainClock = ChessClock::getInstance(600, 600);
	Font digital7;
	digital7.loadFromFile("digital-7.ttf");
	Text WhiteClockText;
	WhiteClockText.setFont(digital7);
	int WhiteMinutes = 0;
	int WhiteSeconds = MainClock.ReturnWhiteClock();
	while (WhiteSeconds >= 60) {
		WhiteSeconds -= 60;
		WhiteMinutes++;
	}
	
	stringstream TempWhite;
	if (WhiteMinutes < 10 && WhiteSeconds < 10)
		TempWhite << "0" << WhiteMinutes << ":" << "0" << WhiteSeconds;
	else if(WhiteSeconds < 10)
		TempWhite << WhiteMinutes << ":" << "0" << WhiteSeconds;
	else if (WhiteMinutes < 10)
		TempWhite << "0" << WhiteMinutes << ":" << WhiteSeconds;
	else
		TempWhite << WhiteMinutes << ":" << WhiteSeconds;
	string FinalWhite = TempWhite.str();

	WhiteClockText.setString(FinalWhite);
	WhiteClockText.setCharacterSize(40);
	WhiteClockText.setFillColor(Color(118, 150, 86));
	WhiteClockText.setOrigin(40, 13);
	WhiteClockText.setPosition(640, 513);
	if (MainEngine.ReturnPlayer() == 'w') {
		WhiteClockText.setOutlineThickness(4);
		WhiteClockText.setOutlineColor(Color(246, 246, 130));
	}
	window.draw(WhiteClockText);

	Text BlackClockText;
	BlackClockText.setFont(digital7);
	int BlackMinutes = 0;
	int BlackSeconds = MainClock.ReturnBlackClock();
	while (BlackSeconds >= 60) {
		BlackSeconds -= 60;
		BlackMinutes++;
	}

	stringstream TempBlack;
	if (BlackMinutes < 10 && BlackSeconds < 10)
		TempBlack << "0" << BlackMinutes << ":" << "0" << BlackSeconds;
	else if (BlackSeconds < 10)
		TempBlack << BlackMinutes << ":" << "0" << BlackSeconds;
	else if (BlackMinutes < 10)
		TempBlack << "0" << BlackMinutes << ":" << BlackSeconds;
	else
		TempBlack << BlackMinutes << ":" << BlackSeconds;
	string FinalBlack = TempBlack.str();

	BlackClockText.setString(FinalBlack);
	BlackClockText.setCharacterSize(40);
	BlackClockText.setFillColor(Color(118, 150, 86));
	BlackClockText.setOrigin(40, 13);
	BlackClockText.setPosition(640, 83);
	if (MainEngine.ReturnPlayer() == 'b') {
		BlackClockText.setOutlineThickness(4);
		BlackClockText.setOutlineColor(Color(246, 246, 130));
	}
	window.draw(BlackClockText);
	
}
void Graphic::Game(RenderWindow& window, Sprite boardsprite) {
	Event event;
	Engine &MainEngine = Engine::getInstance();
	ChessClock &MainClock = ChessClock::getInstance(600, 600);
	bool win = 0;
	while (true) {													//infinite loop
		window.clear(Color::White);
		window.draw(boardsprite);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && !MainEngine.ReturnEnd()) {
			Vector2i Position = Mouse::getPosition(window);
			SetCord(Position.x, Position.y);
			Sleep(100);
		}
		else if (Keyboard::isKeyPressed(Keyboard::B)) {
			Menu(window, boardsprite);
			Sleep(100);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S) && !MainEngine.ReturnEnd()) {
			MainEngine.SetEnd();
			win = 1;
			Sleep(100);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D) && !MainEngine.ReturnEnd()) {
			MainEngine.SetEnd();
			win = 0;
			Sleep(100);
		}
		if (MainEngine.ReturnActX() != 0 && MainEngine.ReturnActY() != 0)
			DrawActive(window);
		for (int i = 0; i < MainEngine.ReturnSize(); i++) {
			DrawPiece(window, i);
		}
		if (MainEngine.ReturnEnd() && win) {
			WinText(window);
		}
		if (MainEngine.ReturnEnd() && !win) {
			Draw_Text(window);
		}
		if (!MainEngine.ReturnEnd()) {
			MainClock.TestTime(MainEngine.ReturnPlayer());
			if (MainClock.TestEndTime(MainEngine.ReturnPlayer())) {
				MainEngine.SetEnd();
				win = 1;
			}
		}
		DrawTimers(window);
		window.display();											//DISPLAY EVERYTHING
	}
}
void Graphic::Menu(RenderWindow& window, Sprite boardsprite) {
	Event event;
	Engine &MainEngine = Engine::getInstance();
	ChessClock &MainClock = ChessClock::getInstance(600,600);
	int menuchoose = 1;
	int gamechoose = 4;
	while (true) {
		window.clear(Color(238,238,210));
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (menuchoose < 3)
				menuchoose++;
			Sleep(100);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (menuchoose > 1)
				menuchoose--;
			Sleep(100);
		}
		if (menuchoose == 2) {
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				if (gamechoose < 4)
					gamechoose++;
				Sleep(100);
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				if (gamechoose > 1)
					gamechoose--;
				Sleep(100);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Return)) {
			if (menuchoose == 1) {
				switch (gamechoose) {
				case 1: {
					MainClock.SetClock(60, 60);
					break;
				}
				case 2: {
					MainClock.SetClock(180, 180);
					break;
				}
				case 3: {
					MainClock.SetClock(600, 600);
					break;
				}
				case 4: {
					MainClock.SetClock(900, 900);
					break;
				}
				}
				MainEngine.Reset();
				Game(window, boardsprite);
			}
			if (menuchoose == 3) {
				window.close();
				break;
			}
		}
		MenuText (window, menuchoose, gamechoose);
		window.display();
	}
}
void Graphic::MenuText(RenderWindow& window, int menuchoose, int gamechoose) {
	Font digital7;
	digital7.loadFromFile("digital-7.ttf");
	Text StartGame;
	StartGame.setFont(digital7);
	StartGame.setString("Start Game");
	StartGame.setCharacterSize(40);
	StartGame.setOrigin(40, 13);
	StartGame.setFillColor(Color(118, 150, 86));
	StartGame.setPosition(325, 150);
	if (menuchoose == 1) {
		StartGame.setOutlineThickness(4);
		StartGame.setOutlineColor(Color(246, 246, 130));
	}
	window.draw(StartGame);

	string choosetype = "XXX";
	switch (gamechoose) {
	case 1: {
		choosetype = "Bullet ( 1 min )";
		break;
	}
	case 2: {
		choosetype = "Blitz ( 3 min )";
		break;
	}
	case 3: {
		choosetype = "Rapid ( 10 min )";
		break;
	}
	case 4: {
		choosetype = "Classic ( 15 min )";
		break;
	}
	}

	Text Type;
	Type.setFont(digital7);
	Type.setString("Game Type:");
	Type.setCharacterSize(40);
	Type.setOrigin(40, 13);
	Type.setFillColor(Color(118, 150, 86));
	Type.setPosition(325, 290);
	if (menuchoose == 2) {
		Type.setOutlineThickness(4);
		Type.setOutlineColor(Color(246, 246, 130));
	}
	window.draw(Type);

	Text SubType;
	SubType.setFont(digital7);
	SubType.setString(choosetype);
	SubType.setCharacterSize(20);
	SubType.setOrigin(40, 13);
	SubType.setFillColor(Color(118, 150, 86));
	SubType.setPosition(350, 340);
	if (menuchoose == 2) {
		SubType.setOutlineThickness(4);
		SubType.setOutlineColor(Color(246, 246, 130));
	}
	window.draw(SubType);

	Text Exit;
	Exit.setFont(digital7);
	Exit.setString("Exit");
	Exit.setCharacterSize(40);
	Exit.setOrigin(40, 13);
	Exit.setFillColor(Color(118, 150, 86));
	Exit.setPosition(370, 450);
	if (menuchoose == 3) {
		Exit.setOutlineThickness(4);
		Exit.setOutlineColor(Color(246, 246, 130));
	}
	window.draw(Exit);
}
void Graphic::WinText(RenderWindow& window) {
	Engine &MainEngine = Engine::getInstance();
	Font digital7;
	digital7.loadFromFile("digital-7.ttf");
	Text WinText;
	WinText.setFont(digital7);
	if (MainEngine.ReturnPlayer() == 'w')
		WinText.setString("Black Win");
	if (MainEngine.ReturnPlayer() == 'b')
		WinText.setString("White Win");
	WinText.setCharacterSize(100);
	WinText.setOrigin(50, 50);
	WinText.setFillColor(Color(118, 150, 86));
	WinText.setPosition(250, 280);
	WinText.setOutlineThickness(40);
	WinText.setOutlineColor(Color(238, 238, 210));
	window.draw(WinText);
}
void Graphic::Draw_Text(RenderWindow& window) {
	Engine &MainEngine = Engine::getInstance();
	Font digital7;
	digital7.loadFromFile("digital-7.ttf");
	Text DText;
	DText.setFont(digital7);
	DText.setString("Draw");
	DText.setCharacterSize(100);
	DText.setOrigin(50, 50);
	DText.setFillColor(Color(118, 150, 86));
	DText.setPosition(280, 280);
	DText.setOutlineThickness(40);
	DText.setOutlineColor(Color(238, 238, 210));
	window.draw(DText);
}