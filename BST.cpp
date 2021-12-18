#include <iostream>
#include <cstdlib> //for rand()
#include <fstream>
//#include "LL.h"//linked list class
using namespace std;

typedef int el_t;

class Node
{
  friend class BST;//to access the private members of Node. BST can access the private members of Node
private:
  el_t elem;//element of the node
  Node* left;//the left branch of the binary tree
  Node* right;//the right branch of the binary tree
public:
  Node(el_t e){elem = e; right = NULL; left = NULL;}; //implement the constructor inside the class definition
};

class BST
{
private:
  Node* root;//root points to the root (top) oc the tree.
  void insertNode(Node*&, el_t);//this is used once the other insertNode function has been called when starting at root
  void destroy(Node* p);
  void inOrderPrint(Node* p);
  void preOrderPrint(Node* p);
  void postOrderPrint(Node* p);
  void inOrderPrintReverse(Node* p);
  void preOrderPrintReverse(Node* p);
  void postOrderPrintReverse(Node* p);
  int getNumNodes(Node* p);
  bool searchRec(Node* p, el_t e);
  int getMaxLength(Node* p);
  int getNumNodesBetween(Node* p, el_t min, el_t max);
  void printNodesBetween(Node* p, el_t min, el_t max);
public:
  BST();//constructor
  ~BST();//destructor
  void insertNode(el_t e);//inserting an element into a tree
  bool search(el_t e);
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  void inOrderPrintReverse();
  void preOrderPrintReverse();
  void postOrderPrintReverse();
  int getNumNodes();
  bool searchRec(el_t e);
  int getMaxLength();
  int getNumNodesBetween(el_t min, el_t max);
  void printNodesBetween(el_t min, el_t max);
};

/******************************************************************************
This is the constructor where it holds the value for the binary search tree. Since it does not have the values for left and right, it has been stated on the public function of Node(el_t e)
root = NULL since it is the start of what the tree will have
******************************************************************************/

BST::BST()
{
  root = NULL;//the tree is empty
}

/******************************************************************************
This is the destructor where it has the value of which node will be deleted. It has a destroy function where it will grab the root of the tree and pass it into the function to see what will be deleted as will be discussed about after this function.
******************************************************************************/

BST::~BST()
{
  destroy(root);//function that will be used for the tree
}

/******************************************************************************
This destroy function will grab a node, mostly used for the destructor, to delete the following branches of the tree. It will have a recursive function to read the following from visiting both the branches and finally the node being passed, or in other terms, the left child will be visited first, then the right child, and after that it will go to the parent and will be deleted. 
******************************************************************************/

void BST::destroy(Node* p)//recursive function
{
  if(p == NULL)//once there are no more nodes inside of the tree
      return;
  destroy(p->left);//eliminates the left side of the tree
  destroy(p->right);//eliminates the right side of the tree
  //cout << p->elem << "-->";
  delete p;//must be deleted once the destructor has been called
}

/******************************************************************************
The orderPrint function will also be used to get the parameter of the node root and will be transferred for what will be outputted based on the correct order by left to middle to right. 
root = the middle of the binary search tree
******************************************************************************/

void BST::inOrderPrint()
{
  inOrderPrint(root);
}

void BST::inOrderPrintReverse()
{
  inOrderPrintReverse(root);
}
/******************************************************************************
The inOrderPrint function will grab the node of the parent and will be used in order traversal where it will go from left to middle to right. It will also be used as the recursive function and will output the following by its respective position.
******************************************************************************/

void BST::inOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  inOrderPrint(p->left);
  cout << p->elem << "-->";
  inOrderPrint(p->right);
}

void BST::inOrderPrintReverse(Node* p)
{
  if(p == NULL)
    return;
  inOrderPrintReverse(p->right);
  cout << p->elem << "-->";
  inOrderPrintReverse(p->left);
}
/******************************************************************************
The preOrderPrint will be used from the public or client so it will have access to use the private function by using the root node, which is used inside of the private class.
******************************************************************************/

