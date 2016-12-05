#include <iostream>
#include <vector>

using std::cout;
using std::vector;

template <typename T>
vector<T> merge(const vector<T>& first_list, const vector<T>& second_list) {
  vector<T> result;

  int i = 0, j = 0;
  while (i < first_list.size() && j < second_list.size()) {
    if (first_list[i] < second_list[j]) {
      result.push_back(first_list[i]);
      ++i;
    } else {
      result.push_back(second_list[j]);
      ++j;
    }
  }

  while (i < first_list.size()) {
    result.push_back(first_list[i]);
    ++i;
  }

  while (j < second_list.size()) {
    result.push_back(second_list[j]);
    ++j;
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
  vector<int> first_list = {1, 42, 60};
  vector<int> second_list = {2, 30, 42, 55};

  print(merge(first_list, second_list));

  return 0;
}
