#pragma once

#include "Level.h"

class Level2 : public Level
{
public:
	Level2();
	~Level2();

private:

	int getId(int i, int j) override;
};