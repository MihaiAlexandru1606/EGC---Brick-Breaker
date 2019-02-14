#include "Level3.h"


Level3::Level3()
{
	creteMap();
}

int Level3::getId(int i, int j)
{
	if (i < 5 && j < 4) {
		return 2;
	}

	if (i < 5 && j > 7) {
		return 1;
	}
	
	if (i > 4 && j < 4) {
		return 3;
	}

	if (i > 4 && j > 7) {
		return 0;
	}

	if (j > 3 && j < 8) {
		return 4;
	}

	return -1;
}