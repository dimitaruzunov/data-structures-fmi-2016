#include <iostream>
#include <stack>
#include <utility>

using std::cout;
using std::boolalpha;
using std::stack;
using std::pair;

class ParenthesesPair {
  pair<char, char> parentheses;

public:

  ParenthesesPair(char opening, char closing): parentheses(opening, closing) {}

  char opening() const {
    return parentheses.first;
  }

  char closing() const {
    return parentheses.second;
  }

  bool operator==(const ParenthesesPair& other_parentheses_pair) const {
    return opening() == other_parentheses_pair.opening() &&
           closing() == other_parentheses_pair.closing();
  }
};

ParenthesesPair parentheses_pairs[4] {
  {'(', ')'},
  {'[', ']'},
  {'{', '}'},
  {'<', '>'}
};

bool is_opening_parenthesis(char character) {
  for (int i = 0; i < 4; ++i) {
    if (parentheses_pairs[i].opening() == character) {
      return true;
    }
  }

  return false;
}

bool is_closing_parenthesis(char character) {
  for (int i = 0; i < 4; ++i) {
    if (parentheses_pairs[i].closing() == character) {
      return true;
    }
  }

  return false;
}

bool parentheses_match(const ParenthesesPair& parentheses_pair) {
  for (int i = 0; i < 4; ++i) {
    if (parentheses_pairs[i] == parentheses_pair) {
      return true;
    }
  }

  return false;
}

bool are_parentheses_correct(const char* expression) {
  stack<char> opening_parentheses;

  while (*expression) {
    if (is_opening_parenthesis(*expression)) {
      opening_parentheses.push(*expression);
    } else if (is_closing_parenthesis(*expression)) {
      if (!opening_parentheses.empty() &&
          parentheses_match(ParenthesesPair(opening_parentheses.top(), *expression))) {
        opening_parentheses.pop();
      } else {
        return false;
      }
    }

    ++expression;
  }

  return opening_parentheses.empty();
}

int main() {
  cout << boolalpha << are_parentheses_correct("{(1 + 2) * [(2 + 3) / 2]}") << '\n';
  cout << boolalpha << are_parentheses_correct("(1 + 2) * [(2 + 3] / 2]") << '\n';
  cout << boolalpha << are_parentheses_correct("(1 + 2))( * [(2 + 3) / 2]") << '\n';

  return 0;
}
