#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

#include "../Entities/NetworkGraph.h"

class MapRenderer
{
    SDL_Renderer *renderer;
    SDL_Texture *MapTexture;

public:

    MapRenderer(SDL_Renderer *ren);
    

    void RenderMap(NetworkGraph *graph);
};