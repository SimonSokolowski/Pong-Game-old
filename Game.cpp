#include "MainWindow.h"
#include "Game.h"
#include "Graphics.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(200, 650);
	std::uniform_int_distribution<int> yDist(50, 550);
	x = xDist(rng);
	y = yDist(rng);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	x = x + vx;
	y = y + vy;

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		lineY = lineY - 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		lineY = lineY + 3;
	}

	lineY = BorderBlockline(lineY);
	vx = BorderBlockX(x);
	vy = BorderBlockY(y);

	LineBounce(lineX, lineY);
	LineBounce(computerX, computerY);

	if (y >= gfx.ScreenHeight - 85)
	{
		computerY = 429;
	}
	else if (y - 85 <= 0)
	{
		computerY = 2;
	}
	else
	{
		computerY = y - 85;
	}

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(200, 650);
	std::uniform_int_distribution<int> yDist(50, 550);

	if (vx == 0)
	{
		if (wnd.kbd.KeyIsPressed(VK_SHIFT))
		{
			x = xDist(rng);
			y = yDist(rng);
			vx = 2;
			vy = 2;
		}
	}
}

void Game::ComposeFrame()
{
	CreateCircle(x, y, 255, 255, 255);

	CreateLine(lineX, lineY, 255, 255, 255);

	CreateLine(computerX, computerY, 255, 255, 255);

}

void Game::CreateCircle(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 4, y,     r, g, b);
	gfx.PutPixel(x + 4, y + 1, r, g, b);
	gfx.PutPixel(x + 3, y + 2, r, g, b);
	gfx.PutPixel(x + 2, y + 3, r, g, b);
	gfx.PutPixel(x + 1, y + 4, r, g, b);
	gfx.PutPixel(x + 4, y - 1, r, g, b);
	gfx.PutPixel(x + 3, y - 2, r, g, b);
	gfx.PutPixel(x + 2, y - 3, r, g, b);
	gfx.PutPixel(x + 1, y - 4, r, g, b);
	gfx.PutPixel(x - 4, y,     r, g, b);
	gfx.PutPixel(x - 4, y - 1, r, g, b);
	gfx.PutPixel(x - 3, y - 2, r, g, b);
	gfx.PutPixel(x - 2, y - 3, r, g, b);
	gfx.PutPixel(x - 1, y - 4, r, g, b);
	gfx.PutPixel(x - 4, y + 1, r, g, b);
	gfx.PutPixel(x - 3, y + 2, r, g, b);
	gfx.PutPixel(x - 2, y + 3, r, g, b);
	gfx.PutPixel(x - 1, y + 4, r, g, b);
	gfx.PutPixel(x    , y + 4, r, g, b);
	gfx.PutPixel(x    , y - 4, r, g, b);

}

