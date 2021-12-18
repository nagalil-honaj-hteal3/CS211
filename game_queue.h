#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

/******************************************************************************
Place the following code in queue.h
******************************************************************************/
//create an enumerate type
enum op {ADD, SUB, MULT, DIVI};

//create a struct that will have an operand, a operator, another operand 
struct expr
{
  int oprd1;//operand 1
  op oprt;//operation
  int oprd2;//operand 2
};

typedef expr el_t;//data type of the queue, in this case it is struct because it represents the question of what would be outputted for the user to enter.
const int QUEUE_SIZE = 10;//for the game.cpp program

class Queue
{
 private:
  el_t el[QUEUE_SIZE];//an array called el. Used as a char array
  int count;//the number of elements it contains
  int front;//front element of the queue
  int rear;//rear element of the queue
  void queueError(string msg);

  //friend ostream& Queue::operator<<(ostream& out, const struct expr);

 public:
  Queue();//default constructor
  bool isEmpty();
  bool isFull();
  void add(el_t e);
  el_t remove();
  el_t getFront();//if empty, calls emergency exit
  void goToBack();//Hint: use remove() and add()
  int getSize();
  void displayAll();

};

#endif
