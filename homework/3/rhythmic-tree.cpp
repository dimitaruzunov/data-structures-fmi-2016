#include <iostream>
#include <cmath>
#include "tree.h"

using std::cout;
using std::boolalpha;
using std::abs;

bool is_rhythmic(const Tree& tree) {
  for (const Tree& child : tree.get_children()) {
    if (abs(tree.get_root() - child.get_root()) != 1 || !is_rhythmic(child)) {
      return false;
    }
  }

  return true;
}

int main() {
  Tree first_tree(1);
  first_tree
    .add_child(Tree(2)
                 .add_child(3)
                 .add_child(1))
    .add_child(Tree(0)
                 .add_child(1)
                 .add_child(-1));

  Tree second_tree(1);
  second_tree
    .add_child(Tree(2)
                 .add_child(3)
                 .add_child(1))
    .add_child(Tree(0)
                 .add_child(1)
                 .add_child(-2));

  cout << boolalpha << is_rhythmic(first_tree) << '\n';
  cout << boolalpha << is_rhythmic(second_tree) << '\n';

  return 0;
}
