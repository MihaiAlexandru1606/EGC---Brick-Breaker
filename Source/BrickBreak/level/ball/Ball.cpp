#include "Ball.h"

#include <iostream>

Ball::Ball(float positionOx, float positionOy)
{
	this->positionOx = positionOx;
	this->positionOy = positionOy;
	this->speedOx = Ball::speed * sinf(0);
	this->speedOy = Ball::speed * cosf(0);
	this->start = false;
	this->destructionBall = false;
	this->initOx = positionOx;
	this->initOy = positionOy;
}

Ball::~Ball()
{
}

void Ball::update(float deltaTimeSeconds)
{
	if (start) {
		positionOx += speedOx * deltaTimeSeconds;
		positionOy += speedOy * deltaTimeSeconds;
	}
}

float Ball::getPositionOx()
{
	return this->positionOx;
}

void Ball::setPositionOx(float x)
{
	this->positionOx = x;
}

float Ball::getPositionOy()
{
	return this->positionOy;
}

void Ball::setPositionOy(float y)
{
	this->positionOy = y;
}

float Ball::getSpeedOx()
{
	return this->speedOx;
}

void Ball::setSpeedOx(float speedOx)
{
	this->speedOx = speedOx;
}

float Ball::getSpeedOy()
{
	return this->speedOy;
}

bool Ball::getStart()
{
	return this->start;
}

void Ball::startBall()
{
	this->start = true;
}

void Ball::activHugeBall()
{
	this->destructionBall = true;
}

void Ball::stopHugeBall()
{
	this->destructionBall = false;
}

bool Ball::isHugeBall()
{
	return this->destructionBall;
}

void Ball::resetBall()
{
	this->positionOx = this->initOx;
	this->positionOy = this->initOy;
	this->start = false;
	this->speedOx = Ball::speed * sinf(0);
	this->speedOy = Ball::speed * cosf(0);
}

void Ball::setSpeedOy(float speedOy)
{
	this->speedOy = speedOy;
}

const glm::vec3 Ball::colorBall = glm::vec3(1, 1, 0);
const float Ball::radius = 11.0f;
const float Ball::speed = 320.0f;