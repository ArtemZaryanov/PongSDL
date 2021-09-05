#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Types.h"
#include <iostream>
#include <vector>

class RenderSDL
{
private:
	int SCREEN_WIDTH;;
	int SCREEN_HEIGHT;
	const float D2R = 1 / 57.29578f;
	const float R2D = 1 / 0.017453f;
	SDL_Window* win;
	SDL_Renderer* ren;
	bool InitSDL(const int screenWidth, const int screenHeight);
	//bool InitSDL(SDL_Window*& win, SDL_Renderer*& ren);
public:
	RenderSDL(const Settings& settings);
	void Draw(const Entity& entity);
	//Destructor
	void DestroySDL();
	//Мировые координаты должны преобразоваться в экранные
	~RenderSDL();
};

