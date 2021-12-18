#include "LL.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/******************************************************************************
This is the default constructor where it holds the values to start on to prevent any functions to start at different values. It is also important that once the constructor is made, it can be used with the other functions and since they are all private values, it is easier to put it in here and set it with the other functions along the way.
******************************************************************************/

LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
  //all three values indicate that the queue will be empty
}

/******************************************************************************
This function is the destructor and will be called automatically when the object of the class is destroyed, or in other terms, it is when the object gets out of the scope or curly brace
******************************************************************************/

LL::~LL()
{
  while(!isEmpty())
    {
      deleteFront();
    }
}

/******************************************************************************
This add rear function will add elements on the rear side of the queue and will also verify if there are any nodes that should be added whether if it is empty or not. It will also be a void function because it does not have to return the element while the process is continuing. 
front and rear will be used to start and end of the heap memory
count will be used to track the amount of times the element has changed or in other terms, it would know when the process is complete after the front and rear have changed.
******************************************************************************/

void LL::addRear(el_t el)
{
  if(isEmpty())//if there are no nodes inside of the heap memory
    {
      front = rear = new node;
      front->elem = el;
    }
  else//if there are nodes inside the heap memory
    {
      rear->next = new node;
      rear = rear->next;
      rear->elem = el;
      rear->next = NULL;//this is important in order to keep the memory stable
    }
  count++;//increment once it has been completed
}

/******************************************************************************
This addFront function is somewhat similar with the addRear function, but the only difference is that the front will be receiving an element from any function and will allow the number to be inserted from the front slot.
******************************************************************************/

void LL::addFront(el_t el)
{
  if(isEmpty())//if there are no nodes inside of the heap memory
    {
      front = rear = new node;//this can be either front or rear since both are pointing at the same node
      rear->elem = el;
    }
  else//if there are nodes inside the heap memory
    {
      node* p = new node;
      p->elem = el;//store the element first
      p->next = front;//the next element will be front since we will be going to use the front node
      front = p;//we will set the front to p because front will be used for the new added node and will continue the process
    }
  count++;//since we are adding, count must go up as well
}

/******************************************************************************
This deleteFront function is a typedef integer type because it allows the element on the front to be found and deleted once the command is called. It would require three conditional statements to access the heap memory whether if there are no nodes, one node, or more nodes. It will be easily accessible and will only focus on the front rather than the rear since the delete will only occur on the front. It is required to return an element in order for it to work since it is not a void function.
count will be used to check on the nodes. 
next will be used to set front to the next once the front will be deleted. 
element is the element that is stored so there would not be any roaming leaking around the heap memory.
******************************************************************************/

el_t LL::deleteFront()
{
  if(isEmpty())//making sure that there are no values inside of this delete front function
    {
      LLError("The queue is empty and cannot be deleted");
    }
  else if(count == 1)//if there is one node inside of the heap memory
    {
      el_t element = front->elem;//this will be used so the element will not be roaming around the heap memory
      delete front;//it is safe to delete now since the element is saved inside the local variable
      front = rear = NULL;//set this to its default values as the defaul constructor
      count--;
      return element;//this will be saved within the local variable and return it back to the program
    }
  else
    {
      node* newFront = front->next;//this must be important since we will be deleting the front so front has to shift to next
      el_t element = front->elem;//this element is important to store inside of the local variable
      delete front;
      front = newFront;//the shift begins and front will now be its newFront
      count--;//must decrement since the front is gone
      return element;//the element the front inititally had
    }
}

/******************************************************************************
The deleteRear function will also have the same process as the deleteFront function, but will differ with the position since I am using the rear. The rear in this case will be deleted based on the position rather than the number being specified, so it will delete whatever number is on the rear.
******************************************************************************/

el_t LL::deleteRear()
{
  if(isEmpty())//if there are no nodes inside of the heap memory
    {
      LLError("Error: list is empty."); 
    }
  else if(count == 1 && front == rear)//I decided to use two different statements just to be safe because if the heap memory has one node then it will be able to delete the last node and return the element it had before it was deleted.
    {
      el_t old = rear->elem;//the element that has been stored
      delete rear;
      front = rear = NULL;//this has to happened because if it is deleted there are memory leaks around the heap memory
      count--;//since we are deleting it should also decrement as well
      return old;
    }
  else//more than one node
    {
      node* p = new node;
      el_t old = rear->elem;
      //el_t extra = front->elem;
      delete rear;
      for(p = front; p->next != rear; p = p->next);//do nothing. The purpose of this for loop is to advance p to second to last node
      rear = p;
      rear->next = NULL;//this is needed because if the rear does not have a limit to stop on, it will not compile properly
      count--;//since we are deleting, it will decrement.
      return old;
    }
}

/******************************************************************************
This isEmpty function will be a bool function to verify if the heap memory is empty or not. Since it is a bool function, it has to return either true or false and not any other data type. It is important that the if statement reads null for both front are rear to confirm that the heap memory is empty.
******************************************************************************/

bool LL::isEmpty()
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
This displayAll function will be used to output if there are any nodes inside the heap memory. It also allows the user to know if the nodes that have been outputted are correct or not.
isEmpty() will be used to check the heap memory so the user will know that it is empty. 
The other part will be used to set a new node p to front until it hits NULL, which is the stopping point of the heap memory.
******************************************************************************/

