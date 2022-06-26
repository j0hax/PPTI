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
    Edge(size_t nodeId1, size_t nodeId2, double w)
        : node1(nodeId1), node2(nodeId2), weight(w) {}
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

template <typename T>
class GraphT {
 public:
  /// Virtual destructor (necessary due to abstract base class usage)
  virtual ~GraphT() = default;

  /// Inserts a directed Edge into the Graph if the Ids of both Nodes are valid
  /// within the Graph
  /// @param nodeId1 Id of incoming Node from which the Edge originates
  /// @param nodeId2 Id of outgoing Node to which the Edge leads
  /// @param weight Weight of the Edge
  /// @returns Id of the new Edge
  virtual std::size_t addEdge(std::size_t nodeId1,
                              std::size_t nodeId2,
                              T weight) = 0;

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
  virtual void setEdgeWeight(std::size_t edgeId, T weight) = 0;

  /// Returns the weight of an Edge
  /// @param edgeId Id of the Edge
  virtual T getEdgeWeight(std::size_t edgeId) const = 0;

  /// Executes a function on all Edges of the Graph
  /// @param function The function to be called
  virtual void forAllEdges(
      const std::function<void(std::size_t edgeId)>& function) const = 0;

  /// Executes a function on all Nodes of the Graph
  /// @param function The function to be called
  virtual void forAllNodes(
      const std::function<void(std::size_t nodeId)>& function) const = 0;

