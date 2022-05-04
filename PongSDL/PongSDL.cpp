// PongSDL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <SDL.h>
#include "RenderSDL.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Types.h"

int main(int argc, char* args[])
{
    
    std::cout << argc << '\n';
    std::cout << *args << '\n';
    Settings settings;
    RectBound paddle1Rect{ 60,60,70,70 };    
    RectBound paddle2Rect{300,300,70,70};
    RectBound ballRect{150,150,50,50};

    Paddle paddle1(0,paddle1Rect);
    Paddle paddle2(0,paddle2Rect);
    Ball ball(1, ballRect);
    settings.screenHeight = 480;
    settings.screenWidth = 640;
    const char* paddleTextPath = "res/paddle.png";
    const char* ballTextPath = "res/circle.png";
    //Может map?
    std::vector<const char*> texturesPath{ paddleTextPath,ballTextPath };
    RenderSDL renderSDL(settings);
    renderSDL.LoadTexture(texturesPath);
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
                std::cout << "quit" << '\n';
            }
            switch (e.key.keysym.sym)
            {
            case SDLK_w:
                paddle1.moveUp();
                std::cout << "paddle1_Up" << '\n';
                break;
            case SDLK_s: 
                paddle1.moveDown();
                std::cout << "paddle1_Down" << '\n';
                break;
            case SDLK_UP:
                paddle2.moveUp();
                std::cout << "paddle2_Up" << '\n'; 
                break;
            case SDLK_DOWN: 
                paddle2.moveDown(); 
                std::cout <<"paddle2_Down" << '\n';
                break;
            default:
                break;
            }
        
        }
        ball.move();
        //Create space
        renderSDL.Draw(paddle1);
        renderSDL.Draw(paddle2);
        renderSDL.Draw(ball);
        renderSDL.UpdateRen();
        //Collision
        //Update GUI
    }
    return 0;
}