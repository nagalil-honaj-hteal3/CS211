#ifndef UTILITY_H
#define UTILITY_H
#include <string>
using namespace std;

/******************************************************************************
This isLetter function will collect a character that will check if it is a letter or not, so since it is a bool function, if the character that does not fit the range inside the if statement, it will not be saved, but if it is in the range, then it will be easy access for the sentence to compile.
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
  if(ch >= 'A' && ch <= 'Z')
    ch = ch + ('a' - 'A');
  return ch;
}

/******************************************************************************
The stripStr string function will store a string that holds a variety of strings to compile. It will require a for loop to get the length of the string being passed to verify any characters from the string if it is a letter or not. With the function isLetter(char), it allows the character in the string to be returned when it is verified of becoming a letter. After that it will have the lowercase function myToLower which will be passed if the character is a capital letter it will be converted into a lower case letter and proceed the process and returns the string w with the whole re edit of the string.
******************************************************************************/

string stripStr(string wd)
{
  string w;
  for(int i = 0; i < wd.length(); i++)//go through each character in wd
    {
      if(isLetter(wd[i]))//the character is a letter
	      w += myToLower(wd[i]);//lowercase letter
    }
  return w;
}

/******************************************************************************
This toMyUpper function will be a char function that will return the value of an uppercase letter that was formerly a lowercase letter. In order to have the lower case value to become an upper case value, it is important that the value of the upper case and lower case letter subtract each other to get the value of the new character and after the character gets created, it will be returned with an upper case letter.
******************************************************************************/

char toMyUpper(char ch)
{
  if(ch >= 'a' && ch <= 'z')
    ch = ch - ('a' - 'A');
  return ch;
}

#endif
