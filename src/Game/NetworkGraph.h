#pragma once

#include <unordered_map>
#include <vector>
#include "HostNode.h"

class NetworkGraph
{
public:
    std::unordered_map<int, HostNode*> Nodes;
    std::unordered_map<int, std::vector<int>> Connections;

    void AddNode(int hostID, HostNode* node);
    void CreateConnection(int NodeA_ID, int NodeB_ID);
};