/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	//Drawing main screen
	draw.welcome(gfx);
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
	if (IsStarted)
	{
		//Saving last controls
		greentank.lastx = greentank.x;
		greentank.lasty = greentank.y;
		bluetank.lastx = bluetank.x;
		bluetank.lasty = bluetank.y;

		/*CONTROLS for the Green Tank*/
		if (wnd.kbd.KeyIsPressed('W'))  // https://www.w3.org/2002/09/tests/keys.html
			greentank.y -= greentank.speed;
		if (wnd.kbd.KeyIsPressed('S'))
			greentank.y += greentank.speed;
		if (wnd.kbd.KeyIsPressed('A'))
			greentank.x -= greentank.speed;
		if (wnd.kbd.KeyIsPressed('D'))
			greentank.x += greentank.speed;
		if (wnd.kbd.KeyIsPressed(32) && !greenbullet.existing && greentank.health > 0) //space
		{
			greenbullet.x = greentank.x;
			greenbullet.y = greentank.y;
			greenbullet.existing = true;
		}

		/*CONTROLS for the Blue Tank*/

		if (wnd.kbd.KeyIsPressed(VK_UP))//up key
			bluetank.y -= bluetank.speed;
		if (wnd.kbd.KeyIsPressed(VK_DOWN))//down key
			bluetank.y += bluetank.speed;
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))//right key
			bluetank.x += bluetank.speed;
		if (wnd.kbd.KeyIsPressed(VK_LEFT))//left key
			bluetank.x -= bluetank.speed;
		if (wnd.kbd.KeyIsPressed(13) && !bluebullet.existing && bluetank.health > 0) //enter
		{
			bluebullet.x = bluetank.x;
			bluebullet.y = bluetank.y;
			bluebullet.existing = true;
		}
		/*Making sure the tanks and obstacles don't overlap*/

		if (greentank.CheckCollision(bluetank.x, bluetank.y, bluetank.width, bluetank.height) ||
			greentank.CheckCollision(obstacle1.x, obstacle1.y, obstacle1.width, obstacle1.height) ||
			greentank.CheckCollision(obstacle2.x, obstacle2.y, obstacle2.width, obstacle2.height))
		{
			greentank.x = greentank.lastx;
			greentank.y = greentank.lasty;
		}
		if (bluetank.CheckCollision(greentank.x, greentank.y, greentank.width, greentank.height) ||
			bluetank.CheckCollision(obstacle1.x, obstacle1.y, obstacle1.width, obstacle1.height) ||
			bluetank.CheckCollision(obstacle2.x, obstacle2.y, obstacle2.width, obstacle2.height))
		{
			bluetank.x = bluetank.lastx;
			bluetank.y = bluetank.lasty;
		}

		/*Making sure the tanks don't go off-screen*/

		greentank.StayOnScreen();
		bluetank.StayOnScreen();

		/*BULLET motion animation*/

		if (greenbullet.existing)
			greenbullet.x += greenbullet.speed;
		else {
			greenbullet.x = -100;
			greenbullet.y = -100;
		}

		if (bluebullet.existing)
			bluebullet.x -= bluebullet.speed;
		else {
			bluebullet.x = -100;
			bluebullet.y = -100;
		}

		/*BULLET collision checks*/

		if (greenbullet.CheckCollision(bluetank.x, bluetank.y, bluetank.width, bluetank.height))
		{
			greenbullet.existing = false;
			bluetank.health--;
			greenexplosion.timer = 0;
			greenexplosion.x = greenbullet.x + greenbullet.width;
			greenexplosion.y = greenbullet.y;
		}
		else if (greenbullet.x >= gfx.ScreenWidth - greenbullet.width ||
			greenbullet.CheckCollision(obstacle1.x, obstacle1.y, obstacle1.width, obstacle1.height) ||
			greenbullet.CheckCollision(obstacle2.x, obstacle2.y, obstacle2.width, obstacle2.height))
		{
			greenbullet.existing = false;
		}


		if (bluebullet.CheckCollision(greentank.x, greentank.y, greentank.width, greentank.height))
		{
			bluebullet.existing = false;
			greentank.health--;
			blueexplosion.timer = 0;
			blueexplosion.x = bluebullet.x;
			blueexplosion.y = bluebullet.y;
		}
		else if (bluebullet.x <= 0 ||
			bluebullet.CheckCollision(obstacle1.x, obstacle1.y, obstacle1.width, obstacle1.height) ||
			bluebullet.CheckCollision(obstacle2.x, obstacle2.y, obstacle2.width, obstacle2.height))
		{
		bluebullet.existing = false;
		}

	}
	if (wnd.kbd.KeyIsPressed(VK_ESCAPE))
	{
		IsStarted = true;

		//Initializing starting positions/values
		bluebullet.existing = false;
		greenbullet.existing = false;

		greentank.y = gfx.ScreenHeight / 2;
		greentank.x = 20;

		bluetank.y = gfx.ScreenHeight / 2;
		bluetank.x = gfx.ScreenWidth - bluetank.width - 20;

		obstacle1.x = 375;
		obstacle1.y = 25;
		obstacle1.width = 50;
		obstacle1.height = 150;

		obstacle2.x = 375;
		obstacle2.y = gfx.ScreenHeight - 101;
		obstacle2.width = 50;
		obstacle2.height = 100;

		bluetank.won = false;
		greentank.won = false;
		bluetank.health = 5;
		greentank.health = 5;
	}

	if (wnd.kbd.KeyIsPressed(112))
		exit(0);
}

void Game::ComposeFrame()
{
	if (IsStarted && bluetank.health > 0 && greentank.health > 0)
	{

		//Obstacles
		gfx.DrawRectangle(obstacle1.x, obstacle1.y, obstacle1.width, obstacle1.height, Colors::Gray);
		gfx.DrawRectangle(obstacle2.x, obstacle2.y, obstacle2.width, obstacle2.height, Colors::Gray);

		//Health Bars
		for (int i = 0; i < greentank.health; i++)
		{
			gfx.DrawRectangle(greentank.x+(20*i), greentank.y + greentank.height, 18, 10, Colors::Green);
		}
		for (int i = 0; i < bluetank.health; i++)
		{
			gfx.DrawRectangle(bluetank.x + (20 * i), bluetank.y + bluetank.height, 18, 10, Colors::Blue);
		}

		//Bullets
		if (greenbullet.existing)
			greenbullet.Draw(gfx);
		if (bluebullet.existing)
			bluebullet.Draw(gfx);

		//Tanks
		if (greentank.health > 0)
			greentank.GTDraw(gfx);
		if (bluetank.health > 0)
			bluetank.BTDraw(gfx);

		//Explosions
		if (greenexplosion.timer <= 20)
		{
			greenexplosion.Draw(gfx);
			greenexplosion.timer++;
		}
		if (blueexplosion.timer <= 20)
		{
			blueexplosion.Draw(gfx);
			blueexplosion.timer++;
		}

	}
	else if (!IsStarted)
		draw.welcome(gfx);
	else if (bluetank.health <= 0 && !bluetank.won) {
		draw.greenwon(gfx);
		greentank.won = true;
	}
	else if (greentank.health <= 0 && !greentank.won) {
		draw.bluewon(gfx);
		bluetank.won = true;
	}
}

