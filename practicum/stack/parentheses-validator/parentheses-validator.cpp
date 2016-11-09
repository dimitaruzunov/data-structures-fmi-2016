#include <stack>
#include "parentheses-validator.h"

using std::stack;

ParenthesesValidator::ParenthesesValidator(ParenthesesPair parentheses_pairs[],
                                           unsigned parentheses_pairs_count)
  : parentheses_pairs_count(parentheses_pairs_count) {
  for (int i = 0; i < parentheses_pairs_count; ++i) {
    this->parentheses_pairs[i] = parentheses_pairs[i];
  }
}

bool ParenthesesValidator::is_opening_parenthesis(char character) const {
  for (int i = 0; i < parentheses_pairs_count; ++i) {
    if (parentheses_pairs[i].opening() == character) {
      return true;
    }
  }

  return false;
}

bool ParenthesesValidator::is_closing_parenthesis(char character) const {
  for (int i = 0; i < parentheses_pairs_count; ++i) {
    if (parentheses_pairs[i].closing() == character) {
      return true;
    }
  }

  return false;
}

bool ParenthesesValidator::parentheses_match(char opening, char closing) const {
  ParenthesesPair parentheses_pair(opening, closing);

  for (int i = 0; i < parentheses_pairs_count; ++i) {
    if (parentheses_pairs[i] == parentheses_pair) {
      return true;
    }
  }

  return false;
}

bool ParenthesesValidator::validate(const char* expression) const {
  stack<char> opening_parentheses;

  while (*expression) {
    if (is_opening_parenthesis(*expression)) {
      opening_parentheses.push(*expression);
    } else if (is_closing_parenthesis(*expression)) {
      if (!opening_parentheses.empty() &&
          parentheses_match(opening_parentheses.top(), *expression)) {
        opening_parentheses.pop();
      } else {
        return false;
      }
    }

    ++expression;
  }

  return opening_parentheses.empty();
}
