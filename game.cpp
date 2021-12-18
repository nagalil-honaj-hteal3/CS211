/****************************************************************************
CS211
Queue application

To compile:
g++ -pthread game.cpp queue.cpp

This program will ask the user to answer math questions (add, sub, mult, div).
The queue will have 3 questions before the game starts. After the game starts, a new question
will be added every 1 second if the level is 5, 2 seconds if the level is 4, .. 5 seconds if the level is 1.
The user will be asked to choose a level from 1 to 5 before the game starts.
A question for the user to answer will be removed from the front of the queue. The user will be asked to answer
the same question until he gives the correct answer. After he gives a correct answer, the next question will be removed from the front of
the queue.

When the queue grows to have 10 questions (the queue is full), the game ends and the user loses (he was too slow doing the math). 
When the queue becomes empty, the game ends and the user wins (he was quick doing the math).
When the user answers 100 questions correctly, the game ends and the user wins (the queue never became empty or full).

This program uses one thread to add new questions to the queue and another to let the user 
enter math questions.
*****************************************************************************/ 

#include <time.h>
#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include "/cs/slott/cs211/checkInput.h"
#include "queue.h" //my queue class
using namespace std;

/******************************
Place the following code in queue.h
Then comment this section. 
********************************/
//create an enumuration type
/*????? replaced with enum*///enum op {ADD, SUB, MULT, DIVI};

//create a struct that will have an operand, a operator, another operand
/*????? replaced with struct*//*struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
  };*/
/*******************************
Place the above code to queue.h
*******************************/

//prototypes
void *answerQuestion(void* data);
void *addQuestion(void* data);
int correctAnswer(int op1, char optr, int op2);
char getOperator(op o);
expr makeQuestion();

//global - easier to share them between threads
Queue q; //create a queu object. the queue will store math questions
bool win = true; //set to true if win, false if lose
int numCorrect = 0; //the number of correct questions the user answered
pthread_mutex_t lock; //used to lock a part of code where a shared resource (q) 
                      //is updated by a thread
int level;//level of difficulty (1 for easy/slot, 5 for hard/fast)

/***************************************************************************** 
In this main function, it would be used for threads, random function, and functions to use the queue class.

q.add(makeQuestion()) = the add function that I created inside of the queue class in order to create questions within the queue.
getData() = used from the checkInput.h to verify the user's choice from the range given.
answerQuestion(NULL) = used to access the void* data and setting it into something for the data to not be interferred or confused.
*****************************************************************************/ 

int main()
{
  //get a different sequence of random numbers in each run
  srand(time(NULL));
  //adds 3 questions into the rear of the queue 
  q.add(makeQuestion());//the makeQuestion() function will be used to create randomized questions related to math problems that consists addition, subtraction, multiplication, and division.
  q.add(makeQuestion());//the makeQuestion() function will be used to create randomized questions related to math problems that consists addition, subtraction, multiplication, and division.
  q.add(makeQuestion());//the makeQuestion() function will be used to create randomized questions related to math problems that consists addition, subtraction, multiplication, and division.
  cout << "Which level do you want to try? 1 (easy) to 5 (hard): ";
  //level 1 will add a new question every 5 seconds. If level 2, every 4 seconds. If level 5, every 1 second.
  level = getData(1, 5, "Invalid level. Enter 1 to 5: "); //from checkInput.h  
  //initialize the mutex
  if (pthread_mutex_init(&lock, NULL) != 0)
    {
      cout << "Creating a mutext failed." << endl;
      return 1; //ending the program. 1 is an error code passed to the operating system
    }
  //delcare 2 threads. first thread to add new questions and second for the user to answer questions.
  pthread_t tAddQues, tAns;
  //thread to add new qustions to the rear of the queue
  pthread_create(&tAddQues, NULL, &addQuestion, NULL);
  //thread for the user to answer questions removed from the front of the queue
  pthread_create(&tAns, NULL, &answerQuestion, NULL);
  //wait for the thread to come back from addQuestion()
  pthread_join( tAddQues, NULL);
  //wait for the thread to come back from answerQuestion()
  pthread_join(tAns, NULL);
  //win is set to true in answeQuestion() - if the user answers quickly and the queue gets empty or he answers 100 questions correctly, the user wins the game
  answerQuestion(NULL);//I was unable to try to keep the queue to continue after 
  if(win == false)//if the user was unable to answer the question correctly.
    cout << "You lost! You answered " << numCorrect << " questions correctly." << endl;
  else //if the user doesn't answer questions quick enough and the queue grows to have 10 questions, he loses.
    //cout << "You lost!\t";
    cout << "Congrats, you won!";
  return 0;
}

