#include <cstdlib>
#include <ctime>

#include "Map.h"
#include "TextureManager.h"
#include <SDL2/SDL_render.h>

int lvl1[20][25];

Map::Map()
{
	std::srand(std::time(0));

	for(int i = 0; i < 20; ++i)
	{
		for(int j = 0; j < 25; ++j)
		{
			lvl1[i][j] = std::rand() % 2;
		}
	}
	dirt  = TextureManager::loadTexture("res/dirt.png");
	grass = TextureManager::loadTexture("res/grass.png");
	water = TextureManager::loadTexture("res/water.png");
	
	loadMap(lvl1);

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

Map::~Map()
{
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
	SDL_DestroyTexture(dirt);
}

void Map::loadMap(int arr[20][25])
{
	for(int row = 0; row  < 20; ++row)
	{
		for(int col = 0; col < 25; ++col)
		{
			map[row][col] = arr[row][col];
		}
	}
}

void Map::drawMap()
{
	int type = 0;
	for(int row = 0; row < 20; ++row)
	{
		for(int col = 0; col < 25; ++col)
		{
			type = map[row][col];
			
			dest.x = col * 32;
			dest.y = row * 32;

			switch(type)
			{
				case 0:
					TextureManager::draw(water, src, dest);				
				break;
				
				case 1:
					TextureManager::draw(grass, src, dest);
				break;

				case 2:
					TextureManager::draw(dirt, src, dest);
				break;
			}
		}
	}
}
