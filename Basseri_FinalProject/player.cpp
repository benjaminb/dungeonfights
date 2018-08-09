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
            m_stats[ m_statMap[key] ] = stoi(value);
    }
    
    inFile.close();
    
    for (int i = 0; i < NUM_ABILITY_MODS; ++i)
        m_abilityMods[i] = (m_stats[i] - 10) / 2;
    
    // Calculate hp
    m_stats[ m_stats[stat::hp] ] += roll( m_stats[stat::hpDie], m_stats[stat::hpRolls]);
}

string Player::getName() { return m_name; }

int Player::getAbilityMod(const string &s)
{
    return m_abilityMods[ m_statMap[s] ];
}

Ushort  Player::getStat(const string &s)
{
    return m_stats[ m_statMap[s] ];
}

