#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <list>

using std::map;
using std::list;
using std::pair;

class Graph {
  map<int, list<int>> graph;

public:

  list<int> vertices() const;
  list<int>& successors(int vertex);
  Graph& add_vertex(int vertex);
  Graph& add_edge(int first_vertex, int second_vertex);
  bool is_edge(int first_vertex, int second_vertex);
};

#endif
