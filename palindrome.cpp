/******************************************************************************
palindrome.cpp
Purpose: Implement an application that will use my linked list class and check to see if the string is a palindrome, which is a word, phrase, number, or other sequemce of characters (@, #, $, %, ^, &, *) that reads the same backward or forwards, i.e. racecar
******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "LL.h"
using namespace std;

bool isLetter(char ch);
char myToLower(char ch);
void createLL(LL& l, string sen);
bool palindrome(LL& l, string sen);

int main() 
{
  ifstream fin;//input of my file  
  fin.open("palindrome.dat");//the data file that holds the inputs for running this program

  if(!fin)//if the file does not exist or cannot be accessed in this program
      {
	cout << "Whoops! You must not have the right file, try again." << endl;
      }
  else//if the file exists
      {
	LL l;//my linked list variable to access my header file
	string s;//the length of the string
  //cout << "Enter a sentence: ";
	    while(!fin.eof())//this is until the file reaches the end
	      {
	      getline(fin, s);//this will grab the whole string rather than a character
	      createLL(l, s);//to have a new sentence
	      if(palindrome(l, s) == true)//to get the return type for having the palindrome be valid
	        cout << s << " is a palindrome." << endl;
	      else//if it is not a palindrome
	        cout << s << " is not a palindrome." << endl;
        }  
      }
  fin.close();//to close the file
}

/******************************************************************************
This createLL function will construct a linked list from the string minus punctuations and spaces to allow the sentence to verify the characters to be palindromes. I inserted two parameters because I will be using the addFront function that will insert the element of the character that will be checked with the isLetter function. Next it will use the myToLower function to make the character lower case if there are any upper case letters, then would be passed with the addFront function to create the new sentence.
******************************************************************************/

void createLL(LL& l, string sen)
{
  for(int i = 0; i < sen.length(); i++)//this for loop will read the whole string 
    {
      if(isLetter(sen[i]))//the character from the string and will be passed to verify the character to be a string
      {	
	char newC = myToLower(sen[i]);//set a new variable for the lower case letter
	l.addFront(newC);//the addFront function inside of my linked list class to create the new sentence and also I am required to use the addFront function
      }
      //cout << "Hello" << endl;
    }
}

/******************************************************************************
This palindrome function will be a bool function because it will return true or false for when the sentence is a palindrome or not. I set two char variables to be front and rear to store the returned variables from the deleteFront and deleteRear functions to compare both of the characters in order for it to compile. If the two variables that I set equal to do not match, then the function will return false and will output that the sentence is not a palindrome.
******************************************************************************/

bool palindrome(LL& l, string sen)//it would be important to have the linked list class to set the functions from my header file and the string sen to access the length of the string
{ 
  char front, rear;//the char variables
  for(int i = 0; i < (sen.length() / 2); i++)//it would be divided by two since I will be using the two charcters to verify the match
    //while(!l.isEmpty()) 
    {
      front = l.deleteFront();
      if(l.isEmpty())//the middle character
	  return true;
      rear = l.deleteRear();
      if(front == rear)//comparing the elements that have been deleted
	      {
	  //cout << i << endl;
	      }
      else//if the character does not match each other
	      {
	  return false;
	      }
    }
  return true;//once the for loop is complete and it has been fully verified that it is a plaindrome.
}

/******************************************************************************
This isLetter function will collect a character that will check if it is a letter or not, so since it is a bool function, if the character that does not fit the range inside the if statement, it will not be returned, but if it is in the range, then it will be easy access for the sentence to compile.
******************************************************************************/

bool isLetter(char ch)
{
  if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))//if it is a letter
    return true;
  else//if it is a number, symbol, or punctuation
    return false;
}

/******************************************************************************
This myToLower function will be a char function that will return the value of what is going to be a lower case letter if the letter that is passed is an uppercase letter. In order to have the upper case value to become a lower case value, it is important to get the value of the lower case subtracted by uppercase since lower case letters have higher ascii value than the upper case letter.
******************************************************************************/

char myToLower(char ch)
{
  if(ch >= 'A' && ch <= 'Z')//if the letter is an upper case
    ch = ch + ('a' - 'A');//add the uppercase letter with the subtracted value of the lower case minus the upper case
  return ch;
}

