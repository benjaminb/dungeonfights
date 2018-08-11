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
#pragma once

using namespace std;

class Player;
class Action;
typedef unsigned short          Ushort;
typedef unsigned int            Uint;
typedef vector<Player>          Party;
const Uint NUM_ABILITY_MODS = 6;
const Uint NUM_PLAYER_STATS = 17;

class Player
{
protected:
    static const unsigned int M_NUM_STATS = 11;
    static map<const string, unsigned int> m_statMap;
    
    string m_name;
    int m_stats[NUM_PLAYER_STATS];
    vector<string> m_actions;
public:
    Player();
    Player(const string &filename);
    virtual ~Player();
    
    // Getters
    int getStat(const string &stat) const;
    int getStat(const int &) const;
    string getName() const;
    int getNumActions();
    string getAction(const int index);
    
    void changeStat(const string &stat, const short &value);
    bool resolveAction(const Player &targetCreature, const Action &theAction );
};

