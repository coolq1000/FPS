#pragma once

#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 color;
};

class Mesh
{

	GLuint VAO, VBO, EBO;

public:

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	Mesh();
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
	~Mesh();

	void Load(std::vector<Vertex> vertices, std::vector<GLuint> indices);
	void Draw();

};

