#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;


template <class T>
class Node
{
 public:
   T elem;
   Node<T>* right;
   Node<T>* left;
   Node(T e){elem = e; right = NULL; left = NULL;}
};


template <class T>
class BST
{
private:
  Node<T>* root;
  void insertNode(Node<T>*&, T);
public:
  BST();
  void insertNode(T);
  bool search(T);
};


template <class T>
BST<T>::BST()
{
  root = NULL;
}

template <class T>
void BST<T>::insertNode(T e)
{

  insertNode(root, e);
}


template <class T>
void BST<T>::insertNode(Node<T>*& p, T e)
{
  if(p == NULL)
    p = new Node<T>(e);
  else if(e < p->elem)
    return insertNode(p->left, e);
  else // e > p->elem
    return insertNode(p->right, e);
}

template <class T>
bool BST<T>::search(T e)
{

}


#endif
