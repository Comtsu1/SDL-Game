#pragma once

#include "Components.h"
#include "SDL2/SDL.h"
#include "../TextureManager.h"
#include <immintrin.h>

class SpriteComponent : public Component
{
	public:
		SpriteComponent() = default;
		SpriteComponent(const char* path)
		{
				setTex(path);
		}
		
		SpriteComponent(const char* path, int pframes,  int pspeed)
		{
			animated = true;
			frames   = pframes;
			speed    = pspeed;
			setTex(path);
		}

		~SpriteComponent()
		{
			SDL_DestroyTexture(texture);
		}
		
		void setTex(const char* path)
		{
				texture = TextureManager::loadTexture(path);
		}

		void init() override
		{
				transform = &entity->getComponent<TransformComponent>();

				srcRect.x = srcRect.y = 0;
				srcRect.w = transform->width;
				srcRect.h = transform->height;
		}

		void update() override 
		{
				if(animated)
				{
					srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
				}
				
				destRect.x = (int)transform->position.x;
				destRect.y = (int)transform->position.y;
				destRect.w = transform->width * transform->scale;
				destRect.h = transform->height * transform->scale;
		}

		void draw() override 
		{
				TextureManager::draw(texture, srcRect, destRect);
		}
	private:
		TransformComponent *transform;
		SDL_Texture *texture;
		SDL_Rect srcRect, destRect;

		bool animated = false;
		int frames = 0;
		int speed = 100;

};
