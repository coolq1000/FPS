
#include <iostream>

#include "Engine/Engine.h"

class FPSGame : public Game
{

	Shader basic;
	Mesh player;

	void OnInit()
	{
		std::vector<Vertex> verts = {
			{ { -0.5f, -0.5f, 0.0f }, { 0, 0, 1 }, { 0, 0 }, { 1.0, 0.0, 0.0 } },
			{ {  0.5f, -0.5f, 0.0f }, { 0, 0, 1 }, { 1, 0 }, { 0.0, 1.0, 0.0 } },
			{ {  0.0f,  0.5f, 0.0f }, { 0, 0, 1 }, { 0, 1 }, { 0.0, 0.0, 1.0 } }
		};

		std::vector<GLuint> faces = {
			0, 1, 2,
			2, 3, 0
		};

		player.Load(verts, faces);
		basic.Load("Resources/Shaders/Basic.vert", "Resources/Shaders/Basic.frag");
	}

	void OnUpdate(double dt)
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glViewport(0, 0, window.GetWidth(), window.GetHeight());

		basic.Use();
		player.Draw();
	}

};

int main(void)
{
	FPSGame game;
	game.Mainloop();
	return 0;
}
