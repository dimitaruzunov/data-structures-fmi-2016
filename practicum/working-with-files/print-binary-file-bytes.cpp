#include <iostream>
#include <fstream>

using std::ifstream;
using std::ios;
using std::cout;

int main() {
  ifstream text_file("lines.txt", ios::binary);

  char buffer[100];
  while (text_file.read(buffer, 100).gcount()) {
    for (int i = 0; i < text_file.gcount(); ++i) {
      cout << (int)buffer[i] << ' ';
    }
    cout << '\n';
  }

  text_file.close();

  return 0;
}
