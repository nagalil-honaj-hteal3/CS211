/*************************************************************************************************************************************************************
Name: Elaeth L.

Description: To create an application using my student class, price class, and array.h
*************************************************************************************************************************************************************/
#include <iostream>//used for input and output
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;//standard
#include "/cs/slott/cs211/checkInput.h"//for other use to check out on the getData/Yes or No
#include "student.h"//To use the student class
#include "price.h"//To use the price class
#include "array.h"//To use whuch arrays to function inside college.cpp
#include <fstream>//use for ifstream especially the addStuFromFile

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

int showMenu();//not sure what this function is used for
int showAdmMenu();//not sure what this function is used for
int showStuMenu();//not sure what this function is used for
void addStu(int c, int sz, int id, Student ar[]);//this function is used to add the students with what the user will input inside this program
void showStuInfo(const Student& s);//to output what the user has inputted
void allStuInfo(const Student& s);//this will show the info of all the students inside the array
bool operator==(const Student& s, int id);//to represent if the id matches with the another id which would be used for delete
void removeStu(Student ar[], int c, int sz);//the remove will read what is inside the array and will be deleted
void addStuFromFile(ifstream& fin);//using the ifstream from college.dat
void addCourse(const Student& s);
void dropCourse(const Student& s);
void makePayment(const Student& s);
/******************************************************************************
In the main function, I put different variable types to access the fstream, iostream, the constant ints, and etc.

fin = input from file
fout = output from file -> I have not used yet
count = start for the array
curID = initial start at 100000
SIZE = 100 entries
ar[SIZE] = to set the array with what is inside size
******************************************************************************/

int main()
{
  ifstream fin;
  fin.open("college.dat");//checking for the data file
  ofstream fout;
  
  int count = 0; //the number of students in the array
  int curID = START; //curID is the student id used for the next student you are creating
  Student ar[SIZE], s;
  do//checks the choices on the menu and verifies what will be used inside of the function 
    {
      cout << showMenu();//outputs the menu for admin, student, or exit
      int choice = showMenu();//the return value of choice
      if(choice == 1)//admin menu
	{
	  int pass;//password
	  cout << "Enter the password" << endl;
	  if(pass == 123)//if it is this password, it will go to the menu of admin
	    {
	      cout << showAdmMenu();//the menu of admin will be displayed
	      int choice2 = showAdmMenu();//the returned value of the menu
	      if(choice2 == 1)//adding a student
		addStu(count, SIZE, curID, ar);
	      else if(choice2 == 2)//adding a student in a file
		addStuFromFile(fin);
	      else if(choice2 == 3)//removing a student
	    removeStu(ar, count, SIZE);
	      else if(choice2 == 4)//showing the info of a student
		showStuInfo(s);
	      else if(choice2 == 5)//showing all the student info in the list
		allStuInfo(s);
	      else//exit the program
		exit(1);
	    }
	  else
	    cout << "Password is wrong." << endl;//if the password is not correct
	}
      else//the student menu
	{
	  cout << showStuMenu();//display the menu of the student
	  choice3 = showStuMenu();//returned value of choice
	  if(choice3 == 1)//adding a course
	    addCourse(s);
	  else if(choice3 == 2)//removing a course
	    dropCourse(s);
	  else if(choice3 == 3)//making a payment
	    makePayment(s);
	  else if(choice3 == 4)//showing the info of the student
	    showStuInfo(s);
	  else//when the user exits the program
	    exit(1);
	}
    }while(choice == 3);//if the user chooses to exit the program
  exit(1);
  return 0;
}



// ************************  PHASE 1  ****************************

/******************************************************************************
This void function addStu would be used to insert the following variables. There is a Student s, since I have used the student class and set it as a default constructor to access with.

c = count from the main function
sz = size or 100 entries, max limit
id = id number that has been set to 100000
ar = array inside the Student class
fN = first name
lN = last name
gen = gender
******************************************************************************/

