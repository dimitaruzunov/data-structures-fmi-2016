#include <iostream>

using std::cout;
using std::boolalpha;

bool are_parentheses_correct(const char* expression) {
  int opening_parentheses_count = 0;

  while (*expression) {
    if (*expression == '(') {
      ++opening_parentheses_count;
    } else if (*expression == ')') {
      --opening_parentheses_count;

      if (opening_parentheses_count < 0) {
        return false;
      }
    }

    ++expression;
  }

  return opening_parentheses_count == 0;
}

int main() {
  cout << boolalpha << are_parentheses_correct("(1 + 2) * ((2 + 3) / 2)") << '\n';
  cout << boolalpha << are_parentheses_correct("(1 + 2)) * ((2 + 3) / 2)") << '\n';
  cout << boolalpha << are_parentheses_correct("(1 + 2))( * ((2 + 3) / 2)") << '\n';

  return 0;
}