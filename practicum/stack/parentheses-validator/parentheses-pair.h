#ifndef PARENTHESES_VALIDATOR_PARENTHESES_PAIR_H
#define PARENTHESES_VALIDATOR_PARENTHESES_PAIR_H

#include <utility>

using std::pair;

class ParenthesesPair {
  pair<char, char> parentheses;

public:

  ParenthesesPair(char opening = '(', char closing = ')');
  char opening() const;
  char closing() const;
  bool operator==(const ParenthesesPair& other) const;
};

#endif
