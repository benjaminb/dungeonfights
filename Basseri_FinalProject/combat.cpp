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
    
    
    // Combat loop
    while ( combatants.size() > 0 )
    {

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
                cout << c->getName() << " decides to " << d.getAction();
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
            
//            ++counter;
        } // end for (end of turn)
    } // end while (end of round)

    return;
}


//
//vector<const Player *> resolveCombatOrder(const vector<Player> &players, const vector<Player> &opponents)
//{
//    // Roll & sort based on initiative
//    vector<PlayerComparison> combatants;
//    rollInitiative(players, combatants);
//    rollInitiative(opponents, combatants);
//    sort(combatants.begin(), combatants.end(), compare);
//
//    // Extract Character *'s to vector since you don't need CharacterComparison objects anymore
//    vector<const Player *> combatOrder;
//    for ( PlayerComparison c : combatants )
//        combatOrder.push_back( c.getCharachterPtr() );
//
//    return combatOrder;
//}
//
//void randomizeFightOrder(const vector<Player> &players, const vector<NonPlayer> &opponents)
//{
//
//    vector<Player const *> combatOrder;
//
//    for ( const Player & player : players)
//        combatOrder.push_back(&player);
//
//    for ( const Player & opponent : opponents)
//        combatOrder.push_back(&opponent);
//
//    std::shuffle( combatOrder.begin(), combatOrder.end(), random() );
//}
