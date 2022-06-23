#include <cmath>
#include <tuple>
#include <iostream>
#include "graph.h"

std::ostream& operator<<(std::ostream& os, const Graph& graph)
{
    os << "Nodes : \n";
    graph.forAllNodes([&](std::size_t nodeId)
        {
            os<<nodeId<<'\n';
        });
    os << "Edges : \n";
    graph.forAllEdges([&](std::size_t edgeId)
        {
            auto [from, to] = graph.getAdjacentNodeIds(edgeId);
            os<<edgeId<<" : "<<from<<"->( "<<graph.getEdgeWeight(edgeId)<<" )->"<<to<<'\n';
        });
    os.flush();
    return os;
}

// TODO: Implement member functions of AdjacentGraph and ClassicGraph

