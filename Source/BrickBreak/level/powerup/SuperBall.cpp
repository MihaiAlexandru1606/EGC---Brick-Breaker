#include "SuperBall.h"

SuperBall::SuperBall(float startX, float startY):
	PowerUp(startX, startY)
{
}

SuperBall::~SuperBall()
{
}

std::string SuperBall::getName()
{
	return std::string("pSuperBall");
}

int SuperBall::getId()
{
	return 3;
}
