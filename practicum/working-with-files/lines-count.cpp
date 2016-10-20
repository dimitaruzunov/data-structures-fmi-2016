#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;

long count_lines(const char* buffer, long size) {
  long number_of_lines = 0;

  for (int i = 0; i < size; ++i) {
    if (buffer[i] == '\n') {
      ++number_of_lines;
    }
  }

  return number_of_lines;
}

int main() {
  ifstream text_file("lines.txt");

  unsigned number_of_lines = 0;
  char buffer[100];
  while (text_file.read(buffer, 100).gcount()) {
    number_of_lines += count_lines(buffer, text_file.gcount());
  }
  cout << "Number of lines in file: " << number_of_lines << '\n';

  text_file.close();

  return 0;
}
