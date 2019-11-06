#pragma once

#include <string>
#include <chrono>

#include "Mesh/Mesh.h"
#include "Shader/Shader.h"
#include "Window/Window.h"

class Engine
{

public:

	Engine();
	~Engine();

	void Setup2D()
	{

	}

	void Setup3D()
	{

	}

};


class Game
{

protected:
	Window window;

	bool running;

	bool automaticWindowUpdate = true;
	bool automaticCloseEvent = true;

public:

	Game(std::string title = "A Game Window", unsigned int width = 640, unsigned int height = 480);
	~Game();

	void Close();

	virtual void OnInit() {}
	virtual void OnPreUpdate(double dt) {}
	virtual void OnUpdate(double dt) {}
	virtual void OnPostUpdate(double dt) {}
	virtual void OnExit() {}

	void Mainloop();

};
