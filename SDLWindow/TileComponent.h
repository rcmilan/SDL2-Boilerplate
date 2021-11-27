#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;

	const char* path;

	TileComponent() = default;
	TileComponent(int x, int y, int w, int h, int id) : tileID(id)
	{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;

		switch (tileID)
		{
		case 0:
			path = "C:/Users/Diogo/Downloads/Free/Background/Blue.png";
			break;
		case 1:
			path = "C:/Users/Diogo/Downloads/Free/Background/Brown.png";
			break;
		case 2:
			path = "C:/Users/Diogo/Downloads/Free/Background/Green.png";
			break;
		default:
			break;
		}
	}

	void Init() override
	{
		entity->AddComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.h, tileRect.w, 1);
		transform = &entity->GetComponent<TransformComponent>();

		entity->AddComponent<SpriteComponent>(path);
		sprite = &entity->GetComponent<SpriteComponent>();
	}
};