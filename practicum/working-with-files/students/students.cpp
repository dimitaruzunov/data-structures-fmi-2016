#include <fstream>
#include <iostream>
#include "student.h"

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;
using std::cin;
using std::cout;

Student* input_students(int& number_of_students) {
  cout << "Choose the number of students to input: ";
  cin >> number_of_students;

  Student* students = new Student[number_of_students];

  for (int i = 0; i < number_of_students; ++i) {
    cin >> students[i];
  }

  return students;
}

void save_students(Student* students, int number_of_students) {
  ofstream students_file("students.txt");

  for (int i = 0; i < number_of_students; ++i) {
    students_file << students[i] << '\n';
  }

  students_file.close();
}

void save_graduates() {
  ifstream students_file("students.txt");
  ofstream graduates_file("graduates", ios::binary);

  Student student;
  while (students_file >> student) {
    if (student.getGrade() >= 3) {
      graduates_file.write((const char*)&student, sizeof(Student));
    }
  }

  graduates_file.close();
  students_file.close();
}

void raise_grade(unsigned fn) {
  fstream graduates_file("graduates", ios::in | ios::out | ios::binary);

  Student student;
  while (graduates_file.read((char*)&student, sizeof(Student))) {
    if (student.getFN() == fn) {
      student.setGrade(student.getGrade() + 1);

      graduates_file.seekp(-sizeof(Student), ios::cur);
      graduates_file.write((const char*)&student, sizeof(Student));
      graduates_file.flush();
    }
  }

  graduates_file.close();
}

void print_graduates() {
  ifstream graduates_file("graduates", ios::binary);

  Student student;
  while (graduates_file.read((char*)&student, sizeof(Student))) {
    cout << student << '\n';
  }

  graduates_file.close();
}

int main() {
  int number_of_students;
  Student* students = input_students(number_of_students);

  save_students(students, number_of_students);
  save_graduates();
  raise_grade(37252);
  print_graduates();

  delete[] students;

  return 0;
}