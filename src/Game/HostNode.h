#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "ProgramCard.h"
#include "Player.h"
#include "NetworkGraph.h"


struct HostStat
{
    //determines how advance the cards it can run
    int CPU;
    //host working memory
    int RAM;
    //hosts persistent memory
    int Storage;
    //hosts susceptibiliy to hard/technical attacks
    float HardDefense;
    //hosts susceptibility to soft/social attacks
    float SoftDefense;
    //total overall security
    float SecurityLevel;
    //power needed to run
    float PowerRequirement;
};

class HostNode
{
private:
    //hosts unique ID
    int HostID;
    //current owner of the host
    Player* Owner;
    //the type of host ex. PC, Server, Laptop, Datacenter, Satellite etc.
    std::string HostType;
    
    HostStat Stats;
    
    //host position
    int PosX;
    int PosY;
    //host storage
    std::vector<ProgramCard> ProgramsStored;
    //host ram
    std::vector<ProgramCard> ProgramsRunning;

public:
    //Create new Host - creates new host with specs and a position
    HostNode(int ID, std::string type, int Cpu, int Ram, int storage, int PosX, int PosY);

    //Get Host Node ID 
    int GetHostNodeID();

    //Get List of all programs in storage
    std::vector<ProgramCard>& GetProgramsStored();

    //Get List of all programs running
    std::vector<ProgramCard>& GetProgramsRunning();

    //GetHostStats


    //Send program - sends a program to host node

    //Recieve program - holds the recieved program in a special section

    //Run Program - adds the program to a running stategiven there is enough memory
    void RunProgram(ProgramCard& program);

    //UpdateState - the state of the host based on the running programs
    void UpdateHost();

    //Add Program - Adds program to storage
    void AddProgram(ProgramCard program);
     

};