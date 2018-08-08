//
//  Startup.h
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/5/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//
#include <vector>
#include <string>
#include "Action.h"
#include "Player.h"
#include "Policy.h"
#pragma once

using namespace std;


ActionsMap      loadActions     (const string &);
vector<Player>  loadParty       (const string &filename, const ActionsMap& actions);
//PolicyMap       loadPolicies    (const string &filename);
