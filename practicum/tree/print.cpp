#include <iostream>
#include <queue>
#include "tree.h"

using std::cout;
using std::queue;

void breadth_first_print(const Tree& tree) {
  queue<Tree> nodes;
  nodes.push(tree);

  while (!nodes.empty()) {
    const Tree& current_node = nodes.front();
    cout << current_node.get_root() << ' ';

    for (const Tree& child : current_node.get_children()) {
      nodes.push(child);
    }

    nodes.pop();
  }
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

  tree.prefix_print();
  cout << '\n';
  tree.postfix_print();
  cout << '\n';

  breadth_first_print(tree);

  return 0;
}
