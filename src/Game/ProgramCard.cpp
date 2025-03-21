#include "ProgramCard.h"
#include "Player.h"

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