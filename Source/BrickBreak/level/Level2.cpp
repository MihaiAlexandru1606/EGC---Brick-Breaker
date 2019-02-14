#include "Level2.h"


Level2::Level2()
{
	creteMap();
}

int Level2::getId(int i, int j)
{
	if (j < 2) {
		return 0;
	}

	if (j < 4) {
		return 3;
	}

	if (j < 8) {
		return 4;
	}

	if (j < 10) {
		return 2;
	}

	if (j < 12) {
		return 1;
	}

	return -1;
}