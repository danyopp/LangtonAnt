/**************************************************
 *Program Name: Ant Simulation
 *Author: Daniel Yopp
 *Date: 4/7/18
 *Description: Ant Class is used to store and calculate Ant position and movements while running Langtons Ant simulations
**************************************************/

#ifndef ANT_HPP
#define ANT_HPP

enum direction {North, South, East, West};

class Ant
{
	private:
	   int antRow;
	   int antColumn;
	   int boardRows;
	   int boardColumns; 
	   direction antDirection;
	   char colorUnderAnt; 	
	   char** boardPointer; 


	public:
	   Ant(int, int, int, int, direction); 
	   ~Ant();
	   void setAntRow(int);
	   void setAntColumn(int);
	   void setBoardRows(int);
	   void setBoardColumns(int);
	   void setAntDirection(direction);
	   void setColorUnderAnt(char);
	   int getAntRow();
	   int getAntColumn();
	   int getBoardRows();
	   int getBoardColumns();
	   direction getAntDirection();
	   char getColorUnderAnt();
	   void takeStep();
	   void printBoard();
	   
};

#endif  
