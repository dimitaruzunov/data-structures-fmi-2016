#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using std::istream;
using std::ostream;

const int MAX_NAME = 100;

class Student {
  char name[MAX_NAME];
  unsigned fn;
  double grade;

public:
  Student(const char* name = "", unsigned fn = 0, double grade = 2);

  unsigned getFN() const;
  double getGrade() const;
  void setGrade(double grade);

  friend istream& operator>>(istream& in, Student& student);
  friend ostream& operator<<(ostream& out, const Student& student);
};

#endif