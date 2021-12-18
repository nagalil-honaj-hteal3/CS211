#include "stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;
/********************************
This function is a default constructor
 *******************************/
Stack::Stack()
{
  top = -1;
}
/********************************
This function is reading the stack when empty
 *******************************/
bool Stack::isEmpty() 
{
  if(top == -1)
    return true;
  else
    return false;
}
/********************************
This function is reading when the stack is full
 *******************************/
bool Stack::isFull()
{
  if(top == MAX - 1)
    return true;
  else
    return false;
}

/********************************
This function pushes in a character
 *******************************/
void Stack::push(el_t e)
{
  if(!isFull())
    {
    top = top + 1;
    el[top] = e;//or el[++top] preincrement
    }  
  else
    stackError("Stack Overflow");
}
/********************************
This function pops a character
 *******************************/
el_t Stack::pop()
{
  if(isEmpty())
    stackError("Stack Underflow");
  else
    return el[top--];//this shows that when top is not empty, it will subtract one 'plate' at a time.
}

void Stack::clearIt() 
{
  //el_t elem;
  while(!isEmpty())
    {
      pop();
    }
}

el_t Stack::topElem()
{
  if(!isEmpty())
    return el[top];
  else
    cout << "Stack is empty." << endl;
}

void Stack::displayAll()
{
  if (isEmpty())     
      cout << "\n\nThe stack is empty.\n" << endl;
  else
    for(int i = top; i >= 0; i-- )
      {
	cout << el[i] << endl;
      }
    
}

void Stack::stackError(string errorMsg)
{
  cout << errorMsg << endl;
  exit(1);//this will end the program. 1 is returned to the operating system.
          //1 ends with errors.
          //0 ends with no errors.
}
