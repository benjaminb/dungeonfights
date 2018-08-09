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
            m_stats[ m_statMap.at(key) ] = stoi(value);
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

Decision NonPlayer::decide(const vector<NonPlayer> &allies, const Party &foes, const PolicyMap &policyMap)
{
    Decision decision;
    double lowScore = __DBL_MAX__;
//    Player * targetPlayer = nullptr;
    
        for (string policy : m_policies )
        {
            Policy thisPolicy = policyMap.at(policy);
            
            vector<Player *> targetParty;
            if ( thisPolicy.targetIsFoe() )
            {
                for (Player p : foes)
                    targetParty.push_back(&p);
            }
            else
            {
                for (NonPlayer p : allies)
                    targetParty.push_back(&p);
            }
            
            int targetValue = thisPolicy.getTargetValue();
            string targetStat = thisPolicy.getTargetStat();
        
            decision.setTarget( targetParty[0] );
            
            for (Uint i = 0; i < targetParty.size(); ++i)
            {
                double score = abs(targetParty[i]->getStat(targetStat) - targetValue) * thisPolicy.getPriority();
                if (score < lowScore)
                {
                    lowScore = score;
                    decision.setTarget(targetParty[i]);
                    decision.setAction( thisPolicy.getTargetAction() );
                }
            }
        }
    
    return decision;
}

void Decision::setAction(const string &actionString) { m_action = actionString; }

Player * Decision::getTarget() { return m_target; }
string Decision::getAction() { return m_action; }