void BST::preOrderPrint()
{
  preOrderPrint(root);
}

void BST::preOrderPrintReverse()
{
  preOrderPrintReverse(root);
}
/******************************************************************************
The preOrderPrint will be used to output elements from a different order compared to the postOrder and inOrder. For example, 7, 5, 9, 8, 6, 4, 10 are inserted into the heap memory, then it will be categorized by root first, left next, and right after. So it will be outputted as 7, 5, 4, 6, 9, 8, 10. p will be used as the root for the binary search tree.
******************************************************************************/

void BST::preOrderPrint(Node* p)
{
  if(p == NULL)//if p points to nothing
    return;
  cout << p->elem << "-->";
  preOrderPrint(p->left);//recursive on the left
  preOrderPrint(p->right);//recursive on the right
}

void BST::preOrderPrintReverse(Node* p)
{
  if(p == NULL)
    return;
  cout << p->elem << "-->";
  preOrderPrintReverse(p->right);
  preOrderPrintReverse(p->left);
}
/******************************************************************************
This is the postOrderPrint function used for the public class so it will be allowed to have access on the private variable of the root in order for it to move around the binary search tree.
******************************************************************************/

void BST::postOrderPrint()
{
  postOrderPrint(root);
}

void BST::postOrderPrintReverse()
{
  postOrderPrintReverse(root);
}
/******************************************************************************
The postOrderPrint function is from the private function that will have the root to output elements that it crosses along the way. For this to output, its order is from going to the left first, right next, and the root last. For example having elements, 7, 5, 9, 6, 8, 4, 10, the order in postOrder will be 4, 6, 5, 8, 10, 9, 7.  
******************************************************************************/

void BST::postOrderPrint(Node* p)
{
  if(p == NULL)//if the pointer is not checking left or right
    return;
  postOrderPrint(p->left);//recusrive on the left
  postOrderPrint(p->right);//recursive on the right
  cout << p->elem << "-->";
}

void BST::postOrderPrintReverse(Node* p)
{
  if(p == NULL)
    return;
  postOrderPrintReverse(p->right);
  postOrderPrintReverse(p->left);
  cout << p->elem << "-->";
}
/******************************************************************************
The getNumNodes function will be used from the public function in order to use the private function of the root node.
******************************************************************************/

int BST::getNumNodes()
{
  return getNumNodes(root);
}

/******************************************************************************
the getNumNodes function will have a return type of the nodes inside of the binary search tree by having it to check the left side, right side and the root by adding it all up together. The number one is the root that is added since it does not have the root recorded as the additional node inside the tree.
******************************************************************************/

int BST::getNumNodes(Node* p)
{
  if(p == NULL)
    return 0;
  else
    return getNumNodes(p->left) + getNumNodes(p->right) + 1;//nodes from the left and from the right, and including one from the root node
}

/******************************************************************************
The getMaxLength function is a public function that will be used in order to get access with the root node by including the same function but in a private class
******************************************************************************/

int BST::getMaxLength()
{
  return getMaxLength(root);
}

/******************************************************************************
The getMaxLength function is a private function that will be used for the root function to check for the greatest length found inside the binary search tree. For this function I created two integer values recursively that checks if the branches from the left is greater than or equal to the right and the branches from the right is greater than the branches from the left. Both will return the branches from its corresponding side and output the length.
******************************************************************************/

int BST::getMaxLength(Node* p)
{
  if(p == NULL)
    return 0;
  else
    {
      int num, num2;
      num = getMaxLength(p->left) + 1;
      num2 = getMaxLength(p->right) + 1;
      if(num >= num2)
	return num;
      if(num2 > num)
	return num2;
    }
}

/******************************************************************************
The search function is a public function that will take a passeed by element from the client, and use it to use the private function including the root. Since the root is a private variable, it must be inside the function and return the value from the private function
******************************************************************************/