/***************************************************************************** 
This void *addQuestion(void* data) will add questions while using the threads and to also reset the time on the clock to continue the same process. It would also have the data type clock_t since it would have the <time.h> The queue class would also be used to not have different functions that will be declared inside of the function and also without it, there would be an error since it would not be declared to run the function.
*****************************************************************************/ 

void *addQuestion(void* data)
{
    expr newQ;//a new question to be added, and not sure where to use it for testing the function. Although it is a struct, I am unsure where I can execute it.

    clock_t endWait;
    //a new question will be added to the queue every 1 second if the level is 5, 
    //2 seconds if the level is 4, .. 5 seconds if the level is 1.
    clock_t waitTime = CLOCKS_PER_SEC * level/4.0;//level = 1 to 5 seconds to determine the difficulty of the program
    endWait = clock() + waitTime;//this would be the timer to be set once the difficulty has been chosen.

    //as soon as the queue grows to have 10 questions(full), gets empty or the user answers 100 questions correctly, the game ends
    while(q.isEmpty() || !q.isFull() || numCorrect == 100)
	  {
	    //it is time to add a new question to the queue
	    if(clock() != endWait)//I set it to does not equal because once it hits the endWait marker, then the program will end, however having this will allow the program to continue if it has not met endWait
	      {
		//create a new question
		//makeQuestion();
		//lock the code so this thread has exclusive access to the queue while updating
		pthread_mutex_lock(&lock);
		//add the new question to the rear of the queue
		q.add(makeQuestion());//using my add function in my queue class to put the question at the rear
		pthread_mutex_unlock(&lock); //unlock the exclusive access so the other thread 
		                             //can access the queue now
		//reset the end wait time
		endWait = clock() + waitTime;
	      }
	  }
}

/*****************************************************************************
This void *answerQuestion(void* data) function will be used to check when the answer is correct or incorrect. With the struct e used accordingly in this function, it will allow the function to recognize the operand and operators easier. The queue class will be used for the while loop to determine the answer.
*****************************************************************************/ 

void *answerQuestion(void* data)
{
  expr e;//struct variable name e
  int answer,correct;//answer = the user input, correct = the correct answer
  int op1, op2;//operands 1 and 2
  char opr;//operation

  //as soon as the queue grows to have 10 questions(full), gets empty, or the user answers 100 questions correctly, the game ends
  while(q.isFull() || !q.isEmpty() || numCorrect == 100)
    {
      //lock the code so this thread has exclusive access to the queue while updating
      pthread_mutex_lock(&lock);

      e = q.getFront();//get the question from the front of the queue
      q.remove();

      pthread_mutex_unlock(&lock); //unlock the exclusive access so the other thread 
	                           //can access the queue now

      op1 = e.oprd1;//struct type that is accessed including oprd1.
      opr = getOperator(e.oprt);//struct type that is accessed including oprt, however by using the function getOperator, it will allow the user to find what operator will be used to access to finding the answer with the operands.
      op2 = e.oprd2;//struct type that is accessed including oprd2.

      //get the answer to the question
      correct = correctAnswer(op1, opr, op2);
 
      //ask the usert to enter the user's answer
      cout << op1 << " " << opr << " " << op2 << " = ";
      //cout <<  << " = "; //Show the expression struct at once
      cin >> answer;//this would be the answer that the user will enter

      //as long as the user's answer is wrong, she/he will have to retry answering the same question
      while(answer != correct && q.getSize() < 10 && !q.isEmpty())//this is when the user is not answering the equation correctly.
	    {
	  cout << "WRONG. try again. " <<  op1 << " " << opr << " " << op2 << " = ";
	  //cout << "WRONG. try again. " <<  ??????  << " = ";  //Show the expression struct
	  cin >> answer;
	  win = false;//this would be false since it is set to not winning the program. 
	  //cout << win << endl;
	    }
      //the user's answer was correct. the number of correct increases 
      if(answer == correct)
	numCorrect++;//numCorrect gets incremented.
    }

  //if the queue grows to have 10 questions, the user loses the game
  //if the queue gets empty or the suer answers 100 questions correctly, the user wins the game
  /*if(q.isEmpty() || numCorrect == 100)
     win = true;
  else 
     win = false;*/
}

