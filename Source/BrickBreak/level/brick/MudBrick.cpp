#include "MudBrick.h"

MudBrick::MudBrick(float startX, float startY):
	Brick(startX, startY)
{
	this->resistance = 1;
}

MudBrick::~MudBrick()
{
}

std::string MudBrick::getName()
{
	return std::string("mudBrick");
}

void MudBrick::reset()
{
	Brick::reset();

	this->resistance = 1;
}
