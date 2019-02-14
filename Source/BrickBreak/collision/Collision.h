#pragma once

#include <cmath>
#include <cstdbool>

#include <iostream>

#include <BrickBreak/level/ball/Ball.h>
#include <BrickBreak/level/brick/Brick.h>
#include <BrickBreak/level/wall/Wall.h>
#include <BrickBreak/level/paddle/Paddle.h>
#include <BrickBreak/level/powerup/PowerUp.h>

namespace Collision 
{
	namespace {

		// verifica daca un cerc si un dreptungi se intersecteaza
		inline bool checkColision(float cx, float cy, float radius, float sx, float sy, float height, float width) {
			float x, y;
			
			// cel mai apropriat punct fata de cx pe Ox apartinand dreptungiului
			if (cx < sx) {
				x = sx;
			}
			else if (cx > sx + width) {
				x = sx + width;
			}
			else
			{
				x = cx;
			}

			// cel mai apropriat punct fata de cy pe Oy apartinand dreptungiului
			if (cy < sy) {
				y = sy;
			}
			else if (cy > sy + height) {
				y = sy + height;
			}
			else
			{
				y = cy;
			}

			// verificare daca apartine cercului
			return ((x - cx) * (x - cx) + (y - cy) * (y - cy)) <= (radius * radius);
		}

		// verifica daca a aprtine (x, y)
		inline bool isInInterval(float a, float x, float y) {
			if (x < a && a < y)
				return true;

			return false;
		}

	}

	// verifica colisiunea dintre mingie si caramida
	void checkCollisionBallBrick(Ball &ball, Brick &brick);

	// verifica colisiunea dintre mingie si zid
	void checkCollisionBallWall(Ball &ball, Wall &wall);

	// verifica colisiunea dintre mingie si platforma
	void checkCollisionBallPaddle(Ball &ball, Paddle &paddle);

	// verifica colisiune dintre powerup si platfoma
	// returneza tipul powerUp care s-a ciocnit
	int checkCollisionPaddlePowerUp(Paddle &paddle, PowerUp &powerup);
}