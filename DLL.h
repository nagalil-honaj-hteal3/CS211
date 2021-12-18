#ifndef DLL_H
#define DLL_H
#include <string>
using namespace std;

typedef int el_t; //element for the struct node

struct node {
  el_t elem;//element at this node is an integer 
  node* next; //a link (pointer) to the next node
  node* prev;
};

class DLL
{ 
 private:
  node* front;
  node* rear;
  int count;
  void DLLError(string msg);

 public:
  DLL();//constructor
  ~DLL();//destructor
  void addFront(el_t el);
  void addRear(el_t el);
  el_t deleteFront();
  el_t deleteRear();
  bool isEmpty();
  void displayAll();
  DLL(const DLL& source);
  //void createLL(const string& s);
  void deleteNode(el_t e);
  bool search(el_t e);
  void addInOrderAscend(el_t e);
  void printAllReverseDLL();
};
#endif
