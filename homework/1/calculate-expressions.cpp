#include <iostream>
#include <fstream>
#include <stack>

using std::ifstream;
using std::ofstream;
using std::ios;
using std::cout;
using std::stack;

bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

void apply_operation(char operation, stack<double>& operands) {
  double second_operand = operands.top();
  operands.pop();
  double first_operand = operands.top();
  operands.pop();

  switch (operation) {
    case '+':
      operands.push(first_operand + second_operand);
      break;
    case '-':
      operands.push(first_operand - second_operand);
      break;
    case '*':
      operands.push(first_operand * second_operand);
      break;
    case '/':
      operands.push(first_operand / second_operand);
      break;
  }
}

void write_result(ofstream& results, stack<double>& operands) {
  results.write((const char*)&operands.top(), sizeof(double));
  operands.pop();
}

void calculate_expressions() {
  ifstream expressions("expressions.txt");
  ofstream results("results.bin", ios::trunc | ios::binary);

  stack<double> operands;

  while (!expressions.eof()) {
    char next_character = expressions.peek();

    if (is_digit(next_character)) {
      double operand;
      expressions >> operand;
      operands.push(operand);
    } else {
      char operation;
      expressions >> operation;
      apply_operation(operation, operands);
    }

    if (expressions.peek() == ';') {
      write_result(results, operands);
    }

    expressions.ignore(2, ' ');
  }

  write_result(results, operands);

  results.close();
  expressions.close();
}

void print_results() {
  ifstream results("results.bin", ios::binary);

  double result;
  while (results.read((char*)&result, sizeof(double))) {
    cout << result << ' ';
  }

  results.close();
}

int main() {
  calculate_expressions();
  print_results();
  cout << '\n';

  return 0;
}