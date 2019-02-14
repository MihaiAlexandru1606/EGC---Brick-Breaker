#include "ClayBrick.h"

ClayBrick::ClayBrick(float startX, float startY) : 
	Brick(startX, startY)
{
	this->resistance = 2;
}

ClayBrick::~ClayBrick()
{
}

std::string ClayBrick::getName()
{
	return std::string("clayBrick");
}

void ClayBrick::reset()
{
	Brick::reset();
	this->resistance = 2;
}

