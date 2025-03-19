#pragma once
#include <vector>
#include "ProgramCard.h"
#include "Player.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class HostNode
{
private:
    int HostID;
    Player* Owner;
    int CPU;
    int RAM;
    int Storage;
    float HardDefense;
    float SoftDefense;
    float SecurityLevel;
    float PowerRequirement;
    SDL_Texture* HostTexture;
    int PosX;
    int PosY;
    std::vector<ProgramCard> ProgramsStored;
    std::vector<ProgramCard> ProgramsRunning;

public:
    //Create new Host
    HostNode(char* ID, Player owner, int Cpu, int Ram, int storage, int PosX, int PosY);

    //Get Host Node ID
    int GetHostNodeID();

    //

    //Add Program
    void AddProgram(ProgramCard program);
     

};