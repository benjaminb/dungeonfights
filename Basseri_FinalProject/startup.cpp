//
//  startup.cpp
//  Basseri_final
//
//  Created by Benjamin Basseri on 8/5/18.
//  Copyright © 2018 Benjamin Basseri. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Startup.h"

using namespace std;

// loads each Action object into a map, keyed by its string name
ActionsMap loadActions(const string &filename)
{
    ActionsMap actions;
    ifstream inFile;
    try
    {
        inFile.open(filename, ios::in);
        if (!inFile)
            throw ("Couldn't open ");
    }
    catch (char const* s)
    {
        cout << s << filename << endl;
    }
    
    string line;
    
    while ( getline(inFile, line, '\n') )
    {
        Action newAction(line);
        actions[newAction.getName()] = newAction;
    }
    
    inFile.close();
    
    return actions;
}

vector<Player> loadParty(const string &fileList, const ActionsMap& actions)
{
    vector<Player> party;
    ifstream inFile(fileList, ios::in);
    string line;
    while ( getline(inFile, line, '\n') )
    {
        Player newCharacter(line);
        party.push_back(newCharacter);
    }
    return party;
}

vector<NonPlayer> loadOpponents(const string &fileList, const ActionsMap& actions)
{
    vector<NonPlayer> opponents;
    ifstream inFile(fileList, ios::in);
    string line;
    while ( getline(inFile, line, '\n') )
    {
        NonPlayer newCharacter(line);
        opponents.push_back(newCharacter);
    }
    return opponents;
}


PolicyMap loadPolicies(const string &filename)
{
    PolicyMap policies;
    ifstream inFile;
    try
    {
        inFile.open(filename, ios::in);
        if (!inFile)
            throw ("Couldn't open ");
    }
    catch (char const* s)
    {
        cout << s << filename << endl;
    }

    string line;

    while ( getline(inFile, line, '\n') )
    {
        Policy newPolicy(line);
        policies[newPolicy.getName()] = newPolicy;
    }

    inFile.close();

    return policies;
}
