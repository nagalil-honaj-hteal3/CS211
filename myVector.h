#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;

template <class T>
class myVector
{
  private: 
    T* ar;//pointer to an array
    int num;//the number of elements in hte array pointed to by ar

  public: 
    myVector();//default constructor
    ~myVector();
    void push_back(const T& e);
    int size() const;//return the number of elements
    T& operator[](int index);//return the element at the specified index so we can do cout << vecObj[i]
    void erase(int index);
    void insert(int index, const T& e);//new element, e, will sit at index
    //T operator[](int index);
    //void print(myVector<T>& v);
};

/******************************************************************************
ar is the array from my private class, which is a pointer with any data type
num is the number of elements that will be stored inside of my array
This function will allow my private members to be used while doing my program or in other terms, there will be easy access
******************************************************************************/

template <class T>//always necessary especially using the template class T
myVector<T>::myVector()//use T even if you are not using T in this function
{
  //initialize ar and num
  ar = NULL;//ar must be set to NULL since it is a pointer
  num = 0;//num must be set to 0 since there are no elements declared at the moment
}

/******************************************************************************
The destructor will be used to delete the array in the heap memory to prevent any memory leaks or dangling pointers to occur or in other terms, no other leaking memory roaming around the program while it is being executed
******************************************************************************/

template <class T>
myVector<T>::~myVector()//destructor 
{//The destructor is called automatically when an object of the class goes out of the scope and cannot be called by the programmer. Do not forget to delete the array in heap.
  if(ar != NULL)
    delete [] ar; //if ar points to an array, delete it
}

/******************************************************************************
array = an extra or new array that will have an extra element 
This push_back function will be a similar function to insert but the only difference is to add an additional element inside of an array i.e. array originally had 3 slots, with the new array, you can choose how many slots, so in this case if it is adding one more slot, do the num added with one and you would have the additional slot inside the array
******************************************************************************/

template <class T>
void myVector<T>::push_back(const T& e)//const and pass by reference is require to prevent e to become a large value
{
  //adds a new element at the end. Reminder: Before you delete an array, you should make sure the pointer is not NULL. If the pointer is NULL, it doesn't point to an array.
  //if(ar == NULL)
  //{
      T* array = new T[num + 1];
      for(int i = 0; i < num; i++)//num is the size of array 
	{
	  *(array + i) = *(ar + i);//left hand side, a new array with an additional element, right hand side, the original array that will be copied
	}
      *(array + num) = e;//e will be the value to have all the copied elements inside including the array
      if(ar != NULL)
	{
	  delete []ar;//must be deleted to prevent any memory leaks 
	}
      ar = array;
      num++;
      //}
}

/******************************************************************************
num = the number inside of the array
This function will record the nnumber of elements inside of my array and can be used with many more functions to come. It will return the num in this case since it will not require anything else to record the numbers inside the array
******************************************************************************/

template <class T>
int myVector<T>::size() const//the size function requires template class T
{
  return num;
}

/******************************************************************************
index = the passed by value that will be entered with an integer
num = the index inside the array
This operator overloading function with [] will be used to for the array in respect with the index in order to get the function to work or in other terms the index of where it will be located.
******************************************************************************/

template <class T>
T& myVector<T>::operator[](int index) //& right value you can change, no & is lvalue cannot change
{
  if(index < num) //if the index has less value than the numbers of elements inside the array
    return *(ar + index);//pointer array will be added with the index
  else
    throw "invalid index"; 
  // return ar[index]; the index of the array
}
/*
template <class T>
T myVector<T>::operator[](int index)
{
  return *(ar + index);
}
*/

/******************************************************************************
index = the passed by value which will be an integer in this case
The erase function will be used to take out the index inside of the array with the corresponding value i.e. if the array has 5 slots, with the passed by value of 4, the array will take out the last index and will proceed to continue once the index has been deleted
******************************************************************************/

template <class T>
void myVector<T>::erase(int index)
{
  if(index > (num - 1)) //since the index will be read, it has to have num - 1 since num is set to zero and the index has a higher value.
    cout << "Index is invalid" << endl;
  else //if the index is less than the num
    {
      T* ar2 = new T[num];//new array with num value 
      for(int i = 0; i < index; i++)//will read the array from left to right  
	{
	  *(ar2 + i) = *(ar + i);//left hand side, a new array with an additional element, right hand side, the original array that will be copied
	}
      for(int i = index; i < (num + 1); i++)//will read the index and would do the process opposite to the if statement
	{
	  *(ar2 + i) = *(ar + (i + 1));//left hand side, a new array with an additional element, right hand side, adds the index by one within the array
	} 
      if(ar != NULL) //since I had set ar to NULL, if the ar is not similar to NULL, it is important to delete the ar to prevent any linker errors
	{
	  delete []ar;//deletes the original array 
	  ar = ar2;
	  num--;//size of the vector decreases
	}
    }  
}

/******************************************************************************
index = the passed by value which will be an integer inside the array
e = the value that will be passed inside the index
This function will be used to insert the value inside the array with an additional index. It will be similar with the erase function, but the difference in this case would be the number of indexes inside of the array to rather than having num - 1 since it will not be deleted.  
******************************************************************************/

template <class T>
void myVector<T>::insert(int index, const T& e)//new element, e, will sit at index
{
  if(index > num)//if index is greater than the limit
    {
      cout << "Index is invalid." << endl;
    }
  else //if the index is less than num
    {
      T* ar2 = new T[num + 1];//where num creates another index
      for(int i = 0; i < num; i++)
	{
	  *(ar2 + i) = *(ar + i);//increases
	}
      num++; //increments since I added the num of index inside the array
      T temp1 = *(ar2 + index);//move out the temp to find 
      for(int i = index; i < num; i++)//this will be used to copy the old array into a new array 
	{
	  T temp2 = *(ar2 + (i + 1));//this will be a second temp value to store
          *(ar2 + (i + 1)) = temp1; //this is temp2 to make the temp1 to equal temp2
	  temp1 = temp2;//this temp1 will be temp2
	  //cout << *(ar2 + (i + 1));
	} 
      *(ar2 + index) = e; //<- error 
      if(ar != NULL)
	{
	  delete []ar;//prevent any memory leak
	  ar = ar2;//temporary value
	}
    }
}
/*
template <class T>
void print(myVector<T>& v)//this outputs the following
{
  for(int i = 0; i < v.size(); i++)
    {
      cout << "[" << v.ar[i] << "]";
    }
  cout << endl;
  }
//template <class T>

int main() 
{
  myVector<int> v;//use any data type
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.print(v);
  v.erase(1);
  v.erase(2);
  //test myVector functions
  //Call push_back() multiple times
  //Call print() to show all the elements in the vector
  return 0;
}

template <class T>
void print(myVector<T>& v)//this outputs the following
{
  for(int i = 0; i < v.size(); i++)
    cout << "[" << v.ar[i] << "]";
  cout << endl;
  }*/
#endif
