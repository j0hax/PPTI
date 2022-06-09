#include "labyrinth.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

Tile* Labyrinth::getOrigin()
{
    //Implement this function
}

/** Helper function that is supposed to be used to process the neighbors of a Tile. */
void emplaceNeighbor(std::vector<std::vector<Tile>>& floor,
                     std::vector<std::vector<Tile*>>& predecessors,
                     std::queue<Tile*>& pending,
                     Tile* current, size_t x, size_t y)
{
    //Implement this function
}

void Labyrinth::searchShortestPath()
{
    std::queue<Tile*> pending;
    std::vector<std::vector<Tile*>> predecessors(this->floor.size(), std::vector<Tile*>(this->floor[0].size(), nullptr));
    //Implement here
}


void Labyrinth::printLabyrinth(std::ostream& os, bool visualizeVisited) const
{
    for(const std::vector<Tile>& row: this->floor)
    {
        for(const Tile& tile: row)
            tile.print(os, visualizeVisited);
        os<<"\n";
    }
}