bool BST::searchRec(el_t e)
{
  return searchRec(root, e);
}

/******************************************************************************
The search function is a private function that will use the root and passed element from the public function. It will be different from the other search function since it will not use any loops and will use recursion. The recursion will be checking when the element has been checked. It will have cases where the element will be checked in the binary search tree by returning true or false. If the element inside the tree has been found, the element will be returned true and while the element is not found it will continue to check the element based on the direction, so if the element passed is less than the element inside the tree, it will proceed left, but if the element passed is greater than the element in the tree, it will move right
******************************************************************************/

bool BST::searchRec(Node* p, el_t e)
{
  if(p == NULL)//once the tree is fully completed
    return false;
  else
    {
      if(p->elem == e)//if it is a match
	return true;
      else if(e < p->elem)//if the element is less than the element in the tree
	searchRec(p->left, e);//left
      else if(e > p->elem)//if the element is greater than the element in the tree
	searchRec(p->right, e);//right
    }
}

/******************************************************************************
The insert node function is a public functino that will grab the passed by element to pass in for the private function in order to use the root.
******************************************************************************/

void BST::insertNode(el_t e)
{
  insertNode(root, e);//starting at root so we can look for the right place to insert a new element
}

/******************************************************************************
p is a pointer to a Node. We need to use pass by reference for p. When inserting the first element, it becomes the root node. p gets the address of the root node (passed by e element) and it gets stored back in root in the caller (the oublic insertNode()), The same happens when the address of the new node isstored back in p->left or p->right in the caller (insertNode(p->left or p->right , e))
******************************************************************************/

void BST::insertNode(Node*& p, el_t e)//private function
{
  if(p == NULL)
    p = new Node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else // e >= p->elem
    insertNode(p->right, e);
}

/******************************************************************************
The search function will be used to get an element and check for possible cases whether if the element is found and not found. Since this search function is different from the other search function used for recursion, it will be using the node root as a temporary value since it will be shifting from one direction to another and since it will use boolean, it will return true when the element searched is found, and if the element is not found and hits null, it will return false and will end the function. This function will use count to check the amount of nodes that have been searched throughout the tree.
******************************************************************************/

bool BST::search(el_t e)
{
  Node* temp = root;
  int count = 0;
  while(temp != NULL)//while the root does not hit NULL
    {
      count++;
      if(temp->elem == e)
	{
	  cout << count << " nodes checked\nfound" << endl;
	  return true;
	}
      else if(e < temp->elem)//if the passed in element is less than the element of "root"
	temp = temp->left;//shifts left
      else if(temp->elem < e)//if the element of "root" is less than the passed in element
	temp = temp->right;//shifts right
    }
  cout << count << " nodes checked/nNOT found" << endl;
  return false;
}

/******************************************************************************
The getNumNodesBetween function will take in two parameters to check the nodes from the given numbers. Since it will be used to access the root node, it is important that the private function gets called to have the function to return the number of elements inside the binary search tree.
******************************************************************************/

int BST::getNumNodesBetween(el_t min, el_t max)
{
  return getNumNodesBetween(root, min, max);
}

/******************************************************************************
The getNumNodesBetween function will take the parameters from the public function to add up the following values from the range. With the minimum and maximum value being passed inside the function, it will count how many values are greater than the minimum and values that are less than the maximum. It will also have an if statement that declares p pointing to NULL to make sure that if there are no nodes that are from the range, it will only return zero since there is nothing visible inside of the binary search tree.
******************************************************************************/

int BST::getNumNodesBetween(Node* p, el_t min, el_t max)
{
  if(p == NULL)
    return 0;
  else if(p->elem > min && p->elem < max)
    return 1 + getNumNodesBetween(p->left, min, max) + getNumNodesBetween(p->right, min, max);//counts the root and the numbers from the left and right side
  else//node not in the range of min and max
    return getNumNodesBetween(p->left, min, max) + getNumNodesBetween(p->right, min, max);//returns the value not in the range
}

