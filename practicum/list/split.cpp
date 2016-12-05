#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
void split(const vector<T>& list, vector<T>& first_list, vector<T>& second_list) {
  vector<T>* first = &first_list;
  vector<T>* second = &second_list;

  for (const T& element : list) {
    first->push_back(element);
    swap(first, second);
  }
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
  vector<int> first_list, second_list;

  split(list, first_list, second_list);
  print(first_list);
  print(second_list);

  return 0;
}
