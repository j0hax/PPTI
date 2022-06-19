/**
 * @file deck.cpp
 */

#include "deck.h"
#include <iostream>

std::mt19937 Deck::re(std::random_device{}());

void Deck::fill(size_t packs) {
  this->cards.reserve(52 * packs);
  for (size_t i = 0; i < 4 * packs; ++i) {
    // Add numbered cards and aces:
    for (size_t i = 2; i < 12; ++i)
      this->cards.push_back(i);
    // Add face cards except aces:
    for (size_t i = 0; i < 3; ++i)
      this->cards.push_back(10);
  }
}

InfiniteDeck::InfiniteDeck() {
  this->fill(1);
  this->dist = std::uniform_int_distribution<size_t>(0, this->cards.size() - 1);
}

size_t InfiniteDeck::getRandomCard() {
  auto idx = this->dist(this->re);
  return this->cards[idx];
}

LimitedDeck::LimitedDeck(size_t d) {
  this->packets = d;
  fill(d);
  std::shuffle(this->cards.begin(), this->cards.end(), this->re);
}

size_t LimitedDeck::getRandomCard() {
  // "move" the card from the deck(s) to the list of given cards
  this->discarded.push_back(this->cards.back());
  this->cards.pop_back();
  return this->discarded.back();
}

void LimitedDeck::resetCards() {
  // move all discarded cards back to the deck(s)
  this->cards.insert(this->cards.end(),
                     std::make_move_iterator(this->discarded.begin()),
                     std::make_move_iterator(this->discarded.end()));
  // re-shuffle everything
  std::shuffle(this->cards.begin(), this->cards.end(), this->re);
}
