#pragma once

#include "Level.h"

class Level1 : public Level
{
public:
	Level1 ();
	~Level1 ();

private:

	int getId(int i, int j) override;
};