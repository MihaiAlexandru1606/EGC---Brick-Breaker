#include "BrickFactory.h"

BrickFractory::BrickFractory()
{
}

BrickFractory::~BrickFractory()
{
}

Brick * BrickFractory::getBrick(int id, float startX, float startY)
{
	if (id == 0) {
		return new MudBrick(startX, startY);
	}

	if (id == 1) {
		return new ClayBrick(startX, startY);
	}

	if (id == 2) {
		return new FireBrick(startX, startY);
	}

	if (id == 3) {
		return new SandLimeBrick(startX, startY);
	}

	if (id == 4) {
		return new EngineeringBrick(startX, startY);
	}
	return nullptr; // nu se intampla
}