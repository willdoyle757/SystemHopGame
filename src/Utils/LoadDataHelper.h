#pragma once

#include "../Entities/HostNode.h"
#include "../Entities/ProgramCard.h"
#include "../Entities/NetworkGraph.h"
#include <iostream>
#include <vector>



ProgramCard* LoadProgram();
void LoadHostNode(std::string filename, NetworkGraph* NG);
void LoadNetworkGraph(std::string filename, NetworkGraph* NG);
std::vector<std::string> splitLine(std::string line);
