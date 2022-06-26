#include "graph.h"
#include <cmath>
#include <cstddef>
#include <iostream>
#include <tuple>
#include <vector>

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
  os << "Nodes : \n";
  graph.forAllNodes([&](std::size_t nodeId) { os << nodeId << '\n'; });
  os << "Edges : \n";
  graph.forAllEdges([&](std::size_t edgeId) {
    auto [from, to] = graph.getAdjacentNodeIds(edgeId);
    os << edgeId << " : " << from << "->( " << graph.getEdgeWeight(edgeId)
       << " )->" << to << '\n';
  });
  os.flush();
  return os;
}

// Implementation for AdjacentGraph
std::size_t AdjacentGraph::addEdge(std::size_t nodeId1,
                                   std::size_t nodeId2,
                                   double weight) {
  this->weights[nodeId1][nodeId2] = weight;

  // formula for finding edge: y * len(matrix) + x
  return nodeId1 * this->weights.size() + nodeId2;
}

std::size_t AdjacentGraph::addNode() {
  // Add another vector to the vector
  const size_t s = this->weights.size() + 1;

  weights.resize(s);

  // update each row
  for (auto& row : this->weights) {
    row.resize(s);
  }

  return s;
}

std::tuple<std::size_t, std::size_t> AdjacentGraph::getAdjacentNodeIds(
    std::size_t edgeId) const {
  // Get "coordinates" from the ID
  size_t r = 0;
  while ((r+1) * this->weights.size() <= edgeId) {
    r += 1;
  }
  size_t c = edgeId - (r * this->weights.size());

  return std::make_tuple(c, r);
}

std::vector<std::size_t> AdjacentGraph::getInEdgeIds(std::size_t nodeId) const {
  std::vector<std::size_t> refs;
  // Loop over specified column and add positive values
  for (std::size_t i = 0; i < this->weights.size(); ++i) {
    if (this->weights[i][nodeId] > 0) {
      refs.push_back(i);
    }
  }

  return refs;
}

std::vector<std::size_t> AdjacentGraph::getOutEdgeIds(
    std::size_t nodeId) const {
  std::vector<std::size_t> refs;
  // Loop over specified row and add positive values
  for (std::size_t i = 0; i < this->weights.size(); ++i) {
    if (this->weights[nodeId][i] > 0) {
      refs.push_back(i);
    }
  }

  return refs;
}

void AdjacentGraph::setEdgeWeight(std::size_t edgeId, double weight) {
  std::tuple<std::size_t, std::size_t> coords =
      this->getAdjacentNodeIds(edgeId);
  this->weights[std::get<0>(coords)][std::get<1>(coords)] = weight;
}

double AdjacentGraph::getEdgeWeight(std::size_t edgeId) const {
  std::tuple<std::size_t, std::size_t> coords =
      this->getAdjacentNodeIds(edgeId);
  return this->weights[std::get<0>(coords)][std::get<1>(coords)];
}

void AdjacentGraph::forAllEdges(
    const std::function<void(std::size_t edgeId)>& function) const {
  for (size_t r = 0; r < this->weights.size(); ++r) {
    for (size_t c = 0; c < this->weights.size(); ++c) {
      if (this->weights[r][c] > 0) {
        // calculate edge id
        size_t edge = r * this->weights.size() + c;
        function(edge);
      }
    }
  }
}

void AdjacentGraph::forAllNodes(
    const std::function<void(std::size_t nodeId)>& function) const {
  for (size_t r = 0; r < this->weights.size(); ++r) {
    function(r);
  }
}

// Implementation for ClassicGraph
std::size_t ClassicGraph::addEdge(std::size_t nodeId1,
                                  std::size_t nodeId2,
                                  double weight) {
  ClassicGraph::Edge e(nodeId1, nodeId2, weight);
  this->edges.push_back(e);
  return this->edges.size();
}

std::size_t ClassicGraph::addNode() {
  ClassicGraph::Node n;
  this->nodes.push_back(n);
  return this->nodes.size();
}

std::tuple<std::size_t, std::size_t> ClassicGraph::getAdjacentNodeIds(
    std::size_t edgeId) const {
  ClassicGraph::Edge e = this->edges[edgeId];
  return std::make_tuple(e.node1, e.node2);
}

std::vector<std::size_t> ClassicGraph::getInEdgeIds(std::size_t nodeId) const {
  ClassicGraph::Node n = this->nodes[nodeId];
  return n.incoming;
}

std::vector<std::size_t> ClassicGraph::getOutEdgeIds(std::size_t nodeId) const {
  ClassicGraph::Node n = this->nodes[nodeId];
  return n.outgoing;
}

void ClassicGraph::setEdgeWeight(std::size_t edgeId, double weight) {
  this->edges[edgeId].weight = weight;
}

double ClassicGraph::getEdgeWeight(std::size_t edgeId) const {
  ClassicGraph::Edge e = this->edges[edgeId];
  return e.weight;
}

void ClassicGraph::forAllEdges(
    const std::function<void(std::size_t edgeId)>& function) const {
  for (size_t i = 0; i < this->edges.size(); ++i) {
    function(i);
  }
}

void ClassicGraph::forAllNodes(
    const std::function<void(std::size_t nodeId)>& function) const {
  for (size_t i = 0; i < this->edges.size(); ++i) {
    function(i);
  }
}