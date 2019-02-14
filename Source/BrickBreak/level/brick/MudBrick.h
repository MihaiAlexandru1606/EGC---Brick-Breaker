#pragma once

#include "Brick.h"

class MudBrick : public Brick
{
public:
	MudBrick(float startX, float startY);
	~MudBrick();

	std::string getName() override;

	void reset() override;

private:

};