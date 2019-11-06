
#include "Engine.h"

Engine::Engine()
{

}

Engine::~Engine()
{

}




Game::Game(std::string title, unsigned int width, unsigned int height) : window(title, width, height)
{
	running = true;
}

Game::~Game()
{

}

void Game::Close()
{
	running = false;
	OnExit();
}

void Game::Mainloop()
{
	OnInit();

	std::chrono::high_resolution_clock::time_point preUpdateTimer = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point updateTimer = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point postUpdateTimer = std::chrono::high_resolution_clock::now();

	while (running)
	{
		std::chrono::high_resolution_clock::time_point preUpdateTimerEnd = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> preUpdateTimerDelta = std::chrono::duration_cast<std::chrono::duration<double>>(preUpdateTimerEnd - preUpdateTimer);
		preUpdateTimer = preUpdateTimerEnd;

		OnPreUpdate(preUpdateTimerDelta.count());

		std::chrono::high_resolution_clock::time_point updateTimerEnd = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> updateTimerDelta = std::chrono::duration_cast<std::chrono::duration<double>>(updateTimerEnd - updateTimer);
		updateTimer = updateTimerEnd;

		OnUpdate(updateTimerDelta.count());

		std::chrono::high_resolution_clock::time_point postUpdateTimerEnd = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> postUpdateTimerDelta = std::chrono::duration_cast<std::chrono::duration<double>>(postUpdateTimerEnd - postUpdateTimer);
		postUpdateTimer = postUpdateTimerEnd;

		OnPostUpdate(postUpdateTimerDelta.count());

		if (automaticWindowUpdate)
		{
			window.Update();
		}

		if (automaticCloseEvent && window.IsClosed())
		{
			Close();
		}
	}
}
