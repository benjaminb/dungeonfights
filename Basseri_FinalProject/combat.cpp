////
////  combat.cpp
////  Basseri_final
////
////  Created by Benjamin Basseri on 8/5/18.
////  Copyright © 2018 Benjamin Basseri. All rights reserved.
////
//
#include <iostream>
#include "Combat.h"
#include "StatEnum.h"


using namespace std;

void fight(Party players, vector<NonPlayer> opponents, ActionsMap actions, PolicyMap policies)
{
    vector<Player *> combatants;
    for (int i = 0; i < players.size(); ++i)
        combatants.push_back( &players[i] );
    for (int i = 0; i < opponents.size(); ++i)
        combatants.push_back(  dynamic_cast<Player *>(&opponents[i]) );
    
    Uint round = 1;
    // Combat loop
    while ( combatants.size() > 0 )
    {
        cout << "@$%$ROUND " << round++ << "!@#$%" << endl;
        for (Player *combatant : combatants )
        {
            // Present combatants
            cout << "Combatants still standing: " << combatants.size() << endl;
            
            Player *targetCreature;
            NonPlayer *c = dynamic_cast<NonPlayer *>(combatant);
            if (c == nullptr)
            {
                for (int i = 0; i < combatants.size(); ++i)
                {
                    cout << i + 1 << ": " << combatants[i]->getName();
                    cout << "(hp: " << combatants[i]->getStat(stat::hp) << ")" << endl;
                }
                
                cout << "It's " << combatant->getName() << "'s turn!" << endl;
                
                cout << "Choose your target: ==>";
                int choice;
                cin >> choice;
                
                targetCreature = combatants[--choice];
                cout << "Make your choice: \n";
                for (int i = 0; i < combatant->getNumActions(); ++i)
                    cout << i + 1 << ":" << combatant->getAction(i) << endl;
                cout << "==>";
                cin >> choice;
                // TODO: do some validation
                string actionString = combatant->getAction(--choice);
                Action theAction = actions.at(actionString);
                
                bool success = combatant->resolveAction(*targetCreature, theAction);
                
                if (success)
                    theAction.applyAction(*combatant, targetCreature);
            }
            else // it's a monster's turn
            {
                Decision d = c->decide(opponents, players, policies);
                targetCreature = d.getTarget();
                Action theAction = actions.at( d.getAction() );
                
                // Display opponent's decision
                cout << c->getName() << " decides to " << d.getAction() << " ";
                cout << targetCreature->getName() << "!\n";
                
                bool success = c->resolveAction(*targetCreature, theAction);
                if (success)
                    theAction.applyAction(*combatant, targetCreature);
            }

            if ( targetCreature->getStat(stat::hp) <= 0)
            {
                cout << targetCreature->getName() << " bites the dust!\n";
                auto it = find(combatants.begin(), combatants.end(), targetCreature);
                combatants.erase(it);
            }
            
            char x;
            cout << "======================\n";
            cout << "enter any char to continue...\n";
            cin  >> x;
        } // end for (end of turn)
    } // end while (end of round)

    return;
}
