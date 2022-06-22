#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::loadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::update()
{
	xpos = (++xpos) % 800;
	ypos = (++ypos) % 600;


	//xpos = 0;
	//ypos = 0;

	srcRect.h = 70;
	srcRect.w = 70;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
