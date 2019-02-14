#pragma once

#include "Brick.h"

class FireBrick : public Brick
{
public:
	FireBrick(float startX, float startY);
	~FireBrick();

	std::string getName() override;

	void reset() override;

private:

};
