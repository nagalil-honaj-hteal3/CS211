#include <iostream>
#include <cmath> 
#include <iomanip>
using namespace std;

struct ratNum {
  int nume, den, neww;
};

void fillRatNum(int& num, int& num2, int& num3, int& num4);
void add2RatNum(int num, int num2, int num3, int num4, int& new_nume, int& new_den);
void Simplify(int& new_nume, int& new_den);

int main() {
  ratNum n1, n2;
  fillRatNum(n1.nume, n1.den, n2.nume, n2.den);
  add2RatNum(n1.nume, n2.nume, n1.den, n2.den, n1.neww, n2.neww);
  Simplify(n1.neww, n2.neww);
  cout << "\n" << setw(3) << n1.nume << setw(8) << n2.nume << setw(8) << n1.neww << "\n----- + ----- = -----\n" << setw(3) << n1.den << setw(8) << n2.den << setw(8) << n2.neww << "\n";

}

void fillRatNum(int& num, int& num2, int& num3, int& num4) {
  cout << "\nRational Number 1\nEnter the top number: ";
  cin >> num;
  cout << "Enter the bottom number: ";
  cin >> num2;
  cout << "\nRational Number 2\nEnter the top number: ";
  cin >> num3;
  cout << "Enter the bottom number: ";
  cin >> num4;
}

void add2RatNum(int num, int num2, int num3, int num4, int& new_nume, int& new_den){
  int numer = (num3 * num4) / num3;
  int numer2 = (num3 * num4) / num4;
  new_den = num3 * num4;
  int numer3 = numer * num;
  int numer4 = numer2 * num2;
  new_nume = numer3 + numer4;
}

void Simplify(int& new_nume, int& new_den) {
  for (int i = new_nume * new_den; i > 1; i--) {
      if ((new_den % i == 0) && (new_nume % i == 0)) {
        new_den /= i;
        new_nume /= i;
      }
  }
}
