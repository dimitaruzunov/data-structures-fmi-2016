#include <iostream>

using std::cout;
using std::boolalpha;

bool validate_parentheses(const char* expression) {
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
  cout << boolalpha << validate_parentheses("(1 + 2) * ((2 + 3) / 2)") << '\n';
  cout << boolalpha << validate_parentheses("(1 + 2)) * ((2 + 3) / 2)") << '\n';
  cout << boolalpha << validate_parentheses("(1 + 2))( * ((2 + 3) / 2)") << '\n';

  return 0;
}