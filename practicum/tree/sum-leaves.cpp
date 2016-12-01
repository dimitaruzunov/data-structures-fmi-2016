#include <iostream>
#include "tree.h"

using std::cout;

bool is_leaf(const Tree& tree) {
  return tree.get_children().empty();
}

int sum_leaves(const Tree& tree) {
  if (is_leaf(tree)) {
    return tree.get_root();
  }

  int sum = 0;

  for (const Tree& child : tree.get_children()) {
    sum += sum_leaves(child);
  }

  return sum;
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

  cout << sum_leaves(tree) << '\n';

  return 0;
}
