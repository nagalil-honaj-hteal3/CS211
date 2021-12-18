#ifndef LQUEUE_H
#define LQUEUE_H
#include <string>
using namespace std;

typedef int el_t; //element for the struct node

struct node {
  el_t elem;//element at this node is an integer 
  node* next; //a link (pointer) to the next node
};

class LQueue
{ 
 private:
  node* front;
  node* rear;
  int count;
  void queueError(string msg);
  void printAllReverse(node* p);

 public:
  LQueue();//constructor
  ~LQueue();//destructor
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  void createReverseLL(LQueue l, const string& s);
  void addLLs(LQueue l1, LQueue l2, LQueue total);
  void printAllReverse();
};
#endif
