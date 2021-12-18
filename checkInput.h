/****************************************************************************
This header was written by Kazumi Slott
CS211
1-30-2020
****************************************************************************/
#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include <iostream>
using namespace std;

/******************************************************************************                                                               
min is the minimum value accepted                                                                                                             
max is the maxmum value accepted                                                                                                               
msg is the message shown when the user's input was outside the range.                                                                          
                                                                                                                                              
This function will read data and keeps asking to enter new data                                                               
as long as the user enters data outside the range. It will return data                                                                 
within the range (between min and max inclusive).                                                                                              
*******************************************************************************/
template <class T>
//template <typename T> //This works too
T getData(T min, T max, string msg)
{
  T n; //user's input                                                                                                                        
  cin >> n;

  while(n < min || n > max) // the user's input was outside the range                                                                          
    {
      cout << msg;  //show the message to the user                                                                                             
      cin >> n;     //read a new input                                                                                                         
    }

  return n; //return a good value that is within the range (between min and max enclusive)                                                    
}

/*******************************************************************
msg is the error message to be shown when a user enters an invalid character(
any character other than Y, y, N or n).

This function will ask the user to enter Y, y, N or N. It will keep asking
as long as the user enters a character other than Y, y, N or n.
It will return Y or N.
*******************************************************************/  
char getYN(string msg)
{
  char ans;
  cin >> ans;

  //An invalid character was entered
  while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
    {
      cout << msg;
      cin >> ans;
    }

  //convert the character to uppercase
  if(ans == 'y' || ans == 'n')
    ans -= 'y' - 'Y'; //subtract 32 from lowercase to get uppercase                                                                            
  return ans;
}

#endif
