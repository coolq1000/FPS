#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class Window
{

	std::string title;
	unsigned int width, height;

	GLFWwindow *window;

public:

	Window(std::string title, unsigned int width, unsigned int height);
	~Window();

	bool IsClosed();

	unsigned int GetWidth();
	unsigned int GetHeight();

	void Update();

};
