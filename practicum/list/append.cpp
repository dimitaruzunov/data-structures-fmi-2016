#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
vector<T> append(const vector<T>& first_list, const vector<T>& second_list) {
  vector<T> result = first_list;

  for (const T& element : second_list) {
    result.push_back(element);
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
  vector<int> first_list = {1, 2, 3};
  vector<int> second_list = {4, 5, 6};

  print(append(first_list, second_list));

  return 0;
}
