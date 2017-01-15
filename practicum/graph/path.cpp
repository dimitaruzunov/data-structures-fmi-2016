#include <iostream>
#include <set>
#include <list>
#include "graph.h"

using std::cout;
using std::set;
using std::list;

bool path(Graph& graph, int start, int end, set<int>& visited, list<int>& current_path) {
  visited.insert(start);

  current_path.push_back(start);

  if (start == end) {
    return true;
  }

  for (int successor : graph.successors(start)) {
    if (visited.find(successor) == visited.end() &&
        path(graph, successor, end, visited, current_path)) {
      return true;
    }
  }

  current_path.pop_back();

  return false;
}

list<int> path(Graph& graph, int start, int end) {
  list<int> result;

  set<int> visited;
  path(graph, start, end, visited, result);

  return result;
}

void print_path(const list<int>& path) {
  for (int vertex : path) {
    cout << vertex << ' ';
  }
  cout << '\n';
}

int main() {
  Graph graph;
  graph
    .add_vertex(1).add_vertex(2).add_vertex(3).add_vertex(4).add_vertex(5)
    .add_edge(1, 2).add_edge(2, 3).add_edge(3, 1)
    .add_edge(4, 5);

  print_path(path(graph, 1, 3));

  return 0;
}
