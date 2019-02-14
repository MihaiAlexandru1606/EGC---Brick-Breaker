#pragma once

#include <string>
#include <cstdlib>
#include <ctime>

#include <Core/Engine.h>

class Brick
{
public:
	// dimensiunile unei caramizi
	static const float width;
	static const float height;

	// culoarile pentru fiecare tip de caramida
	static const glm::vec3 colorClayBrick;
	static const glm::vec3 colorMudBrick;
	static const glm::vec3 colorFireBrick;
	static const glm::vec3 colorSandLimeBrick;
	static const glm::vec3 colorEngineeringBrick;

	Brick(float startX = 0.0f, float startY = 0.0f);
	~Brick();

	virtual std::string getName() {
		return std::string("cevaNull");
	}

	float getPositionX();
	float getPositionY();

	float getScaleX();
	float getScaleY();

	int getResistence();
	void collision();

	// functia care actializa starea unei caramizi
	void update(float deltaTimeSeconds);
	// functia genereaza id-ul unui power-up
	int genrateId();

	// functile care indica daca mingia "a primit o putere speciala"
	void activSuperball();
	void stopSuperBall();
	
	// functia folosita pentru fresetarea unui nivel
	virtual void reset();

protected:
	float startX;
	float startY;
	float scaleX;
	float scaleY;
	int resistance; // numarul maxim de "lovituri" suportate de o caramida

	// pentru fiecare powerUp
	bool superBall;
};
