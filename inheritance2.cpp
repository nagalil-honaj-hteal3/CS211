/******************************************************************************
Elaeth Lilagan
CS211

This program demonstrates inheritance, constant data members, static data members and functions.
******************************************************************************/

#include <iostream>
using namespace std;

//############### Person class ##################
class Person //base class
{
protected://used to access from inherited classes, faculty and student
  static int current_id;
  static int num;//number of people created
  const int ID;//includes student, employee, faculty
  string fn;
  string ln;
  string SSN;
  string email;
public: 
  Person(string f = "unknown", string l = "unknown", string S = "000-00-0000", string e = "unknown");//default variables
  void printInfo();
  static int getCurrentId();
  static int getNum();
};

int Person::current_id = 1000;//intialize the statc int to 1000, and must be declared outside of the person class
int Person::num = 0;//initialize the static int to zero to track the number of people
/******************************************************************************
Set the default values inside of the function header of the constructor. The constant data member needs to be initialized in the function header, implementing this constructor outside of the class definition, will not have access with the default values.
******************************************************************************/

Person::Person(string f, string l, string S, string e): ID(current_id)
{
  fn = f;
  ln = l;
  SSN = S;
  email = e;
  current_id++;//increment after every person
  num++;//increment the people added or created
}

void Person::printInfo()
{
  cout << "Person::printInfo()" << endl;
  cout << "Your ID is " << ID << "\nYour first name is " << fn << "\nYour last name is " << ln << "\nYour social security number is " << SSN << "\nYour email is " << email << endl;
}

int Person::getCurrentId()//this is a static function. Do not add the word static on the function, only on the prototype
{
  return current_id;
}

int Person::getNum()
{
  return num;
}

//############### Faculty class ##################
class Faculty : public Person//faculty is an inherited class of Person class
{
private:
  int dprtID;//department id
  int year;//years present in the school
public:
  Faculty(string f = "unknown", string l = "unknown", string S = "000-00-0000", string e = "unknown", int d = -1, int y = -1) : Person(f, l, S, e)//calling the constructor of person class
  
  {
    dprtID = d;
    year = y;
  }
  void printInfo()
  {
    cout << "Faculty::printInfo()" << endl;
    Person::printInfo();//Calling the function from the person class to have less redundancy
    cout << "Your department ID is " << dprtID << "\nThe number of years you attended in this school for is " << year << endl << endl;
  }
};

//############### Student class ##################
class Student : public Person 
{
private:
  string major;
  double gpa;
  char grade;
public:
  Student(string f = "unknown", string l = "unknown", string S = "000-00-0000", string e = "unknown", string m = "unknown", double gp = -1.00, char gr = '?') : Person(f, l, S, e)
  {
    major = m;
    gpa = gp;
    grade = gr;
  }
  void printInfo()
  {
    cout << "Student::printInfo()" << endl;
    Person::printInfo();
    cout << "Your major is " << major << "\nYour gpa is " << gpa << "\nYour grade is " << grade << endl << endl;
  }
};

//############### Client ##################
int main()
{
  Faculty f("Kathy", "Ross", "222-33-4444", "kathy@csusm.edu", 100, 2);
  Student s("Tom", "Lopez", "333-44-5555", "tom@csusm.edu", "CS", 3.33, 'J');
  Faculty f2("Mike", "Smith", "111-22-3333", "mike@csusm.edu", 100, 5);
  Student s2("Mike", "Smith", "111-22-3333", "mike@csusm.edu", "CS", 3.25, 'S');

  cout << "----------------------------\n1: Faculty" << endl;
  f.printInfo();
  cout << "----------------------------" << endl;

  cout << "2: Student" << endl;
  s.printInfo();
  cout << "----------------------------" << endl;

  cout << "3: Faculty" << endl;
  f2.printInfo();
  cout << "----------------------------" << endl;

  cout << "4: Student" << endl;
  s2.printInfo();
  cout << "----------------------------" << endl;

  cout << "There are " << Person::getNum() << " people that are registered and the current id is " << Person::getCurrentId() << endl;
  return 0;
}
