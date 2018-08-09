//
//  character.cpp
//  DungeonCrawl
//
//  Created by Benjamin Basseri on 8/4/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "functions.h"
#include "StatEnum.h"
using namespace std;

map<const string, unsigned int> Player::m_statMap = {
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

Player::Player()
{
    m_name = "unnamed character";
}

Player::Player(const string &filename)
{
    ifstream inFile;
    try         { inFile.open(filename, ios::in); }
    catch (string) { cout << "Couldn't open file " << filename << endl; return; }
    
    string key, value;
    while ( inFile >> key >> value )
    {
        if ( key == "action" )
            m_actions.push_back( value );
        else if ( key == "name" )
            m_name = value;
        else // Default: it's a stat
            m_stats[ m_statMap.at(key) ] = stoi(value);
    }
    
    inFile.close();
    
    for (int i = 0; i < NUM_ABILITY_MODS; ++i)
        m_abilityMods[i] = (m_stats[i] - 10) / 2;
    
    // Calculate hp
    m_stats[ m_stats[stat::hp] ] += roll( m_stats[stat::hpDie], m_stats[stat::hpRolls]);
    
    return;
}

string Player::getName() const { return m_name; }

int Player::getAbilityMod(const string &s) const
{
    return m_abilityMods[ m_statMap[s] ];
}

Ushort  Player::getStat(const string &s)
{
    return m_stats[ m_statMap[s] ];
}

int Player::getNumActions() { return static_cast<int>(m_actions.size()); }

string Player::getAction(const int index)
{
    return m_actions[index];
}
