
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>
#include "Game.h"
#include "Screen.h"


int Run()
{
    
    Screen screen;

    screen.Init();
    
    SDL_Event windowEvent;

    bool display = false;

    while(true)
    {
        //clear screen
        screen.Clear();

        //checks if user quits and deletes window
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                break;
            }

            if (windowEvent.type == SDL_MOUSEBUTTONDOWN )
            {
                std::cout << "mouse clicked" << std::endl;
                display = !display;
            }
        }

        if (display)
        {
            //render rectangle with png texture
            screen.Update();
        }
        //draw current render
        screen.Draw();

    }

    
    screen.Close();
    return EXIT_SUCCESS;
}