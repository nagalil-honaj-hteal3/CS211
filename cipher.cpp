/******************************************************************************
Name: Elaeth Lilagan
Cipher.cpp
3-29-2021

The purpose of this program is to make an application using myVector class, which is located in my header file (myVector.h), and to make sure that it runs properly with the cipher.cpp
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "myVector.h"
#include "/cs/slott/cs211/checkInput.h"
using namespace std;

//prototypes
template <class T>
void cipher(myVector<T> & c);
template <class T>
void print(myVector<T>& v);
bool isLetterDigit(char ch);
char myToLower(char ch);
bool isDigit(char ch);

int main()
{
  ifstream fin;//input for the file
  //ofstream fout;//output for the file
  string filename;

  cout << "Enter the file name: ";
  cin >> filename;

  fin.open(&filename[0]);// -> this will allow to open any files for input that have been inside of my directory, it also allows me to open up fin.open to not look at just one .txt file i.e. fin.open("cipher1.txt"), but having filename to be set as in input for the user, it can detect the other files. It must need pass by reference to work because without it, it will not compile. Also with the array 0, it is just to keep it on the start
  //fin.open("cipher2.txt");

  if(!fin)
    {
      cout << "File cannot be recognized. Try entering again!" << endl;
    }
  else
    {
      //int number;
      myVector<string> v; //this will be used for my string and called it v
      myVector<char> c; //this will be used for my character and called it c
      string sentence; //this is to make sure that the sentence can be read inside the file
      //fout.open("cipherOut.dat");

      getline(fin, sentence);//it can only work with getline and not with cin because it has extra spaces inside of my examples for the txt files
      v.push_back(sentence);//would be pushed back inside of my vector class and check the sentence by copying itself
      
      cout << "---- sentence ----" << endl;
      print(v);

      cout << "---- after removing non-letter/digit ----" << endl;
      for(int i = 0; i < sentence.size(); i++)//all characters in a sentence, reads the sentence one character at a time
	  if(isLetterDigit(sentence[i]))//reads the sentence
	      c.push_back(sentence[i]);//vector of characters
      
      print(c);


      cout << "---- after converting to lower case ----" << endl;
      for(int i = 0; i < c.size(); i++)//all characters in a sentence, reads the sentence one character at a time
	c[i] = myToLower(c[i]);//this will check the letters for it to become lower case

      print(c);

      cout << "Enter a secret number to cipher a sentence between 1 and 26: ";
      //number = getData(1, 26, "Out of range");
      cipher(c);//I am unsure why my cipher function does not compile the way it is suppose to compile
      cout << "\n---- after inserting a space after every 5 characters ----\n";
      c.insert(0, 5);//I am unsure how to implement the code for having five characters combines to together and be separated by a space
      print(c);

      return 0;
    }
}

/*****************************************************************************
This bool isLetterDigit function verifies/detects the characters inside the setence. I assigned the character name to ch to have the if statement for it to compile, so once I have the ch, it will read the letters and digits within the range and set it to true to let my print function easy to compile. 

ch = will be used in the main function 
Must be bool because it will determine the character to be true or false
 *****************************************************************************/

bool isLetterDigit(char ch)
{
  if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))//verifying the letter/digit
    return true;//if it is a letter or digit, returns true
  else
    return false;//not a letter or digit
}

/*****************************************************************************
This isDigit function checks for the number from the range 0 to 9 which will also have the same compile as the isLetterDigit, but without the letters since it will only check for the number. It will be only single digit numbers in this case and would not be extended for more than number 9.

ch = the character from the main function 
Would be a bool function because it will verify the digit
*****************************************************************************/

bool isDigit(char ch)
{
  if (ch >= '0' && ch <= '9')//verifying the digit from 0 to 9
    return true;
  else //if it is less then zero and greater than 9
    return false; 
}

/*****************************************************************************
This myToLower function views each letter that has been on the sentence and makes sure that each capital letter becomes lower case. It will verify each character at a time on the sentence.

ch = the character from the main function
It would return the ch once it finishes the process
*****************************************************************************/

char myToLower(char ch)
{
  if(ch >= 'A' && ch <= 'Z')//this is when ch is in the range for capital letters
    ch = ch + ('a' - 'A');//since the ascii letters have diffeent values, lower cas letters are higher than uppercase letters it would be subtracted with lowercase letter to uppercase letter to get the character value then add it with the other character to return the lowercase character
    
  return ch;//returns the new value
}

/*****************************************************************************
This cipher function will be a void function because it will be simpler for me to shift the characters. I set my parameter to become a vector class of c because it is used as my character on my main function and would be used to access similar to a struct or class to access my size function inside of my vector class. 

shift = input for how many numbers the character would shift
a = character that will be viewed inside of the size function or looks at each character
newChar = the new character after it has been shifted and would have modulo
newC = once the character in the sentence is added with the shift
*****************************************************************************/

template <class T>
void cipher(myVector<T>& c)
{
  int shift = getData(1, 26, "Number entered is not in range. ");//used the getData dunction to get the shift from range 1 to 26
  for(int i = 0; i < c.size(); i++)//this checks one character at a time with the sentence
    {
      char a = c[i];//the character
      char newChar;
      int newC = a + shift;
      if(newC > 127)//if the character is over the ascii value
	newChar = (char)(newC % 128);//this is to convert the value if it is over 127 and would wrap around while in the process
      else //if it is in the range
	    {
	  //isDigit(a);
	  //a = (char)(newC % 10);
	  newChar = (char)(newC); //newChar would just be newC since it is in the range
	    }
      /*char a = c[i];
      if(isDigit(a))
	      a = a + num % 10;//
      else
	      a = a + num;//this is until it reaches 128 then cycles again
      */
    }
}

/*****************************************************************************
This print function would output the sentence. It would have the myVector v because it will output a sentence rather than c because it is a character. 
*****************************************************************************/
template <class T>
void print(myVector<T>& v)
{
  for(int i = 0; i < v.size(); i++)//this is to view the sentence one at a time and output the result
    cout << v[i];
  cout << endl << endl << endl;
}

