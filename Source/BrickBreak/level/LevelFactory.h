#pragma once

#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"

class LevelFactory
{
public:
	LevelFactory();
	~LevelFactory();

	static Level * getLevel(int id);

private:

};