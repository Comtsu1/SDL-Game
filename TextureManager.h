#pragma once

#include "Game.h"
#include "SDL2/SDL_image.h"

class TextureManager
{
	public:
		static SDL_Texture* loadTexture(const char* fileName);
		static void draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
};