 private:
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const GraphT<U>& g);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const GraphT<T>& graph) {
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

template <typename T>
class AdjacentGraphT : public GraphT<T> {
 private:
  std::vector<std::vector<T>> weights;

 public:
  std::size_t addEdge(std::size_t nodeId1, std::size_t nodeId2, T weight);
  std::size_t addNode();
  std::tuple<std::size_t, std::size_t> getAdjacentNodeIds(
      std::size_t edgeId) const;
  std::vector<std::size_t> getInEdgeIds(std::size_t nodeId) const;
  std::vector<std::size_t> getOutEdgeIds(std::size_t nodeId) const;
  void setEdgeWeight(std::size_t edgeId, T weight);
  T getEdgeWeight(std::size_t edgeId) const;
  void forAllEdges(
      const std::function<void(std::size_t edgeId)>& function) const;
  void forAllNodes(
      const std::function<void(std::size_t nodeId)>& function) const;
};

template <typename T>
class ClassicGraphT : public GraphT<T> {
 public:
  std::size_t addEdge(std::size_t nodeId1, std::size_t nodeId2, T weight);
  std::size_t addNode();
  std::tuple<std::size_t, std::size_t> getAdjacentNodeIds(
      std::size_t edgeId) const;
  std::vector<std::size_t> getInEdgeIds(std::size_t nodeId) const;
  std::vector<std::size_t> getOutEdgeIds(std::size_t nodeId) const;
  void setEdgeWeight(std::size_t edgeId, T weight);
  T getEdgeWeight(std::size_t edgeId) const;
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
    Edge(size_t nodeId1, size_t nodeId2, double w)
        : node1(nodeId1), node2(nodeId2), weight(w) {}
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

/*
    Template Classes are best implemented in the header:
    "The only portable way of using templates at the moment is to implement them
   in header files by using inline functions."
*/

// Implementation for AdjacentGraphT
template <typename T>
std::size_t AdjacentGraphT<T>::addEdge(std::size_t nodeId1,
                                       std::size_t nodeId2,
                                       T weight) {
  this->weights[nodeId1][nodeId2] = weight;

  // formula for finding edge: y * len(matrix) + x
  return nodeId1 * this->weights.size() + nodeId2;
}

template <typename T>
std::size_t AdjacentGraphT<T>::addNode() {
  // Add another vector to the vector
  const size_t s = this->weights.size() + 1;

  weights.resize(s);

  // update each row
  for (auto& row : this->weights) {
    row.resize(s);
  }

  return s;
}

template <typename T>
std::tuple<std::size_t, std::size_t> AdjacentGraphT<T>::getAdjacentNodeIds(
    std::size_t edgeId) const {
  // Get "coordinates" from the ID
  size_t r = 0;
  while ((r + 1) * this->weights.size() <= edgeId) {
    r += 1;
  }
  size_t c = edgeId - (r * this->weights.size());

  return std::make_tuple(c, r);
}

template <typename T>
std::vector<std::size_t> AdjacentGraphT<T>::getInEdgeIds(
    std::size_t nodeId) const {
  std::vector<std::size_t> refs;
  // Loop over specified column and add positive values
  for (std::size_t i = 0; i < this->weights.size(); ++i) {
    if (this->weights[i][nodeId] > 0) {
      refs.push_back(i);
    }
  }

  return refs;
}

template <typename T>
std::vector<std::size_t> AdjacentGraphT<T>::getOutEdgeIds(
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

template <typename T>
void AdjacentGraphT<T>::setEdgeWeight(std::size_t edgeId, T weight) {
  std::tuple<std::size_t, std::size_t> coords =
      this->getAdjacentNodeIds(edgeId);
  this->weights[std::get<0>(coords)][std::get<1>(coords)] = weight;
}

template <typename T>
T AdjacentGraphT<T>::getEdgeWeight(std::size_t edgeId) const {
  std::tuple<std::size_t, std::size_t> coords =
      this->getAdjacentNodeIds(edgeId);
  return this->weights[std::get<0>(coords)][std::get<1>(coords)];
}

template <typename T>
void AdjacentGraphT<T>::forAllEdges(
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

template <typename T>
void AdjacentGraphT<T>::forAllNodes(
    const std::function<void(std::size_t nodeId)>& function) const {
  for (size_t r = 0; r < this->weights.size(); ++r) {
    function(r);
  }
}

// Implementation for ClassicGraphT
template <typename T>
std::size_t ClassicGraphT<T>::addEdge(std::size_t nodeId1,
                                      std::size_t nodeId2,
                                      T weight) {
  ClassicGraphT<T>::Edge e(nodeId1, nodeId2, weight);
  this->edges.push_back(e);
  return this->edges.size();
}

template <typename T>
std::size_t ClassicGraphT<T>::addNode() {
  ClassicGraphT<T>::Node n;
  this->nodes.push_back(n);
  return this->nodes.size();
}

template <typename T>
std::tuple<std::size_t, std::size_t> ClassicGraphT<T>::getAdjacentNodeIds(
    std::size_t edgeId) const {
  ClassicGraphT<T>::Edge e = this->edges[edgeId];
  return std::make_tuple(e.node1, e.node2);
}

template <typename T>
std::vector<std::size_t> ClassicGraphT<T>::getInEdgeIds(
    std::size_t nodeId) const {
  ClassicGraphT<T>::Node n = this->nodes[nodeId];
  return n.incoming;
}

template <typename T>
std::vector<std::size_t> ClassicGraphT<T>::getOutEdgeIds(
    std::size_t nodeId) const {
  ClassicGraphT<T>::Node n = this->nodes[nodeId];
  return n.outgoing;
}

template <typename T>
void ClassicGraphT<T>::setEdgeWeight(std::size_t edgeId, T weight) {
  this->edges[edgeId].weight = weight;
}

template <typename T>
T ClassicGraphT<T>::getEdgeWeight(std::size_t edgeId) const {
  ClassicGraphT<T>::Edge e = this->edges[edgeId];
  return e.weight;
}

template <typename T>
void ClassicGraphT<T>::forAllEdges(
    const std::function<void(std::size_t edgeId)>& function) const {
  for (size_t i = 0; i < this->edges.size(); ++i) {
    function(i);
  }
}

template <typename T>
void ClassicGraphT<T>::forAllNodes(
    const std::function<void(std::size_t nodeId)>& function) const {
  for (size_t i = 0; i < this->edges.size(); ++i) {
    function(i);
  }
}

#endif  // ABSTRACTGRAPH_GRAPH_H
