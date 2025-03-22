#pragma once
#include "Player.h"
#include <string>

struct GeneralStats
{
    Player* Owner;
    std::string Name;
    int Size;
    int ComputationalLoad;
};

struct OffensiveStats
{
    float PenetrationStrength;
    float Stealth;
    float AttackPotency;
    float ExecutionSpeed;

    OffensiveStats() 
        : PenetrationStrength(0), Stealth(0), AttackPotency(0), ExecutionSpeed(0) {}

    OffensiveStats(float penStr, float stealth, float attackPot, float execSpeed){
        PenetrationStrength = penStr;
        Stealth = stealth;
        AttackPotency = attackPot;
        ExecutionSpeed = execSpeed;
    }
};

struct DefensiveStats
{
    float HardDefense;
    float SoftDefense;
    float Detection;

    DefensiveStats()
        : HardDefense(0), SoftDefense(0), Detection(0){}

    DefensiveStats(float hardDef, float softDef, float detect){
        HardDefense = hardDef;
        SoftDefense = softDef;
        Detection = detect;
    }

};

struct UtilityStats
{
    UtilityStats()
    {}
};


class ProgramCard
{
private:
    GeneralStats generalStats;
    OffensiveStats offenseStats;
    DefensiveStats defenseStats;
    UtilityStats utilityStats;

public:
    ProgramCard(std::string name, int size, int load, OffensiveStats offense, DefensiveStats defense, UtilityStats utility);
    GeneralStats GetGeneralStats();
    OffensiveStats GetOffensiveStats();
    DefensiveStats GetDefensiveStats();
    UtilityStats GetUtilityStats();

    void AddOwner(Player* player);


};