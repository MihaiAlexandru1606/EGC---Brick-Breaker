#include "Brick.h"

Brick::Brick(float startX, float startY) : 
	startX(startX), 
	startY(startY), 
	scaleX{ 1 }, 
	scaleY{ 1 },
	resistance{ 0 },
	superBall{ false }
{
}

Brick::~Brick()
{
}

float Brick::getPositionX()
{
	return this->startX;
}

float Brick::getPositionY()
{
	return this->startY;
}

float Brick::getScaleX()
{
	return this->scaleX;
}

float Brick::getScaleY()
{
	return this->scaleY;
}

int Brick::getResistence()
{
	return this->resistance;
}

void Brick::collision()
{
	if (superBall) {
		this->resistance = 0;
	}
	else {
		this->resistance--;
	}
}

void Brick::update(float deltaTimeSeconds)
{
	if (this->resistance <= 0) {
		this->scaleX -= deltaTimeSeconds;
		this->scaleY -= deltaTimeSeconds;
	}
}

// generarea random a powerUp-urilor
int Brick::genrateId()
{
	srand((unsigned int)time(NULL));

	int random = rand();
	if (random % 2 == 0) {
		random = rand();
		
		return random % 4;
	}
	return 0;
}

void Brick::activSuperball()
{
	this->superBall = true;
}

void Brick::stopSuperBall()
{
	this->superBall = false;
}

void Brick::reset()
{
	this->scaleX = 1.0f;
	this->scaleY = 1.0f;
}


// initilizare dimensiunile 
const float Brick::width = 60.0f;
const float Brick::height = 30.0f;

// initilizare culorilor
const glm::vec3 Brick::colorClayBrick = glm::vec3(1.0f, 0.38f, 0);
const glm::vec3 Brick::colorMudBrick = glm::vec3(0.564705f, 0.42352f, 0.24705f);
const glm::vec3 Brick::colorFireBrick = glm::vec3(0.69f, 0.0f, 0.0f);
const glm::vec3 Brick::colorSandLimeBrick = glm::vec3(0.296803f, 0.274509f, 0.196078f);
const glm::vec3 Brick::colorEngineeringBrick = glm::vec3(0.00392f, 0.45098f, 0.317647f);
