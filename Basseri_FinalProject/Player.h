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
//#include "Action.h"
#pragma once

using namespace std;

class Player;
class Action;
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
    static map<const string, unsigned int> m_statMap;
    
    string m_name;
    int m_stats[NUM_PLAYER_STATS]; // make sure core 6 stats are the first 6 to align with abilityMods
    int m_abilityMods[NUM_ABILITY_MODS];
    vector<string> m_actions;
public:
    Player();
    Player(const string &filename);
    virtual ~Player();
    
    Ushort getStat(const string &stat) const;
    void changeStat(const string &stat, const short &value);
    int getAbilityMod(const string& ability) const;
    string getName() const;
    int getNumActions();
    string getAction(const int index);
    Ushort getStat(const int &) const;
    
    bool resolveAction(const Player &targetCreature, const Action &theAction );
};

