//
//  functions.cpp
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/4/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <cstdlib>
#include "functions.h"

Uint roll(Uint rolls, Uint die)
{
    Uint result = 0;
    for (int i = 0; i < rolls; ++i)
        result += random() % die + 1;
    return result;
}

//bool compareCriteria(const Player &p1, const Player &p2, const string &criteria, const string &lookingFor)
//{
//    // TODO: add a try on the lookingFor string
//    if ( lookingFor == "min")
//        return p1.getStat(criteria) < p2.getStat(criteria);
//    if ( lookingFor == "max")
//        return p1.getStat(criteria) > p2.getStat(criteria);
//
//    cout << "Didn't understand the lookingFor string. Returning false\n";
//    return false;
//
//}
//
//// TODO: do something with the bool parameter
//void comparePlayers(const vector<Player> &players, const string &criteria, bool returnMax)
//{
//    // create a playerComparison array
//    // sort based on m_value
//    PlayerComparison *playerCmp = new PlayerComparison[players.size()];
//
//    int i = 0;
//    for (Player p : players)
//    {
//        PlayerComparison thisPlayer(&p, p.getStat(criteria));
//        playerCmp[i++] = thisPlayer;
//    }
//
//    delete[] playerCmp;
//}



