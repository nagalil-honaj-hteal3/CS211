//The idea of the bubble sort is the following.
  //In the first iteration, the largest value bubbles up to the last slot.
  //In the second iteration, the second largest value bubbles up to the second to last slot.
  //In the third iteration, the third largest value bubbles up to the third to last.

//The Pseudocode (the most primitive and also the most inefficient way) would be
  //For (each slot of the array)
    //For( each adjacent pair of items)
      //If(the pair of items are out of order)
        //Swap the pair of items

//Here is the pseudocode for the better bubble sort algorithm shown above (we will make it even better below)
/*while ( array is not fully sorted because swapping was required )
  {
  for ( each adjacent pair of items )
    {
      if ( the pair of items are out of order )
            swap the pair of items
    }
  }
*/
#include <iostream>
using namespace std;
void bubbleSort(int ar[], int s)//where ar is the array from the sort, s is the size
{
  bool done = false;//set to false if there was swapping -- or has not been swapped
  int last = s - 2;//check the adjacent pair of items in the unsorted part
  while(!done)//array is not fully sorted <- checks if its done
  {
    for(int i = 0; i <= last; i++)//check each adjacent pair of items in the unsorted part
    {
      if(ar[i] < ar[i + 1])//the pair of items are out of order
      {
         int temp = ar[i];
         ar[i] = ar[i + 1];
         ar[i + 1] = temp;
         return false;//swap is required; checks to see into the next iteration
      }
    }
    last--;//shrinks the iteration down from the list of items in the array
  }
}
