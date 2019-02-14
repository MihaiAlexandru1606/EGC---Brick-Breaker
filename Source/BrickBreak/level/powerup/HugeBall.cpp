#include "HugeBall.h"

HugeBall::HugeBall(float startX, float startY):
	PowerUp(startX, startY)
{
}

HugeBall::~HugeBall()
{
}

std::string HugeBall::getName()
{
	return std::string("pHugeBall");
}

int HugeBall::getId()
{
	return 1;
}
