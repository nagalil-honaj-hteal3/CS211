#include <iostream>
using namespace std;
#include "price.h"

/******************************************************************************
The consturctor will set both the private variables to be zero since it will be set to start. It is important to set both dollar and cent to be zero since it is logical to not have any values less than or greater than zero.
******************************************************************************/

Price::Price() 
{
  dollar = 0;
  cent = 0;
}

/******************************************************************************
This constructor has parameters since it will be reused when adding or subtracting values
******************************************************************************/

Price::Price(int d, int c) 
{

  dollar = d;
  cent = c;
}

/******************************************************************************
This operator + function uses the this pointer and a class name parameter because it is easy accessible to have both add up and return the value of what has been added
******************************************************************************/

Price Price::operator+(const Price& rs) 
{//rs is passed to the operator by reference 
  //Adds the this-> object and z to return a new object 
  int d = this->dollar + rs.dollar;
  int c = this->cent + rs.cent;
  if(c >= 100) { 
     d = d + 1;
     c = c - 100;
  }
  Price t(d, c);
  return t;
}

/******************************************************************************
This operator - function uses the this pointer and a class name parameter because it is easy accessible to have both subtract and return the value of what has been subtracted
******************************************************************************/

Price Price::operator-(const Price& rs) 
{
  int d = this-> dollar - rs.dollar;
  int c = this-> cent - rs.cent;
  if (c < 0) {
    d = d - 1;
    c = c + 100;
  }
  /*else {
    c = c - 100;
    }*/
  Price t(d, c);
  return t;
}

/******************************************************************************
The operator << function outputs the followings values from the addition and subtraction functions. Since it is using the ostream function, it is used as a cout
******************************************************************************/

ostream& operator<<(ostream& o, const Price& r) 
{   
  if (r.cent < 10) {
  o << r.dollar << ".0" << r.cent;
  }
  else {
    o << r.dollar << "." << r.cent;
  }
}
  /*if (r.cent >= 100)
    o << r.dollar + 1 << "." << r.cent - 100;
  //else if (r.cent < 110 || r.cent > 0)
  //o << r.dollar + 1 << "." << r.cent % 100;
  else if (r.cent < 0)
    o << r.dollar - 1 << "." << r.cent + 100;
  else
    o << r.dollar << "." << r.cent;
  return o;//from ostream
  */
