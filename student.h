#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "price.h"
using namespace std;

enum classes {ONE, TWO, THREE, FOUR, FIVE, SIX};

const int MAX = 6;//number of classes the student takes

class Student {

private:
  string firstname, lastname;
  char gender;
  int numClasses, stuID;//number of classes the student will take
  int classes[MAX];//constant array that has the limit of 6 slots
  //int courseNumber;
  Price balance;//data member

public:
  Student();
  Student(string f, string l, char g, int ID);
  int addCourse(int crn);
  void viewAllCourses();
  bool dropCourse(int crn);
  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getNumClasses() const;
  int getStuID() const;
  int getClassOf(int i) const;
  Price getBalance() const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};
#endif
