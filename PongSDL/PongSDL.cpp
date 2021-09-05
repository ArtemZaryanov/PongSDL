// PongSDL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "RenderSDL.h"
#include "Entity.h"
#include "Types.h"

int main(int argc, char* args[])
{
    std::cout << argc << std::endl;
    std::cout << *args << std::endl;
    Settings settings;
    Entity paddle1;
    Entity paddle2;
    Entity ball;
    settings.screenHeight = 480;
    settings.screenWidth = 640;
    RenderSDL renderSDL(settings);
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            switch (e.key.keysym.sym)
            {
            case SDLK_w: quit = true; 
                break;
            case SDLK_s: quit = true;
                break;
            case SDLK_UP: quit = true;
                break;
            case SDLK_DOWN: quit = true;
                break;
            default:
                break;
            }
        }
        //Create space
        /*renderSDL.Draw(paddle1);
        renderSDL.Draw(paddle2);
        renderSDL.Draw(ball);*/
        //Collision
        //Control
        // 
        //Update GUI
    }
    return 0;
}