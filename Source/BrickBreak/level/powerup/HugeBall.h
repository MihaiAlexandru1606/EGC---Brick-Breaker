#pragma once

#include  "PowerUp.h"

class HugeBall : public PowerUp
{
public:
	HugeBall(float startX, float startY);
	~HugeBall();

	std::string getName() override;
	int getId() override;

private:

};