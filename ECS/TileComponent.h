#pragma once

#include "ECS.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>

class TileComponent : public Component
{
	public:
		TransformComponent *transform;
		SpriteComponent *sprite;

		SDL_Rect tileRect;
		int tileID;
		const char* path;

		TileComponent() = default;
	
		TileComponent(int x, int y, int w, int h, int id)
		{
			tileRect.x = x;
			tileRect.y = y;
			tileRect.w = w;
			tileRect.h = h;
			tileID = id;

			switch (tileID) {
				case 0:
					path = "res/water.png";
				break;
				case 1:
					path = "res/dirt.png";
				break;
				case 2:
					path = "res/grass.png";
				break;
			}
		}

		void init() override
		{
			entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
			transform = &entity->getComponent<TransformComponent>();

			entity->addComponent<SpriteComponent>(path);
			sprite = &entity->getComponent<SpriteComponent>();
		}
};
