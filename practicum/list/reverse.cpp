#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
vector<T> reverse(const vector<T>& list) {
  vector<T> result;

  for (long i = list.size() - 1; i >= 0; --i) {
    result.push_back(list[i]);
  }

  return result;
}

template <typename T>
void print(const vector<T>& list) {
  for (const T& element : list) {
    cout << element << ' ';
  }
  cout << '\n';
}

int main() {
  vector<int> list = {1, 2, 3, 4, 5};

  print(reverse(list));

  return 0;
}
