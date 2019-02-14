#pragma once

#include "PowerUp.h"

class ExtraLife : public PowerUp
{
public:
	ExtraLife(float startX, float startY);
	~ExtraLife();

	std::string getName() override;
	int getId() override;

private:

};