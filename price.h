#ifndef PRICE_H//start, if PRICE_H has not been created yet 
#define PRICE_H//then create it and do the following up to endif 
#include <iostream>
using namespace std;
class Price {  

 private:
  friend ostream& operator<<(ostream& o, const Price& r);
  int dollar;
  int cent; 

 public: 
  Price();
  Price(int d, int c);
  Price operator+(const Price& rs);//rs is to declare the second parameter
  Price operator-(const Price& rs);
};
#endif//end of the part checked by PRICE_H
/*
Price::Price() {//default constructor
  dollar = 0;//declaring dollar to zero 
  cent = 0;//declaring cent to zero
}

Price::Price(int d, int c) {//non-default constructor
  dollar = d;//declaring dollar to equal d since dollar is a private member
  cent = c;//declaring cent to equal d since cent is a private member
}

Price Price::operator+(const Price& rs) {//Price in green to be used for the data types int d and c to add the dollars and cents
  int d = this-> dollar + rs.dollar;
  int c = this-> cent + rs.cent;

  Price t(d, c);
  return t;
}
*/
