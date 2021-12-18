#include "lqueue.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/******************************************************************************
This is the constructor where the values start at. This allows me to use my private members become usable in order for it to be accessible with the other functions that I will be using later in the program.
front = the value that will be used from the front
rear = will be similar with the front, but will be used from the rear
count = to know how many times the front and rear changed 
******************************************************************************/

LQueue::LQueue()
{
  front = NULL;
  rear = NULL;
  count = 0;
  //all three values indicate that the queue will be empty
}

/******************************************************************************
This is the destructor and will be called automatically when the object of the class is destroyed, or in other terms, once the object gets out the scope or curly brace. 
******************************************************************************/

LQueue::~LQueue()
{
  while(!isEmpty())//this will be used if there are nodes inside the heap memory
    {
      deleteFront();//will delete the front part of the node
    }
}

/******************************************************************************
The addRear function will add elements on the rear side of the queue and will also verify if there are any nodes that should be added whether if it is empty or not. It will also be a void function because it does not have to return the element while the process is continuing. 
front and rear will be used to start the and end the heap memory.
count will be used to track the amount of times the element has changed or in other terms, it know when the process is complete after front and rear has been changed.
******************************************************************************/

void LQueue::addRear(el_t el)
{
  if(isEmpty())//this if statement is if there are no nodes yet inside of the heap memory
    {
      front = rear = new node;
      //rear = front;
      front->elem = el;//the new element
      //rear = new node;
    }
  else//if there are any nodes inside the heap memory
    {
      rear->next = new node;//adds an extra node
      rear = rear->next;//this is where the rear will be located
      rear->elem = el;//this is needed to keep the memory of what is inside of the element
      rear->next = NULL;//this is the final destination for the next slot of the heap memory or in other terms, the next slot will be stored inside inside a memory that does not have a leak memory
    }
  count++;//this is used once the process has been complete
}

/******************************************************************************
This deleteFront function is a typedef integer type becuase it allows the element on the front to be found and deleted once the command is called. It would require three conditional statements to access the heap memory whether if there are no nodes, one node, or more nodes. It will be easily accessible and will only foucs on the front rather than the rear since the delete will only occur on the front. It is required to return an element in order for it to work since it is not a void function.
-1 is the number to return since it is a number that has not been used yet.
count will be used to check on the nodes.
next will be used to set front to be next once the front will be deleted.
element is the element that is stored before the front will be deleted so would not be any heap memory.
******************************************************************************/

el_t LQueue::deleteFront()
{
  if(isEmpty())//access the empty function
    {
      queueError("The queue is empty. Cannot delete");
      return -1;//returning this number because it has not been used and is below the count which is set to zero.
    }
  else if(count == 1)//if there is one node or has a new node being entered
    {
      el_t element = front->elem;
      delete front;//it can also delete rear
      front = rear = NULL;//to prevent memory 
      count--;//since it deletes, the heap memory shortens
      return element;
    }
  else//if there are more than one node
    {
      //node* p = new node;
      //p->rear = p->front->next;
      node* next = front->next;//the node after the first node
      el_t element = front->elem;
      delete front;
      //cout << old;
      front = next;//front moves down
      count--;
      return element;
    }
}

/******************************************************************************
This isEmpty function will be a bool function to verify if the heap memory is empty or not. Since it is a bool function, it has to return either true or false and not any other data type. It is important that the if statement reads null for both front and read to confirm that the heap memory is empty.
******************************************************************************/

bool LQueue::isEmpty()
{
  
  if(front == NULL && rear == NULL)//if the queue is empty
    {
      return true;
      //cout << queueError("The queue is empty");
    }
  else//if there are extra elements inside the queue
      return false;
}

/******************************************************************************
This displayAll function will be used to output if there are any nodes inside the heap memory. It also allows the user to know if there are any nodes inside the heap memory. 
isEmpty() will be used to check the heap memory so the user will know that it is empty.
The other part will be used to set a new node p to front until it hits NULL, which is the stopping point of the heap memory.
******************************************************************************/

void LQueue::displayAll()
{
  if(isEmpty())//if there are no nodes
    //cout << "ok" << endl << endl;
    cout << "[empty]" << endl; 
  //else if(isEmpty() == true)
  //cout << "The queue is empty" << endl;
  //else if(isEmpty() == false)
  //cout << "The queue is not empty" << endl;
  else//if there are any nodes inside of the heap memory
    {
      node* p;
      p = front;
      while(p != NULL)//this is when the p goes to the end of the nodes or in other terms the stopping point
	{
	  cout << p->elem << endl;
	  p = p->next;
	}
    }
}

