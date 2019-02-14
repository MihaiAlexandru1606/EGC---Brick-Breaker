#include "Paddle.h"

const float Paddle::width = 200.0f;

const float Paddle::height = 10.0f;

const glm::vec3 Paddle::colorPaddle = glm::vec3(0.113f, 0.188f, 0.788f);

Paddle::Paddle(float startX, float startY)
{
	this->startX = startX;
	this->stratY = startY;
	this->sensivityOX = 2.0f;
	
	this->initOx = startX;
	this->initOy = startY;
}

Paddle::~Paddle()
{
}

float Paddle::getPositionX()
{
	return this->startX;
}

float Paddle::getPositionY()
{
	return this->stratY;
}

void Paddle::update(int deltaX)
{
	this->startX += this->sensivityOX * deltaX;
}

void Paddle::reset()
{
	this->startX = initOx;
	this->stratY = initOy;
}
