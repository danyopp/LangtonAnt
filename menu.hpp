/**************************************************
 *Program Name: Ant Simulation
 *Author: Daniel Yopp
 *Date: 4/7/18
 *Description: Menu class is responsible for prompting the user for data and verifying it so it can be used in a Langton Ant simulation 
**************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "ant.hpp"


class Menu
{
	public:
	   int startMenu(); 
	   bool randomQuestion();
	   int numberOfRows();   
 	   int numberOfColumns();
	   int numberOfSteps();
	   int antRowStart(int);
	   int antColumnStart(int); 
	   direction selectDirection();
	   int endMenu(); 

};

#endif  
