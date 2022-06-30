/**
 * Implementation of Tower and Hanoi
 */

#include "hanoi.h"
#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <ostream>
#include <stack>
#include <string>

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
        preMovePrint(origin.getName(), target.getName());
        
        // Check if move is legal
        if (!target.getTower().empty()) {
        if (target.getTower().back() < origin.getTower().front()) {
            return;
        }
        }

        size_t p = origin.getTower().back();
        origin.getTower().pop_back();
        target.getTower().push_back(p);

        postMovePrint();
}

void Hanoi::solveHanoi(
    size_t towersize,
    Tower& source,
    Tower& destination,
    Tower& spare,
    const std::function<void(const std::string&, const std::string&)>&
        preMovePrint,
    const std::function<void()>& postMovePrint) {
        if (towersize == 1) {
            moveTopPlate(source, destination, preMovePrint, postMovePrint);
        } else {
            solveHanoi(towersize - 1, source, spare, destination, preMovePrint, postMovePrint);
            moveTopPlate(source, destination, preMovePrint, postMovePrint);
            solveHanoi(towersize - 1, spare, destination, source, preMovePrint, postMovePrint);
        }
}

void Hanoi::solveHanoiStart(std::ostream& os,
                            Tower& source,
                            Tower& destination,
                            Tower& spare) {

    auto pre = [&](std::string a, std::string b)
    {
        os << a << " -> " << b << std::endl;
    };

    auto post = [&]()
    {

        // Get the greatest sized tower
        size_t m = std::max({towerA.getTower().size(), towerB.getTower().size(), towerC.getTower().size()});

        for (int i = m - 1; i >= 0; --i) {
            if (i < towerA.getTower().size()) {
                os << towerA.getTower()[i];
            } else {
                os << "│";
            }

            os << " ";

            if (i < towerB.getTower().size()) {
                os << towerB.getTower()[i];
            } else {
                os << "│";
            }

            os << " ";

            if (i < towerC.getTower().size()) {
                os << towerC.getTower()[i];
            } else {
                os << "│";
            }

            os << std::endl;
        }

        os << "╧═╧═╧" << std::endl;
    };

    solveHanoi(this->towerA.getTower().size(), source, destination, spare, pre, post);
}
