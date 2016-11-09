#include <iostream>
#include <stack>
#include "parentheses-pair.h"
#include "parentheses-validator.h"

using std::cout;
using std::boolalpha;

int main() {
  ParenthesesPair parentheses_pairs[4] {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
    {'<', '>'}
  };
  ParenthesesValidator parentheses_validator(parentheses_pairs, 4);

  cout << boolalpha
       << parentheses_validator.validate("{(1 + 2) * [(2 + 3) / 2]}") << '\n';

  cout << boolalpha
       << parentheses_validator.validate("(1 + 2) * [(2 + 3] / 2]") << '\n';

  cout << boolalpha
       << parentheses_validator.validate("(1 + 2))( * [(2 + 3) / 2]") << '\n';

  return 0;
}
