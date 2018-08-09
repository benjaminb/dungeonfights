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

void takeAParty(vector<Player> party);


class NonPlayer: public Player {
private:
    vector<string> m_policies;
    static map<const string, unsigned int> m_policyMap;

public:
    NonPlayer(const string &filename);
    virtual ~NonPlayer();
    Decision decide(vector<NonPlayer> &allies, Party &foes, const PolicyMap &policyMap);
};

class Decision
{
private:
    Player *m_target;
    string m_action;

public:
    Decision();
    
    void setTarget(Player *);
    void setAction(const string &);
    Player * getTarget();
    string getAction();
};
