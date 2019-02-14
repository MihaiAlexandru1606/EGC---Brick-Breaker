#pragma once

#include "PowerUp.h"
#include "HugeBall.h"
#include "ExtraLife.h"
#include "SuperBall.h"

class PowerUpFactory
{
public:
	PowerUpFactory();
	~PowerUpFactory();

	static PowerUp * getPowerUp(int id, float startX, float startY);

private:

};