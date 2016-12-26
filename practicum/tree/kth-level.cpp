#include <iostream>
#include <queue>
#include <list>
#include "tree.h"

using std::cout;
using std::queue;
using std::list;

list<int> kth_level(const Tree& tree, int k) {
  queue<Tree> nodes;
  nodes.push(tree);

  list<int> nodes_on_kth_level;
  int current_level = 0;
  unsigned long current_level_nodes_count = 1;

  while (!nodes.empty()) {
    if (current_level_nodes_count == 0) {
      ++current_level;
      current_level_nodes_count = nodes.size();
    }

    if (current_level == k) {
      while (!nodes.empty()) {
        nodes_on_kth_level.push_back(nodes.front().get_root());
        nodes.pop();
      }

      return nodes_on_kth_level;
    }

    for (const Tree& child : nodes.front().get_children()) {
      nodes.push(child);
    }

    nodes.pop();
    --current_level_nodes_count;
  }

  return nodes_on_kth_level;
}

void print_list(const list<int>& list) {
  for (int element : list) {
    cout << element << ' ';
  }
  cout << '\n';
}

int main() {
  Tree tree(1);
  tree
    .add_child(Tree(2)
                 .add_child(3)
                 .add_child(Tree(4)
                              .add_child(5)
                              .add_child(6))
                 .add_child(7)
                 .add_child(8))
    .add_child(9)
    .add_child(10);

  print_list(kth_level(tree, 2));

  return 0;
}