/******************************************************************************
The printNodesBetween function will get the following passed in elements including minimum and maximum to view what will be outputted. Since it is a public function, it will be a used to a private function in order to have access with the root node.
******************************************************************************/

void BST::printNodesBetween(el_t min, el_t max)
{
  cout << "----------------------The number of nodes between " << min << " and " << max << " are -----------------------" << endl;
  printNodesBetween(root, min, max);
}

/******************************************************************************
The printNodesBetween function will be used to output the following values within the ranges of the minimum and maximum values. While it has the following test cases to check the value, similar to the inOrderPrint function to properly fix the following values, it must read from least to greatest to have an organized output and while it must go from left to output to right, it will have the values in order.
******************************************************************************/

void BST::printNodesBetween(Node* p, el_t min, el_t max)
{
  if(p == NULL)
    return;
  printNodesBetween(p->left, min, max);//node traverses the tree from the left
  if(p->elem > min && p->elem < max)//when it is inside the range
    cout << p->elem << "-->";
  printNodesBetween(p->right, min, max);//node traverses the tree from the right
}

int main()
{
  BST b;//class object
  ifstream fin;//used to check the values inside the data file
  fin.open("bst.dat");
  int min, max, value;
  cout << "Enter min: ";
  cin >> min;
  cout << "Enter max: ";
  cin >> max;

  if(!fin)//if the file is not recognized
    cout << "File cannot be recognized" << endl;
  else//if the file is recognized
    {
      fin >> value;//input the values from the file
      while(fin)//inside the file
	{
	  b.insertNode(value);//insert the nodes from the ifstream
	  fin >> value;//continue to check the other values
	}
      cout << "The number of nodes between " << min << " and " << max << " is " << b.getNumNodesBetween(min, max) << endl << endl;//outputs how many nodes inside the following range
      b.printNodesBetween(min, max);//print the nodes that are in the range
      cout << endl;
    }
  fin.close();
  return 0;
}
/*
  srand(time(0)); //you need to include cstdlib
  //LL l;
  int key;

  cout << "What number do you want to search for? ";
  cin >> key;

  for(int i = 0; i < 10000; i++)
    {
      int random = rand() % 10000 + 1;
      b.insertNode(random);
      l.addInOrderAscend(random);
    }

  cout << "BST *************************" << endl << endl;
  b.search(key);

  cout << "\nLL************************" << endl;
  l.search(key);
	
  b.insertNode(5);
  b.insertNode(8);
  b.insertNode(3);
  b.insertNode(9);
  b.insertNode(6);
  b.insertNode(1);

  b.insertNode(0);
  b.insertNode(4);
  b.insertNode(7);
  b.insertNode(20);

  cout << "----- Print all elements using the in-order traversal -----" << endl;
  b.inOrderPrint();
  //cout << "\n\n--- destructor gets called ---" << endl << endl;
  cout << "\n\n----- Print all elements using the pre-order traversal -----" << endl;
  b.preOrderPrint();

  cout << "\n\n----- Print all elements using the post-order traversal -----" << endl;
  b.postOrderPrint();
 
  //cout << "\n\n Output" << endl;
  cout << "\n\nThe total number of nodes inside the binary search tree is " << b.getNumNodes();
  cout << "\nThe maximum length in the binary search tree is " << b.getMaxLength();
  cout << "\n\nSearch for 20: " << b.searchRec(20); 
  cout << "\n\nSearch for 5: " << b.searchRec(5); 
  cout << "\n\nSearch for 9: " << b.searchRec(9); 
  cout << "\n\nSearch for 10: " << b.searchRec(10); 

  cout << "\n\n----- Destructor gets called when b goes out of scope here -----" << endl;
  //b.getMaxLength();
  */
  
