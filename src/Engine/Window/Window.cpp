
#include "Window.h"

Window::Window(std::string title, unsigned int width, unsigned int height) : title(title), width(width), height(height)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::IsClosed()
{
	return glfwWindowShouldClose(window);
}

unsigned int Window::GetWidth()
{
	return width;
}

unsigned int Window::GetHeight()
{
	return height;
}

void Window::Update()
{
	glfwPollEvents();
	glfwSwapBuffers(window);
}
