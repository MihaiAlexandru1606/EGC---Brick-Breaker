#include "Level.h"

const int Level::maxLevel = 4;

Level::Level()
{
}

Level::~Level()
{
}

std::vector<Brick *> Level::getBricks()
{
	return bricks;
}

void Level::creteMap()
{
	for (int i = 0; i < numberBrickOy; i++) {
		for (int j = 0; j < numberBrickOx; j++) {
			int id = this->getId(i, j);
			float x = startOx + j * (space + Brick::width);
			float y = startOy + i * (space + Brick::height);
			Brick *brick = BrickFractory::getBrick(id, x, y);

			if (brick == nullptr) {
				continue;
			}

			bricks.push_back(brick);
		}
	}
}

int Level::getId(int i, int j)
{
	return 0;
}

void Level::reset()
{
	for (Brick *brick : this->bricks) {
		brick->reset();
	}
}
