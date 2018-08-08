//
//  policy.cpp
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include "Policy.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Constructors
Policy::Policy() {
    m_targetIsFoe = 0;
    m_targetStat =  "";
    m_targetValue = 0;
    m_targetAction = "";
    m_priority = 0.0;
    m_name = "";
}

Policy::Policy(const string &line)
{
    // String format: "foe"|"friend" "stat" # "action" # "name of policy"
    stringstream ss;
    ss << line;
    
    // Read in data
    string targetParty;
    //    ss >> targetParty;
    getline(ss, targetParty, ' ');
    m_targetIsFoe = (targetParty == "foe") ? true : false;
    ss >> m_targetStat;
    ss >> m_targetValue;
    ss >> m_targetAction;
    ss >> m_priority;
    
    ss.ignore();
    getline(ss, m_name, '\n');
}

Policy::~Policy() {}

string Policy::getName() { return m_name; }
bool   Policy::targetIsFoe() { return m_targetIsFoe; }
