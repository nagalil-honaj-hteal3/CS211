//An object is what will be used in a class
//EX: (header file) -> student.h
#include <string>//string datatypes that will be used in the example
using namespace std;
const int MAX = 10//Max number of classes the student will take

class Student
{
  private://used for data members
    string first;
    string last;
    int ssn;
    string tel;
    int numClasses;
    int classes[MAX];
  public://used for functions (prototypes)
    Student(string f, string l, int s, string t);// <- constructor for the default variables
    void addClass(int c);
    void dropClass(int c);
    void viewClasses();
    string getTel();
    void updateTel(string t);
}; //imperative to put a semicolon at the end

//for the .cpp file
#include <iostream>//not as needed in the '.h' file since it will not require cin/cout statements
using namespace std;
#include "student.h"//includes the header file that was made including the class (Student)

//constructor - set the parameters in the function to the private members
Student::Student(string f, string l, int s, string t)//-> always format it by "className::funcName()"
{
  first = f;
  last = l;
  ssn = s;
  tel = t;
  numClasses = 0;//since it will be starting off by default --> newly added
}

void Student::addClass(int c)
{
  //adds the parameter c into the array
  classes[numClasses++] = c;
}

void Student::dropClass(int c)
{
  //delete c if course is found 
}

//...continues until the following functions in the public are finished