void Game::CreateLine(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x, y + 1, 255, 255, 255);
	gfx.PutPixel(x, y + 2, 255, 255, 255);
	gfx.PutPixel(x, y + 3, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 5, 255, 255, 255);
	gfx.PutPixel(x, y + 6, 255, 255, 255);
	gfx.PutPixel(x, y + 7, 255, 255, 255);
	gfx.PutPixel(x, y + 8, 255, 255, 255);
	gfx.PutPixel(x, y + 9, 255, 255, 255);
	gfx.PutPixel(x, y + 11, 255, 255, 255);
	gfx.PutPixel(x, y + 10, 255, 255, 255);
	gfx.PutPixel(x, y + 12, 255, 255, 255);
	gfx.PutPixel(x, y + 13, 255, 255, 255);
	gfx.PutPixel(x, y + 14, 255, 255, 255);
	gfx.PutPixel(x, y + 15, 255, 255, 255);
	gfx.PutPixel(x, y + 16, 255, 255, 255);
	gfx.PutPixel(x, y + 17, 255, 255, 255);
	gfx.PutPixel(x, y + 18, 255, 255, 255);
	gfx.PutPixel(x, y + 19, 255, 255, 255);
	gfx.PutPixel(x, y + 20, 255, 255, 255);
	gfx.PutPixel(x, y + 21, 255, 255, 255);
	gfx.PutPixel(x, y + 22, 255, 255, 255);
	gfx.PutPixel(x, y + 23, 255, 255, 255);
	gfx.PutPixel(x, y + 24, 255, 255, 255);
	gfx.PutPixel(x, y + 25, 255, 255, 255);
	gfx.PutPixel(x, y + 26, 255, 255, 255);
	gfx.PutPixel(x, y + 27, 255, 255, 255);
	gfx.PutPixel(x, y + 28, 255, 255, 255);
	gfx.PutPixel(x, y + 29, 255, 255, 255);
	gfx.PutPixel(x, y + 31, 255, 255, 255);
	gfx.PutPixel(x, y + 30, 255, 255, 255);
	gfx.PutPixel(x, y + 32, 255, 255, 255);
	gfx.PutPixel(x, y + 33, 255, 255, 255);
	gfx.PutPixel(x, y + 34, 255, 255, 255);
	gfx.PutPixel(x, y + 35, 255, 255, 255);
	gfx.PutPixel(x, y + 36, 255, 255, 255);
	gfx.PutPixel(x, y + 37, 255, 255, 255);
	gfx.PutPixel(x, y + 38, 255, 255, 255);
	gfx.PutPixel(x, y + 39, 255, 255, 255);
	gfx.PutPixel(x, y + 40, 255, 255, 255);
	gfx.PutPixel(x, y + 41, 255, 255, 255);
	gfx.PutPixel(x, y + 42, 255, 255, 255);
	gfx.PutPixel(x, y + 43, 255, 255, 255);
	gfx.PutPixel(x, y + 44, 255, 255, 255);
	gfx.PutPixel(x, y + 45, 255, 255, 255);
	gfx.PutPixel(x, y + 46, 255, 255, 255);
	gfx.PutPixel(x, y + 47, 255, 255, 255);
	gfx.PutPixel(x, y + 48, 255, 255, 255);
	gfx.PutPixel(x, y + 49, 255, 255, 255);
	gfx.PutPixel(x, y + 51, 255, 255, 255);
	gfx.PutPixel(x, y + 50, 255, 255, 255);
	gfx.PutPixel(x, y + 52, 255, 255, 255);
	gfx.PutPixel(x, y + 53, 255, 255, 255);
	gfx.PutPixel(x, y + 54, 255, 255, 255);
	gfx.PutPixel(x, y + 55, 255, 255, 255);
	gfx.PutPixel(x, y + 56, 255, 255, 255);
	gfx.PutPixel(x, y + 57, 255, 255, 255);
	gfx.PutPixel(x, y + 58, 255, 255, 255);
	gfx.PutPixel(x, y + 59, 255, 255, 255);
	gfx.PutPixel(x, y + 60, 255, 255, 255);
	gfx.PutPixel(x, y + 61, 255, 255, 255);
	gfx.PutPixel(x, y + 62, 255, 255, 255);
	gfx.PutPixel(x, y + 63, 255, 255, 255);
	gfx.PutPixel(x, y + 64, 255, 255, 255);
	gfx.PutPixel(x, y + 65, 255, 255, 255);
	gfx.PutPixel(x, y + 66, 255, 255, 255);
	gfx.PutPixel(x, y + 67, 255, 255, 255);
	gfx.PutPixel(x, y + 68, 255, 255, 255);
	gfx.PutPixel(x, y + 69, 255, 255, 255);
	gfx.PutPixel(x, y + 71, 255, 255, 255);
	gfx.PutPixel(x, y + 70, 255, 255, 255);
	gfx.PutPixel(x, y + 72, 255, 255, 255);
	gfx.PutPixel(x, y + 73, 255, 255, 255);
	gfx.PutPixel(x, y + 74, 255, 255, 255);
	gfx.PutPixel(x, y + 75, 255, 255, 255);
	gfx.PutPixel(x, y + 76, 255, 255, 255);
	gfx.PutPixel(x, y + 77, 255, 255, 255);
	gfx.PutPixel(x, y + 78, 255, 255, 255);
	gfx.PutPixel(x, y + 79, 255, 255, 255);
	gfx.PutPixel(x, y + 81, 255, 255, 255);
	gfx.PutPixel(x, y + 80, 255, 255, 255);
	gfx.PutPixel(x, y + 82, 255, 255, 255);
	gfx.PutPixel(x, y + 83, 255, 255, 255);
	gfx.PutPixel(x, y + 84, 255, 255, 255);
	gfx.PutPixel(x, y + 85, 255, 255, 255);
	gfx.PutPixel(x, y + 86, 255, 255, 255);
	gfx.PutPixel(x, y + 87, 255, 255, 255);
	gfx.PutPixel(x, y + 88, 255, 255, 255);
	gfx.PutPixel(x, y + 89, 255, 255, 255);
	gfx.PutPixel(x, y + 90, 255, 255, 255);
	gfx.PutPixel(x, y + 91, 255, 255, 255);
	gfx.PutPixel(x, y + 92, 255, 255, 255);
	gfx.PutPixel(x, y + 93, 255, 255, 255);
	gfx.PutPixel(x, y + 94, 255, 255, 255);
	gfx.PutPixel(x, y + 95, 255, 255, 255);
	gfx.PutPixel(x, y + 96, 255, 255, 255);
	gfx.PutPixel(x, y + 97, 255, 255, 255);
	gfx.PutPixel(x, y + 98, 255, 255, 255);
	gfx.PutPixel(x, y + 99, 255, 255, 255);
	gfx.PutPixel(x, y + 101, 255, 255, 255);
	gfx.PutPixel(x, y + 100, 255, 255, 255);
	gfx.PutPixel(x, y + 102, 255, 255, 255);
	gfx.PutPixel(x, y + 103, 255, 255, 255);
	gfx.PutPixel(x, y + 104, 255, 255, 255);
	gfx.PutPixel(x, y + 105, 255, 255, 255);
	gfx.PutPixel(x, y + 106, 255, 255, 255);
	gfx.PutPixel(x, y + 107, 255, 255, 255);
	gfx.PutPixel(x, y + 108, 255, 255, 255);
	gfx.PutPixel(x, y + 109, 255, 255, 255);
	gfx.PutPixel(x, y + 111, 255, 255, 255);
	gfx.PutPixel(x, y + 110, 255, 255, 255);
	gfx.PutPixel(x, y + 112, 255, 255, 255);
	gfx.PutPixel(x, y + 113, 255, 255, 255);
	gfx.PutPixel(x, y + 114, 255, 255, 255);
	gfx.PutPixel(x, y + 115, 255, 255, 255);
	gfx.PutPixel(x, y + 116, 255, 255, 255);
	gfx.PutPixel(x, y + 117, 255, 255, 255);
	gfx.PutPixel(x, y + 118, 255, 255, 255);
	gfx.PutPixel(x, y + 119, 255, 255, 255);
	gfx.PutPixel(x, y + 120, 255, 255, 255);
	gfx.PutPixel(x, y + 121, 255, 255, 255);
	gfx.PutPixel(x, y + 122, 255, 255, 255);
	gfx.PutPixel(x, y + 123, 255, 255, 255);
	gfx.PutPixel(x, y + 124, 255, 255, 255);
	gfx.PutPixel(x, y + 125, 255, 255, 255);
	gfx.PutPixel(x, y + 126, 255, 255, 255);
	gfx.PutPixel(x, y + 127, 255, 255, 255);
	gfx.PutPixel(x, y + 128, 255, 255, 255);
	gfx.PutPixel(x, y + 129, 255, 255, 255);
	gfx.PutPixel(x, y + 131, 255, 255, 255);
	gfx.PutPixel(x, y + 130, 255, 255, 255);
	gfx.PutPixel(x, y + 132, 255, 255, 255);
	gfx.PutPixel(x, y + 133, 255, 255, 255);
	gfx.PutPixel(x, y + 134, 255, 255, 255);
	gfx.PutPixel(x, y + 135, 255, 255, 255);
	gfx.PutPixel(x, y + 136, 255, 255, 255);
	gfx.PutPixel(x, y + 137, 255, 255, 255);
	gfx.PutPixel(x, y + 138, 255, 255, 255);
	gfx.PutPixel(x, y + 139, 255, 255, 255);
	gfx.PutPixel(x, y + 140, 255, 255, 255);
	gfx.PutPixel(x, y + 141, 255, 255, 255);
	gfx.PutPixel(x, y + 142, 255, 255, 255);
	gfx.PutPixel(x, y + 143, 255, 255, 255);
	gfx.PutPixel(x, y + 144, 255, 255, 255);
	gfx.PutPixel(x, y + 145, 255, 255, 255);
	gfx.PutPixel(x, y + 146, 255, 255, 255);
	gfx.PutPixel(x, y + 147, 255, 255, 255);
	gfx.PutPixel(x, y + 148, 255, 255, 255);
	gfx.PutPixel(x, y + 149, 255, 255, 255);
	gfx.PutPixel(x, y + 151, 255, 255, 255);
	gfx.PutPixel(x, y + 150, 255, 255, 255);
	gfx.PutPixel(x, y + 152, 255, 255, 255);
	gfx.PutPixel(x, y + 153, 255, 255, 255);
	gfx.PutPixel(x, y + 154, 255, 255, 255);
	gfx.PutPixel(x, y + 155, 255, 255, 255);
	gfx.PutPixel(x, y + 156, 255, 255, 255);
	gfx.PutPixel(x, y + 157, 255, 255, 255);
	gfx.PutPixel(x, y + 158, 255, 255, 255);
	gfx.PutPixel(x, y + 159, 255, 255, 255);
	gfx.PutPixel(x, y + 160, 255, 255, 255);
	gfx.PutPixel(x, y + 161, 255, 255, 255);
	gfx.PutPixel(x, y + 162, 255, 255, 255);
	gfx.PutPixel(x, y + 163, 255, 255, 255);
	gfx.PutPixel(x, y + 164, 255, 255, 255);
	gfx.PutPixel(x, y + 165, 255, 255, 255);
	gfx.PutPixel(x, y + 166, 255, 255, 255);
	gfx.PutPixel(x, y + 167, 255, 255, 255);
	gfx.PutPixel(x, y + 168, 255, 255, 255);
	gfx.PutPixel(x, y + 169, 255, 255, 255);
}

int Game::BorderBlockX(int circleX)
{
	if ((circleX + 6 >= gfx.ScreenWidth) || (circleX - 6 <= 0))
	{
		return vx = 0;
	}
	else
	{
		return vx;
	}
}
int Game::BorderBlockY(int circleY)
{
	if ((circleY + 6 >= gfx.ScreenHeight) || (circleY - 6 <= 0))
	{
		return -vy;
	}
	else
	{
		return vy;
	}
}

int Game::BorderBlockline(int lineyY)
{
	if (lineY <= 0)
	{
		return lineY + 3;
	}
	else if (lineY + 169 >= gfx.ScreenHeight)
	{
		return lineY - 3;
	}
	else
	{
		return lineY;
	}
}

void Game::LineBounce(int linesX, int linesY)
{
	if (x - 4 <= linesX && x + 4 >= linesX && y + 4 <= linesY + 172 && y - 4 >= linesY - 1)
	{
		vx = -vx;
	}
}