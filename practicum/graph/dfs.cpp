#include <iostream>
#include <set>
#include "graph.h"

using std::cout;
using std::set;

void dfs(Graph& graph, int vertex, set<int>& visited) {
  visited.insert(vertex);

  cout << vertex << '\n';

  for (int successor : graph.successors(vertex)) {
    if (visited.find(successor) == visited.end()) {
      dfs(graph, successor, visited);
    }
  }
}

void dfs(Graph& graph) {
  set<int> visited;

  for (int vertex : graph.vertices()) {
    if (visited.find(vertex) == visited.end()) {
      dfs(graph, vertex, visited);
    }
  }
}

int main() {
  Graph graph;
  graph
    .add_vertex(1).add_vertex(2).add_vertex(3).add_vertex(4).add_vertex(5)
    .add_edge(1, 2).add_edge(2, 3).add_edge(3, 1)
    .add_edge(4, 5);

  dfs(graph);

  return 0;
}
