//
//  nonplayer.cpp
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/8/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include "NonPlayer.h"
#include "Stats.h"
#include "functions.h"

using namespace std;

//NonPlayer::NonPlayer() {}

NonPlayer::NonPlayer(const string &filename)
{
    ifstream inFile;
    try         { inFile.open(filename, ios::in); }
    catch (string) { cout << "Couldn't open file " << filename << endl; return; }
    
    string key, value;
    while ( inFile >> key >> value )
    {
        if ( key == "action" )
            m_actions.push_back( value );
        else if ( key == "policy" )
            m_policies.push_back( value );
        else if ( key == "name" )
            m_name = value;
        else // Default: it's a stat
            m_stats[ m_statMap[key] ] = stoi(value);
    }
    
    inFile.close();
    
    for (int i = 0; i < NUM_ABILITY_MODS; ++i)
        m_abilityMods[i] = (m_stats[i] - 10) / 2;
    
    // Calculate hp
    m_stats[ m_statMap["hp"] ] += roll(m_stats[ m_statMap["hpDie"] ], m_stats[m_statMap["hpRolls"]]);
}

Decision NonPlayer::decide(const Party &friends, const Party &foes, PolicyMap &policyMap)
{
    Decision decision;
    vector<double> decisionScores;
    Party theParty;
    
    //    for (string policy : m_policies )
    //    {
    ////        Policy thisPolicy = policyMap[policy];
    ////        if ( policyMap[policy].targetIsFoe() )
    //        if (true)
    ////            theParty = foes;
    ////        else
    ////            theParty = friends;
    //    }
    
    return decision;
}

