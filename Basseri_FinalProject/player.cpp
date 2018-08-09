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
#include "Action.h"
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

Player::~Player() {}    

void Player::changeStat(const string &key, const short &value)
{
    m_stats[ m_statMap.at(key)] += value;
}

Ushort  Player::getStat(const string &s) { return m_stats[ m_statMap[s] ]; }
Ushort  Player::getStat(const int &index) { return m_stats[index]; };
string Player::getName() const { return m_name; }
int Player::getAbilityMod(const string &s) const { return m_abilityMods[ m_statMap[s] ]; }
int Player::getNumActions() { return static_cast<int>(m_actions.size()); }
string Player::getAction(const int index) { return m_actions[index]; }

bool Player::resolveAction(const Player &targetCreature, const Action &theAction )
{
    // 1d10 str +0 +0 decrease ac long sword
    string playerName = getName();
    short successMod = theAction.getSuccessMod();
    short abilityMod = getAbilityMod( theAction.getBaseStat() );
    int dieRoll = roll(1, 20);
    short rollResult = dieRoll + successMod + abilityMod;
    
    // Display roll results
    cout << playerName << " rolls a " << dieRoll << "! ";
    cout << " plus " << successMod << " action modifier, ";
    cout << " and " << playerName << "'s " << theAction.getBaseStat() << " modifier of " << abilityMod << endl;
    cout << "For a total of: " << rollResult << endl;
    
    string targetStat = theAction.getTargetStat();
    
    // Determine success
    if ( rollResult >= targetCreature.m_stats[ getStat(targetStat) ])
    {
        cout << "Success!";
        return true;
    }
    else
    {
        cout << playerName << " fails!\n";
        return false;        
    }
}
