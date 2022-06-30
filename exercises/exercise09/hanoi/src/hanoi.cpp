/**
 * Implementation of Tower and Hanoi
 */

#include "hanoi.h"
#include <algorithm>
#include <deque>
#include <stack>

std::string& Tower::getName() {
  return this->name;
}

std::vector<size_t>& Tower::getTower() {
  return this->tower;
}

Tower::Tower() {}

Tower::Tower(const std::string& name)
    : name(name), tower(std::vector<size_t>()) {}

Tower::Tower(const std::string& name, std::vector<size_t>& v)
    : name(name), tower(v) {}

Hanoi::Hanoi(size_t height) {
  this->towerA = Tower("TowerA");
  for (size_t i = height; i > 0; --i)
    this->towerA.getTower().push_back(i);
  this->towerB = Tower("TowerB");
  this->towerC = Tower("TowerC");
  this->solveHanoiStart(std::cout, this->towerA, this->towerB, this->towerC);
}

void Hanoi::moveTopPlate(
    Tower& origin,
    Tower& target,
    const std::function<void(const std::string&, const std::string&)>&
        preMovePrint,
    const std::function<void()>& postMovePrint) {
  // TODO: Implement
}

void Hanoi::solveHanoi(
    size_t towersize,
    Tower& source,
    Tower& destination,
    Tower& spare,
    const std::function<void(const std::string&, const std::string&)>&
        preMovePrint,
    const std::function<void()>& postMovePrint) {
  // TODO: Implement
}

void Hanoi::solveHanoiStart(std::ostream& os,
                            Tower& source,
                            Tower& destination,
                            Tower& spare) {
  // TODO: Implement
}
