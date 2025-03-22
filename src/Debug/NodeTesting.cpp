#include "NodeTesting.h"
#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>

#include "../Game/Screen.h"
#include "../Entities/HostNode.h"
#include "../Entities/ProgramCard.h"
#include "../Entities/NetworkGraph.h"



void RunTest()
{

    std::cout << "Starting Test" << std::endl;
    NetworkGraph * ng = CreateNetworkA();
    DisplayNetwork(ng);

    OffensiveStats offenseA(0, 0, 0, 0);
    DefensiveStats defenseA(5.0, 1.0, 1.0);
    UtilityStats utilityA;
    std::string nameA = "Anti-Virus";

    ProgramCard AntiVirus(nameA, 10, 5, offenseA, defenseA, utilityA);

    (ng->Nodes[1]->DownloadProgram(AntiVirus) == 1) ? std::cout<<"Added Program!"<<std::endl : std::cout<<"unable to add Program"<<std::endl;

    std::cout << "Programs stored in host " << ng->Nodes[1]->GetProgramsStored().size() << std::endl;

    DisplayCardsOnHostStorage(ng->Nodes[1]);
    
    Screen screen;

    screen.Init();

    SDL_Event windowEvent;

    while(true)
    {
        //checks if user quits and deletes window
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                break;
            }
        }

        screen.Update(ng);
        SDL_Delay(16);
    }

    delete ng;
    screen.Close();
}

NetworkGraph* CreateNetworkA()
{
    NetworkGraph *NG = new NetworkGraph();

    HostNode *PC_A = new HostNode(1, "PC", 5, 20, 100, 100, 200);
    NG->AddNode(PC_A->GetHostNodeID(), PC_A);
    HostNode *PC_B = new HostNode(2, "PC", 5, 20, 100, 200, 250);
    NG->AddNode(PC_B->GetHostNodeID(), PC_B);
    HostNode *PC_C = new HostNode(3, "PC", 5, 20, 100, 400, 300);
    NG->AddNode(PC_C->GetHostNodeID(), PC_C);
    HostNode *PC_D = new HostNode(4, "PC", 5, 20, 100, 200, 400);
    NG->AddNode(PC_D->GetHostNodeID(), PC_D);

    NG->CreateConnection(1, 2);
    NG->CreateConnection(2, 3);
    NG->CreateConnection(1, 3);
    NG->CreateConnection(2, 4);

    return NG;
}

void DisplayProgram(ProgramCard* program)
{
    std::cout << "Program: " << program->GetGeneralStats().Name << std::endl;
    std::cout << "General Info - CPU Load: " << program->GetGeneralStats().ComputationalLoad;
    std::cout << ", Memory Size: " << program->GetGeneralStats().Size << std::endl;
    
    std::cout << "Offense Info - PenetrationStrength: " << program->GetOffensiveStats().PenetrationStrength;
    std::cout << ", Stealth: " << program->GetOffensiveStats().Stealth;
    std::cout << ", Attack Potency: " << program->GetOffensiveStats().AttackPotency << std::endl;

    std::cout << "Defense Info - Hard Defense: " << program->GetDefensiveStats().HardDefense;
    std::cout << ", Soft Defense: " << program->GetDefensiveStats().SoftDefense;
    std::cout << ", Detection: " << program->GetDefensiveStats().Detection << std::endl;
}

void DisplayCardsOnHostStorage(HostNode* host)
{   
    std::cout << "Host " << host->GetHostNodeID() << " Programs" << std::endl;
    for (ProgramCard program : host->GetProgramsStored())
    {
        DisplayProgram(&program);
    }
}


void DisplayNetwork(NetworkGraph* network)
{
    std::cout << "Network:" << std::endl;

    int nodes = network->Nodes.size();
    for (int i = 1; i <= nodes; i++){
        std::cout << "Host " << i << " Is connected to Hosts: " ;
        std::vector<int> connectedNodes = network->Connections[i];
        for (int e : connectedNodes )
        {
            std::cout<< e << " ";
        }
        std::cout << std::endl;
    } 

}