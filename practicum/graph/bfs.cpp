#include <iostream>
#include <set>
#include <queue>
#include "graph.h"

using std::cout;
using std::set;
using std::queue;

void bfs(Graph& graph, int vertex, set<int>& visited) {
  visited.insert(vertex);

  queue<int> q;
  q.push(vertex);

  while (!q.empty()) {
    int current_vertex = q.front();
    q.pop();

    cout << current_vertex << '\n';

    for (int successor : graph.successors(current_vertex)) {
      if (visited.find(successor) == visited.end()) {
        visited.insert(successor);
        q.push(successor);
      }
    }
  }
}

void bfs(Graph& graph) {
  set<int> visited;

  for (int vertex : graph.vertices()) {
    if (visited.find(vertex) == visited.end()) {
      bfs(graph, vertex, visited);
    }
  }
}

int main() {
  Graph graph;
  graph
    .add_vertex(1).add_vertex(2).add_vertex(3).add_vertex(4).add_vertex(5)
    .add_edge(1, 2).add_edge(2, 3).add_edge(3, 1)
    .add_edge(4, 5);

  bfs(graph);

  return 0;
}
