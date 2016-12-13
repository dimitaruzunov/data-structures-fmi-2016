#include <list>
#include <queue>
#include <iostream>
#include "tree.cpp"
#include "bintree.cpp"

using std::cout;
using std::queue;
using std::list;

bool isLeaf(const Tree& tree) {
	return tree.getSubtrees().empty();
}

void sumLeafs(Tree const& tree, int& sum)
{
	if (isLeaf(tree))
	{
		sum += tree.getRoot();
	}
	else
	{
		for (auto subtree : tree.getSubtrees())
		{
			sumLeafs(subtree, sum);
		}
	}
}

int sumLeafs2(Tree const& tree)
{
	if (isLeaf(tree))
	{
		return tree.getRoot();
	}
  int sum = 0;
  for (list<Tree>::const_iterator it = tree.getSubtrees().begin(); it != tree.getSubtrees().end(); it++)
  {
    sum += sumLeafs2(*it);
  }
	return sum;
}

void DFS(const Tree& tree) {
	// обработваме корена
	cout << tree.getRoot() << ' ';

	// извикваме рекурсивно DFS за всяко от поддърветата
	for (list<Tree>::const_iterator it = tree.getSubtrees().begin(); it != tree.getSubtrees().end(); ++it) {
		DFS(*it);
	}
}

void BFS(Tree const& tree)
{
	//по-доброто решение е с опашка от върхове, като използваме функция за намиране на наследниците на даден връх
	//така ще пестим и време и памет
	queue<Tree> q;

	//list<int> path съхранява пътя ако е необходимо
	//size_t level=1; съхранява индекса на текущото ниво

	q.push(tree);

	while (!q.empty())
	{
		Tree const& t = q.front();
		//обработваме корена, намиращ се в началото на опашката
		cout << t.getRoot();

		//слагаме всичките наследници на корена в опашката
		for (list<Tree>::const_iterator it = t.getSubtrees().begin(); it != t.getSubtrees().end(); it++)
		{
			q.push(*it);
		}

		//махаме корена - dequeue
		q.pop();
	}
}

int depth(Tree const& t, int& currLen, int& maxLen)
{
	if (isLeaf(t))
	{
		if (currLen > maxLen)
			maxLen = currLen;
	}
	currLen++;

	for (list<Tree>::const_iterator it = t.getSubtrees().begin(); it != t.getSubtrees().end(); ++it) {
		depth(*it, currLen, maxLen);
		
	}
	currLen--;

	return maxLen;
}

int depth2(Tree const& t) {
  if (isLeaf(t)) {
    return 0;
  }
  int currDepth, maxDepth = 0;
  for (list<Tree>::const_iterator it = t.getSubtrees().begin(); it != t.getSubtrees().end(); ++it) {
    currDepth = depth2(*it);
    if (currDepth > maxDepth)
      maxDepth = currDepth;
  }

  return maxDepth + 1;
}

void breadth(Tree const& t, int& maxB)
{
	int i = 0;
	for (list<Tree>::const_iterator it = t.getSubtrees().begin(); it != t.getSubtrees().end(); ++it, i++) {
		breadth(*it, maxB);
	}
	if (i > maxB)
		maxB = i;
}

int breadth2(Tree const& t) {
  int curBreadth, max = t.getSubtrees().size();

  for (list<Tree>::const_iterator it = t.getSubtrees().begin(); it != t.getSubtrees().end(); ++it) {
    curBreadth = breadth2(*it);
    if (curBreadth > max)
      max = curBreadth;
  }

  return max;
}


int main() {
//	// (1 (2 (3) (4)) (5 (6) (7) (8)) (9))
//	Tree tree(1);
//	tree.addChild(Tree(2).addChild(3).addChild(4))
//		.addChild(Tree(5).addChild(6).addChild(7)
//									.addChild(8))
//		.addChild(9);
//	cout << tree;
//
//  cout << sumLeafs2(tree);

  BinaryTree<int> bt(1, 2, BinaryTree<int>(4));
	cout << bt;
	return 0;
}
