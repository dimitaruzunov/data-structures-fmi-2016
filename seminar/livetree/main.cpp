#include <iostream>
#include <vector>

using std::ostream;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int data;

  Node* left;
  Node* right;

  // changed: added data(data)
  Node(int data, Node* left = nullptr, Node* right = nullptr)
    : data(data), left(left), right(right) {}
};

class BinaryTree {
protected:
  Node* root;

  BinaryTree(Node* node) {
    root = copyNode(node);
  }

  Node* copyNode(Node* node) {
    if (node == nullptr)
      return node;
    return new Node(node->data,
                    copyNode(node->left),
                    copyNode(node->right));
  }

  void eraseNode(Node* node) {
    if (node != nullptr) {
      eraseNode(node->left);
      eraseNode(node->right);
      delete node;
    }
  }

  void assignFrom(Node*& to, Node*& from) {
    Node* toDel = to;
    to = from;
    from = nullptr;
    // changed: eraseNode(to)->eraseNode(toDel)
    eraseNode(toDel);
  }

public:
  BinaryTree() : root(nullptr) {}

  BinaryTree(int rootData,
             BinaryTree&& left = BinaryTree(),
             BinaryTree&& right = BinaryTree()) {
    root = new Node(rootData);
    assignFrom(root->left, left.root);
    assignFrom(root->right, right.root);
  }

  BinaryTree(const BinaryTree& other) {
    root = copyNode(other.root);
  }

  BinaryTree& operator=(const BinaryTree& other) {
    if (this != &other) {
      eraseNode(root);
      root = copyNode(other.root);
    }
  }

  ~BinaryTree() {
    eraseNode(root);
  }

  bool empty() const { return root == nullptr; }

  BinaryTree leftTree() const {
    return BinaryTree(root->left);
  }

  BinaryTree rightTree() const {
    return BinaryTree(root->right);
  }

  int getRoot() const {
    return root->data;
  }

  friend ostream& operator<<(ostream& os, const BinaryTree& bt) {
    if (bt.empty())
      return os << '.';

    // changed: added braces
    return os << '(' << bt.getRoot() << ' ' << bt.leftTree() << ' '
      << bt.rightTree() << ')';
  }

};

class OrderedTree : public BinaryTree {
  Node*& findNode(const int& data) {
    Node** p = &root;
    while (*p != nullptr && (*p)->data != data) {
      if (data < (*p)->data)
        p = &((*p)->left);
      else
        p = &((*p)->right);
    }
    return *p;
  }

  Node*& findMin(Node*& node) {
    Node** p = &node;
    while ((*p)->left != nullptr) {
      p = &((*p)->left);
    }
    return *p;
  }
public:
  int* search(const int& data) {
    Node*& found = findNode(data);
    if (found == nullptr)
      return nullptr;
    return &found->data;
  }

  bool addElement(const int& data) {
    Node*& here = findNode(data);
    if (here != nullptr)
      return false;

    here = new Node(data);
    return true;
  }

  bool deleteElement(const int& data) {
    Node*& p = findNode(data);
    if (p == nullptr)
      return false;
    if (p->left == nullptr) {
      Node* toDel = p;
      p = p->right;
      delete toDel;
      return true;
    }
    if (p->right == nullptr) {
      Node* toDel = p;
      p = p->left;
      delete toDel;
      return true;
    }

    Node*& m = findMin(p->right);
    p->data = m->data;

    Node* toDel = m;
    m = m->right;
    delete toDel;

    return true;
  }
};

void printInOrder(const BinaryTree& tree) {
  if (!tree.empty()) {
    printInOrder(tree.leftTree());
    cout << tree.getRoot() << " ";
    printInOrder(tree.rightTree());
  }
}

void printInOrderOnlyNs(const BinaryTree& tree, int n
    , int& current) {
  if (!tree.empty()) {
    printInOrderOnlyNs(tree.leftTree(), n, current);
    if (current % n == 0)
      cout << tree.getRoot() << " ";
    ++current;
    printInOrderOnlyNs(tree.rightTree(), n, current);
  }
}

void printInOrderNs(const BinaryTree& tree, int n) {
  int current = 0;
  printInOrderOnlyNs(tree, n, current);
}

void toVectorInOrder(const BinaryTree& tree, vector<int>& v) {
  if (!tree.empty()) {
    toVectorInOrder(tree.leftTree(), v);
    v.push_back(tree.getRoot());
    toVectorInOrder(tree.rightTree(), v);
  }
}

vector<int> sortUsingOT(vector<int>& list) {
  OrderedTree t;
  for (int el : list)
    t.addElement(el);
  vector<int> v;
  toVectorInOrder(t, v);
  return v;
}

int main() {
  BinaryTree bt(3);
  BinaryTree bt2(3, 4, 5);

//  OrderedTree bt3(3, 2, OrderedTree(6, 5, 7));
OrderedTree t;
  t.addElement(4);
  t.addElement(5);
  t.addElement(1);
  t.addElement(2);
  t.addElement(8);
  t.addElement(7);
  t.addElement(-1);

  cout << t << endl;
  printInOrder(t);
  cout << endl;

  printInOrderNs(t, 3);

  return 0;
}