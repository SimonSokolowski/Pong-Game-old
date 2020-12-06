#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
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
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (movingX == true)
		{
			vx = 0;
			movingX = false;
		}
		vy = 1;
		movingY = true;

	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (movingX == true)
		{
			vx = 0;
			movingX = false;
		}
		vy = -1;
		movingY = true;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (movingY == true)
		{
			vy = 0;
			movingY = false;
		}
		vx = -1;
		movingX = true;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (movingY == true)
		{
			vy = 0;
			movingY = false;
		}
		vx = 1;
		movingX = true;
	}

	CollidedCursor(300, 300);

	x = x + vx;
	y = y + vy;

	x = BorderBlockx(x);
	y = BorderBlocky(y);
	vx = BorderVelx(x, x);
	vy = BorderVely(y, y);
}

void Game::ComposeFrame()
{
	CreateCursor(300, 300, 255, 0, 255);

	if (shapeIsChanged)
	{
		gfx.PutPixel(x - 5, y + 1, 255, gb, gb);
		gfx.PutPixel(x - 4, y + 2, 255, gb, gb);
		gfx.PutPixel(x - 3, y + 3, 255, gb, gb);
		gfx.PutPixel(x + 3, y + 3, 255, gb, gb);
		gfx.PutPixel(x + 4, y + 2, 255, gb, gb);
		gfx.PutPixel(x + 5, y + 1, 255, gb, gb);
		gfx.PutPixel(x + 1, y - 5, 255, gb, gb);
		gfx.PutPixel(x + 2, y - 4, 255, gb, gb);
		gfx.PutPixel(x + 3, y - 3, 255, gb, gb);
		gfx.PutPixel(x + 3, y + 3, 255, gb, gb);
		gfx.PutPixel(x + 2, y + 4, 255, gb, gb);
		gfx.PutPixel(x + 1, y + 5, 255, gb, gb);
	}
	else
	{
		CreateCursor(x, y, 255, gb, gb);
	}
	
//	if (createTail == true)
//	{
//		if (lookingUp == true)
//		{
//			CreateCursor(x, y + 14, 255, gb, gb);
//		}
//
//		else if (lookingDown == true)
//		{
//			CreateCursor(x, y - 14, 255, gb, gb);
//		}
//
//		else if (lookingRight == true)
//		{
//			CreateCursor(x - 14, y, 255, gb, gb);
//		}
//
//		else if (lookingLeft == true)
//		{
//			CreateCursor(x + 14, y, 255, gb, gb);
//		}
//	}

}

void Game::CollidedCursor(int fixedx, int fixedy)
{
	if ((x - 5 <= fixedx + 5 && x + 5 >= fixedx - 5) && (y - 5 <= fixedy + 5 && y + 5 >= fixedy - 5))
	{
		gb = 0;
	}
	else
	{
		gb = 255;
	}
}
void Game::CreateCursor(int fixedx, int fixedy, int r, int g, int b)
{
	gfx.PutPixel(fixedx - 5, fixedy, r, g, b);
	gfx.PutPixel(fixedx - 4, fixedy, r, g, b);
	gfx.PutPixel(fixedx - 3, fixedy, r, g, b);
	gfx.PutPixel(fixedx + 3, fixedy, r, g, b);
	gfx.PutPixel(fixedx + 4, fixedy, r, g, b);
	gfx.PutPixel(fixedx + 5, fixedy, r, g, b);
	gfx.PutPixel(fixedx, fixedy - 5, r, g, b);
	gfx.PutPixel(fixedx, fixedy - 4, r, g, b);
	gfx.PutPixel(fixedx, fixedy - 3, r, g, b);
	gfx.PutPixel(fixedx, fixedy + 3, r, g, b);
	gfx.PutPixel(fixedx, fixedy + 4, r, g, b);
	gfx.PutPixel(fixedx, fixedy + 5, r, g, b);
}

int Game::BorderBlockx(int cursorx)
{
	if (cursorx + 5 >= gfx.ScreenWidth)
	{
		return gfx.ScreenWidth - 6;
	}

	if (cursorx - 5 < 0)
	{
		return 5;
	}
	else
	{
		return cursorx;
	}
}
int Game::BorderBlocky(int cursory)
{
	if (cursory + 5 >= gfx.ScreenHeight)
	{
		return gfx.ScreenHeight - 6;
	}  

	if (cursory - 5 < 0)
	{
		return 5;
	}
	else
	{
		return cursory;
	}
}
int Game::BorderVelx(int velocityx, int cursorx)
{
	if ((cursorx + 6 >= gfx.ScreenWidth) || (cursorx - 5 <= 0))
	{
		return 0;
	}
	else
	{
		return vx;
	}
}
int Game::BorderVely(int velocityy, int cursory)
{
	if ((cursory + 6 >= gfx.ScreenHeight) || (cursory - 5 <= 0))
	{
		return 0;
	}
	else
	{
		return vy;
	}
}