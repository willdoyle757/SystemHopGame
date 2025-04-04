#include "GUIRenderer.h"
#include <iostream>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl2.h>
#include <imgui/imgui_impl_sdlrenderer2.h>

GUIRenderer::GUIRenderer(SDL_Renderer *ren)
{
    GUIRenderer::renderer = ren;
}

GUIRenderer::~GUIRenderer()
{
    renderer = nullptr;
}

void GUIRenderer::RenderHostPrograms()
{
    static int counter = 0;
    
    ImGui_ImplSDL2_NewFrame();
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();
    ImGui::SetNextWindowPos(ImVec2(posX, posY));
    ImGui::SetNextWindowSize(ImVec2(width, height));

    ImGui::Begin("Hello, world!");           
    ImGui::Text("This is some useful text.");
    ImGui::Checkbox("Demo Window", &show_demo_window);
     
    
    if (ImGui::Button("Button"))                    
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);
    ImGui::End();
    
}