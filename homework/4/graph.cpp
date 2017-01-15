#include "graph.h"

list<int> Graph::vertices() const {
  list<int> result;

  for (const pair<int, list<int>>& p : graph) {
    result.push_back(p.first);
  }

  return result;
}

list<int>& Graph::successors(int vertex) {
  return graph[vertex];
}

Graph& Graph::add_vertex(int vertex) {
  graph[vertex] = {};
  return *this;
}

Graph& Graph::add_edge(int first_vertex, int second_vertex) {
  graph[first_vertex].push_back(second_vertex);
  graph[second_vertex].push_back(first_vertex);

  return *this;
}

bool Graph::is_edge(int first_vertex, int second_vertex) {
  for (int successor : successors(first_vertex)) {
    if (successor == second_vertex) {
      return true;
    }
  }

  return false;
}
