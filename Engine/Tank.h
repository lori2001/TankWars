#pragma once

#include "Graphics.h"
#include "Object.h"

class Tank
{
public:
	void StayOnScreen();
	bool CheckCollision(int objx, int objy, int objwidth, int objheight);

	void GTDraw(Graphics& gfx) const;
	void BTDraw(Graphics& gfx) const;

	int lastx;
	int lasty;
	int  x;
	int  y;
	int health = 5;
	int speed = 5;
	bool won = false;

	static const int width = 100;
	static const int height = 58;
};