#pragma once

#include "Graphics.h"

class Explosion
{
public:
	int x;
	int y;
	int timer;
	static const int width;
	static const int height;

	void Draw(Graphics& gfx) const;
};