#pragma once

#include <cstdlib>     
#include <ctime> 

#include "Level.h"

//  nivelul random
class Level4 : public Level
{
public:
	Level4();
	~Level4();

private:

	int getId(int i, int j) override;
};