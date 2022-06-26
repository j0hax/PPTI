#ifndef ABSTRACTGRAPH_GRAPH_H
#define ABSTRACTGRAPH_GRAPH_H
#include <cmath>
#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <tuple>
#include <vector>

/**
 * Graph is an abstract base class for specific graph implementations
 */
class Graph {
 public:
  /// Virtual destructor (necessary due to abstract base class usage)
  virtual ~Graph() = default;

  /// Inserts a directed Edge into the Graph if the Ids of both Nodes are valid
  /// within the Graph
  /// @param nodeId1 Id of incoming Node from which the Edge originates
  /// @param nodeId2 Id of outgoing Node to which the Edge leads
  /// @param weight Weight of the Edge
  /// @returns Id of the new Edge
  virtual std::size_t addEdge(std::size_t nodeId1,
                              std::size_t nodeId2,
                              double weight) = 0;

  /// Adds a new Node to the Graph and returns its Id
  /// @returns Id of the new Node
  virtual std::size_t addNode() = 0;

  /// Returns a tuple of the two Nodes connected by an Edge
  /// @param edgeId Id of the Edge
  /// @returns Tuple of the Ids of the two Nodes connected by the given Edge
  virtual std::tuple<std::size_t, std::size_t> getAdjacentNodeIds(
      std::size_t edgeId) const = 0;

  /// Returns Ids of all Edges going into a Node
  /// @param nodeId Id of the Node
  /// @returns Vector of Ids of incoming Edges
  virtual std::vector<std::size_t> getInEdgeIds(std::size_t nodeId) const = 0;

  /// Returns Ids of all Edges coming out of a Node
  /// @param nodeId Id of the Node
  /// @returns Vector of Ids of outgoing Edges
  virtual std::vector<std::size_t> getOutEdgeIds(std::size_t nodeId) const = 0;

  /// Replaces the weight of an Edge
  /// @param edgeId Id of the Edge
  /// @param weight New weight to be set
  virtual void setEdgeWeight(std::size_t edgeId, double weight) = 0;

  /// Returns the weight of an Edge
  /// @param edgeId Id of the Edge
  virtual double getEdgeWeight(std::size_t edgeId) const = 0;

  /// Executes a function on all Edges of the Graph
  /// @param function The function to be called
  virtual void forAllEdges(
      const std::function<void(std::size_t edgeId)>& function) const = 0;

  /// Executes a function on all Nodes of the Graph
  /// @param function The function to be called
  virtual void forAllNodes(
      const std::function<void(std::size_t nodeId)>& function) const = 0;

 private:
  friend std::ostream& operator<<(std::ostream& os, const Graph& g);
};

class AdjacentGraph : public Graph {
 private:
  std::vector<std::vector<double>> weights;

 public:
  std::size_t addEdge(std::size_t nodeId1, std::size_t nodeId2, double weight);
  std::size_t addNode();
  std::tuple<std::size_t, std::size_t> getAdjacentNodeIds(
      std::size_t edgeId) const;
  std::vector<std::size_t> getInEdgeIds(std::size_t nodeId) const;
  std::vector<std::size_t> getOutEdgeIds(std::size_t nodeId) const;
  void setEdgeWeight(std::size_t edgeId, double weight);
  double getEdgeWeight(std::size_t edgeId) const;
  void forAllEdges(
      const std::function<void(std::size_t edgeId)>& function) const;
  void forAllNodes(
      const std::function<void(std::size_t nodeId)>& function) const;
};

class ClassicGraph : public Graph {
 public:
  std::size_t addEdge(std::size_t nodeId1, std::size_t nodeId2, double weight);
  std::size_t addNode();
  std::tuple<std::size_t, std::size_t> getAdjacentNodeIds(
      std::size_t edgeId) const;
  std::vector<std::size_t> getInEdgeIds(std::size_t nodeId) const;
  std::vector<std::size_t> getOutEdgeIds(std::size_t nodeId) const;
  void setEdgeWeight(std::size_t edgeId, double weight);
  double getEdgeWeight(std::size_t edgeId) const;
  void forAllEdges(
      const std::function<void(std::size_t edgeId)>& function) const;
  void forAllNodes(
      const std::function<void(std::size_t nodeId)>& function) const;

protected:
  class Edge {
   public:
    size_t node1;
    size_t node2;
    double weight;
    Edge() {}
    Edge(size_t nodeId1, size_t nodeId2, double w) : node1(nodeId1), node2(nodeId2), weight(w) {}
  };

  class Node {
   public:
    std::vector<std::size_t> incoming;
    std::vector<std::size_t> outgoing;
  };

 private:
  std::vector<Edge> edges;
  std::vector<Node> nodes;
};

// BONUS TODO: Implement template classes GraphT, AdjacentGraphT and
// ClassicGraphT

#endif  // ABSTRACTGRAPH_GRAPH_H
