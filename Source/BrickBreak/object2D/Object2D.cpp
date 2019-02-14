#include "Object2D.h"

Mesh * Object2D::createRectangle(std::string name, glm::vec3 leftBottomCorner, float height, float width, glm::vec3 color)
{
	glm::vec3 corner = leftBottomCorner;

	/* adaugarea de vertex */
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(width, 0, 0), color),
		VertexFormat(corner + glm::vec3(width, height, 0), color),
		VertexFormat(corner + glm::vec3(0, height, 0), color)
	};

	std::vector<unsigned short> indices =
	{
		0, 1, 2,
		3, 0, 2
	};

	Mesh *rectangle = new Mesh(name);
	rectangle->InitFromData(vertices, indices);

	return rectangle;
}

Mesh * Object2D::createSquare(std::string name, glm::vec3 leftBottomCorner, float size, glm::vec3 color)
{
	return Object2D::createRectangle(name, leftBottomCorner, size, size, color);
}

Mesh * Object2D::createCircel(std::string name, glm::vec3 center, float radius, glm::vec3 color)
{
	glm::vec3 centerCircel = center;
	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;
	float x, y, angle;
	glm::vec3 specialColor;

	vertices.push_back(VertexFormat(centerCircel, color)); // aduagare centrului
	for (int i = 0; i < Object2D::numberTringleCircel; i++)
	{
		angle = MY_DOUBLE_PI * float(i) / float(Object2D::numberTringleCircel);
		x = radius * cosf(angle);
		y = radius * sinf(angle);

		vertices.push_back(VertexFormat(centerCircel + glm::vec3(x, y, 0), color));
	}

	for (int i = 2; i <= Object2D::numberTringleCircel; i++) {
		indices.push_back(0);
		indices.push_back(i - 1);
		indices.push_back(i);
	}

	indices.push_back(0);
	indices.push_back(Object2D::numberTringleCircel);
	indices.push_back(1);

	Mesh *circle = new Mesh(name);
	circle->InitFromData(vertices, indices);

	return circle;
}