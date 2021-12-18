/******************************************************************************
This program demonstrates inheritance, constant data members, static data members and functions.
******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "LL_T.h"
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
  Person(string f = "unknown", string l = "unknown", string S = "000-00-0000", string e = "unknown") : ID(current_id)
  {
    fn = f;
    ln = l;
    SSN = S;
    email = e;
    current_id++;
    num++;
  }//default variables
  virtual void printInfo()
  {
    cout << "Person::printInfo()" << endl;
    cout << "Your ID is " << ID << "\nYour first name is " << fn << "\nYour last name is " << ln << "\nYour social security number is " << SSN << "\nYour email is " << email << endl << endl;
  }
  static int getCurrentId();
  static int getNum();
};

int Person::current_id = 1000;//intialize the statc int to 1000, and must be declared outside of the person class
int Person::num = 0;//initialize the static int to zero to track the number of people
/******************************************************************************
Set the default values inside of the function header of the constructor. The constant data member needs to be initialized in the function header, implementing this constructor outside of the class definition, will not have access with the default values.
******************************************************************************/
/*
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
*/
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
  ifstream fin;
  fin.open("campus.dat");
  string first, last, SSN, email, major;
  int year, depID, pos;
  char level;
  double gpa;
  if(!fin)
    cout << "File has not been recognized. Please try again." << endl;
  else
    {//use deleteFront function to get each person and call printInfo()
      LL<Person*> l;//data type of the Linked List
      fin >> pos;
      while(fin)
      {
        if(pos == 1)//Person
          {	      
            fin >> first;
            fin >> last;
            fin >> SSN;
            fin >> email;
            Person* p = new Person(first, last, SSN, email);
            l.addRear(p);//adds the constructor elements into the linked list
            //first name, last name, ssn, email
          }
        else if(pos == 2)//Faculty
          {
            fin >> first;
            fin >> last;
            fin >> SSN;
            fin >> email;
            fin >> depID;
            fin >> year;
            Faculty* fa = new Faculty(first, last, SSN, email, depID, year);
            l.addRear(fa);//adds the elements into the linked list
            //first name, last name, ssn, email, depID, year
          }
        else if(pos == 3)//Student
          {
            fin >> first;
            fin >> last;
            fin >> SSN;
            fin >> email;
            fin >> major;
            fin >> gpa;
            fin >> level;
            Student* st = new Student(first, last, SSN, email, major, gpa, level);
            l.addRear(st);//adds the elements into the linked list
            //first name, last name, ssn, email, major, gpa, level
	      }
	    fin >> pos;
	}      
      while(!l.isEmpty())
      {
        Person* p1 = l.deleteFront();
        p1->printInfo();
      }
    }
  fin.close();
  
    cout << "There are " << Person::getNum() << " people that are registered and the current id is " << Person::getCurrentId() << endl;
  return 0;
}
