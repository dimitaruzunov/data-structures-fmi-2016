#include <iostream>
#include <list>
#include <queue>
#include <set>
#include "graph.h"

using std::cout;
using std::list;
using std::priority_queue;
using std::set;

list<int> sound_waves_order(Graph& graph, int start) {
  list<int> buildings_order;

  set<int> visited;
  visited.insert(start);

  priority_queue<int> q;
  q.push(start);

  while (!q.empty()) {
    int current_vertex = q.top();
    q.pop();

    buildings_order.push_back(current_vertex);

    for (int successor : graph.successors(current_vertex)) {
      if (visited.find(successor) == visited.end()) {
        visited.insert(successor);
        q.push(successor);
      }
    }
  }

  return buildings_order;
}

void print_buildings_order(const list<int>& buildings) {
  for (int building : buildings) {
    cout << building << ' ';
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

  print_buildings_order(sound_waves_order(graph, 22));

  return 0;
}