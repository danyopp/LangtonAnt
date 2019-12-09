/********************************************************
 *Project Name: Ant Simulation
 *Name: Daniel Yopp
 *Date: 4/7/18
 *Description: The Menu class functions are responsible for prompting the program user for data and then verifying the data is in the correct format befre sending it to be used in an LAngton's Ant simulation. 
********************************************************/

#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/********************************************************
 *	Menu::startMenu
 *Description: Prompts user to run simulation or quit program 
 * *****************************************************/

int Menu::startMenu()
{
   bool inputVerification = false;
   string list1AnswerString;
   int    list1Answer = 0;

   while(inputVerification == false)
	{
	 cout << "1. Start Langton's Ant simulation" << endl;
	 cout << "2. Quit" << endl;
         getline(cin, list1AnswerString);
	 if(list1AnswerString == "1" || list1AnswerString == "2")
	   {
	    inputVerification = true;
	    list1Answer = stoi(list1AnswerString);
	   }
	 else
	   {
	    cout << "INVALID USER INPUT" << endl;
	   }
	}
   return list1Answer;
}

/*******************************************************
 *	Menu::randomQuestion
 *Description: Asks user if they would like to enter an Ant starting location or want the program to assign a random ant starting location
 * ****************************************************/ 

bool Menu::randomQuestion()
{
   bool skipStartLocationPrompt = false;
   bool inputVerification = false;			//used only to verify proper input
   string list2Answer;

   while (inputVerification == false)
	{
	 cout << "Would you like to use a random starting location for the ant simulation? (Y/N) " << endl;
	 getline(cin, list2Answer);
	 if(list2Answer == "Y" || list2Answer == "N" || list2Answer == "y" || list2Answer == "n")
	   {
	    inputVerification = true;
	   }
	 else
	   {
	    cout << "INVALID USER INPUT" << endl;
	   }
	}
   if (list2Answer == "Y" || list2Answer == "y")
	{
	 skipStartLocationPrompt = true;
	}
   return skipStartLocationPrompt;
}
 
/********************************************************
 *	Menu::numberOfRows()
 *Description: Asks for the number of rows the user wants on the game board
 * ****************************************************/   

int Menu::numberOfRows()
{
   int userRowInput; 
   cout << "Please enter an integer for the number of rows on the board: " << endl;
   cin >>userRowInput;
   while( cin.fail() || userRowInput < 1)
        {
	    cin.clear();				//clears cin error flag
	    cin.ignore(1000, '\n');		//skips up to 1000 chars in the buffer to the next new line char. 
	    							//Possible refractoring, consider #include <limits> ; cin ignore(std::numeric_limits<std::streamsize>::max(), '\n')
	    cout << "INVALID USER INPUT" << endl;
	    cout << "Please enter an integer for the number of rows on the board: " << endl;
	    cin >> userRowInput;
        }
   return userRowInput;
}

/********************************************************
 *	Menu::numberOfColumns
 *Description: Asks for the number of columns the user wants on the game board 
 * *****************************************************/

int Menu::numberOfColumns()
{
   int userColumnInput;
      cin.ignore(1000, '\n');  
   cout << "Please enter an integer for the number of columns on the board: " << endl;
   cin >>userColumnInput;
   while( cin.fail() || userColumnInput < 1)
        {
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "INVALID USER INPUT" << endl;
	    cout << "Please enter an integer for the number of columns on the board: " << endl;
	    cin >> userColumnInput;
        }
   return userColumnInput;
}

/*******************************************************
 *	Menu::numberOfSteps
 *Description: Asks the user for the number of steps they want the ant to take in a simulation
 ******************************************************/

int Menu::numberOfSteps()
{
   int antSteps;
   cin.ignore(1000, '\n');
   cout << "Please enter an integer for the number of steps the ant will take: " << endl;
   cin >>antSteps;
   while( cin.fail() || antSteps < 1 || antSteps > 100000)
        {
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "INVALID USER INPUT" << endl;
	    cout << "Please enter an integer for the number of steps the ant will take: " << endl;
	    cin >> antSteps;
        }
   return antSteps;
}

/******************************************************
 *	Menu::antRowStart
 *Description: Asks user what row they want the ant to start on 
 *****************************************************/
int Menu::antRowStart(int userRowInput)
{
   int startingRow;
   cin.ignore(1000, '\n');
   cout << "Please enter an integer for the row on which to start the ant: " << endl;
   cin >>startingRow;
   while( cin.fail() || startingRow < 1 || startingRow > userRowInput )
        {
         cin.clear();
         cin.ignore(1000, '\n');
         cout << "INVALID USER INPUT" << endl;
         cout << "Please enter an integer for the row on which to start the ant: " << endl;
         cin >> startingRow;
        }
   return startingRow;
}
/*******************************************************
 *	Menu::antColumnStart
 *Description: Asks user what column they want the ant to start on
 * ****************************************************/
int Menu::antColumnStart(int userColumnInput)
{
   int startingColumn; 
      cin.ignore(1000, '\n');
      cout << "Please enter an integer for the column on which to start the ant: " << endl;
      cin >> startingColumn;
      while( cin.fail() || startingColumn < 1 || startingColumn > userColumnInput )
           {
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "INVALID USER INPUT" << endl;
	    cout << "Please enter an integer for the column on which to start the ant: " << endl;
	    cin >> startingColumn;
           }
   return startingColumn;
}
/************************************************************
 *	Menu::selectDirection
 *Description: Asks the user what direction they want the at to face at the start of the simulation 
 * *********************************************************/ 
direction Menu::selectDirection()
{ 
   string startDir;
   bool inputValidation = false;
   direction dirEnum;
   while (!inputValidation)
	{   cout << "Please enter a direction for the ant to begin pointing. (North/South/East/West)  " << endl;
	    cin >> startDir;
		if(startDir == "North" || startDir == "north")
			{
			  dirEnum = North;
			  inputValidation = true;
			}  

		if(startDir == "South" || startDir == "south")
			{
			  dirEnum = South;
			  inputValidation = true;
			}  

		if(startDir == "East" || startDir == "east")
			{
			  dirEnum = East;
			  inputValidation = true;
			}  

		if(startDir == "West" || startDir == "west")
			{
			  dirEnum = West;
			  inputValidation = true;
			}  
		if(!inputValidation)
            		{
			cout << "INVALID USER INPUT" << endl;
			}
	}
   return dirEnum;
}

/*****************************************************
 * 	Menu::endMenu
 *Description: Asks the user if they would like to run another simulation or quit program
 ****************************************************/
int Menu::endMenu()
{
   int userInput;
   cout << "1. Play Again?" << endl;
   cout << "2. Quit" << endl;

      cin >> userInput;
      while( cin.fail() || userInput < 1 || userInput > 2)
           {
	    cin.clear();
	    cin.ignore(1000, '\n');
	    cout << "INVALID USER INPUT" << endl;
	    cout << "1. Play Again?" << endl;
	    cout << "2. Quit" << endl;
            cin >> userInput;	   
           }
     return userInput; 
}

