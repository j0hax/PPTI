/**
 * @file player.cpp
 */

#include "player.h"

Player::Player(Deck* d) : deck(d) {}

size_t Player::getHandValue() const {
  size_t total = 0;
  for (const auto& card : this->cards) {
    total += card;
  }

  return total;
}

bool Player::isBust() const {
  return this->getHandValue() > 21;
}

bool Player::hasBlackjack() const {
  return this->cards.size() == 2 && this->getHandValue() == 21;
}

bool Player::devaluateAce() {
  for (auto& card : this->cards) {
    if (card == 11) {
      card = 1;
      return true;
    }
  }

  return false;
}

void Player::takeHit() {
  size_t card = this->deck->getRandomCard();
  this->cards.push_back(card);

  if (this->isBust()) {
    while (this->devaluateAce() && this->isBust()) {
      // Just keep devaluating until no aces are left or the player isn't bust
    }
  }
}

void Player::playTurn() {
  while (!this->isBust() && this->evaluateHand())
    this->takeHit();
}

void Player::resetHand() {
  this->cards.clear();
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
  os << player.getHandValue();
  os << " (";
  for (size_t card : player.cards)
    os << " " << card;
  os << " "
     << ")";
  return os;
}

std::unique_ptr<Player> Player::create(PlayerType type, Deck* deck) {
  switch (type) {
    case PlayerType::automated:
      return std::unique_ptr<Player>(new AutomatedPlayer(deck));
    case PlayerType::manual:
      return std::unique_ptr<Player>(new ManualPlayer(deck));
    default:
      return nullptr;
  }
}

bool AutomatedPlayer::evaluateHand() {
  return this->getHandValue() < 17;
}

bool ManualPlayer::evaluateHand() {
  std::cout << *this << std::endl;
  std::cout << "Hit? (y/n) ";

  std::string s;
  std::cin >> s;

  return std::toupper(s[0]) == 'Y';
}