#pragma once

#include "Brick.h"

class SandLimeBrick : public Brick
{
public:
	SandLimeBrick (float startX, float startY);
	~SandLimeBrick ();

	std::string getName() override;

	void reset() override;
private:

};