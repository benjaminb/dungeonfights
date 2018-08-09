//
//  Policy.h
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <string>
#include <vector>
#include <map>
#pragma once

using namespace std;

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
    
    // Getters
    string getName();
    bool targetIsFoe();
    string getTargetStat();
    int getTargetValue();
    string getTargetAction();
    double getPriority();
};
