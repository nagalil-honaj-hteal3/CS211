#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

const int MAX = 5;
typedef string el_t;

class Stack {
  
 private: 
  el_t el[MAX];//el is array with 5
  int top;//index of top element
  void stackError(string errorMsg);//never put this function on the public function

 public:
  Stack();//default constructor
  bool isEmpty();//returns true if stack is empty or returns false if not
  bool isFull();// returns true if stack is full or returns false if not
  void push(el_t e); //if full, calls stackError(errorMsg)
                     //if not full, enters an element at the top
  el_t pop();//if empty calls stackError(errorMsg)
             //if not empty, removes an element from the top
  el_t topElem();//
  void displayAll();
  void clearIt();

};
#endif
