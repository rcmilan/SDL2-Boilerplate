#pragma once
#include "SDL.h"

class ColliderComponent;

class Collision
{
public:
	/// <summary>
	/// Axis Aligned Bound Box
	/// </summary>
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);

	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);

};
