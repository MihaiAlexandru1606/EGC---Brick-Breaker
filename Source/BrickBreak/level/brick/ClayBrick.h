#pragma once

#include "Brick.h"

class ClayBrick : public Brick
{
public:
	ClayBrick(float startX, float startY);
	~ClayBrick();

	std::string getName() override;

	void reset() override;

private:

};