//
//  main.cpp
//  Basseri_FinalProject
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <iostream>
#include "Action.h"
#include "Startup.h"
#include "Player.h"
//#include "Stats.h"

using namespace std;

int main() {

    ActionsMap actions = loadActions("actions.txt");
    Player magnus("fighter.txt");
    Party usGuys = loadParty("round1.txt", actions);
    
    return 0;
}
