#include <iostream>
#include <set>
#include <queue>
#include <map>
#include "graph.h"

using std::cout;
using std::set;
using std::queue;
using std::map;

map<int, int> shortest_paths_from(Graph& graph, int start) {
  map<int, int> shortest_paths;
  shortest_paths[start] = 1;

  set<int> visited;
  visited.insert(start);

  queue<int> q;
  q.push(start);

  while (!q.empty()) {
    int current_vertex = q.front();
    q.pop();

    for (int successor : graph.successors(current_vertex)) {
      if (visited.find(successor) == visited.end()) {
        shortest_paths[successor] = shortest_paths[current_vertex] + 1;

        visited.insert(successor);
        q.push(successor);
      }
    }
  }

  return shortest_paths;
}

void print_shortest_paths(const map<int, int>& shortest_paths) {
  for (const pair<int, int>& p : shortest_paths) {
    cout << "Path to " << p.first << " has length of " << p.second << '\n';
  }
}

int main() {
  Graph graph;
  graph
    .add_vertex(1).add_vertex(2).add_vertex(3).add_vertex(4).add_vertex(5)
    .add_edge(1, 2).add_edge(2, 3).add_edge(3, 1)
    .add_edge(4, 5);

  print_shortest_paths(shortest_paths_from(graph, 2));

  return 0;
}
