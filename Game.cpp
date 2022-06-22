#include "Game.h"
#include "ECS/ColliderComponent.h"
#include "ECS/SpriteComponent.h"
#include "ECS/TransformComponent.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"


Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());
auto& testobj(manager.addEntity());

Map* map;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout<<"something went wrong, idk:" << SDL_GetError();
		isRunning = false;
		return;
	}

	window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if(!window)
	{
		std::cout<<"Window was not created: " << SDL_GetError();	
		isRunning = false;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if(!renderer)
	{
		std::cout<<"Renderer was not created: " << SDL_GetError();
		isRunning = false;
		return;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	isRunning = true;

	map = new Map();

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("res/player.png");
    player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("res/dirt.png");
	wall.addComponent<ColliderComponent>("wall");

	testobj.addComponent<TransformComponent>(0.0f, 0.0f, 100, 20, 2);
	testobj.addComponent<SpriteComponent>("res/Bat.png");
}

void Game::handleEvents()
{

	SDL_PollEvent(&event);

	switch(event.type)
	{
		case SDL_QUIT:
			isRunning = false;
		break;

		default:
		break;
	}
}

void Game::update()
{
	manager.refresh();
	manager.update();

	if(Collision::AABB(player.getComponent<ColliderComponent>().collider
					, wall.getComponent<ColliderComponent>().collider))
	{
		player.getComponent<TransformComponent>().scale = 1;
		std::cout<<"shut the fuck up, you degenerate idiot";
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->drawMap();
	
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