void addStu(int c, int sz, int id, Student ar[])
{
//case 1 of admission
  string fN, lN;
  char gen;
  cout << "Enter your first name: ";
  cin >> fN;//first name
  cout << "Enter your last name, " << fN << ": ";
  cin >> lN;//last name
  cout << "Enter your gender: ";
  cin >> gen;//gender
  //id = id + 1; 
  Student s(fN, lN, gen, id);//create a student object filled with the user's inputs.
  ar[c] = s;//array set to count and assign to s since that is the start
  //c++;//goes up one to move onto the next element
  //id = id++;

  showStuInfo(s);//to output the element within the constructor
}
  /*  
create a student object. The first student created is given a stu id, 100000 (coming from const START).
The second student gets 100001, the third student gets 100002, etc (notice curID in main).

copy the info from the stu obj into the array at the appropriate slot
  */

                                                             
//showStuInfo( pass ONE student object - NOT the array)                                                                                       

/******************************************************************************
This void function will output what was initially inserted inside the addStu void function. The parameter would be a constant student class because it would not change once the program outputs the inputs. 

sz = size
I will go in depth with the other functions as shown below with the student class being operated with the getFunctions
******************************************************************************/

void showStuInfo(const Student& s)
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 

  cout << "--------------------" << endl;//this will be used to make the outputs more neat and organized                            
  cout << "first name: " <<  s.getFirstName()  << endl;//this will be used from my student.cpp with the function of getFirstName
  cout << "last name: " << s.getLastName()  << endl;//this will be used from my student.cpp with the function of getLastName                      
  cout << "gender: " << s.getGender() << endl;//this will be used from my student.cpp with the function of getGender        
  cout << "stu id: " << s.getStuID() << endl;//this will be used from my student.cpp with the function of getStuID                              
  cout << "num classes: " << s.getNumClasses() << endl;//this will be used from my student.cpp with the function of getNumClasses                                       
  cout << "Courses: ";                                                                                                                      
  for(int i = 0; i < s.getNumClasses(); i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course? I would choose the getNumClasses member function because it would receive the amount of classes the student is taking.       
    cout << s.getClassOf(i) << ", ";//this is used to output the classes of what the student is taking.                                                                  
  cout << "\nAmount owed $" << s.getBalance() << endl;  //You have an operator overloading function to show a price object at once     
  cout << endl;                                                                                                                               
}

/******************************************************************************
This void function will output all the following from showStuInfo void function and addStuFromFile void function because since one of the functions are from a file and an input function, it would be important to set both of those out to get the following to output properly.

s = the student class to set for the following outputs inside the functions (I was unsure how to compile it, so I just added some extra things inside the function.
sz = size that is from the other functions and is passed by refernce since it will be used over and over again
fin = the input from the file college.dat
******************************************************************************/

void allStuInfo(const Student& s)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  showStuInfo(s);//the void function that records the user inputs
  //addStuFromFile(fin);//the void function that records what is inside the data file
}

/******************************************************************************
This bool function is set to operator == because it is a conditional operator and to read each students inputs to prevent repetition within the process. 

s = the student class to set for the following outputs inside the functions (I was unsure how to compile it, so I just added some extra things inside the function.
id = the id number that is used for default at 1000000
******************************************************************************/

bool operator==(const Student& s, int id) 
{
  if(s.getStuID() == id)//if the id that was used from the start 1000000 is equivalent to the 1000000 then the if statement has to change the id
    {    
      id = id + 1;//this is to add the id by one once there is another user that has been added in the program, however it would not add on the id number
      return true;
    }
  else//if the id is not the same or different from the original, which I doubt will happened with the exception of some circumstances
    return false;
}

/******************************************************************************
This void function will remove what appear first in the list. The function also does not have a choice for the user to delete, but would delete what is inside the program by using my array.h file.

s = my student class, I was unsure how to operate it so I just left it inside of my remove function.
c = count, which would be used to keep track of the size inside of the array
sz = the max size for the array to reach so the program has a limit of students that has to be entered
******************************************************************************/

