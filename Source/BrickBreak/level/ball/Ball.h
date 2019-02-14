#pragma once

#include <Core/Engine.h>

class Ball
{
public:
	static const glm::vec3 colorBall;
	static const float radius;
	static const float speed;

	Ball(float positionOx = 0.0f, float positionOy = 0.0f);
	~Ball();

	void update(float deltaTimeSeconds);

	float getPositionOx();
	void setPositionOx(float x);

	float getPositionOy();
	void setPositionOy(float y);

	float getSpeedOx();
	void setSpeedOx(float speedOx);

	void setSpeedOy(float speedOx);
	float getSpeedOy();

	bool getStart();
	void startBall();

	// folosite pentru powerUp: HugeBall
	void activHugeBall();
	void stopHugeBall();

	bool isHugeBall();

	// reseteaza mingia in starea initial
	void resetBall();
	
private:
	float positionOx;
	float positionOy;
	float speedOx;
	float speedOy;

	// variala indica daca bila s-a desprins de platforma
	bool start;
	// variala folosita in caz de powerUp: HugeBall
	bool destructionBall;

	// retinea pozitilor initilale
	float initOx;
	float initOy;
};
