//
//  main.cpp
//  Basseri_FinalProject
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Action.h"
#include "Combat.h"
#include "Startup.h"
#include "NonPlayer.h"
#include "Player.h"
#include "Policy.h"



using namespace std;

int main() {
    srandom( static_cast<unsigned int>( time(nullptr) ) );
    
    ActionsMap actions = loadActions("actions.txt");
    PolicyMap policies = loadPolicies("policies.txt");
    Party theHeroes = loadParty("party.txt", actions);
    vector<NonPlayer> theRats = loadOpponents("round1.txt", actions);
    
    fight(theHeroes, theRats);
    
    return 0;
}
