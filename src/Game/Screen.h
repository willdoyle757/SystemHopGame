#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include "../Rendering/MapRenderer.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

class Screen {

public:
    const int WIDTH = 1000, HEIGHT = 800;

private:
    SDL_Window *win;
    SDL_Renderer *ren;
    SDL_Texture *texture;
    
    bool show_demo_window = true;
    

public:
    Screen();
    void Init();
    void Update(NetworkGraph *network);
    void Draw();
    void Clear();
    void Close();

};