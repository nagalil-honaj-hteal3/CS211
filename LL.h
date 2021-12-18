#ifndef LL_H
#define LL_H
#include <string>
using namespace std;

typedef string el_t; //element for the struct node

struct node {
  el_t elem;//element at this node is an integer 
  node* next; //a link (pointer) to the next node
};

class LL
{ 
 private:
  node* front;
  node* rear;
  int count;
  void LLError(string msg);

 public:
  LL();//constructor
  ~LL();//destructor
  void addFront(el_t el);
  void addRear(el_t el);
  el_t deleteFront();
  el_t deleteRear();
  bool isEmpty();
  void displayAll();
  LL(const LL& source);
  //void createLL(const string& s);
  void deleteNode(el_t e);
  bool search(el_t e);
  void addInOrderAscend(el_t e);
};
#endif
