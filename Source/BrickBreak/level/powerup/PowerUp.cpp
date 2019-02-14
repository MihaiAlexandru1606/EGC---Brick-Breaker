#include "PowerUp.h"

const float PowerUp::size = 10.0f;

// culorile pentru powerup-uri
const glm::vec3 PowerUp::colorSuperBall = glm::vec3(0.2352941f, 0.078431f, 0.31764705f);
const glm::vec3 PowerUp::colorHugeBall = glm::vec3(0.0f, 1.0f, 1.0f);
const glm::vec3 PowerUp::colorExtraLife = glm::vec3(0.3215686f, 0.8784431372f, 0.0f);

PowerUp::PowerUp(float startX, float startY)
{
	this->startX = startX;
	this->startY = startY;
	this->angle = 0.0f;
	this->used = false;
}

PowerUp::~PowerUp()
{
}

void PowerUp::update(float deltaTimeSeconds)
{
	this->angle += this->angleStep * deltaTimeSeconds;
	this->startY -= this->speed * deltaTimeSeconds;
}

void PowerUp::collision()
{
	this->used = true;
}

float PowerUp::getPositionOx()
{
	return this->startX;
}

float PowerUp::getPositionOy()
{
	return this->startY;
}

float PowerUp::getAngle()
{
	return this->angle;
}

float PowerUp::isUsed()
{
	return this->used;
}

std::string PowerUp::getName()
{
	return std::string("cevaNull");
}

int PowerUp::getId()
{
	return 0;
}
