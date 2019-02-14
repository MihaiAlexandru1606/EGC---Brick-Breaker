#include "ExtraLife.h"

ExtraLife::ExtraLife(float startX, float startY):
	PowerUp(startX, startY)
{
}

ExtraLife::~ExtraLife()
{
}

std::string ExtraLife::getName()
{
	return std::string("extraLife");
}

int ExtraLife::getId()
{
	return 2;
}