void removeStu(Student ar[], int c, int sz)
{
//Case 3 of Admission
  Student s;//student class
//2 different messages
  remove(ar, c, sz);//remove function used inside of my array.h
  cout << "student with id " << s.getStuID() << " doesn't exist" << endl;//this will show the id 
  cout << s.getFirstName() << " " << s.getLastName() << " has been removed." << endl;//this will show the last name and first name
}

/******************************************************************************
This function will be used from the ifstream data type to read the inputs inside of my college.dat 

fin = to access the ifstream and would be exaggerated as cin
******************************************************************************/

void addStuFromFile(ifstream& fin)
{
//Case 2 of admission
  fin.open("college.dat");//to open up the file
  if(!fin)//if the file cannot be open
    {
      cout << "File cannot be found" << endl;
    }
  else//if the file can be found or opened
    {
      string first, last;
      char gen;
      fin >> first;
      fin >> last;
      fin >> gen;
    }
}

//*******************  PHASE 2 ****************************

/******************************************************************************
This void addCourse function will pass a student class in order to access the addCourse function from the student class.  
******************************************************************************/
void addCourse(const Student& s)
{
//case 1 of student
//FYI, I am passing one student to this function not the array. 
  int crn = 111;
  for(int i = 0; i < SIZE; i++)
    {
//3 different messages to show
      if(s.addCourse(crn) == 1)//if the course is not in the list
	{
	  cout << crn <<" has been added successfully" << endl;
	  crn = crn + 111;//everytime the class has been added
	}
      else if(s.addCourse(crn) == 0)//if the course already exists
	cout << crn << " was not added because you have " << crn << " already." << endl;
      else//if the list has reached the limit of courses
	cout << crn << " was not added because your schedule is full." << endl;
    }
}

/******************************************************************************
The void dropCourse function is used to pass the student class object to call in the remove course and to get other functions inside of my student class
******************************************************************************/

void dropCourse(const Student& s)
{
//case 2 of admission
//FYI, I am passing one student to this function not the array. 
  int crn = 111;
  for(int i = 0; i < SIZE; i--)
    {
//2 different messages
      if(s.dropCourse(crn) == false)
	cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
      else
	cout << crn << " has been dropped successfully." << endl;
    }
}

/******************************************************************************
This void makePayment function requires the student to enter the following integers as shown inside the function. I will be using the addFee function in this case in order for it to complete the transaction. 
******************************************************************************/

void makePayment(const Student& s)
{
//case 3 of student
//FYI, I am passing one student to this function not the array. 
  int d, c; 
  cout << "You currently owe $10.50 for your unreturned textbooks. Enter the money like this. 10 50 and not 10.50 " << endl;
  cin >> d >> c;
  s.addFee(d, c);
}


//******************** PHASE 3 ****************************
/*
void checkPassword(int password)
{
  if(password == 123)
    
  else
    cout << "The password is wrong." << endl;
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
}

/*
 findStu()
{
//Small function. You may choose not to use this function. That is OK.

//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
}


 viewStuInfo()
{
//Case 4 of admission
//Ask for the student id
//If the student doesn't exist, show an error message.
//If it exists, call showStuInfo to show the student
}


 verifyStu()
{
//You may decide not to use this function. If so, that is OK.

//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
}

*/
/******************************************************************************
This function outputs the following inside and will have the user choose the following numbers. The numbers will be set into a function called getData that will store the numbers inside of the range and would return the integer if it is in the range but if it is outside of the range, then the choice would be invalid and will output an error message.
******************************************************************************/
int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}

/******************************************************************************
This function will show the following menu from the list and will have an integer to be entered. The numbers will be from a range of one to five to gather what functions to be used. The function getData, will be used to get the integers to store the following and verify to see if the numbers entered are within the range and when the number is not in the range, it will output an error message.
******************************************************************************/

int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

/******************************************************************************
Similar with the other two following functions, it will have a set of numbers that has a range for numbers. In this case the getData function will be used to store the numbers and if it is not in the range, there will be an error message and will do the following steps again.
******************************************************************************/

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}



