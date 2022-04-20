/******************************************************************************
Elaeth Lilagan
4-19-21

Agenda: The purpose of this program is to use my linked list class to read each character of a word from the given input data files by ascending order and categorize each respective character into a .txt file within the dictionary directory.
******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "LL.h"
#include "utility.h"
using namespace std;

void buildLL(LL& l, ifstream& fin);
void removeBadWords(LL l, ifstream& fin2);
void outputToFile(LL l, ofstream& fout);

int main()
{
  LL l;

  ifstream fin, fin2;
  ofstream fout;

  fin.open("essay.txt");
  fin2.open("bad.txt");

  if(!fin && !fin2)
    {
      cout << "File cannot be recognized" << endl;
    }
  else//if the file exists
    {
      buildLL(l, fin);
      removeBadWords(l, fin2);
      outputToFile(l, fout);
    }

  return 0;
}

/******************************************************************************
The function buildLL will add words from essay.txt into a linked list in ascending order (in alphabetical order) with no duplicates. Since this function requires me to use two parameters including the linked list and ifstream, it makes the string read from the file get transferred to a function called stripStr that will check each character within the string and return a new string that will have all lowercase letters with no spaces and punctuation. I will be using the search function to read each first character of the word and ascend it by the letter from the range 'a' to 'z' so it will organize the letters.
******************************************************************************/

void buildLL(LL& l, ifstream& fin)
{
  string sentence;
  while(fin)//when reading the file input
    {
      fin >> sentence;//from the data file to grab everything inside it
      sentence = stripStr(sentence);//used to grab the string and revamp it to all lower case
      if(!l.search(sentence))//once the letter cannot be searched inside the string
	l.addInOrderAscend(sentence);//the word will be added by its position and will continue from there
    }
}

/******************************************************************************
This removeBadWords function will be used to grab another .txt file to read the bad words and search what is going to be deleted inside of the essay.txt. As the function uses a while loop to check the file, it will use the search function inside of my linked list class and grab that word to delete it inside of the essay.txt file and proceed from there.
******************************************************************************/

void removeBadWords(LL l, ifstream& fin2)
{
  string sentence;
  while(fin2)//the bad.txt file that will be read for this function
    {
      fin2 >> sentence;//the input
      if(l.search(sentence))//searches for the words inside of the bad.txt file
	l.deleteNode(sentence);//deletes the word that matches the words inside of the bad.txt file
    }
}

/******************************************************************************
The outputToFile function will require to use two parameters including the linked list and the ofstream to output .txt files with the word's corresponding first letter. While the letters have already been set to alphabetical order, also known as ascending order, it will be easily read for the fout to process and the letters with the same words, will continue to output the words and once there is a different letter with the original letter, then it will close the .txt files and proceed to add a new set of words with the same first letter. To locate the .txt files, they are all opened up in a dictionary directory and will have the words in alphabetical order once opening up a .txt file.
******************************************************************************/

void outputToFile(LL l, ofstream& fout)
{
  string s = l.deleteRear();//this is to have it in the correct order and if it is deleteFront(), it will read backwards
  string fileName = "./dictionary/?.txt";//means current directory
  fileName[13] = toMyUpper(s[0]);//to get the letter of the word and name it by the capital letter with .txt
  fout.open(fileName.c_str());//opens up the file name
  while(!l.isEmpty())//if the linked list is not empty
    {
      if(toMyUpper(s[0]) != fileName[13])//letter does not match with file 
	{
	  fileName[13] = toMyUpper(s[0]); //index of where question mark is located
	  fout.close();
	  fout.open(fileName.c_str());//opens the character of the word.txt into the dictionary directory under my directory  
	  fout << s << endl;//outputs the words that matches the first letter
	}
      else//if the letter has the same file
	{
	  fout << s << endl;//continues to output the words
	}
      s = l.deleteRear();//shifts to the next word
    }
  fout.close();
  //cout << s << endl;
}
