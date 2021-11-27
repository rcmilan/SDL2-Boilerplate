#pragma once
#include "Vector2D.h"
#include "Components.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int widht = 32;
	int scale = 1;

	int speed = 3;

	TransformComponent()
	{
		position.x = position.y = 0.0f;
	}

	TransformComponent(int sc)
	{
		position.x = 0.0f;
		position.y = 0.0f;
		scale = sc;
	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x;
		position.y = y;
		height = h;
		widht = w;
		scale = sc;
	}

	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void Init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void Update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};