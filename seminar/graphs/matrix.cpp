#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using std::map;
using std::list;
using std::cout;
using std::find;
using std::queue;
using std::stack;
using std::priority_queue;
using std::vector;

class WGraph {
  static const int MAX = 20;
  int m[MAX][MAX];
  int vertices;
public:
  WGraph(int vertices = 20) : vertices(vertices) {
    for (int i = 0; i < MAX; ++i)
      for (int j = 0; j < MAX; ++j)
        m[i][j] = 0;
  }
  void addEdge(int a, int b, int w = 1) {
    m[a][b] = w;
    m[b][a] = w;
  }
  int DFS() {
    list<int> visited;
    for (int i = 0; i < vertices; ++i)
      if (find(visited.begin(), visited.end(), i) == visited.end())
        DFSConnected(i, visited);
  }
  int DFSConnected(int u, list<int>& visited) {
    visited.push_back(u);
    cout << u << " ";
    for (int i = 0; i < vertices; ++i)
      if (m[u][i] > 0 && find(visited.begin(), visited.end(), i) == visited.end())
        DFSConnected(i, visited);
  }
  void BFS(int u) {
  }

};

int main() {
  WGraph g(12);
  g.addEdge(1, 2, 1);
  g.addEdge(1, 3, 1);
  g.addEdge(3, 4, 1);
  g.addEdge(3, 5, 1);
  g.addEdge(3, 6, 1);
  g.addEdge(6, 7, 1);
  g.addEdge(4, 8, 1);
  g.addEdge(8, 9, 1);
  g.addEdge(2, 10, 1);
  g.addEdge(10, 11, 1);

  g.DFS();

  priority_queue<int, vect

  return 0;
}