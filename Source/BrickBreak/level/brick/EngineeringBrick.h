#pragma once

#include "Brick.h"

class EngineeringBrick : public Brick
{
public:
	EngineeringBrick(float startX, float startY);
	~EngineeringBrick();

	std::string getName() override;
	
	void reset() override;

private:

};
