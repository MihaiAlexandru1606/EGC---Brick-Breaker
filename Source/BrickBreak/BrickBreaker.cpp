#include "BrickBreaker.h"

BrickBreaker::BrickBreaker()
{
}

BrickBreaker::~BrickBreaker()
{
}

void BrickBreaker::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
	
	this->height = (float)resolution.y;
	this->width = (float)resolution.x;

	// crearea de mesh-urilor
	glm::vec3 corner = glm::vec3(0, 0, 0);
	
	initBrick();
	initWall();
	initPaddle();
	initBall();
	initPowerUp();
	initLevel();
	initLife();
}

void BrickBreaker::initBrick()
{
	glm::vec3 corner;

	// crearea fiecarui tip de caramida:
	corner = glm::vec3(-Brick::width / 2, -Brick::height / 2, 0);
	Mesh *clayBrick = Object2D::createRectangle("clayBrick", corner, Brick::height, Brick::width, Brick::colorClayBrick);
	Mesh *mudBrick = Object2D::createRectangle("mudBrick", corner, Brick::height, Brick::width, Brick::colorMudBrick);
	Mesh *fireBrick = Object2D::createRectangle("fireBrick", corner, Brick::height, Brick::width, Brick::colorFireBrick);
	Mesh *sandLimeBrick = Object2D::createRectangle("sandLimeBrick", corner, Brick::height, Brick::width, Brick::colorSandLimeBrick);
	Mesh *engineeringBrick = Object2D::createRectangle("engineeringBrick", corner, Brick::height, Brick::width, Brick::colorEngineeringBrick);

	AddMeshToList(clayBrick);
	AddMeshToList(mudBrick);
	AddMeshToList(fireBrick);
	AddMeshToList(sandLimeBrick);
	AddMeshToList(engineeringBrick);
}

void BrickBreaker::initWall()
{
	// initililiare peretilor
	this->walls.push_back(Wall(0.0f, 700.0f, 1280.0f, 20.0f));  // sus
	this->walls.push_back(Wall(0.0f, 60.0f, 20.0f, 660.0f));    // stanga
	this->walls.push_back(Wall(1260.0f, 60.0f, 20.0f, 660.0f)); // dreapta

	glm::vec3 corner = glm::vec3(0, 0, 0);
	//crearea "zidurilor"
	Mesh *wall = Object2D::createRectangle("wall", corner, 1, 1, Wall::colorWall);
	AddMeshToList(wall);
}

void BrickBreaker::initPaddle()
{
	glm::ivec2 resolution = window->GetResolution();
	glm::vec3 corner = glm::vec3(0, 0, 0);

	this->paddle = std::make_unique<Paddle>(((float)resolution.x - Paddle::width) / 2, 15.0f);
	// crearea platformei
	Mesh *paddle = Object2D::createRectangle("paddle", corner, Paddle::height, Paddle::width, Paddle::colorPaddle);
	AddMeshToList(paddle);
}

void BrickBreaker::initBall()
{
	glm::ivec2 resolution = window->GetResolution();
	glm::vec3 corner = glm::vec3(0, 0, 0);

	this->ball = std::make_unique<Ball>(((float)resolution.x - Ball::radius) / 2, 30.0f + Ball::radius);
	// creare mingie
	Mesh *ball = Object2D::createCircel("ball", corner, Ball::radius, Ball::colorBall);
	AddMeshToList(ball);

	// tipul de mingii pentru fiecare powerUp
	Mesh *superBall = Object2D::createCircel("superBall", corner, Ball::radius, PowerUp::colorSuperBall);
	AddMeshToList(superBall);
	Mesh *hugeBall = Object2D::createCircel("hugeBall", corner, Ball::radius, PowerUp::colorHugeBall);
	AddMeshToList(hugeBall);

}

void BrickBreaker::initLevel()
{
	this->levels = new Level*[Level::maxLevel];
	for (int i = 0; i < Level::maxLevel; i++) {
		levels[i] = LevelFactory::getLevel(i + 1);
	}
	currentLevel = 0;
	level = levels[currentLevel];
	finish = false;
}

