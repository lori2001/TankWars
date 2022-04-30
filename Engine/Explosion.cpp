#include "Explosion.h"

void Explosion::Draw(Graphics& gfx) const

{
	gfx.PutPixel(2 + x, 7 + y, 252, 224, 18);
	gfx.PutPixel(3 + x, 7 + y, 252, 224, 18);
	gfx.PutPixel(4 + x, 7 + y, 250, 224, 18);
	gfx.PutPixel(5 + x, 7 + y, 250, 227, 18);
	gfx.PutPixel(6 + x, 7 + y, 239, 239, 15);
	gfx.PutPixel(7 + x, 7 + y, 255, 255, 0);
	gfx.PutPixel(1 + x, 8 + y, 250, 225, 17);
	gfx.PutPixel(2 + x, 8 + y, 247, 224, 15);
	gfx.PutPixel(3 + x, 8 + y, 246, 214, 12);
	gfx.PutPixel(4 + x, 8 + y, 247, 210, 11);
	gfx.PutPixel(5 + x, 8 + y, 247, 215, 13);
	gfx.PutPixel(6 + x, 8 + y, 246, 227, 18);
	gfx.PutPixel(7 + x, 8 + y, 251, 225, 18);
	gfx.PutPixel(1 + x, 9 + y, 250, 226, 18);
	gfx.PutPixel(2 + x, 9 + y, 251, 209, 13);
	gfx.PutPixel(3 + x, 9 + y, 253, 195, 8);
	gfx.PutPixel(4 + x, 9 + y, 253, 192, 8);
	gfx.PutPixel(5 + x, 9 + y, 253, 190, 9);
	gfx.PutPixel(6 + x, 9 + y, 253, 186, 8);
	gfx.PutPixel(7 + x, 9 + y, 253, 194, 8);
	gfx.PutPixel(8 + x, 9 + y, 252, 212, 14);
	gfx.PutPixel(9 + x, 9 + y, 255, 170, 0);
	gfx.PutPixel(1 + x, 10 + y, 251, 225, 17);
	gfx.PutPixel(2 + x, 10 + y, 254, 200, 10);
	gfx.PutPixel(3 + x, 10 + y, 255, 146, 4);
	gfx.PutPixel(4 + x, 10 + y, 255, 97, 3);
	gfx.PutPixel(5 + x, 10 + y, 255, 95, 3);
	gfx.PutPixel(6 + x, 10 + y, 255, 138, 4);
	gfx.PutPixel(7 + x, 10 + y, 254, 182, 5);
	gfx.PutPixel(8 + x, 10 + y, 252, 204, 12);
	gfx.PutPixel(9 + x, 10 + y, 251, 225, 18);
	gfx.PutPixel(0 + x, 11 + y, 251, 225, 17);
	gfx.PutPixel(1 + x, 11 + y, 251, 224, 17);
	gfx.PutPixel(2 + x, 11 + y, 254, 194, 8);
	gfx.PutPixel(3 + x, 11 + y, 255, 121, 4);
	gfx.PutPixel(4 + x, 11 + y, 255, 83, 3);
	gfx.PutPixel(5 + x, 11 + y, 255, 84, 3);
	gfx.PutPixel(6 + x, 11 + y, 254, 128, 5);
	gfx.PutPixel(7 + x, 11 + y, 253, 191, 8);
	gfx.PutPixel(8 + x, 11 + y, 251, 217, 16);
	gfx.PutPixel(9 + x, 11 + y, 251, 225, 17);
	gfx.PutPixel(0 + x, 12 + y, 251, 224, 18);
	gfx.PutPixel(1 + x, 12 + y, 251, 224, 17);
	gfx.PutPixel(2 + x, 12 + y, 254, 196, 9);
	gfx.PutPixel(3 + x, 12 + y, 255, 155, 4);
	gfx.PutPixel(4 + x, 12 + y, 255, 101, 3);
	gfx.PutPixel(5 + x, 12 + y, 255, 108, 4);
	gfx.PutPixel(6 + x, 12 + y, 254, 174, 6);
	gfx.PutPixel(7 + x, 12 + y, 252, 205, 12);
	gfx.PutPixel(8 + x, 12 + y, 251, 225, 18);
	gfx.PutPixel(9 + x, 12 + y, 251, 225, 18);
	gfx.PutPixel(1 + x, 13 + y, 251, 223, 17);
	gfx.PutPixel(2 + x, 13 + y, 251, 209, 16);
	gfx.PutPixel(3 + x, 13 + y, 253, 203, 12);
	gfx.PutPixel(4 + x, 13 + y, 254, 189, 10);
	gfx.PutPixel(5 + x, 13 + y, 254, 180, 9);
	gfx.PutPixel(6 + x, 13 + y, 252, 196, 11);
	gfx.PutPixel(7 + x, 13 + y, 251, 217, 16);
	gfx.PutPixel(8 + x, 13 + y, 251, 224, 17);
	gfx.PutPixel(2 + x, 14 + y, 251, 220, 18);
	gfx.PutPixel(3 + x, 14 + y, 250, 221, 18);
	gfx.PutPixel(4 + x, 14 + y, 251, 224, 18);
	gfx.PutPixel(5 + x, 14 + y, 251, 224, 18);
	gfx.PutPixel(6 + x, 14 + y, 250, 223, 18);
	gfx.PutPixel(7 + x, 14 + y, 251, 224, 18);
	gfx.PutPixel(2 + x, 15 + y, 251, 225, 18);
	gfx.PutPixel(3 + x, 15 + y, 250, 226, 17);
	gfx.PutPixel(4 + x, 15 + y, 250, 225, 18);
	gfx.PutPixel(5 + x, 15 + y, 250, 225, 18);
	gfx.PutPixel(6 + x, 15 + y, 251, 226, 18);
	gfx.PutPixel(7 + x, 15 + y, 251, 224, 16);
	gfx.PutPixel(9 + x, 15 + y, 255, 255, 0);
}