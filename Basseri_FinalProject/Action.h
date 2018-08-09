//
//  Action.h
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/4/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

/* An Action can be an attack, spell etc that has an effect on a certain stat, either to increase
 or decrease it. The amount of the effect is determined by a die roll. For actions that have set results,
 like +5 hp, we can make numRolls 0 and a bonus in the resultMod of +5 */

#include <string>
#include <map>
#include <sstream>
#pragma once

using namespace std;

class Action;
typedef unsigned short Ushort;
typedef map<const string, Action> ActionsMap;

class Action
{
private:
    string m_name;
    Ushort m_numRolls;
    string m_statAffected;
    string m_basedOnStat;
    Ushort m_die;
    short  m_resultMod;  // Bonus / penalty to resulting roll
    short  m_successMod; // Bonus / penalty to execute the action
    bool   m_isIncrease;
    string m_targetStat;
public:
    Action();
    Action(const string &);
    ~Action();
    
    // Getters
    string getName();
    bool isIncrease();
    Ushort getNumRolls();
    string getBaseStat();
    Ushort getDie();
    short getResultMod();
    short getSuccessMod();
    string getTargetStat();
    string getStatAffected();
};
