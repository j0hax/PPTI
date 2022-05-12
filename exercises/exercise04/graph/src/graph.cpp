/**
 * @file graph.cpp
 */
#include "graph.h"
#include <algorithm>

// Complete the following constructor:
Vertex::Vertex(std::string name,
               size_t vertexId)
{}   

void Vertex::addInEdgeId(size_t edgeId)
{
    // Add code here.
} 

void Vertex::addOutEdgeId(size_t edgeId)
{
    // Add code here.
}

// Complete the following constructor:
Edge::Edge(size_t edgeId, size_t inVertexId, size_t outVertexId)
{}

/**
 * Factory function to make a new Vertex
 * @returns Id of the new Vertex
 */
size_t Graph::makeVertex(const std::string& name)
{
    // Add code here.
    return 0; // Change this line.
}

/**
 * Factory function to make a new Edge
 * @returns Id of the new edge
 */
size_t Graph::makeEdge(const size_t inVertexId, const size_t outVertexId)
{
    // Add code here.
    // Do not forget to set in and out edge IDs to the vertices.
    return 0; // Change this line.
}

Vertex& Graph::getVertex(size_t id) { return this->vertices[id]; }
Edge& Graph::getEdge(size_t id) { return this->edges[id]; }

const Vertex& Graph::getVertex(size_t id) const { return this->vertices[id]; }
const Edge& Graph::getEdge(size_t id) const { return this->edges[id]; }

void printGraph(std::ostream& os, const Graph& graph)
{
    os << "-------------------------------------------" << std::endl;
    for(const Vertex& vertex: graph.getVertices())
    {
        os << "Vertex Name: " << vertex.getName() << std::endl;
        os << "Input Edges: " << std::endl;
        if(vertex.getInEdgeIds().empty())
        {
            os << " " << std::endl;
        }
        else
        {
            for(const size_t& inEdgeId: vertex.getInEdgeIds()) {
                os << "Edge ID: " << inEdgeId << std::endl;
            }
        }
        os << "Output Edges: " << std::endl;
        if(vertex.getOutEdgeIds().empty())
        {
            os << " " << std::endl;
        }
        else
        {
            for(const size_t& outEdgeId: vertex.getOutEdgeIds()) {
                os << "Edge ID: " << outEdgeId << std::endl;
            }
        }
        os<<"\n";
    }
    os << "-------------------------------------------" << std::endl;
}


