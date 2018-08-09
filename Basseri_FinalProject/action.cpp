//
//  action.cpp
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <string>
#include "Action.h"
#include "functions.h"
#include "Player.h"

using namespace std;

// MARK: Constructors
Action::Action()
{
    m_name = "unnamed action";
    m_numRolls = 0;
    m_die = 0;
    m_successMod = 0;
    m_resultMod = 0;
    m_isIncrease = false;
}

Action::Action(const string &line)
{
    // String format: #d# basedOnStat successBonus resultBonus statAffected increase|decrease targetStat <name of action>
    // e.g.: 1d1 str +0 +0 hp decrease ac bite

    stringstream ss;
    ss << line;
    
    // Read in data
    string numRolls;
    getline(ss, numRolls, 'd');
    m_numRolls = stoi(numRolls);
    ss >> m_die;
    
    ss >> m_basedOnStat;
    
    string value;
    ss >> value;
    m_successMod = stoi(value);
    
    ss >> value;
    m_resultMod = stoi(value);
    
    ss >> m_statAffected;
    
    ss >> value;
    m_isIncrease = (value == "increase") ? true : false;
    
    ss >> m_targetStat;
    
    ss.ignore();
    getline(ss, m_name, '\n');
}


Action::~Action() {}

void Action::applyAction(const Player &player, Player *targetCreature) const
{
    string theStat = getStatAffected();
    Uint numRolls  = getNumRolls();
    Uint die       = getDie();
    Uint modifier  = getResultMod();

    short result   = roll(numRolls, die) + modifier;
    
    // Display roll
    cout << "Rolling " << numRolls << "d" << die << " plus " << modifier << "..." << endl;
    
    // Apply result
    result *= isIncrease() ? 1 : -1;
    targetCreature->changeStat(theStat, result);
    
    // Display results
    string effectStr = isIncrease() ? "increases" : "decreases";
    cout << targetCreature->getName() << "'s " << theStat << " " << effectStr << " by " << result << "!\n";
}

// MARK: getters
string Action::getName() const { return m_name; }
Ushort Action::getNumRolls() const { return m_numRolls; }
string Action::getBaseStat() const { return m_basedOnStat; }
Ushort Action::getDie() const { return m_die; }
short Action::getResultMod() const { return m_resultMod; }
short Action::getSuccessMod() const { return m_successMod; }
string Action::getTargetStat() const { return m_targetStat; }
string Action::getStatAffected() const { return m_statAffected; }
bool Action::isIncrease() const { return m_isIncrease; }
