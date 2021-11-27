#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return isRunning; };



	static SDL_Renderer* renderer;
	static SDL_Event evt;

	static std::vector<ColliderComponent*> colliders;

private:
	bool isRunning = false;
	SDL_Window* window;
};
