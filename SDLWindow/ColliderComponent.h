#pragma once

#include <string>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component
{
	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;

	void Init() override
	{
		if (!entity->HasComponent<TransformComponent>()) {
			entity->AddComponent<TransformComponent>();
		}

		transform = &entity->GetComponent<TransformComponent>();
	}

	void Update() override
	{
		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = transform->widht * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};
