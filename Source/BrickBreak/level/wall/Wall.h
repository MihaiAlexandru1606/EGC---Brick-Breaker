#pragma once

#include <Core/Engine.h>

class Wall
{
public:
	
	static const glm::vec3 colorWall;

	Wall(float startX, float startY, float width, float height);
	~Wall();

	float getPositionX();
	float getPositionY();

	float getHeight();
	float getWidth();

private:
	
	float startX;
	float startY;
	float width;
	float height;

};
