/**
 * @file deck.cpp
 */

#include "deck.h"
#include <iostream>

std::mt19937 Deck::re(std::random_device{}());

void Deck::fill(size_t packs)
{
    this->cards.reserve(52 * packs);
    for (size_t i = 0; i < 4 * packs; ++i)
    {
        // Add numbered cards and aces:
        for (size_t i = 2; i < 12; ++i)
            this->cards.push_back(i);
        // Add face cards except aces:
        for (size_t i = 0; i < 3; ++i)
            this->cards.push_back(10);
    }
}

InfiniteDeck::InfiniteDeck()
{
    this->fill(1);
    this->dist = std::uniform_int_distribution<size_t> (0, this->cards.size() - 1);
}

size_t InfiniteDeck::getRandomCard()
{    
    auto idx = this->dist(this->re);
    return this->cards[idx];
}

// TODO: Complete the following constructor
LimitedDeck::LimitedDeck(size_t d)
{

}

size_t LimitedDeck::getRandomCard()
{
    // TODO: Add code here
    // Dummy return:
    return 0;
}

void LimitedDeck::resetCards()
{
    // TODO: Add code here
}

