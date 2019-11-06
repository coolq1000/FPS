#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

class Shader
{

public:

	GLuint programId;

	Shader();
	Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
	~Shader();

	void Load(const GLchar* vertexPath, const GLchar* fragmentPath);

	void Use();

	void SetBool(const std::string& name, GLboolean value);
	void SetInt(const std::string& name, GLint value);
	void SetFloat(const std::string& name, GLfloat value);

};

