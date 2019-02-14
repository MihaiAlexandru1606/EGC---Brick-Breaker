#include "EngineeringBrick.h"

EngineeringBrick::EngineeringBrick(float startX, float startY):
	Brick(startX, startY)
{
	this->resistance = 7;
}

EngineeringBrick::~EngineeringBrick()
{
}

std::string EngineeringBrick::getName()
{
	return std::string("engineeringBrick");
}

void EngineeringBrick::reset()
{
	Brick::reset();
	this->resistance = 7;
}
