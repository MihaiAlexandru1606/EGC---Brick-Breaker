#pragma once

#include <Core/Engine.h>

class Paddle
{
public:
	static const float width;
	static const float height;
	static const glm::vec3 colorPaddle;

	Paddle(float startX, float startY);
	~Paddle();

	float getPositionX();
	float getPositionY();
	
	// functia relizare miscare platformei
	void update(int deltaX);

	// functia care reseteza platforma
	void reset();

private:
	float startX;
	float stratY;

	float sensivityOX;

	// retinerea pozitilor initiale
	float initOx;
	float initOy;
};
