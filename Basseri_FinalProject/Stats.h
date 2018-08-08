#include <string>
#include <map>
#pragma once

using namespace std;

const unsigned int NUM_STATS = 11;
const string statsStrings[NUM_STATS] = {
    "str",
    "dex",
    "con",
    "int",
    "wis",
    "cha",
    "ac",
    "hp",
    "hitDice",
    "hpRolls",
    "hpDie"
};

// Maps string abbreviation of stat to its index
map<const string, unsigned int> statMap = {
    {"str", 0},
    {"dex", 1},
    {"con", 2},
    {"int", 3},
    {"wis", 4},
    {"cha", 5},
    {"ac", 6},
    {"hp", 7},
    {"hitDice", 8},
    {"hpRolls", 9},
    {"hpDie", 10}
};

enum Stat {
    str,
    dex,
    con,
    intl, // Watch out for the 'l'!
    wis,
    cha,
    ac,
    hp,
    hitDice,
    hpRolls,
    hpDie
};
