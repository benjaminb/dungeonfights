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
    
    string filename = "";
    cout << "Enter filename of party to load: ";
    cin >> filename;
    Party theHeroes = loadParty(filename, actions);
    
    cout << "Thanks! Who do you want to fight?: ";
    cin >> filename;
    vector<NonPlayer> opponents = loadOpponents(filename, actions);

    
    fight(theHeroes, opponents, actions, policies);
    
    cout << "Thanks for playing!\n";
    return 0;
}