/*****************************************************************************
This would check when the operator will be one of the following. This would convert an enum value to char in order to access the variables ADD, SUB, MULT, and DIVI to let the user read the following properly
*****************************************************************************/

char getOperator(op o)//op is the enum value and o will be a random variable name to let the function work. 
{
  switch(o)
    {
    case ADD: return '+';
    case SUB: return '-';
    case MULT: return '*';
    case DIVI: return '/';
    }
}

/*****************************************************************************
This int correctAnswer function checks to see if the user that finds the operator and find the answer with what the two operands will be. With the four different cases, each represent the operation as mentioned before to accept the following and outputting the correct answer. 
*****************************************************************************/
//do the math
int correctAnswer(int op1, char optr, int op2)
{
  switch(optr)//this optr value will be used to find the following operators in the cases.
    {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    }
}

/*****************************************************************************
This makeQuestion function would be used as a struct because it would allow the program to randomize different equations with the different operations and operands to be used. It would be used as expr in this case since the element type would be struct, so necessilary, it will allow the program to easily add it inside of the queue without any issue or problem.
*****************************************************************************/

//creates a question and returns a struct
expr makeQuestion()
{
  int temp;//temporary value
  expr e;
  /*??.oprt = (?????)(rand()%?????);*/ //0 for add, 1 for sub, 2 for mult, 3 for divi
  e.oprt = (op)(rand() % 4);
  if(e.oprt == MULT) //if the operator is multiplication, make operands between 1 and 20 for the first operand and between 1 and 10 for the second operand.
                     // (large operands would make multiplication hard.)
    {
      /*??.oprd1 = ?????????;*/ //create a random number between 1 and 20
      e.oprd1 = (op)(rand() % 20 + 1);
      /*??.oprd2 = ?????????;*///create a random number between 1 and 10
      e.oprd2 = (op)(rand() % 10 + 1);
    }
  else //the operator is add, sub or divi. Make operands between 1 and 100
    {
      e.oprd1 = (op)(rand() % 100 + 1);//create a randowm number between 1 and 100
      e.oprd2 = (op)(rand() % 100 + 1); //create a randowm number between 1 and 100

      //if the operator is sub or division, the first operand should be greater than or equal to the second operator (otherwise the calulation
      //would the too difficult for SUB and too easy for DIVI. 
      if(e.oprt == SUB && e.oprt == DIVI)
	{
	  if(e.oprd1 < e.oprd2) //if the second operand is larger, swap operand1 and operand2
	    {
	      temp = e.oprd2;//what the second operand was temporarily 
	      e.oprd2 = e.oprd1;//swap the e.oprd2 with e.oprd1
	      e.oprd1 = temp;//set the e.oprd1 to temp to finish the swap
	    }
	}
    }
 
  return e;//return the struct value
}

/**********************************************************************************************
You need to create the following opoerator overloading function in queue.cpp above displayAll().

Create this operator overloading function to show an expression at once in the following format
8 + 3
***********************************************************************************************/
/*
????? operator<<(?????)
{
   ?????
}
*/
