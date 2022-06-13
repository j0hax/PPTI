#include "labyrinth.h"
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

Tile* Labyrinth::getOrigin() {
  for (auto& row : this->floor) {
    for (auto& t : row) {
      if (t.isOrigin()) {
        return &t;
      }
    }
  }

  // If no origin found, return bogus
  return new Tile('O', 0, 0);
}

/** Helper function that is supposed to be used to process the neighbors of a
 * Tile. */
void emplaceNeighbor(std::vector<std::vector<Tile>>& floor,
                     std::vector<std::vector<Tile*>>& predecessors,
                     std::queue<Tile*>& pending,
                     Tile* current,
                     size_t x,
                     size_t y) {
  // Quick and dirty range check
  if (x >= floor.size() || y >= floor.size()) {
    return;
  }

  Tile t = floor[x][y];

  // Make sure tile is neither a barrier or visited
  if (t.isBarrier() || t.isVisited()) {
    return;
  }

  pending.push(&t);

  predecessors[x][y] = current;
}

void Labyrinth::searchShortestPath() {
  std::queue<Tile*> pending;
  std::vector<std::vector<Tile*>> predecessors(
      this->floor.size(), std::vector<Tile*>(this->floor[0].size(), nullptr));

  Tile* o = getOrigin();

  std::cout << "Origin is at " << o->getX() << ", " << o->getY() << std::endl;

  pending.push(o);

  // Iterate over queue
  while (!pending.empty()) {
    Tile* t = pending.front();

    // emplace each neighbor
    size_t x = t->getX();
    size_t y = t->getY();

    if (x < this->floor.size()) {
      emplaceNeighbor(this->floor, predecessors, pending, t, x + 1, y);
    }

    if (x > 0) {
      emplaceNeighbor(this->floor, predecessors, pending, t, x - 1, y);
    }
    if (y < this->floor[0].size()) {
      emplaceNeighbor(this->floor, predecessors, pending, t, x, y + 1);
    }
    if (y < 0) {
      emplaceNeighbor(this->floor, predecessors, pending, t, x, y - 1);
    }

    pending.pop();
  }

  /* Leider war die Aufgabenstellung in dieser Teilaufgabe für mich etwas
   * unklar...*/

  /*
    for (const auto& r : predecessors) {
      for (const auto& t : r) {
        if (t != nullptr)
          t->print(std::cout, true);
      }
    }
    */
}

void Labyrinth::printLabyrinth(std::ostream& os, bool visualizeVisited) const {
  for (const std::vector<Tile>& row : this->floor) {
    for (const Tile& tile : row)
      tile.print(os, visualizeVisited);
    os << "\n";
  }
}
