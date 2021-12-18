#include "DLL.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/******************************************************************************
This is the default constructor where it holds the values to start on to prevent any functions to start at different values. It is also important that once the constructor is made, it can be used with the other functions and since they are all private values, it is easier to put it in here and set it with the other functions along the way.
******************************************************************************/

DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
  //all three values indicate that the queue will be empty
}

/******************************************************************************
This function is the destructor and will be called automatically when the object of the class is destroyed, or in other terms, it is when the object gets out of the scope or curly brace
******************************************************************************/

DLL::~DLL()
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

void DLL::addRear(el_t el)
{
  if(isEmpty())//if there are no nodes inside of the heap memory
    {
      front = rear = new node;
      front->elem = el;
      rear->prev = rear->next = NULL;//since there is only one node, it is logical to set both prev and next to NULL
    }
  else//if there are nodes inside the heap memory
    {
      rear->next = new node;//an additional node inside of the heap memory
      rear->next->prev = rear;//the previous node of the created node is rear
      rear = rear->next;//set the rear to the new rear
      rear->elem = el;//store the element inside of the new rear
      rear->next = NULL;//this is important in order to keep the memory stable
    }
  count++;//increment once it has been completed
}

/******************************************************************************
This addFront function is somewhat similar with the addRear function, but the only difference is that the front will be receiving an element from any function and will allow the number to be inserted from the front slot.
******************************************************************************/

void DLL::addFront(el_t el)
{
  if(isEmpty())//if there are no nodes inside of the heap memory
    {
      front = rear = new node;//this can be either front or rear since both are pointing at the same node
      rear->elem = el;
      front->prev = front->next = NULL;
    }
  else//if there are nodes inside the heap memory
    {
      front->prev = new node;//this will have the front of previous node since it is addFront and will be set as a new node
      front->prev->elem = el;//this is where the element will be stored
      front->prev->next = front;//this is where the new node of the next slot will be set to the original front
      front->prev->prev = NULL;//prev must be set to NULL since it must have a stopping point
      front = front->prev;//setting the original front to the new front
    }
  count++;//since we are adding, count must go up as well
}

/******************************************************************************
This deleteFront function is a typedef integer type because it allows the element on the front to be found and deleted once the command is called. It would require three conditional statements to access the heap memory whether if there are no nodes, one node, or more nodes. It will be easily accessible and will only focus on the front rather than the rear since the delete will only occur on the front. It is required to return an element in order for it to work since it is not a void function.
count will be used to check on the nodes. 
next will be used to set front to the next once the front will be deleted. 
element is the element that is stored so there would not be any roaming leaking around the heap memory.
******************************************************************************/

el_t DLL::deleteFront()
{
  if(isEmpty())//making sure that there are no values inside of this delete front function
    {
      DLLError("[empty]");
    } 
  else
    {
      el_t element = front->elem;//this is when the element is stored
      if(count == 1 && rear == front && front->next == NULL && front->prev == NULL)
	    {
        delete front;
        rear = front = NULL;
	    }
      else
	    {
        front = front->next;//shift the front to the next node
        delete front->prev;//this is where the front was at previously, so it will be safe to be deleted
        front->prev = NULL;//has to be set to NULL since there will nothing pointed to the deleted node
	    }
      count--;//must decrement since the front is gone
      return element;//the element the front inititally had
    }
}

/******************************************************************************
The deleteRear function will also have the same process as the deleteFront function, but will differ with the position since I am using the rear. The rear in this case will be deleted based on the position rather than the number being specified, so it will delete whatever number is on the rear.
******************************************************************************/

el_t DLL::deleteRear()
{
  if(isEmpty())//if there are no nodes inside of the heap memory
    {
      DLLError("Error: list is empty."); 
    }
 else//deleting nodes inside the heap memory
    {
      el_t old = rear->elem;
      if(count == 1 && front == rear && front->next == NULL && front->prev == NULL)
	    {
	      delete rear;//deletes the rear node since there is only one node
	      front = rear = NULL;//must be set to NULL since there are no more nodes
	    }
      else//more than one node inside the heap memory
      {
        rear = rear->prev;//this will shift the rear to be on the new rear
        delete rear->next;//will delete the original rear
        rear->next = NULL;//will be set to NULL since the node is gone
      }
      count--;//must be decremented
      return old;//return the element that has been deleted
    }
}

/******************************************************************************
This isEmpty function will be a bool function to verify if the heap memory is empty or not. Since it is a bool function, it has to return either true or false and not any other data type. It is important that the if statement reads null for both front are rear to confirm that the heap memory is empty.
******************************************************************************/

bool DLL::isEmpty()
{
  if(front == NULL && rear == NULL)//if the queue is empty
      return true;
  else//if there are extra elements inside the queue
      return false;
}

