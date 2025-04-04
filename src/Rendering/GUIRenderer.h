#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

class GUIRenderer 
{
private: 
    SDL_Renderer *renderer;
    bool show_demo_window = true;
    int posX = 0;
    int posY = 600;

    int width = 1000;
    int height = 200;

public:
    GUIRenderer(SDL_Renderer *ren);
    ~GUIRenderer();

    void RenderHostPrograms();
};