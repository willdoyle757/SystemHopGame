#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include "Screen.h"
#include "../Rendering/MapRenderer.h"

Screen::Screen(){
}

void Screen::Init(){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Couldnt initialize SDL: " << SDL_GetError() << std::endl;
    }

    Screen::win = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if  (NULL == Screen::win)
    {
        std::cout << "Could not create window SDL Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    Screen::ren = SDL_CreateRenderer(Screen::win, -1, SDL_RENDERER_ACCELERATED);

    if (!Screen::ren) {
        std::cerr << "Renderer could not be created SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
    }

    //change this soon 
    IMG_Init(IMG_INIT_PNG);
    Screen::texture = IMG_LoadTexture(Screen::ren, "../assets/SDL2-icon.png");
    //checks if image loads correctlyw
    if (!Screen::texture) {
        std::cerr   << "Failed to load texture! IMG_Error: " << IMG_GetError() << std::endl;
    }
}

void Screen::Update(NetworkGraph *network)
{
    Screen::Clear();
    SDL_RenderCopy(Screen::ren, Screen::texture, NULL, &iconRect);
    SDL_RenderDrawRect(Screen::ren, &iconRect);
    MapRenderer MR(Screen::ren);
    MR.RenderMap(network);

    Screen::Draw();
 
}

void Screen::Draw()
{
    SDL_RenderPresent(Screen::ren);
}

void Screen::Clear()
{
    SDL_SetRenderDrawColor(Screen::ren, 0, 0, 0, 255);
    SDL_RenderClear(Screen::ren);

}

void Screen::Close()
{

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    IMG_Quit();

}