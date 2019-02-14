#pragma once

#include "Brick.h"
#include "ClayBrick.h"
#include "EngineeringBrick.h"
#include "FireBrick.h"
#include "MudBrick.h"
#include "SandLimeBrick.h"

class BrickFractory
{
public:

	BrickFractory();
	~BrickFractory();

	static Brick *getBrick(int id, float startX, float startY);

private:

};