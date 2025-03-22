#include "HostNode.h"
#include "ProgramCard.h"
#include <iostream>
#include <string>


HostNode::HostNode(int ID, std::string type, int Cpu, int Ram, int storage, int PosX, int PosY)
{
    HostNode::HostID = ID;
    HostNode::HostType = type;
    HostNode::Stats.CPU = Cpu;
    HostNode::Stats.RAM = Ram;
    HostNode::Stats.Storage = storage;
    HostNode::Pos.PosX = PosX;
    HostNode::Pos.PosY = PosY;
    
    //Reset all the stats 
    HostNode::Stats.UsedCPU = 0;
    HostNode::Stats.UsedRAM = 0;
    HostNode::Stats.UsedStorage = 0;
    HostNode::Stats.HardDefense = 0;
    HostNode::Stats.SoftDefense = 0;
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

HostStat HostNode::GetHostStats()
{
    return HostNode::Stats;
}

Position HostNode::GetPosition()
{
    return HostNode::Pos;
}

//pushes the object into the running list
int HostNode::RunProgram(ProgramCard program)
{

    HostStat stats = HostNode::GetHostStats();

    if (stats.RAM - stats.UsedRAM > program.GetGeneralStats().ComputationalLoad)
    {
        ProgramsRunning.push_back(program);
        return 1;
    }
    else{
        return 0;
    }
}

//Will look at all the cards that are running and update the stats of the host
void HostNode::UpdateHost()
{
    HostStat stats = HostNode::GetHostStats();
    
    //Reset all the stats 
    stats.UsedCPU = 0;
    stats.UsedRAM = 0;
    stats.UsedStorage = 0;
    stats.HardDefense = 0;
    stats.SoftDefense = 0;

    for (ProgramCard program : HostNode::ProgramsRunning)
    {
        GeneralStats programGeneral = program.GetGeneralStats();
        DefensiveStats programDefense = program.GetDefensiveStats();

        stats.UsedCPU += programGeneral.ComputationalLoad;
        stats.UsedRAM += programGeneral.Size;

        stats.HardDefense += programDefense.HardDefense;
        stats.SoftDefense += programDefense.SoftDefense;
        stats.DetectionRate += programDefense.Detection;
        
    }

    for (ProgramCard program : HostNode::ProgramsStored)
    {
        GeneralStats programGeneral = program.GetGeneralStats();

        stats.UsedStorage += programGeneral.Size;
    }
}

//Add program to the host Storage
int HostNode::DownloadProgram(ProgramCard program)
{
    HostStat stats = HostNode::GetHostStats();

    std::cout << "Program Size: " << program.GetGeneralStats().Size << std::endl;
    std::cout << "Storage left: " << stats.Storage - stats.UsedStorage << std::endl;

    if ((stats.Storage - stats.UsedStorage) >= program.GetGeneralStats().Size)
    {
        stats.UsedStorage += program.GetGeneralStats().Size;
        ProgramsStored.push_back(program);
        return 1;
    }
    else{
        return 0;
    }
}