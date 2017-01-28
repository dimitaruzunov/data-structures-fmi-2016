#include <iostream>
#include <list>
#include <set>
#include "graph.h"

using std::cout;
using std::list;
using std::set;

bool find_cycle(Graph& graph, int vertex, set<int>& visited,
                set<int>& current_path_vertices, list<int>& current_path) {
  visited.insert(vertex);

  current_path_vertices.insert(vertex);
  current_path.push_back(vertex);

  for (int successor : graph.successors(vertex)) {
    if (current_path_vertices.find(successor) != current_path_vertices.end() &&
        current_path.size() > 2 && successor == current_path.front()) {
      current_path.push_back(successor);
      return true;
    }

    if (visited.find(successor) == visited.end() &&
        find_cycle(graph, successor, visited, current_path_vertices, current_path)) {
      return true;
    }
  }

  current_path_vertices.erase(vertex);
  current_path.pop_back();

  return false;
}

list<int> find_cycle(Graph& graph) {
  list<int> cycle;

  set<int> visited;
  set<int> current_path_vertices;

  for (int vertex : graph.vertices()) {
    if (visited.find(vertex) == visited.end() &&
        find_cycle(graph, vertex, visited, current_path_vertices, cycle)) {
      return cycle;
    }
  }

  return cycle;
}

void print_cycle(const list<int>& cycle) {
  for (int vertex : cycle) {
    cout << vertex << ' ';
  }
  cout << '\n';
}

int main() {
  Graph graph;
  graph
    .add_vertex(10).add_vertex(22).add_vertex(42)
    .add_vertex(25).add_vertex(56).add_vertex(6)
    .add_edge(22, 10).add_edge(22, 25).add_edge(10, 42)
    .add_edge(42, 25).add_edge(25, 6).add_edge(42, 6).add_edge(42, 56);

  print_cycle(find_cycle(graph));

  return 0;
}