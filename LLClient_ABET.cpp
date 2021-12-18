/******************************************************************************
Purpose: To design, implement, and thoroughly test the addInOrderAscend function and check all possible cases while using my linked list class.
******************************************************************************/
#include <iostream>
#include <string>
#include "checkInput.h"
#include "LL.h"
using namespace std;

void progressRun(LL l, int n, int r, string nm, int c);

int main()
{
  LL l;//this is used in order to access the linked list function such as display all and addInOrderAscend
  string name;//this is used to enter the name of the user
  int num, counter, run = 0;//num is the integers the user enters, counter will set the amount of times the user wants to enter numbers, run will be set as the amount of times the user enters in the integer
  char elem;//the return type of the yes or no choice
  cout << "****************************************\nWelcome to my program! Lets get started by getting your name!\nEnter your name: ";
  getline(cin, name);

  do//cycle for the user to enter the numbers
    {
      progressRun(l, num, run, name, counter);
      cout << "\n\nWould you care to continue " << name << "?\nEnter yes (Y or y) or no (N or n)" << endl;
      elem = getYN("Friend, I cannot believe that you do not follow my directions! Enter again: ");
    }while(elem == 'Y');//this is if the user would want to continue to add numbers

  cout << "Thank you for playing " << name << endl;
  return 0;
}

/******************************************************************************
The progressRun function will be used to gather the elements and use for the addInOrderAscending function. I will be using five parameters. The l parameter will be used from the linked list class in order for it to access the addInOrderAscending and displayAll functions. The n parameter is the passed value from the main for the integer the user entered. The r parameter is the run to keep count for the amount of times the user will be entering the integers. The nm parameter will be the string of the user's name. The c parameter is the number the user entered for the amount of times the user wants to run the program.
******************************************************************************/

void progressRun(LL l, int n, int r, string nm, int c)
{
  cout << "\nMy friend " << nm << ", how many times do you like to run this program?\nEnter a number: ";
  cin >> c;
  cout << "\nHello " << nm << ", lets get started shall we!" << endl << endl << "----------------------------------------------------------" << endl << endl;
  do
    {
      cout << "Enter an integer you can think of: ";
      cin >> n;
      if(n == 18)//this is my age in real life for fun fact
	    {
	  l.addInOrderAscend(n);
	  cout << "That number is my age! Great choice!" << endl;
	    }
      else if(n < 0)//I despise negative numbers, so I added a comment for the users
	    {
	  l.addInOrderAscend(n);
	  cout << "Fan of negative numbers? That is very interesting " << nm << endl;
	    }
      else//continues to add numbers
	      l.addInOrderAscend(n);
      r++;//the set of times the integer has been completed to be added in the process
      }while(r < c);//everytime the run is not greater than or equal to the counter the user entered.

  cout << "\n**********************************************************\n\nHere are the numbers you have entered and will be set to ascending order as shown below" << endl << endl;
  l.displayAll();//the elements that are entered and displayed for the user to view
}
