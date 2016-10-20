#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;
using std::cout;

void testTextFileOutput() {
  ofstream text_file("test.txt");

  text_file << "This is my text file\n";
  text_file << 10 << ' ' << 5.6;

  text_file.close();
}

void testBinaryFileOutput() {
  ofstream binary_file("test.bin", ios::binary);

  for (int i = 0; i <= 20; ++i) {
    binary_file.put((char)i);
  }

  double numbers[] = { 1.2, 3.4, 5.6, 7.8 };
  binary_file.write((const char*)numbers, sizeof(numbers));

  binary_file.close();
}

void testTextFileInput() {
  ifstream text_file("test.txt");

  char line[100];
  text_file.getline(line, 100);

  int first_number;
  double second_number;
  text_file >> first_number >> second_number;

  cout << "line = " << line << '\n';
  cout << "first_number = " << first_number << '\n';
  cout << "second_number = " << second_number << '\n';

  text_file.close();
}

void testBinaryFileInput() {
  ifstream binary_file("test.bin", ios::binary);

  for (int i = 0; i <= 20; ++i) {
    cout << binary_file.get() << '\n';
  }

  double numbers[4];
  binary_file.read((char*)numbers, 4 * sizeof(double));

  for (int i = 0; i < 4; ++i) {
    cout << numbers[i] << '\n';
  }

  binary_file.seekg(-2 * sizeof(double), ios::cur);
  cout << binary_file.tellg() << '\n';

  double number;
  binary_file.read((char*)&number, sizeof(double));
  cout << "number = " << number << '\n';

  binary_file.close();
}

int main() {
//  testTextFileOutput();
//  testBinaryFileOutput();
//  testTextFileInput();
  testBinaryFileInput();

  return 0;
}
