//
//  Policy.h
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <string>
#include "Player.h"
#pragma once

class Policy;
typedef map<string, Policy> PolicyMap;

class Policy {
private:
    string  m_name;
    bool    m_targetIsFoe;
    string  m_targetStat;
    int     m_targetValue;
    string  m_targetAction;
    double  m_priority;
public:
    Policy();
    Policy(const string &line);
    ~Policy();
    
    string getName();
    bool targetIsFoe();
};
