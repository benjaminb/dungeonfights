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
#include "StatEnum.h"
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
    m_stats[ m_stats[stat::hp] ] += roll( m_stats[stat::hpDie], m_stats[stat::hpRolls]);
}

Decision::Decision()
{
    m_target = nullptr;
    m_action = "";
}

void Decision::setTarget(Player *target) { m_target = target; }

Decision NonPlayer::decide(Party &allies, Party &foes, PolicyMap &policyMap)
{
    Decision decision;
    vector<double> decisionScores;
    
        for (string policy : m_policies )
        {
            Policy thisPolicy = policyMap[policy];
            
            
            // TODO: Refactor this to a function or get it to branch properly
            if ( thisPolicy.targetIsFoe() )
            {
                int targetValue = thisPolicy.getTargetValue();
                string targetStat = thisPolicy.getTargetStat();
                
                decision.setTarget(&foes[0]);
                double currentHighestDifference = (foes[0].getStat(targetStat) - targetValue) * thisPolicy.getPriority();
                
                for (Uint i = 1; i < foes.size(); ++i)
                {
                    int difference = abs(foes[i].getStat(targetStat) - targetValue) * thisPolicy.getPriority();
                    if (difference > currentHighestDifference)
                        decision.setTarget(&foes[i]);
                }
            }
            else
            {
                int targetValue = thisPolicy.getTargetValue();
                string targetStat = thisPolicy.getTargetStat();
                
                decision.setTarget(&allies[0]);
                double currentHighestDifference = (allies[0].getStat(targetStat) - targetValue) * thisPolicy.getPriority();
                
                for (Uint i = 1; i < allies.size(); ++i)
                {
                    int difference = abs(allies[i].getStat(targetStat) - targetValue) * thisPolicy.getPriority();
                    if (difference > currentHighestDifference)
                        decision.setTarget(&allies[i]);
                }
            }
        }
    
    return decision;
}

