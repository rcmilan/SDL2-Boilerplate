#include "Game.h"
#include "Map.h"
#include "TextureManager.h"
#include "Components.h"
#include "Collision.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::evt;

Manager manager;

auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());

Game::Game() {
}

Game::~Game() {
}

/// <summary>
/// Inicializa SDL window e renderer, define isRunning true/false
/// </summary>
/// <param name="title">Nome da janela</param>
/// <param name="xpos">Posição x</param>
/// <param name="ypos">Posição y</param>
/// <param name="widht">Largura</param>
/// <param name="height">Altura</param>
/// <param name="fullscreen">Flag Fullscreen</param>
void Game::Init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, widht, height, flags);

		if (window) {
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}

	map = new Map();

	player.AddComponent<TransformComponent>();
	player.AddComponent<SpriteComponent>("C:/Users/Diogo/Downloads/Free/Main Characters/Virtual Guy/Jump (32x32).png");
	player.AddComponent<KeyboardController>();
	player.AddComponent<ColliderComponent>("player");

	wall.AddComponent<TransformComponent>(100.0f, 100.0f, 32, 32, 1);
	wall.AddComponent<SpriteComponent>("C:/Users/Diogo/Downloads/Free/Background/Pink.png");
	wall.AddComponent<ColliderComponent>("wall");
}

/// <summary>
/// Trata eventos do SDL
/// </summary>
void Game::HandleEvents() {
	SDL_PollEvent(&evt);

	switch (evt.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

/// <summary>
/// Atualiza as coisas
/// </summary>
void Game::Update() {
	manager.Refresh();
	manager.Update();

	if (Collision::AABB(player.GetComponent<ColliderComponent>().collider, wall.GetComponent<ColliderComponent>().collider)) {

		auto w = player.GetComponent<TransformComponent>().position;

		//std::cout << "Wall Hit" << " (" << w.x << "," << w.y << ")" << std::endl;
	}

	//std::cout << "Player Position: " << player.GetComponent<TransformComponent>().position.x << "," << player.GetComponent<TransformComponent>().position.y << std::endl;
}

/// <summary>
/// Renderiza coisas
/// </summary>
void Game::Render() {
	SDL_RenderClear(renderer);
	// Begin

	// Renderizamos coisas aqui
	map->DrawMap();
	manager.Draw();

	// End
	SDL_RenderPresent(renderer);
}

/// <summary>
/// Faz a limpa
/// </summary>
void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}