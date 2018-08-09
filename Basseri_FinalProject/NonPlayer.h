//
//  NonPlayer.h
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <string>
#include <vector>
#include "Player.h"
#include "Policy.h"
#pragma once

class Decision;

using namespace std;

class NonPlayer: public Player {
private:
    vector<string> m_policies;
public:
    NonPlayer(const string &filename);
    Decision decide(vector<NonPlayer> &, Party&, PolicyMap&);
};

class Decision
{
private:
    Player *m_target;
    string m_action;
    Policy m_outcome;
public:
    Decision();
    
    void setTarget(Player *);
    void setAction(const string &);
};
