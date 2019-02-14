#pragma once

#include "PowerUp.h"

class SuperBall : public PowerUp
{
public:
	SuperBall(float startX, float startY);
	~SuperBall();

	std::string getName() override;
	int getId() override;

private:

};