//
//  character.cpp
//  DungeonCrawl
//
//  Created by Benjamin Basseri on 8/4/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include "Player.h"
#include "functions.h"
//#include "Action.h"
using namespace std;

Player::Player() { m_name = "unnamed character"; }

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
            m_stats[statMap[key]] = stoi(value);
    }
    
    inFile.close();
    
    for (int i = 0; i < NUM_ABILITY_MODS; ++i)
        m_abilityMods[i] = (m_stats[i] - 10) / 2;
    
    // Calculate hp
    m_stats[hp] += roll(m_stats[hpDie], m_stats[hpRolls]);
}

string  Player::getName() const { return m_name; }

int Player::getAbilityMod(const string & a) const
{
    return m_abilityMods[ statMap[a] ];
}

Ushort  Player::getStat(const string &s) const
{
    return m_stats[ statMap[s] ];
}

