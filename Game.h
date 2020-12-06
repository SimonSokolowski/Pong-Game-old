#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private://functions

	void ComposeFrame();
	void UpdateModel();
	int BorderBlockX(int circleX);
	int BorderBlockY(int circleY);
	int BorderBlockline(int lineY);
	void LineBounce(int linesX, int linesY);
	void CreateCircle(int fixedx, int fixedy, int r, int g, int b);
	void CreateLine(int x, int y, int r, int g, int b);


private://variables

	MainWindow& wnd;
	Graphics gfx;
	int x = 300;
	int y = 300;
	int lineX = 10;
	int lineY= 10;
	int computerX = 790;
	int computerY = 0;
	int vx = 2;
	int vy = 2;
	int circleX = 0;
};