#include "LoadDataHelper.h"

#include "../Entities/HostNode.h"
#include "../Entities/ProgramCard.h"
#include "../Entities/NetworkGraph.h"

#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::string> splitLine(std::string line)
{
    std::vector<std::string> words;
    std::istringstream stream(line);
    std::string word;

    while (stream >> word) { 
        words.push_back(word);
    }
    return words;
}

void LoadHostNode(std::string filename, NetworkGraph* NG)
{

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file for loading nodes " << filename << std::endl;
        return;
    }

    std::string line;
    
    while (std::getline(file, line))
    {
        if (line == "connections")
        {
            break;
        }
        std::vector<std::string> HostValues = splitLine(line);
        std::cout << HostValues[0] << std::endl;
        HostNode *Host = new HostNode(
        std::stoi(HostValues[0]), 
        HostValues[1], 
        std::stoi(HostValues[2]), 
        std::stoi(HostValues[3]), 
        std::stoi(HostValues[4]), 
        std::stoi(HostValues[5]), 
        std::stoi(HostValues[6]));

        NG->AddNode(Host->GetHostNodeID(), Host);
    }

    file.close();
}

void LoadNetworkGraph(std::string filename, NetworkGraph* NG)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file for  " << filename << std::endl;
        return;
    }

    std::string line;
    bool connectionSection = false;
    
    while (std::getline(file, line))
    {
        if (line == "connections")
        {
            connectionSection = true;
            continue;
        }
        if (connectionSection) 
        {
            std::cout << line << std::endl;
            std::vector<std::string> nodeConnection = splitLine(line);
            NG->CreateConnection(std::stoi(nodeConnection[0]), std::stoi(nodeConnection[1]));
        }
    }
    file.close();
}