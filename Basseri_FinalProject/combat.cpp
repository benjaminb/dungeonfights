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

using namespace std;

void fight(vector<Player> allies, vector<NonPlayer> opponents, ActionsMap actions)
{
    vector<Player *> combatants;
    for (int i = 0; i < allies.size(); ++i)
        combatants.push_back( &allies[i] );
    for (int i = 0; i < opponents.size(); ++i)
        combatants.push_back( &opponents[i] );
    
    // loop over players
    for (Player ally : allies )
    {
        // prompt user choices
            // loop over actions in this player's action vector
        cout << "It's " << ally.getName() << "'s turn!\n";
        cout << "Make your choice: \n";
        for (int i = 0; i < ally.getNumActions(); ++i)
            cout << i + 1 << ":" << ally.getAction(i) << endl;
        cout << "==>";
        int choice;
        cin >> choice;
        // TODO: do some validation
        string actionString = ally.getAction(--choice);
        Action theAction = actions.at(actionString);
        
        cout << "Choose your target: \n";
        for (int i = 0; i < combatants.size(); ++i)
            cout << i + 1 << ": " << combatants[i]->getName() << endl;
        cout << "==>";
        cin >> choice;
        
        const Player *targetCreature = combatants[--choice];
        
        resolveAction(targetCreature, theAction);

        // resolve action
        
        // test for deaths/end of fight
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

void resolveAction(const Player *targetCreature, Action theAction )
{
    // 1d10 str +0 +0 decrease ac long sword
    int rollResult = roll(theAction.getNumRolls(), theAction.getDie()) + theAction.getSuccessMod();
    rollResult;
    
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