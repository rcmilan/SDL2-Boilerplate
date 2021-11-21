#include "Game.h"
#include "Map.h"
#include "TextureManager.h"
#include "Components.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.AddEntity());

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

	isRunning = false;

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
	player.AddComponent<SpriteComponent>("C:/Users/Diogo/Downloads/Free/Main Characters/Ninja Frog/Jump (32x32).png");
}

/// <summary>
/// Trata eventos do SDL
/// </summary>
void Game::HandleEvents() {
	SDL_Event evt;
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

	std::cout << "Player Position: " << player.GetComponent<TransformComponent>().x() << "," << player.GetComponent<TransformComponent>().y() << std::endl;
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