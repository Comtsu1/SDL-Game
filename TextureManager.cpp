#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
	SDL_Surface* tempS = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempS);
	SDL_FreeSurface(tempS);

	return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);	
}
