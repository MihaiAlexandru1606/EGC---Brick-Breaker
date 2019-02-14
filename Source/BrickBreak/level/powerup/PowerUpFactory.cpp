#include "PowerUpFactory.h"

PowerUpFactory::PowerUpFactory()
{
}

PowerUpFactory::~PowerUpFactory()
{
}

PowerUp * PowerUpFactory::getPowerUp(int id, float startX, float startY)
{
	if (id == 1) {
		return new HugeBall(startX, startY);
	}

	if (id == 3) {
		return new SuperBall(startX, startY);
	}

	if (id == 2) {
		return new ExtraLife(startX, startY);
	}

	return nullptr;
}
