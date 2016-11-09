#ifndef PARENTHESES_VALIDATOR_PARENTHESES_VALIDATOR_H
#define PARENTHESES_VALIDATOR_PARENTHESES_VALIDATOR_H

#include "parentheses-pair.h"

class ParenthesesValidator {
  static const unsigned MAX_PAIRS = 10;

  ParenthesesPair parentheses_pairs[MAX_PAIRS];
  unsigned parentheses_pairs_count;

  bool is_opening_parenthesis(char character) const;
  bool is_closing_parenthesis(char character) const;
  bool parentheses_match(char opening, char closing) const;
public:

  ParenthesesValidator(ParenthesesPair parentheses_pairs[],
                       unsigned parentheses_pairs_count);
  bool validate(const char* expression) const;
};

#endif
