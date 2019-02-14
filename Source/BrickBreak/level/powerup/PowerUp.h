#pragma once

#include <string>

#include <Core/Engine.h>

class PowerUp
{
public:
	static const float size;
	static const glm::vec3 colorSuperBall;
	static const glm::vec3 colorHugeBall;
	static const glm::vec3 colorExtraLife;

	PowerUp(float startX, float startY);
	~PowerUp();

	void update(float deltaTimeSeconds);
	void collision();

	float getPositionOx();
	float getPositionOy();
	float getAngle();
	float isUsed();

	virtual std::string getName();
	virtual int getId();

protected:
	float startX;
	float startY;
	float angle;
	bool used;

	const float speed = 200.0f;
	const float angleStep = 10.0f;
};