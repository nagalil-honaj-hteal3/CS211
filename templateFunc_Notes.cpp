//If you make functions template, they work with any data type. We don’t need to make multiple functions that contain the same code using different data types any more.

//Example used for CS111
//The following two functions (getInt() and getDouble()) are the same except the data types.
//The following two functions are in input.h
/****************************************************************************
min is the minimum value accepted
max is the maximum value accepted
msg is the message shown when the user's input was outside the range.
These functions will read in an integer/double number and keeps asking to enter a number as long as
a number outside the range is entered. It will return a number within the range (between min and
max inclusive).
*******************************************************************************/
int getInt(int min, int max, string msg)
{
  int n;
  cin >> n;
  while(n < min || n > max)
    {
      cout << msg;
      cin >> n;
    }
  return n;
}
double getDouble(double min, double max, string msg)
{
  double n;
  cin >> n;
  while(n < min || n > max)
    {
      cout << msg;
      cin >> n;
    }
  return n;
}
//testInput.cpp
#include “input.h”
int main()
{
  int age, score;
  double gpa;
  char ans;
//Test getInt()
  cout << "Enter an age: ";
  age = getInt(0, 200, "An age must be between 0 and 200. Enter again: ");
  cout << "age = " << age << endl << endl;
  cout << "Enter a test score: ";
  score = getInt(0, 100, "A test score must be between 0 and 100. Enter again: ");
  cout << "score = " << score << endl << endl;
//Test getDouble()
//get a gpa. It should be between 0.00 and 4.00.
  cout << "Enter your gpa: ";
  gpa = getDouble(0.00, 4.00, "A GPA must be between 0.00 and 4.00. Enter again: ");
  cout << "gpa = " << gpa << endl << endl;
  return 0;
}

//___________________________________________________________________________________________________________________

//In CS211 -- code will be less redundant so this is how a template function will be used
//This is in checkInput.h
//template <typename T> <— This works too
template <class T>
T getData(T min, T max, string msg)
{
  T n; //user's input
  cin >> n;
  while(n < min || n > max) // the user's input was outside the range
  {
    cout << msg; //show the message to the user
    cin >> n; //read a new input
  }
  return n; //return a good value that is within the range (between min and max enclusive)
}
//testCheckInput.cpp
include <iostream>
using namespace std;
#include "checkInput.h"
int main()
{
  int age, score;
  double gpa;
  char ans;
//Test getData() with int
  cout << "Enter an age: ";
  age = getData(0, 200, "An age must be between 0 and 200. Enter again: ");
  cout << "age = " << age << endl << endl;
  cout << "Enter a test score: ";
  score = getData(0, 100, "A test score must be between 0 and 100. Enter again: ");
  cout << "score = " << score << endl << endl;
//Test getData() with double
//get a gpa. It should be between 0.00 and 4.00.
  cout << "Enter your gpa: ";
  gpa = getData(0.00, 4.00, "A GPA must be between 0.00 and 4.00. Enter again: ");
  cout << "gpa = " << gpa << endl << endl;
  return 0;
}
