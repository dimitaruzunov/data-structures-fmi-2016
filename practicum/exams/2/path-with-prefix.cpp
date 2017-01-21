#include <iostream>
#include <set>
#include <list>
#include <queue>
#include "graph.h"

using std::cout;
using std::set;
using std::list;
using std::queue;

bool is_prefix(queue<int> prefix, list<int>& current_path) {
  list<int>::const_iterator it = current_path.begin();

  while (!prefix.empty() && it != current_path.end()) {
    if (prefix.front() != *it) {
      return false;
    }

    prefix.pop();
    ++it;
  }

  return prefix.empty();
}

bool path_with_prefix(Graph& graph, queue<int>& prefix, int start, int end,
                      set<int>& visited, list<int>& current_path) {
  visited.insert(start);
  current_path.push_back(start);

  if (start == end && is_prefix(prefix, current_path)) {
    return true;
  } else if (start == end) {
    current_path.pop_back();
    visited.erase(start);

    return false;
  }

  for (int successor : graph.successors(start)) {
    if (visited.find(successor) == visited.end() &&
        path_with_prefix(graph, prefix, successor, end, visited, current_path)) {
      return true;
    }
  }

  current_path.pop_back();
  visited.erase(start);

  return false;
}

list<int> path_with_prefix(Graph& graph, queue<int>& prefix, int start, int end) {
  list<int> result;

  set<int> visited;
  path_with_prefix(graph, prefix, start, end, visited, result);

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
    .add_vertex(10).add_vertex(22).add_vertex(42)
    .add_vertex(25).add_vertex(56).add_vertex(6)
    .add_edge(22, 10).add_edge(22, 25).add_edge(10, 42)
    .add_edge(42, 25).add_edge(25, 6).add_edge(42, 6).add_edge(42, 56);

  queue<int> prefix;
  prefix.push(22);
  prefix.push(25);
  prefix.push(42);

  print_path(path_with_prefix(graph, prefix, 22, 56));

  return 0;
}
