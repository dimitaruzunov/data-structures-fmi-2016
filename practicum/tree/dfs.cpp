#include <iostream>
#include "tree.h"

using std::cout;
using std::boolalpha;

bool is_in_tree(const Tree& tree, int element) {
  if (tree.get_root() == element) {
    return true;
  }

  for (const Tree& child : tree.get_children()) {
    if (is_in_tree(child, element)) {
      return true;
    }
  }

  return false;
}

bool dfs(const Tree& tree, int element, list<int>& current_path) {
  current_path.push_back(tree.get_root());

  if (tree.get_root() == element) {
    return true;
  }

  for (const Tree& child : tree.get_children()) {
    if (dfs(child, element, current_path)) {
      return true;
    }
  }

  current_path.pop_back();

  return false;
}

list<int> dfs(const Tree& tree, int element) {
  list<int> current_path;

  dfs(tree, element, current_path);

  return current_path;
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

  cout << boolalpha << is_in_tree(tree, 7) << '\n';
  print_list(dfs(tree, 7));

  return 0;
}
