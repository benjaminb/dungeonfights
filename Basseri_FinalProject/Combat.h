//
//  Combat.h
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/5/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <vector>
#include "Player.h"
#include "Action.h"
#include "NonPlayer.h"
#include "functions.h"
#pragma once

using namespace std;

// Prototypes
void fight(vector<Player> players, vector<NonPlayer> opponents);
void resolveAction(const Player *targetCreature, Action theAction );