void BrickBreaker::initPowerUp()
{
	glm::vec3 corner = glm::vec3(-PowerUp::size / 2, -PowerUp::size / 2, 0);
	this->timeSuperBall = 0;
	this->timeHugeBall = 0;

	Mesh *pSuperBall = Object2D::createSquare("pSuperBall", corner, PowerUp::size, PowerUp::colorSuperBall);
	Mesh *pHugeBall = Object2D::createSquare("pHugeBall", corner, PowerUp::size, PowerUp::colorHugeBall);
	Mesh *extraLife = Object2D::createSquare("extraLife", corner, PowerUp::size, PowerUp::colorExtraLife);

	AddMeshToList(pSuperBall);
	AddMeshToList(pHugeBall);
	AddMeshToList(extraLife);
}

void BrickBreaker::initLife()
{
	// crearea "vietiilor"
	glm::vec3 corner = glm::vec3(0, 0, 0);
	this->numberLife = 3;

	Mesh *life = Object2D::createCircel("life", corner, Ball::radius - 2, glm::vec3(1, 0, 0));
	AddMeshToList(life);
}

void BrickBreaker::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

}

void BrickBreaker::Update(float deltaTimeSeconds)
{
	resetLevel();
	loseBall();
	drawLife();
	powerUpSistem(deltaTimeSeconds);
	ball->update(deltaTimeSeconds);
	collision();

	glm::mat3 modelMatrix;

	// reprezentarea peretilor
	for (Wall &wall : this->walls) {
		float x = wall.getPositionX();
		float y = wall.getPositionY();
		float width = wall.getWidth();
		float height = wall.getHeight();

		modelMatrix = Transform2D::Translate(x, y) * Transform2D::Scale(width, height);
		RenderMesh2D(meshes["wall"], shaders["VertexColor"], modelMatrix);
	}

	// reperezentarea caramizilor 
	for (Brick *brick : level->getBricks()) {
		brick->update(2 * deltaTimeSeconds);
		float x = brick->getPositionX();
		float y = brick->getPositionY();
		float scaleX = brick->getScaleX();
		float scaleY = brick->getScaleY();

		if (scaleX > 0 && scaleY > 0) {
			modelMatrix = Transform2D::Translate(x + Brick::width/2, y + Brick::height/2);
			modelMatrix *= Transform2D::Scale(scaleX, scaleY);
			RenderMesh2D(meshes[brick->getName()], shaders["VertexColor"], modelMatrix);
		}
	}

	// reprezentarea platformei
	modelMatrix = Transform2D::Translate(paddle->getPositionX(), paddle->getPositionY());
	RenderMesh2D(meshes["paddle"], shaders["VertexColor"], modelMatrix);

	if (!this->ball->getStart()) {
		float x = paddle->getPositionX() + Paddle::width / 2;
		ball->setPositionOx(x);
		modelMatrix = Transform2D::Translate(x, ball->getPositionOy());
	}
	else {
		modelMatrix = Transform2D::Translate(ball->getPositionOx(), ball->getPositionOy());
	}
	if (timeSuperBall > 0) {
		RenderMesh2D(meshes["superBall"], shaders["VertexColor"], modelMatrix);
	}
	else if (timeHugeBall > 0) {
		RenderMesh2D(meshes["hugeBall"], shaders["VertexColor"], modelMatrix);
	}
	else {
		RenderMesh2D(meshes["ball"], shaders["VertexColor"], modelMatrix);
	}

	// reprezentare a powerUp-urilor
	for (PowerUp *powerUp : this->powerUps) {
		if (powerUp->isUsed()) {
			continue;
		}
		powerUp->update(deltaTimeSeconds);
		float x = powerUp->getPositionOx();
		float y = powerUp->getPositionOy();
		float angle = powerUp->getAngle();

		modelMatrix = Transform2D::Translate(x + PowerUp::size / 2, y + PowerUp::size / 2);
		modelMatrix *= Transform2D::Rotate(angle);
		RenderMesh2D(meshes[powerUp->getName()], shaders["VertexColor"], modelMatrix);
	}

	nextLevel();
}