/******************************************************************************
This displayAll function will be used to output if there are any nodes inside the heap memory. It also allows the user to know if the nodes that have been outputted are correct or not.
isEmpty() will be used to check the heap memory so the user will know that it is empty. 
The other part will be used to set a new node p to front until it hits NULL, which is the stopping point of the heap memory.
******************************************************************************/

void DLL::displayAll()
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

DLL::DLL(const DLL& source)//the source will be the class name variable
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
The deleteNode function will look for the element and verify to see if it is occuring. It will be using a variety of test cases to check for the element inside of the function, whether if it is empty, the element from the front matches with the passed by element, the elemeent from the rear matches with the passed by element, and once the element is searched within the heap memory. For the node to be located around the middle, it is important that the node from the middle set to previous to equal the middle node's next and set the middle node's next to the middle node's previous to prevent any memory leak.
******************************************************************************/

void DLL::deleteNode(el_t e)
{
  node* del;//local variable that will scavange the heap memory, which will start at front
  if(isEmpty())//must be outside the for loop to process
    cout << "Nothing happens" << endl;
  else if(front->elem == e)//the element from front matches with e
    deleteFront();
  else if(rear->elem == e)//the element from the rear matches with e
    deleteRear();
  else//if there are nodes not located from the rear or front
    {
      for(del = front; del != NULL && del->elem != e; del = del->next);
      if(del != NULL)//when it does not reach the end of the heap memory 
      {
        del->prev->next = del->next;//set the first previous' next with the first next
        del->next->prev = del->prev;//set the first next previous with the previous element
        delete del;//delete the node pointed to by del
        count--;//decrement the heap memory
      }
    }
}

/******************************************************************************
The search function is a bool function that returns true if the element matches inside of the heap memory and will return false if there are no matching elements. I will be using a variable for node to be set for front so it will check the next nodes inside the heap memory. I used a while loop to view the whole heap memory and check to see when the element has the same element that is passed.
******************************************************************************/

bool DLL::search(el_t e)
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
The addInOrderAscend function will store an element that is passed and will be processed while the element passed will be checked on ascending order. Ascending order is set up by smallest to largest. It will have four test cases that includes the heap memory not having any nodes inside of the heap memory, which will require to add any function to include inside of the heap memory such as addFront or addRear. The two other cases will have the passed by element to be read when it is greater than or less than the elements from front or rear. Depending on it's position, if the number is higher than the rear element inside the heap memory, it must add the element from the rear and if the element is less than the front element, it will add it on the front. For the last case, that is when the element will be somewhere inside of the heap memory that is not located from the front or rear and will add it into it's respective location. 
******************************************************************************/

void DLL::addInOrderAscend(el_t e)
{
  if(front == NULL && rear == NULL)//if there are no elements inside of the heap memory. IT IS IMPORTANT THAT THERE ARE TWO ASSIGNMENT OPERATORS AND NOT ONE!
      addFront(e);
  else//there are nodes inside of the heap memory
    {
      if(e <= front->elem)//the node is less than the front element
	  addFront(e);
      else if(e >= rear->elem)//if the element is greater than the tail
	  addRear(e);
      else//if the node is inside the range rather than outside the rear/front
      {
        node* newNode = new node;//the node that will be entered within the range
        newNode->elem = e;//the new node element
        node* p = front;//used to locate the node
        node* s;//another local variable
        while(p->next != NULL && p->next->elem < e)//this will verify when the node of the pointed front of the next elem is less than e and when it does not hit null
          {	  	      
            p = p->next;//this is when the pointed front will be set to the pointed next since I am adding the element in between two elements.
          }
        s = p->next;//a shortcut to say p->next
        newNode->next = s;//this is to set the newNode's next into the pointed next to set the address
        newNode->prev = p;//new node's previous will point to the original pointer's next
        s->prev = newNode;//the original pointer's next of its previous
        p->next = newNode;//then the pointed next will be set to the NewNode's address and continues from there
        count++;//increments the heap memory
      }
    }
}

/******************************************************************************
This printAllReverseDLL function will be used to output the elements inside of the heap memory. It will similar with the displayAll function that uses the next node, but the only difference is that it will be using the rear node and continue the process by using the previous node to read from right to left rather than left to right. It will have two test cases that includes when the heap memory is empty or when the heap memory has extra nodes inside. 
******************************************************************************/

void DLL::printAllReverseDLL()
{
  if(isEmpty())
    cout << "[empty]" << endl;
  else
    {
      node* current = rear;
      while(current != NULL)
      {
        cout << current->elem << " ";
        current = current->prev;
      }
    }
}

/******************************************************************************
This is the Linked List error message that outputs a statement that is used in the other functions, which has a message as parameter to enter any string. It will have an exit 1, which is from the cstdlib library, that allows the program to stop.
******************************************************************************/

void DLL::DLLError(string msg)
{
  cout << msg << endl;
  exit(1);
}
