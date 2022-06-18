/**
 * @file player.cpp
 */

#include "player.h"

Player::Player(Deck* d) : deck(d)
{}

size_t Player::getHandValue() const
{
    // TODO: Add code here
    // Dummy return:
    return 0;
}

bool Player::isBust() const 
{
    // TODO: Add code here
    // Dummy return:
    return true;
}

bool Player::hasBlackjack() const
{
    // TODO: Add code here
    // Dummy return:
    return true;
}

bool Player::devaluateAce()
{
    // TODO: Add code here
    // Dummy return:
    return false;
}

void Player::takeHit()
{
    // TODO: Add code here
}

void Player::playTurn()
{
    while(!this->isBust() && this->evaluateHand())
        this->takeHit();
}

void Player::resetHand()
{
    this->cards.clear();
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << player.getHandValue();
    os << " (";
    for(size_t card : player.cards)
        os << " " << card;
    os << " " << ")";
    return os;
}

std::unique_ptr<Player> Player::create(PlayerType type, Deck* deck)
{
    // TODO: Implement this factory method
    // Dummy return:
    return nullptr;
}

// TODO: Implement the evaluateHand method for both AutomatedPlayer and ManualPlayer

