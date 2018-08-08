//
//  players.hpp
//  DungeonCrawl
//
//  Created by Benjamin Basseri on 7/27/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
//#include "Action.h"
#include "Stats.h"
#pragma once

using namespace std;

class Player;
typedef unsigned short          Ushort;
typedef unsigned int            Uint;
typedef vector<Player>          Party;
const Uint NUM_ABILITY_MODS = 6;

// Prototypes
class   PlayerComparison;
bool    compare(const PlayerComparison & first, const PlayerComparison & second);
Uint    getStatIndex(const string *);

class Player
{
protected:
    string m_name;
    int m_stats[NUM_STATS]; // make sure core 6 stats are the first 6 to align with abilityMods
    int m_abilityMods[NUM_ABILITY_MODS];
    vector<string> m_actions;
public:
    Player();
    Player(const string &filename);
    
    Ushort getStat(const string &stat) const;
    int getAbilityMod(const string& ability) const;
    string getName() const;
};
//
//class PlayerComparison
//{
//private:
//    const Player * m_character;
//public:
//    int m_value;
//    PlayerComparison();
//    PlayerComparison(const Player * character);
//    PlayerComparison(const Player * character, int value);
//    
//    void setValue(int value);
//    int getValue();
//    const Player * getCharachterPtr();
//};
