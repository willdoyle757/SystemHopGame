#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include "Screen.h"
#include "../Rendering/MapRenderer.h"
#include "../Rendering/GUIRenderer.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

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

    if (!Screen::ren) 
    {
        std::cerr << "Renderer could not be created SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
    }

    //change this soon 
    IMG_Init(IMG_INIT_PNG);
    Screen::texture = IMG_LoadTexture(Screen::ren, "../assets/SDL2-icon.png");
    //checks if image loads correctlyw
    if (!Screen::texture) 
    {
        std::cerr   << "Failed to load texture! IMG_Error: " << IMG_GetError() << std::endl;
    }

    //Init Imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;    
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui_ImplSDL2_InitForSDLRenderer(win, ren);
    ImGui_ImplSDLRenderer2_Init(ren);

    ImGui::StyleColorsDark();
    io.Fonts->AddFontDefault();

}

void Screen::Update(NetworkGraph *network)
{

    Screen::Clear();
    
    GUIRenderer GUIR(Screen::ren);
    GUIR.RenderHostPrograms();
    
    
    //imgui game uo
    MapRenderer MR(Screen::ren);
    MR.RenderMap(network);
    
    //render imgui menus
    

    Screen::Draw();
 
}

void Screen::Draw()
{
    
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), ren);
    SDL_RenderPresent(Screen::ren);
}

void Screen::Clear()
{
    SDL_SetRenderDrawColor(Screen::ren, 0, 0, 0, 255);
    SDL_RenderClear(Screen::ren);
}

void Screen::Close()
{
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    IMG_Quit();

}