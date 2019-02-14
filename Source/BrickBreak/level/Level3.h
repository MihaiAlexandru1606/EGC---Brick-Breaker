#pragma once

#include "Level.h"

class Level3 : public Level
{
public:
	Level3();
	~Level3();

private:

	int getId(int i, int j) override;
};