/******************************************************************************
For this createReverseLL, I am required to have two parameters in order for it to work. The LQueue l is used to be read from the class object and the string will be a pass by reference to be reffered from the main function or from other functions that has not been applies in this function. Inside of my for loop I was unsure if my temp was working because initailly I inserted a cout inside the loop to test it but got junk values however when I put it outside, my numbers would be read reversed and tried to output it on the example as follows. 
******************************************************************************/

void LQueue::createReverseLL(LQueue l, const string& s)
{
  /*
  int j = s.length() - 1;//the number
  for(int i = 0; i < s.length(); i++)
    {
      int temp = (s.at(j) - 48);
      //int temp = 0;
      //int temp = l.deleteFront();
      //temp = q - 48;
      l.addRear(temp);
      j--;
    }
  */
  int temp = 0;//length of the number
  int j = s.length() - 1;
  for(int i = 0; i < s.length(); i++)
    {
      temp += (s[j] - 48) * pow(10, (s.length() - i - 1));//+= used to add up/concatenate the characters inside the string. I would have to use j, which is my size of the string which is subtracted by one in order to get the right size. The s[j] will be subtracted by 48 because 48 is the ASCII value for zero and will be converted as an int. It will be multiplied with base of 10 to the power of the size while subtracting i, which will be used everytime the char is shifted, and one since the size has to fit with the queue.
      l.addRear(temp);
	//cout << s[i] << " ";
      j--;
    }
  cout << temp << " + ";//outputs weird
}

/******************************************************************************
This addLLs function will be used to add my numbers from the createReverseLL function to add the numbers by reverse. It is easier that way to prevent the numbers to not be added wrong so for instance if the a two digit number is being added by the three digit number, without the reverse, it would probably add the tens digit on the two digit number with a hundred digit on a three digit number. While doing the process on reverse, it will allow the numbers to easily align with each other. I am unable to get this function to work for some odd reason and tired outputting my sum inside of my while loop so I can see what it outputs, but would be rejected from the process. It is also important that the numbers being added has to have a carry over because if the number is added by greater than or equal to 10, it will keep the digit from the ones spot, and carry the tens, to the next slot by easily adding one. 
******************************************************************************/

void LQueue::addLLs(LQueue l1, LQueue l2, LQueue total)
{ 
  
  //order is messed up or the carry is wrong  
  int carry = 0, sum;
  while(!l1.isEmpty() || !l2.isEmpty())//this will be used to make sure if there is anything inside the heap memory
    {
      //cout << "l" << endl;
      if(!l1.isEmpty())//to access the l1 number
	      sum += carry + l1.front->elem;
      if(!l2.isEmpty())//to access the l2 number
	      sum += carry + l2.front->elem;
      else
	      sum += carry + 0;
      //sum = carry + (l1 ? l1->elem : 0) + (l2 ? l2->elem : 0)
      //cout << sum << endl;
    
      //cout << "The sum is " << sum << endl;
      if(sum >= 10)//will be used when the number is getting carried over
      {
        sum = sum % 10;
        carry = 1;
      }
      else //if the number is less than 10
	      carry = 0;
      
	total.addRear(sum);
	//total.front->elem = sum;
	//rear = sum;
	
	if(!l1.isEmpty())//to access the l1 number
	l1.front = l1.front->next;
	if(!l2.isEmpty())//to access the l2 number
	l2.front = l2.front->next;
	//
      //cout << sum << endl;
 
    }
  if(carry > 0)//to make sure that the carry is completed
    total.addRear(carry);
  cout << "= " << sum << endl;
  //total.displayAll(); 
}

/******************************************************************************
This function will be used if there are no nodes as the parameter or in other terms, it will be used for the public class to easily access the function. It will output the number in reverse, however I am unsure why this would not output. Since inside of the parameter has front, it will access the private member function of this function.
******************************************************************************/

void LQueue::printAllReverse()
{
  printAllReverse(front);//
}

/******************************************************************************
This function will be used to output, but since it has a parameter of the node pointer, it will be easily accessed especially when there is a front inside of the function, it is also inside of the private function, which allows this to become the private function rather than a public function.
******************************************************************************/

void LQueue::printAllReverse(node* p)
{
  if(p == NULL)//this is once p has no longer got anywhere else to go inside of the heap memory
    return;
  else//if there are more nodes remaining to add
    {
      printAllReverse(p->next);//to move the p to next
      cout << p->elem;//it will store the element of where p is located
    }
}

/******************************************************************************
This will be the error message to notify the user
******************************************************************************/

void LQueue::queueError(string msg)
{
  cout << msg << endl;
}
