#pragma once

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
        public:

		Vector2D position;
		Vector2D velocity;
		
		int height = 32;
		int width = 32;
		int scale = 1;

		int speed = 3;

		TransformComponent()
		{
			position.x = 0;
			position.y = 0;
		}

		TransformComponent(int sc)
		{
			position.x = 0.0f;
			position.y = 0.0f;
			scale = sc;
		}

		TransformComponent(float px, float py)
		{
			position.x = px;
			position.y = py;
		}

		TransformComponent(float x, float y, int h, int w, int s)
		{
			position.x = x;
			position.y = y;

			height = h;
			width = w;
			scale = s;
		}

		void setPos(int px, int py)
		{
			position.x = px;
			position.y = py;
		}

		void init() override
		{
			velocity.x = 0;
			velocity.y = 0;
		}

		void update() override
		{
				position.x += velocity.x * speed;
				position.y += velocity.y * speed;
		}
};
