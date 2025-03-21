#include "NetworkGraph.h"
#include "HostNode.h"
#include <unordered_map>
#include <vector>


void NetworkGraph::AddNode(int hostID, HostNode* node)
{
    NetworkGraph::Nodes[hostID] = node;
}

void NetworkGraph::CreateConnection(int NodeA_ID, int NodeB_ID)
{
    NetworkGraph::Connections[NodeA_ID].push_back(NodeB_ID);
    NetworkGraph::Connections[NodeB_ID].push_back(NodeA_ID);
}