void LL::displayAll()
{
  if(isEmpty())//if there are no nodes
    cout << "[empty]" << endl; 
  else//if there are any nodes inside of the heap memory
    {
      node* p;
      p = front;
      while(p != NULL)//this is when the p goes to the end of the nodes or in other terms the stopping point
      {
        cout << p->elem << " ";
        p = p->next;
      }
    }
}

/******************************************************************************
This function is the copy constructor, which will allow me to have a separate list that will have the same elements from the source coming from the main function most likely. Without this, it will be difficult to allow the elements to be copied and will allow a memory leak and error. I will not use this function for the palindrome.cpp  
******************************************************************************/

LL::LL(const LL& source)//the source will be the class name variable
{
  this->front = this->rear = NULL;//this when the objext has no elements in the list
  this->count = 0;

  //node* p = new node;
  node* p = source.front;
  while(p != NULL)//makes sure that it visits every node in source
    {
      this->addFront(p->elem);//element from the source
      p = p->next;//goes to next node
    }
}

/******************************************************************************
The deleteNode function will look for the element and verify to see if it is ready to be deleted. It will be using test cases to check for the element inside of the function, whether if the function is empty, the pointer that scans through the for loop to see if the element exists, whether if the node is located at the rear and if the node is located at the front. It will also decrement throughout the process since the node will be deleted and is logical to do so.
******************************************************************************/

void LL::deleteNode(el_t e)
{
  node* pre;
  node* del;
  if(isEmpty())//must be outside the for loop to process
    cout << "[empty]" << endl;
  for(pre = front, del = front->next; del != NULL && del->elem != e; pre = del, del = del->next);
  if(del != NULL)//node exists
    {
      pre->next = pre->next->next;//the pre node will go to the next node after that node 
      delete del;//delete the node pointed to by del
      count--;
    }
  else if(pre == front || front->elem == e)//one node inside
    {
      deleteFront();
      //front = rear = NULL;
    }
  else//if the element does not exist
    {
      return;
      //deleteRear();//link the node before the node to be deleted to the node after that, and do not input the error message here because it will not compile the other elements
    }
}

/******************************************************************************
The search function is a bool function that returns true if the element matches inside of the heap memory and will return false if there are no matching elements. I will be using a variable for node to be set for front so it will check the next nodes inside the heap memory. I used a while loop to view the whole heap memory and check to see when the element has the same element that is passed.
******************************************************************************/

bool LL::search(el_t e)
{
  node* temp = front;//set a node to front
  while(temp != NULL)//until the front has not touched NULL
    {
      if(temp->elem == e)//if it is found in the linked list
	return true;//return that it is true
      temp = temp->next;//continues to go to the next node
    }
  //if the linked list is empty
  return false;//the value is non existent
}

/******************************************************************************
The addInOrderAscend function will store an element that is passed and will be processed while the element passed will be checked on ascending order. Ascending order is set up by smallest to largest. There will be four test cases in order for this to work. First, if there are no nodes inside of the heap memory it is logical that the node with the passed element should be added. Second, if the element passed is less than the first element inside of the node, it will be kind of similar with the empty node, but the difference is that the node that is passed will be declared as the new front of the heap memory. Third, if the element is greater than the last element, then the element must be set to the last node and will be set as the new rear node. Last, the node that is in between the numbers entered are going to be set in the middle of the two elements inside of the heap memory.
******************************************************************************/

void LL::addInOrderAscend(el_t e)
{
  node* p = front;
  if(front == NULL && rear == NULL)//if there are no elements inside of the heap memory. IT IS IMPORTANT THAT THERE ARE TWO ASSIGNMENT OPERATORS AND NOT ONE!
    {
      front = rear = new node;//front and rear will have the same node
      front->elem = e;//the front element or rear element would be set to the new added element in the linked list
      count++;//increment the heap memory
    }
  else//there are nodes inside of the heap memory
    {
      if(e < front->elem)//the node is less than the front element
      {
        node* newFront = new node;//to add a new front node
        newFront->elem = e;//set the element being passed to its assigned position
        newFront->next = front;//since it is ahead, it will be set previous to the front of the "original" node
        front = newFront;//since the front is new, it will be set to the newFront
        count++;//increment the heap memory
      }
      else if(e > rear->elem)//if the element is greater than the tail
      {
        rear->next = new node;//the new node after rear
        rear = rear->next;//the rear will now be set to the new node
        rear->elem = e;//add the element to its correct position
        rear->next = NULL;//the rear will now be NULL since it is now the new additional rear
        count++;//increment the count
      }
      else//if the node is inside the range rather than outside the rear/front
      {
        node* newNode = new node;//the node that will be entered within the range
        newNode->elem = e;//the new node element
        //newNode->next = NULL;
        while(p->next != NULL && p->next->elem < e)//this will verify when the node of the pointed front of the next elem is less than e and when it does not hit null
          {	  	      
            p = p->next;//this is when the pointed front will be set to the pointed next since I am adding the element in between two elements.
            }
        newNode->next = p->next;//this is to set the newNode's next into the pointed next to set the address
        p->next = newNode;//then the pointed next will be set to the NewNode's address and continues from there
      }
    }
}

/******************************************************************************
This is the Linked List error message that outputs a statement that is used in the other functions, which has a message as parameter to enter any string. It will have an exit 1, which is from the cstdlib library, that allows the program to stop.
******************************************************************************/

void LL::LLError(string msg)
{
  cout << msg << endl;
  exit(1);
}
