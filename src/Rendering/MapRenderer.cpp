#include "MapRenderer.h"
#include "../Entities/NetworkGraph.h"
#include "../Entities/HostNode.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

MapRenderer::MapRenderer(SDL_Renderer *ren)
{
    MapRenderer::renderer = ren;
    MapRenderer::MapTexture = IMG_LoadTexture(MapRenderer::renderer, "../assets/pc-icon.png");
}

void MapRenderer::RenderMap(NetworkGraph *graph)
{
    
    int nodes = graph->Nodes.size();

    for (int i = 1; i <= nodes; i++){
        HostNode *host = graph->Nodes[i];
        int x = host->GetPosition().PosX;
        int y = host->GetPosition().PosY;
        
        SDL_Rect NodeRect = {x, y, 50, 50};
        SDL_RenderCopy(MapRenderer::renderer, MapRenderer::MapTexture, NULL, &NodeRect);
        SDL_RenderDrawRect(renderer, &NodeRect);
    } 
    
}
