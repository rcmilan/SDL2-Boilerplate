#pragma once

#include "Components.h"
#include "SDL.h"

class SpriteComponent :public Component
{
private:
	TransformComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void Init() override
	{
		position = &entity->GetComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;

		destRect.w = destRect.h = 32;
	}

	void Update() override
	{
		destRect.x = position->x();
		destRect.y = position->y();
	}

	void Draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};