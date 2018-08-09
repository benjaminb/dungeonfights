//
//  action.cpp
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//
#include <sstream>
#include <string>
#include "Action.h"

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
    // String format: #d# basedOnStat successBonus resultBonus increase|decrease targetStat <name of action>

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
    
    ss >> value;
    m_isIncrease = (value == "increase") ? true : false;
    
    ss >> m_targetStat;
    
    ss.ignore();
    getline(ss, m_name, '\n');
}


Action::~Action() {}

// MARK: methods
string Action::getName() { return m_name; }
Ushort Action::getNumRolls() { return m_numRolls; }
string Action::getBaseStat() { return m_basedOnStat; }
Ushort Action::getDie() { return m_die; }
short Action::getResultMod() { return m_resultMod; }
short Action::getSuccessMod() { return m_successMod; }
string Action::getTargetStat() { return m_targetStat; }
