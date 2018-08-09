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
//#include "Stats.h"
#pragma once

class Decision;

class NonPlayer: public Player {
private:
    vector<string> m_policies;
public:
    NonPlayer(const string &filename);
    Decision decide(const Party &, const Party&, PolicyMap&);
};

class Decision
{
    Player *m_target;
    Action action;
};
