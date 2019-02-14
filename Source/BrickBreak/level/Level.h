#pragma once

#include <vector>
#include <memory>

#include "ball/Ball.h"
#include "paddle/Paddle.h"
#include "wall/Wall.h"
#include "brick/Brick.h"
#include "brick/BrickFactory.h"


class Level
{
public:
	Level();
	~Level();

	// numarul maxim de niveluri
	static const int maxLevel;

	std::vector<Brick *> getBricks();

	// functia resetrza nivelul
	void reset();

protected:
	std::vector<Brick *> bricks;

	const float startOy = 250.0f;
	const float startOx = 220.0f;
	const float space = 10.0f;

	const float numberBrickOx = 12;
	const float numberBrickOy = 10;

	// intializare celor 10 x 12 careamizi
	// pentru fiecare nivel va fi alt model 
	//acest lucru este reusit cu ajutorul functiei : getId
	void creteMap();

	// functia ajutatoare pentru creare de modelul de caramizi
	virtual int getId(int i, int j);
};