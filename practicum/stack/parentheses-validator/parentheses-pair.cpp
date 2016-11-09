#include "parentheses-pair.h"

ParenthesesPair::ParenthesesPair(char opening, char closing)
  : parentheses(opening, closing) {}

char ParenthesesPair::opening() const {
  return parentheses.first;
}

char ParenthesesPair::closing() const {
  return parentheses.second;
}

bool ParenthesesPair::operator==(const ParenthesesPair& other) const {
  return opening() == other.opening() && closing() == other.closing();
}
