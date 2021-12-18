using namespace std;
#include "student.h"
#include "array.h"
#include "price.h"

Student::Student(string f, string l, char g, int ID) {
  firstname = f;
  lastname = l;
  gender = g;
  numClasses = 0;
  stuID = ID;
}

Student::Student() {
  firstname = "unknown";
  lastname = "unknown";
  gender = 'x';
  stuID = -1;
}

int Student::addCourse(int crn) {
  //the if statement that represents numClasses < MAX, is representing how this statement can allow the program to add more classes, but once numClasses becomes equals or becomes more larger than MAX, this program would be unusable.
  if (numClasses < MAX) {
   int choice = find(classes, MAX, crn);
   if(choice == -1) {//if it does not exist
      classes[numClasses++] = crn;
      return 1;
   }
    else {
      return 0;
    }
  }
  else {  
    return -1;
  }
}

void Student::viewAllCourses() {
  print(classes, numClasses);
  }

bool Student::dropCourse(int crn) {
  if (remove(classes, numClasses, crn)) {
    numClasses--;
    return true;
  }
  else 
    return false;
}

string Student::getFirstName() const
{
  return firstname; 
}

string Student::getLastName() const
{
  return lastname;
}

char Student::getGender() const
{
  return gender;
}

int Student::getNumClasses() const
{
  return numClasses;
}

int Student::getStuID() const
{
  return stuID;
}

int Student::getClassOf(int i) const//this function should return the crn at i from classes array
{
  find(classes, MAX, i);
  return classes[i];
}

Price Student::getBalance() const
{
  return balance;
}

void Student::addFee(int d, int c)
{
  const Price p(d, c);//make a new price from d and c
  //add it to the balance
  balance = balance + p; 
}

void Student::reduceFee(int d, int c)
{
  const Price p(d, c);//make a new price from d and c
  balance = balance - p; 
}
