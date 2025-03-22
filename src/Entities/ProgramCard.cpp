#include "ProgramCard.h"
#include "Player.h"

ProgramCard::ProgramCard(std::string name, int size, int load, OffensiveStats offense, DefensiveStats defense, UtilityStats utility)
{
    generalStats.Name = name;
    generalStats.Size = size;
    generalStats.ComputationalLoad = load;

    offenseStats = offense;
    defenseStats = defense;
    utilityStats = utility;

}

GeneralStats ProgramCard::GetGeneralStats()
{
    return ProgramCard::generalStats;
}

OffensiveStats ProgramCard::GetOffensiveStats()
{
    return ProgramCard::offenseStats;
}

DefensiveStats ProgramCard::GetDefensiveStats()
{
    return ProgramCard::defenseStats;
}

UtilityStats ProgramCard::GetUtilityStats()
{
    return ProgramCard::utilityStats;
}

void ProgramCard::AddOwner(Player* player)
{
    ProgramCard::generalStats.Owner = player;
}

