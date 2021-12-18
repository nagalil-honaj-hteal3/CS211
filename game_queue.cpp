#include "queue.h" 
#include <cstdlib>
#include <iostream>
using namespace std;

Queue::Queue()//default constructor
{
  count = 0;
  front = 0;
  rear = -1;
}

bool Queue::isEmpty()
{
  if(count == 0)
    return true;//if the queue is empty
  else
    return false;//if it is not empty
}

bool Queue::isFull()
{
  if(count == QUEUE_SIZE)//Change the isFull function
    return true;//if the queue is full
  else 
    return false;//if there are any space remaining
}

void Queue::add(el_t e)
{
  if(!isFull())
    {
      rear = (rear + 1) % QUEUE_SIZE;//shifts the rear to the next slot
      count++;
      el[rear] = e;//enters what the next slot is
    }
  else 
    queueError("Queue Overflow");//this will occur once the queue is full
}

el_t Queue::remove()
{
  if(!isEmpty())
    {
      el_t old;//grab the original front element of the queue
      old = el[front];//use this to return the value once it goes on the next front element
      front = (front + 1) % QUEUE_SIZE;
      count--; 
      return old;//remove(return) the front element and change front to the next slot
    }
  else
    queueError("Queue Underflow");//this will occur once the queue is empty
}

el_t Queue::getFront()
{
  if(!isEmpty())//remove(return) the front element, but does not remove it
    {
      return el[front];//the front element inside the array
    }
  else
    queueError("Front cannot be found.");
}


void Queue::goToBack()//use both remove() and add()
{
  if(isEmpty())
    {
    queueError("The queue is empty.");
    }
  else 
    {//remove adds on the front, Add adds on the rear
      el_t old2 = remove();//Get the original char that was deleted from the function
      add(old2);//Used to do the wrap and around
      //Add();
      //count = 1;
    }
}

int Queue::getSize()
{
  cout << "\nYou currently have " << count << " elements inside the queue." << endl;
  return count;
}

/******************************************************************************
This ostream function will have an operator << to output the following numbers inside the function. ex will be used as the struct used in queue.h. I learned that you cannot put const struct& because it is a compilation error that will confuse the computer so removing the struct& with the struct name expr& lets the queue class program run. This function would have to be above the displayAll() function because it is an overloading function.
******************************************************************************/
ostream& operator<<(ostream& out, const expr& ex)//I named it out since it was directed inside of the instructions. const has to be placed because the struct expr would not change and would be reused from the struct inside the queue class
{
  out << ex.oprd1 << " " << ex.oprt << " " << ex.oprd2;//Show 5 + 8
  return out;//moves it into the displayAll()
}

/******************************************************************************
This displayAll function is used to output the following. I would also use this to know when it is necessary to execute the output statements such as the operator from ostream and from the other functions that uses the queue.

el[n]: the queue array that reads where the index is located 
******************************************************************************/

void Queue::displayAll()
{
  if(isEmpty())//this is if the queue is empty, so in case there has not been anything added inside the queue, then it will output this.
    {
      queueError("The queue is empty.");
    }
  else if(front <= rear)//this is if the front is less than or equal to the rear 
    {
      for(int n = front; n <= rear; n++)//this it to make sure that the front would be have a less or equivalent value to rear and would output what the queue is.
	    {
	  cout << "[" << el[n] << "] ";
	    }
      cout << endl;
    }
  else//this is for extra functions that can be used to display the functions
    {
      for(int n = front; n < QUEUE_SIZE; n++)//this for loop is whether the front element is less than the queue size to 
	    {
	  cout << "[" << el[n] << "] ";
	    }
      for(int n = 0; n <= rear; n++)//this for loop is to increase the rear until it fills up the queue
	    {
	  cout << "[" << el[n] << "] ";
	    }
      cout << endl;
    }
}
void Queue::queueError(string msg)
{
  cout << msg << endl;
  //exit(1);
}
