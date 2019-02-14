#include "Level4.h"


Level4::Level4()
{
	creteMap();
}

int Level4::getId(int i, int j)
{
	srand((unsigned int)time(NULL));
	int rand1 = rand();

	srand((unsigned int)i * i);
	int rand2 = rand();

	srand((unsigned int)j * j);
	int rand3 = rand();

	srand((unsigned int)i * j);
	int rand4 = rand();

	return ((rand1 + 1) * (rand2 + 42) + (rand3 << 7) + (rand4 << 10) % 100)  % 5;
}