#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>

using std::map;
using std::list;
using std::cout;
using std::find;
using std::queue;
using std::stack;

class Graph {
  map<int, list<int> > v;
public:
  void addEdge(int a, int b) {
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int DFS() {
    list<int> visited;
    int count = 0;
    for (auto p : v) {
      if (find(visited.begin(), visited.end(), p.first)
          == visited.end()) {
        DFS(p.first, visited);
        cout << "\n";
        count++;
      }
    }
    return count;
  }
  void DFS(int u, list<int>& visited) {
    visited.push_back(u);
    cout << u << " ";
    for (int n : v[u])
      if (find(visited.begin(), visited.end(), n)
          == visited.end())
        DFS(n, visited);
  }
  list<int> DFSPath(int a, int b, list<int>& visited, list<int>& path) {
    visited.push_back(a);
    path.push_back(a);
    cout << a << " ";
    if (a == b)
      return path;
    for (int n : v[a])
      if (find(visited.begin(), visited.end(), n)
          == visited.end())
        return DFSPath(n, b, visited, path);
    path.pop_back();
    return path;
  }
  void DFSNonRecursive(int u) {
    stack<int> front;
    list<int> visited;
    front.push(u);
    while (!front.empty()) {
      int c = front.top();
      visited.push_back(c);
      cout << c << " ";
      for (int n : v[c])
        if (find(visited.begin(), visited.end(), n)
            == visited.end())
          front.push(n);
      front.pop();
    }
  }
  void BFS(int u) {
    queue<int> front;
    list<int> visited;
    front.push(u);
    while (!front.empty()) {
      int c = front.front();
      visited.push_back(c);
      cout << c << " ";
      for (int n : v[c])
        if (find(visited.begin(), visited.end(), n)
            == visited.end())
          front.push(n);
      front.pop();
    }
  }
};

int main() {
  Graph g;
  g.addEdge(1, 2);
//  g.addEdge(1, 3);
  g.addEdge(3, 4);
  g.addEdge(3, 5);
  g.addEdge(3, 6);
  g.addEdge(6, 7);
//  g.addEdge(4, 8);
  g.addEdge(8, 9);
  g.addEdge(2, 10);
  g.addEdge(10, 11);
  list<int> visited;
  list<int> path;
  int c = g.DFS();
  cout << c;
  return 0;
}