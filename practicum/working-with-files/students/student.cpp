#include "student.h"

Student::Student(const char* name, unsigned fn, double grade)
  : fn(fn), grade(grade) {
  strncpy(this->name, name, MAX_NAME);
  this->name[MAX_NAME - 1] = '\0';
}

unsigned Student::getFN() const {
  return fn;
}

double Student::getGrade() const {
  return grade;
}

void Student::setGrade(double grade) {
  this->grade = grade;
}

istream& operator>>(istream& is, Student& student) {
  return (is >> student.fn >> student.grade)
    .ignore() // ignore the separator between student's grade and name
    .getline(student.name, MAX_NAME);
}

ostream& operator<<(ostream& os, const Student& student) {
  return os << student.fn << ' '
            << student.grade << ' '
            << student.name;
}