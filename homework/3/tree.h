#ifndef TREE_H
#define TREE_H

#include <list>

using std::list;

class Tree {
  int root;
  list<Tree> children;

public:

  Tree(int root);

  int get_root() const;

  const list<Tree>& get_children() const;

  Tree& add_child(const Tree& child);

  void prefix_print() const;

  void postfix_print() const;
};

#endif
