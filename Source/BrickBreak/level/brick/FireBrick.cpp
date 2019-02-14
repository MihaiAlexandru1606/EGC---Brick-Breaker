#include "FireBrick.h"

FireBrick::FireBrick(float startX, float startY):
	Brick(startX, startY)
{
	this->resistance = 4;
}

FireBrick::~FireBrick()
{
}

std::string FireBrick::getName()
{
	return std::string("fireBrick");
}

void FireBrick::reset()
{
	Brick::reset();

	this->resistance = 4;
}
