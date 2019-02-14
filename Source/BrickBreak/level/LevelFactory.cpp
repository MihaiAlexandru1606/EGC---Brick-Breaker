#include "LevelFactory.h"

LevelFactory::LevelFactory()
{
}

LevelFactory::~LevelFactory()
{
}

Level * LevelFactory::getLevel(int id)
{
	if (id == 1) {
		return new Level1();
	}

	if (id == 2) {
		return new Level2();
	}

	if (id == 3) {
		return new Level3();
	}

	if (id == 4) {
		return new Level4();
	}

	return nullptr;
}
