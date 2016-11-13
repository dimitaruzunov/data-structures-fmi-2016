#include <iostream>
#include <queue>

using std::cout;
using std::queue;

int dequeue_min(queue<int>& q) {
  unsigned long queue_size = q.size();

  int min = q.front();
  q.pop();

  for (int i = 1; i < queue_size; ++i) {
    int front = q.front();
    q.pop();

    if (front < min) {
      q.push(min);
      min = front;
    } else {
      q.push(front);
    }
  }

  return min;
}

void print_queue(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << ' ';
    q.pop();
  }
}

int main() {
  queue<int> q;
  q.push(4);
  q.push(2);
  q.push(6);
  q.push(-1);
  q.push(3);

  cout << dequeue_min(q) << '\n';
  print_queue(q);
  cout << '\n';

  return 0;
}
