#pragma once

#include <string>
#include <vector>
#include <include/math.h>

#include <cstdlib>
#include <ctime>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace Object2D
{
	const int numberTringleCircel = 200;

	Mesh * createRectangle(std::string name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color);

	Mesh * createSquare(std::string name, glm::vec3 leftBottomCorner, float size, glm::vec3 color);

	Mesh * createCircel(std::string name, glm::vec3 center, float radius, glm::vec3 color);
}