void BrickBreaker::FrameEnd()
{
}

void BrickBreaker::OnInputUpdate(float deltaTime, int mods)
{
}

void BrickBreaker::OnKeyPress(int key, int mods)
{
}

void BrickBreaker::OnKeyRelease(int key, int mods)
{
}

void BrickBreaker::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	this->paddle->update(deltaX);
}

void BrickBreaker::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT) {
		ball->startBall();
	}
}

void BrickBreaker::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void BrickBreaker::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void BrickBreaker::OnWindowResize(int width, int height)
{
}


void BrickBreaker::collision()
{
	if (timeHugeBall > 0 ) {
		ball->activHugeBall();
	}
	else {
		ball->stopHugeBall();
	}

	// verificam daca s-a terminat nivelul curent
	finish = true;
	for (Brick *brick : level->getBricks()) {
		if (brick->getResistence() > 0) {
			finish = false;
			if (this->timeSuperBall > 0 || this->timeHugeBall > 0) {
				brick->activSuperball();
			}
			else {
				brick->stopSuperBall();
			}

			Collision::checkCollisionBallBrick(*ball, *brick);
			if (brick->getResistence() == 0) {
				// a  fost distrusa o caramida
				int id = brick->genrateId();
				if (id == 0) {
					continue;
				}
				PowerUp *powerUp = PowerUpFactory::getPowerUp(id, brick->getPositionX() + Brick::width / 2,
					brick->getPositionY() + Brick::height / 2);
				if (powerUp == nullptr) {
					continue;
				}
				powerUps.push_back(powerUp);
			}
		}
	}

	for (Wall &wall : walls) {
		Collision::checkCollisionBallWall(*ball, wall);
	}

	Collision::checkCollisionBallPaddle(*ball, *paddle);

	for (PowerUp * powerUp : this->powerUps) {
		if (powerUp->isUsed()) {
			continue;
		}

		int id = Collision::checkCollisionPaddlePowerUp(*paddle, *powerUp);

		if (id == 2) {
			numberLife++;
		}

		if (id == 3) {
			this->timeSuperBall = this->timePowerUp;
			this->timeHugeBall = 0;
		}

		if (id == 1) {
			this->timeHugeBall = this->timePowerUp;
			this->timeSuperBall = 0;
		}
	}
}

void BrickBreaker::powerUpSistem(float deltaTimeSeconds)
{
	this->timeSuperBall -= deltaTimeSeconds;
	this->timeHugeBall -= deltaTimeSeconds;
}

void BrickBreaker::drawLife()
{
	glm::mat3 modelMatrix;

	for (int i = 0; i < numberLife; i++) {
		float x = (15.0f) * (i + 1)  + i * 10.0f;
		float y = 710.0f;
		modelMatrix = Transform2D::Translate(x, y);

		RenderMesh2D(meshes["life"], shaders["VertexColor"], modelMatrix);
	}
}

void BrickBreaker::loseBall()
{
	if (ball->getPositionOx() < 0 || ball->getPositionOy() < 0 ||
		ball->getPositionOx() > width || ball->getPositionOy() > height) {
		this->numberLife--;
		ball->resetBall();
		this->timeSuperBall = 0;
		this->timeHugeBall = 0;
	}
}

void BrickBreaker::resetLevel()
{
	if (numberLife < 1) {
		this->level->reset();
		ball->resetBall();
		paddle->reset();
		numberLife = 3;
		this->timeSuperBall = 0;
		this->timeHugeBall = 0;
	}
}


void BrickBreaker::nextLevel()
{
	if (finish) {
		ball->resetBall();
		paddle->reset();
		level->reset(); // resetare nivelului terminat
		currentLevel += 1;
		currentLevel = currentLevel % Level::maxLevel;
		level = levels[currentLevel]; // trecerea la urmatorul nivel
	
		for (PowerUp *powerUp: powerUps) {
			delete powerUp;
		}
		powerUps.clear();
		this->timeSuperBall = 0;
		this->timeHugeBall = 0;
	}
}
