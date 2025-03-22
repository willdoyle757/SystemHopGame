#pragma once
#include "../Entities/NetworkGraph.h"
#include "../Entities/ProgramCard.h"

void RunTest();

NetworkGraph* CreateNetworkA();

void DisplayCardsOnHostStorage(HostNode* host);

void DisplayProgram(ProgramCard* program);

void DisplayNetwork(NetworkGraph* network);