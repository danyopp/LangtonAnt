/********************************************************
 *Project Name: Ant simulation
 *Name: Daniel Yopp
 *Date: 4/7/18
 *Description: This main file combines the Ant class that stores data about an Langton's Ant simulation with the Menu class which collects data from a user to create a full Langton's Ant simulation program.
********************************************************/

#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "ant.hpp"
#include "menu.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
   
   Menu questions;      //declare menu class

   //ask play game/quit question
   if (questions.startMenu()==2)
      {
       return 0;
      } 

   //begin game loop   
   bool playAgain = true;
   while(playAgain)
   { 
      // Gather simulation data from user
      bool skipStartLocationPrompt = questions.randomQuestion();    //pick ant start point
      int userRowInput = questions.numberOfRows();                  //number of rows on game board
      int userColumnInput = questions.numberOfColumns();            //number of columns on game board
      int antSteps = questions.numberOfSteps();                     //number of steps for ant to take

      //Determine starting location of ant
      int startingRow, startingColumn;
      if (!skipStartLocationPrompt)
            //user assignment of Ant starting location
	        {
            startingRow = questions.antRowStart(userRowInput);
            startingColumn = questions.antColumnStart(userColumnInput); 
          }
      else 
            //random assignment of Ant starting location
          { 
	           unsigned seed;
	           seed = time(0);
	           srand(seed);
		         startingRow = (rand() % userRowInput + 1);
	           startingColumn = (rand() % userColumnInput + 1);
          }	
        
      direction dirEnum = questions.selectDirection();            //get direction that ant is pointing
 
      // Post the simulation specifications given by the user
      cout << endl << endl; 
      cout << "Board Rows: " << userRowInput << endl;
      cout << "Board Columns: " << userColumnInput << endl;
      cout << "Ant starting position: "<< startingRow << "x" << startingColumn << endl;    
      cout << "Number of steps: " << antSteps << endl;

      //Run Langton's Ant Simulation
      Ant simulation(startingRow, startingColumn, userRowInput, userColumnInput, dirEnum);
  
      for(int count = 0; count < antSteps; count++)
      {
       simulation.takeStep();
      }

      //Ending Menu
      int userInput = questions.endMenu();
      cin.ignore(100, '\n'); 
      if( userInput == 2)
        {
          playAgain = false;
        }
   }
return 0; 

}

   


