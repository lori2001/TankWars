#pragma once

#include "Graphics.h"

class Bullet
{
public:
	bool CheckCollision(int objx,int objy, int objwidth, int objheight);
	void Draw(Graphics& gfx) const;
	int x;
	int y;
	static const int speed = 15;
	static const int width = 49;
	static const int height = 16;
	bool existing = false;
};