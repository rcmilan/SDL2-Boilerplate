#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

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
void Game::init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen) {

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
	else {
		isRunning = false;
	}

	playerTex = IMG_LoadTexture(renderer, "C:/Users/Diogo/Downloads/Free/Main Characters/Ninja Frog/Jump (32x32).png");
}

/// <summary>
/// Trata eventos do SDL
/// </summary>
void Game::handleEvents() {
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
void Game::update() {
	destR.h = 64;
	destR.w = 64;
}

/// <summary>
/// Renderiza coisas
/// </summary>
void Game::render() {
	SDL_RenderClear(renderer);
	// Begin

	// Renderizamos coisas aqui
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);

	// End
	SDL_RenderPresent(renderer);
}

/// <summary>
/// Faz a limpa
/// </summary>
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}