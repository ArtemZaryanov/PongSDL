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
	const int screenWidth;;
	const int screenHeight;
	const float D2R = 1 / 57.29578f;
	const float R2D = 1 / 0.017453f;
	std::vector<SDL_Texture*> textures;
	SDL_Window* win;
	SDL_Renderer* ren;
	bool InitSDL();
	RenderSDL() = delete;
	//bool InitSDL(SDL_Window*& win, SDL_Renderer*& ren);
public:
	RenderSDL(const Settings& settings);
	void Draw(const Entity& entity);
	bool LoadTexture(const std::vector<const char*> texturesPath);
	void UpdateRen();
	//Destructor
	void DestroySDL();
	//Мировые координаты должны преобразоваться в экранные
	~RenderSDL();
};

