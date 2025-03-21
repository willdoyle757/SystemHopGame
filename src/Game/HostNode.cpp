#include "HostNode.h"
#include <string>


HostNode::HostNode(int ID, std::string type, int Cpu, int Ram, int storage, int PosX, int PosY)
{
    HostNode::HostID = ID;
    HostNode::HostType = type;
    HostNode::Stats.CPU = Cpu;
    HostNode::Stats.RAM = Ram;
    HostNode::Stats.Storage = storage;
    HostNode::PosX = PosX;
    HostNode::PosY = PosY;
}

int HostNode::GetHostNodeID()
{
    return HostNode::HostID;
    
}

std::vector<ProgramCard>& HostNode::GetProgramsStored()
{
    return HostNode::ProgramsStored;
}

std::vector<ProgramCard>& HostNode::GetProgramsRunning()
{
    return HostNode::ProgramsRunning;
}



void HostNode::RunProgram(ProgramCard& program)
{

}

void HostNode::UpdateHost()
{

}

void HostNode::AddProgram(ProgramCard program)
{

}