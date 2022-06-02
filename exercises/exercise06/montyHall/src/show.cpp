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
    // TODO: Implement Show::getGoatDoor here
    // Dummy:
    return 0;
}



