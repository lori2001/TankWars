#pragma once

#include "Graphics.h"

class Draw
{
private:
	static constexpr int x = 0;
	static constexpr int y = 0;
public:
	void welcome(Graphics& gfx) const;
	void bluewon(Graphics& gfx) const;
	void greenwon(Graphics& gfx) const;
};
