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
    // String format: #d# +|-# increase|decrease <name of action>
    stringstream ss;
    ss << line;
    
    // Read in data
    string numRolls;
    getline(ss, numRolls, 'd');
    m_numRolls = stoi(numRolls);
    
    ss >> m_die;
    
    string value;
    ss >> value;
    m_successMod = stoi(value);
    
    ss >> value;
    m_resultMod = stoi(value);
    
    ss >> value;
    m_isIncrease = (value == "increase") ? true : false;
    
    ss.ignore();
    getline(ss, m_name, '\n');
}


Action::~Action() {}

// MARK: methods
string Action::getName() { return m_name; }
