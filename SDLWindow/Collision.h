#pragma once
#include "SDL.h"


class Collision
{
public:
	/// <summary>
	/// Axis Aligned Bound Box
	/// </summary>
	static bool AABB(const SDL_Rect& a, const SDL_Rect& b);

};
