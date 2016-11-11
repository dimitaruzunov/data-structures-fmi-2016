#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

class Queue {
    stack<int> stackIn, stackOut;

    void transfer() {
      while (!stackIn.empty()) {
        stackOut.push(stackIn.top());
        stackIn.pop();
      }
    }
public:

    bool empty() {
      return stackIn.empty() && stackOut.empty();
    }

    int front() {
      if (stackOut.empty()) {
        transfer();
      }

      return stackOut.top();
    }

    void pop() {
      if (stackOut.empty()) {
        transfer();
      }

      stackOut.pop();
    }

    void push(int n) {
      stackIn.push(n);
    }

};

int main() {
  Queue q;

  q.push(1);
  q.push(2);

  cout << q.front() << endl;
  q.pop();

  q.push(3);

  cout << q.front() << endl;
  q.pop();

  q.push(4);
  q.push(5);
  q.push(6);

  cout << q.front() << endl;
  q.pop();

  cout << q.front() << endl;
  q.pop();

  cout << q.front() << endl;
  q.pop();

  cout << q.front() << endl;
  q.pop();
  
  return 0;
}