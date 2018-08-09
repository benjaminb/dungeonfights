//
//  players.hpp
//  DungeonCrawl
//
//  Created by Benjamin Basseri on 7/27/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//
#include <string>
#include <vector>
#include <map>
#include "Action.h"
//#include "Stats.h"
#pragma once

using namespace std;

class Player;
typedef unsigned short          Ushort;
typedef unsigned int            Uint;
typedef vector<Player>          Party;
const Uint NUM_ABILITY_MODS = 6;

// TODO: get this to include Stats.h
const Uint NUM_PLAYER_STATS = 11;

// Prototypes
class   PlayerComparison;
bool    compare(const PlayerComparison & first, const PlayerComparison & second);
Uint    getStatIndex(const string *);

class Player
{
protected:
    static const unsigned int M_NUM_STATS = 11;
    string m_statStrings[M_NUM_STATS] = {
        "str",
        "dex",
        "con",
        "int",
        "wis",
        "cha",
        "ac",
        "hp",
        "hitDice",
        "hpRolls",
        "hpDie"
    };
    
    map<const string, unsigned int> m_statMap =
    {
        {"str", 0},
        {"dex", 1},
        {"con", 2},
        {"int", 3},
        {"wis", 4},
        {"cha", 5},
        {"ac", 6},
        {"hp", 7},
        {"hitDice", 8},
        {"hpRolls", 9},
        {"hpDie", 10}
    };
    
    string m_name;
    int m_stats[NUM_PLAYER_STATS]; // make sure core 6 stats are the first 6 to align with abilityMods
    int m_abilityMods[NUM_ABILITY_MODS];
    vector<string> m_actions;
public:
    Player();
    Player(const string &filename);
    
    Ushort getStat(const string &stat);
    int getAbilityMod(const string& ability);
    string getName();
};
