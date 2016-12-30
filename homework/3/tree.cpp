#include <iostream>
#include "tree.h"

using std::cout;

Tree::Tree(int root): root(root) {}

int Tree::get_root() const {
  return root;
}

const list<Tree>& Tree::get_children() const {
  return children;
}

Tree& Tree::add_child(const Tree& child) {
  children.push_back(child);

  return *this;
}

void Tree::prefix_print() const {
  cout << '(' << root;

  for (const Tree& child : children) {
    cout << ' ';
    child.prefix_print();
  }

  cout << ')';
}

void Tree::postfix_print() const {
  cout << '(';

  for (const Tree& child : children) {
    child.postfix_print();
    cout << ' ';
  }

  cout << root << ')';
}
