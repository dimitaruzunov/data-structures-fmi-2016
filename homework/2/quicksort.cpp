#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::swap;

long partition(vector<int>& list, long begin, long end) {
  int pivot = list[end];

  long pivot_index = begin;
  for (long i = begin; i < end; ++i) {
    if (list[i] <= pivot) {
      swap(list[pivot_index], list[i]);
      ++pivot_index;
    }
  }
  swap(list[pivot_index], list[end]);

  return pivot_index;
}

void quicksort(vector<int>& list, long begin, long end) {
  if (begin < end) {
    long pivot_index = partition(list, begin, end);

    quicksort(list, begin, pivot_index - 1);
    quicksort(list, pivot_index + 1, end);
  }
}

void quicksort(vector<int>& list) {
  quicksort(list, 0, list.size() - 1);
}

int main() {
  vector<int> list = {1, 42, 21, 12, 3, 14};
  quicksort(list);

  for (int element : list) {
    cout << element << ' ';
  }
  cout << '\n';

  return 0;
}