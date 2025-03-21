#include "NodeTesting.h"
#include <iostream>
#include <vector>
#include "../Game/HostNode.h"
#include "../Game/ProgramCard.h"
#include "../Game/NetworkGraph.h"


void RunTest()
{
    std::cout << "Starting Test" << std::endl;
    NetworkGraph * ng = CreateNetworkA();
    DisplayNetwork(ng);

}

NetworkGraph* CreateNetworkA()
{
    NetworkGraph *NG = new NetworkGraph();

    HostNode *PC_A = new HostNode(1, "PC", 5, 20, 100, 100, 200);
    NG->AddNode(PC_A->GetHostNodeID(), PC_A);
    HostNode PC_B(2, "PC", 5, 20, 100, 200, 250);
    NG->AddNode(PC_B.GetHostNodeID(), &PC_B);
    HostNode PC_C(3, "PC", 5, 20, 100, 400, 300);
    NG->AddNode(PC_C.GetHostNodeID(), &PC_C);
    HostNode PC_D(4, "PC", 5, 20, 100, 200, 400);
    NG->AddNode(PC_D.GetHostNodeID(), &PC_D);

    NG->CreateConnection(1, 2);
    NG->CreateConnection(2, 3);
    NG->CreateConnection(1, 3);
    NG->CreateConnection(2, 4);

    return NG;
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