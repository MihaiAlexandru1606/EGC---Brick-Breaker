#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <Component/SimpleScene.h>
#include <Core/Engine.h>

#include "transform2D/Transform2D.h"
#include "object2D/Object2D.h"
#include "level/wall/Wall.h"
#include "level/ball/Ball.h"
#include "level/LevelFactory.h"
#include "level/powerup/PowerUp.h"
#include "level/powerup/PowerUpFactory.h"

#include "collision/Collision.h"

#include "level/brick/BrickFactory.h"
#include "level/brick/Brick.h"


class BrickBreaker : public SimpleScene
{

public:

	BrickBreaker();
	~BrickBreaker();

	void Init() override;

private:
	const float timePowerUp = 45.0f; // timpul maxim pentru un powerups: 45s
	float timeSuperBall;   
	float timeHugeBall;   
	
	std::unique_ptr<Ball> ball;
	std::vector<Wall> walls;
	Level *level;
	std::unique_ptr<Paddle> paddle;
	std::vector<PowerUp * > powerUps;

	Level **levels;
	int currentLevel; 
	bool finish;
	void nextLevel();

	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
	
	void initBrick();
	void initWall();
	void initPaddle();
	void initBall();
	void initLevel();
	void initPowerUp();
	void initLife();

	void collision();
	
	void powerUpSistem(float deltaTimeSeconds);

	int numberLife;
	void drawLife();

	// functia  care dectecteza daca jucatorul a pierdut o viata
	float height;
	float width;
	void loseBall();

	void resetLevel();
};