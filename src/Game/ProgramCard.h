#pragma once
#include "Player.h"

struct GeneralStats
{
    Player* Owner;
    int Size;
    int ComputationalLoad;
};

struct OffensiveStats
{
    int PenetrationStrength;
    int Stealth;
    int AttackPotency;
    int ExecutionSpeed;

};

struct DefensiveStats
{
    int HardDefense;
    int SoftDefense;
    int Detection;
};

struct UtilityStats
{

};


class ProgramCard
{
private:
    GeneralStats generalStats;
    OffensiveStats offenseStats;
    DefensiveStats defenseStats;
    UtilityStats utilityStats;

public:
    GeneralStats GetGeneralStats();
    OffensiveStats GetOffensiveStats();
    DefensiveStats GetDefensiveStats();
    UtilityStats GetUtilityStats();

    void AddOwner(Player* player);


};