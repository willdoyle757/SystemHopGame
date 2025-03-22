#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include "../Rendering/MapRenderer.h"

class Screen {

public:
    const int WIDTH = 800, HEIGHT = 600;

private:
    SDL_Window *win;
    SDL_Renderer *ren;
    SDL_Texture *texture;
    SDL_Rect iconRect = {0, 0, WIDTH, HEIGHT}; // x, y, width, height

public:
    Screen();
    void Init();
    void Update(NetworkGraph *network);
    void Draw();
    void Clear();
    void Close();

};