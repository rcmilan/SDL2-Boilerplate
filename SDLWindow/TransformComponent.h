#pragma once
#include "Vector2D.h"
#include "Components.h"

class TransformComponent : public Component
{
public:
	Vector2D position;

	TransformComponent()
	{
		position.x = position.y = 0.0f;
	}

	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void Update() override
	{
	}
};