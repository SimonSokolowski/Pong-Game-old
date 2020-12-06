/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
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
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions*/
	void CreateCursor(int fixedx, int fixedy, int r, int g, int b);
	void CollidedCursor(int fixedx, int fixedy);
	int BorderBlockx(int cursorx);
	int BorderBlocky(int cursory);
	int BorderVelx(int velocityx, int cursorx);
	int BorderVely(int velocityy, int cursory);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int x = 400;
	int y = 300;
	int memX = x;
	int memY = y;
	int vx = 0;
	int vy = 0;
	int gb = 255;
	int fixedy = 200;
	int fixedx = 200;
	bool shapeIsChanged = false;
	bool movingY = false;
	bool movingX = false;
	bool colourChange = false;
	bool lookingUp = false;
	bool lookingDown = false;
	bool lookingLeft = false;
	bool lookingRight = false;
	bool createTail = false;
	bool direction = false;
	/********************************/
};