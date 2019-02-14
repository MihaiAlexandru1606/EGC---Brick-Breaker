#include "Wall.h"

const glm::vec3 Wall::colorWall = glm::vec3(0.75f, 0.75f, 0.75f);

Wall::Wall(float startX, float startY, float width, float height) :
	startX(startX), startY(startY), width(width), height(height)
{
}

Wall::~Wall()
{
}

float Wall::getPositionX()
{
	return this->startX;
}

float Wall::getPositionY()
{
	return this->startY;
}

float Wall::getHeight()
{
	return this->height;
}

float Wall::getWidth()
{
	return this->width;
}
