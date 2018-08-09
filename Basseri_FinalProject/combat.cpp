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

void fight(Party allies, vector<NonPlayer> opponents, ActionsMap actions, PolicyMap policies)
{
    vector<Player *> combatants;
    for (int i = 0; i < allies.size(); ++i)
        combatants.push_back( &allies[i] );
    for (int i = 0; i < opponents.size(); ++i)
        combatants.push_back( &opponents[i] );
    
    // loop over players
    for (Player *combatant : combatants )
    {
        NonPlayer *c = reinterpret_cast<NonPlayer *>(combatant);
        if (c == nullptr)
        {
            cout << "It's " << combatant->getName() << "'s turn!\n";
            cout << "Make your choice: \n";
            for (int i = 0; i < combatant->getNumActions(); ++i)
                cout << i + 1 << ":" << combatant->getAction(i) << endl;
            cout << "==>";
            int choice;
            cin >> choice;
            // TODO: do some validation
            string actionString = combatant->getAction(--choice);
            Action theAction = actions.at(actionString);
            
            cout << "Choose your target: \n";
            for (int i = 0; i < combatants.size(); ++i)
                cout << i + 1 << ": " << combatants[i]->getName() << endl;
            cout << "==>";
            cin >> choice;
            
            Player *targetCreature = combatants[--choice];
            
            bool success = combatant->resolveAction(*targetCreature, theAction);
            
            if (success)
                theAction.applyAction(*combatant, targetCreature);
            
            if ( targetCreature->getStat(stat::hp) <= 0)
            {
                auto it = find(combatants.begin(), combatants.end(), targetCreature);
                combatants.erase(it);
            }
        }
        else
        {
            combatant;
        }

        
    }
    
    // loop over opponents
    for (NonPlayer opponent : opponents)
    {
        // make decision
        // resolve action
        // test for deaths/end of fight

        
    }
    
    // resolve action
    // if monster, perform logic
    // if player, prompt for options
    // calculate consequences
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
