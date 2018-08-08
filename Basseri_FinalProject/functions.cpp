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

