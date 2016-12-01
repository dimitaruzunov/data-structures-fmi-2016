#include <iostream>
#include "tree.h"

using std::cout;

unsigned long breadth(const Tree& tree) {
  unsigned long result = tree.get_children().size();

  for (const Tree& child : tree.get_children()) {
    unsigned long current_child_breadth = breadth(child);
    if (current_child_breadth > result) {
      result = current_child_breadth;
    }
  }

  return result;
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

  cout << breadth(tree) << '\n';

  return 0;
}
