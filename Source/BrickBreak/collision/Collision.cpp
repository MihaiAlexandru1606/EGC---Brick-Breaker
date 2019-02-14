#include "Collision.h"

void Collision::checkCollisionBallBrick(Ball &ball, Brick &brick)
{
	bool collision = checkColision(ball.getPositionOx(), ball.getPositionOy(), ball.radius,
		brick.getPositionX(), brick.getPositionY(), Brick::height, Brick::width);
	
	if (collision) {
		brick.collision();
		
		if (isInInterval(ball.getPositionOx(), brick.getPositionX(), brick.getPositionX() + Brick::width) ||
			isInInterval(ball.getPositionOx() - ball.radius / 2, brick.getPositionX(), brick.getPositionX() + Brick::width) ||
			isInInterval(ball.getPositionOx() + ball.radius / 2, brick.getPositionX(), brick.getPositionX() + Brick::width)
			) {
			if (!ball.isHugeBall()) {
				ball.setSpeedOy(-ball.getSpeedOy());
			}
			
		}

		if (isInInterval(ball.getPositionOy(), brick.getPositionY(), brick.getPositionY() + Brick::height) ||
			isInInterval(ball.getPositionOy() - ball.radius / 2, brick.getPositionY(), brick.getPositionY() + Brick::height) ||
			isInInterval(ball.getPositionOy() + ball.radius / 2, brick.getPositionY(), brick.getPositionY() + Brick::height)
			) {
			if (!ball.isHugeBall()) {
				ball.setSpeedOx(-ball.getSpeedOx());
			}
		}
	}
}

void Collision::checkCollisionBallWall(Ball & ball, Wall & wall)
{
	bool collision = checkColision(ball.getPositionOx(), ball.getPositionOy(), ball.radius,
		wall.getPositionX(), wall.getPositionY(), wall.getHeight(), wall.getWidth());

	if (collision) {
		bool collisonOx = false;

		if (isInInterval(ball.getPositionOx(), wall.getPositionX(), wall.getPositionX() + wall.getWidth())) {
			ball.setSpeedOy(-ball.getSpeedOy());	
			collisonOx = true;
		}

		if (isInInterval(ball.getPositionOy(), wall.getPositionY(), wall.getPositionY() + wall.getHeight())) {
			ball.setSpeedOx(-ball.getSpeedOx());
		}

		if (wall.getHeight() == 20.0f) {
			ball.setPositionOy(wall.getPositionY() - Ball::radius);
			return;
		}

		if (collisonOx) {
			return;
		}

		// peretele din stanga
		if (wall.getPositionX() == 0.0f) {
			ball.setPositionOx(wall.getWidth() + Ball::radius);
			return;
		}

		// peretele din dreapta
		ball.setPositionOx(wall.getPositionX() - Ball::radius);
	}
}

void Collision::checkCollisionBallPaddle(Ball & ball, Paddle & paddle)
{
	bool collision = checkColision(ball.getPositionOx(), ball.getPositionOy(), ball.radius,
		paddle.getPositionX(), paddle.getPositionY(), Paddle::height, Paddle::width);

	if (collision) {
		if (ball.getPositionOx() >= paddle.getPositionX()
			&& ball.getPositionOx() <= (paddle.getPositionX() + Paddle::width)) {
			// calculare unghiului de reflexie
			float x = ball.getPositionOx() - paddle.getPositionX();
			x /= (Paddle::width /2);
			x -= 1;
			float angle = acos(x);
			
			ball.setSpeedOx(cosf(angle) * Ball::speed);
			ball.setSpeedOy(sinf(angle) * Ball::speed);
		}
		else {
			ball.setSpeedOx(-ball.getSpeedOx());
			ball.setSpeedOy(-ball.getSpeedOy());
		}
	}
}

int Collision::checkCollisionPaddlePowerUp(Paddle & paddle, PowerUp & powerUp)
{
	bool collision = checkColision(powerUp.getPositionOx(), powerUp.getPositionOy(), powerUp.size / 2,
		paddle.getPositionX(), paddle.getPositionY(), Paddle::height, Paddle::width);

	if (collision) {
		powerUp.collision();
		return powerUp.getId();
	}

	return 0;
}


