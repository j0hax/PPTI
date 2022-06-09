/**
 * @file show.cpp
 */

#include <random>
#include <cassert>
#include "show.h"


static std::random_device rd;
std::default_random_engine Show::re(rd());

Show::Show()
{
    std::uniform_int_distribution<int> dist(1, 3);
    carDoor = dist(re);
}

int Show::showGoatDoor(int firstGuess)
{
    std::vector<int> probs = {1, 1, 1};

    // "Remove" our known values
    probs[firstGuess - 1] = 0;
    probs[carDoor - 1] = 0;

    std::discrete_distribution<int> dist(probs.begin(), probs.end());
    
    return dist(re) + 1;
}



