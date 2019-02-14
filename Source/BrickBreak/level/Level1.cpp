#include "Level1.h"

Level1::Level1()
{
	creteMap();
}

int Level1::getId(int i, int j)
{
	if (i < 2 || i > 7 || j < 2 || j > 9) {
		return 0;
	}

	if (i < 4 || i > 5 || j < 4 || j > 7) {
		return 1;
	}

	if (j == 4) {
		return 2;
	}

	if (j == 5 || j == 6) {
		return 4;
	}

	if (j == 7) {
		return 3;
	}

	return -1;
}
