#include <iostream>
using std::ostream;

struct TreeNode {
  int data;

  TreeNode* left;
  TreeNode* right;

  TreeNode(int const& _data = T(),
    TreeNode* _left = nullptr,
    TreeNode* _right = nullptr)
      : data(_data), left(_left), right(_right) {}
};

class BinaryTree {
private:
	TreeNode* root;

public:
  BinaryTree() :
  BinaryTree() : root(_root), left(_left), right(_right) {}

  BinaryTree& addLeft(BinaryTree& child)
  {
    left = &child;
    return *this;
  }

  BinaryTree& addRight(BinaryTree& child)
	{
    right = &child;
		return *this;
	}

	int getRoot() const { return root; }

  BinaryTree& leftTree() const {
    return *left;
  }

  BinaryTree& rightTree() const {
    return *right;
  }

	// извежда дървото
	friend ostream& operator<<(ostream& os, BinaryTree const& tree)
	{
    return os <<'('<< tree.getRoot() << ' ' << tree.getLeft() << ' ' << tree.getRight() << ')';
	}
};
