#include "SandLimeBrick.h"

SandLimeBrick::SandLimeBrick(float startX, float startY): 
	Brick(startX, startY)
{
	this->resistance = 5;
}

SandLimeBrick::~SandLimeBrick()
{
}

std::string SandLimeBrick::getName()
{
	return std::string("sandLimeBrick");
}

void SandLimeBrick::reset()
{
	Brick::reset();
	this->resistance = 5;
}
