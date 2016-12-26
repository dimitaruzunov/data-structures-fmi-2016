#include <iostream>
#include "tree.h"

using std::cout;

int height(const Tree& tree) {
  int max_height_of_child = 0;

  for (const Tree& child : tree.get_children()) {
    int current_child_height = height(child);
    if (current_child_height > max_height_of_child) {
      max_height_of_child = current_child_height;
    }
  }

  return max_height_of_child + 1;
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

  cout << height(tree) << '\n';
}
