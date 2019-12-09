/*********************************************
 *Program Name:
 *Author: Daniel Yopp
 *Date: 4/7/18
 *Description: The following Ant class functions manipulate data associated with the "Ant" in a Langton's ant simulation.
*********************************************/

#include <iostream>
#include <string>
#include "ant.hpp"


using std::cin;
using std::cout;
using std::endl;

/*******************************************
 * 	Ant::Ant(int int int int direction)
 * Description: Ant class constructor sets up all class member variables, build a dynamic 2D array to serve as a game board, and fills the game board with white space.
 ******************************************/

Ant::Ant(int antRw, int antCol, int boardRw, int boardCol, direction dirStart)
{
   //setup class private variables
   setAntRow(antRw-1);
   setAntColumn(antCol-1);
   setAntDirection(dirStart);
   setBoardRows(boardRw);
   setBoardColumns(boardCol);

   //build game board as a 2D array, using the private class variable boardPointer
   int tempRows = getBoardRows();
   int tempColumns = getBoardColumns(); 
   boardPointer = new char*[tempRows];             //format is boardpointer[row][column]
   for (int count = 0; count < tempRows; count++)
	{
	 boardPointer[count] = new char[tempColumns]; 
 	}

   //fill board with white
   char * tempPtr;
   for (int count = 0; count < tempRows; count++)
       {
	for (int count2 = 0; count2 < tempColumns; count2++)	
   	    {
	     tempPtr = boardPointer[count];
	     tempPtr[count2] = ' ';	
	    }
       }	

   //add ant starting position
   int tempAntRow = getAntRow();
   int tempAntCol = getAntColumn(); 
   boardPointer[tempAntRow][tempAntCol] = '*';
   setColorUnderAnt(' ');

   printBoard();
}

/********************************************
 *		Ant::~Ant
 *Description: The Ant class deconstructor returns the 2D array memory to the heap
********************************************/

Ant::~Ant()
{
   int tempRows = getBoardRows();
   for (int count = 0; count < tempRows; count++)
	{
	 delete [] boardPointer[count];
	 boardPointer[count] = NULL;
	}
   delete [] boardPointer;
   boardPointer = NULL;
}

/********************************************
 *	Ant::setAntRow  		
 *Description: Stores the row the ant currently occupies
*********************************************/	

void Ant::setAntRow(int rowInput)
{
 antRow = rowInput;
}

/*******************************************
 * 	Ant::setAntColumn
 * Description: Stores the column the ant currently occupies
 * ****************************************/

void Ant::setAntColumn(int columnInput)
{
 antColumn = columnInput;
}

/*******************************************
 * 	Ant::setBoardRows
 * * Description: Stores the total number of rows on the board
 * ****************************************/

void Ant::setBoardRows(int boardRowsInput)
{
 boardRows = boardRowsInput;
}


/*******************************************
 * 	Ant::setBoardColumns
 * Description: Stores the total number of columns on the board
 * ****************************************/

void Ant::setBoardColumns(int boardColumnInput)
{
 boardColumns = boardColumnInput;
}

/******************************************
 * 	Ant::setAntDirection
 * Description: Stores the direction the ant is facing
 * ***************************************/

void Ant::setAntDirection(direction inputDirection)
{
 antDirection = inputDirection;
}

/******************************************
 * 	Ant::setColorUnderAnt
 * Description: Stores the color of the square under the ant. This is not on the array because the array carries a * where the ant is located so the color is stored here
 * ***************************************/

void Ant::setColorUnderAnt(char colorInput)
{
 colorUnderAnt = colorInput;
}


/******************************************
 * 	Ant::getAntRow()
 * Description: returns ant's current row
 * ***************************************/

int Ant::getAntRow()
{
 return antRow;
}

/*****************************************
 * 	Ant::getAntColumn()
 * Description: returns ant's current column
 * **************************************/

int Ant::getAntColumn()
{
 return antColumn;
}

/*****************************************
 * 	Ant::getBoardRows()
 * Description: Returns number of rows on the board
 * **************************************/

int Ant::getBoardRows()
{
 return boardRows;
}

/*****************************************
 * 	Ant::getBoardColumns()
 * Description: Returns number of Columns on Board
 * **************************************/

int Ant::getBoardColumns()
{
 return boardColumns;
}

/****************************************
 * 	Ant::getAntDirection()
 * Description: Returns Direction Ant is facing
 * *************************************/

direction Ant::getAntDirection()
{
 return antDirection;
}	

/***************************************
 * 	Ant::getColorUnderAnt
 * Description: Returns the color under the Ant
 * ************************************/

char Ant::getColorUnderAnt()
{
 return colorUnderAnt;
}	

/**************************************
 * 	Ant::takeStep
 * Description: Goes throught the process of an ant taking a step and updates all member variables with new location data
 *************************************/

void Ant::takeStep()
{
 //get ant current location
 int antCurrentRow = getAntRow();
 int antCurrentCol = getAntColumn();
 direction antFacing = getAntDirection();
   

 //get color of square ant is stepping off of 
 char startColorUnderAnt = getColorUnderAnt();
 

 //Ant Steps north(row change only); ant faces East if white(' ') and west if black ('#')
 if (antFacing == North)
    {
      //set new ant location a position higher on array
      int antOldRow = antCurrentRow;
      setAntRow(antCurrentRow-1); 
      antCurrentRow = getAntRow();
      //wraps board around if step takes ant off board 
      if(antCurrentRow < 0)
        {
	        int maxRows = getBoardRows();
	        setAntRow(maxRows-1); 
	     } 
     
      //record color of new spot ant is standing on
      antCurrentRow = getAntRow();
      antCurrentCol = getAntColumn();	
      char currentColor = boardPointer[antCurrentRow][antCurrentCol]; 
      setColorUnderAnt(currentColor);

      //Change the ants direction
      if (currentColor== ' ')       //colors on the game board are denoted by chars: ' ' and '#'
         {
       	   setAntDirection(East);
	      }
      else  
	     {    
	        setAntDirection(West);
	     }

      //Change the old ants spot on board from '*' to Black or white  
      if (startColorUnderAnt == ' ')
         {
         boardPointer[antOldRow][antCurrentCol] = '#';
         }
      else  
         {
         boardPointer[antOldRow][antCurrentCol] = ' ';
         }
  
      //Add the new '*' to the Board
      boardPointer[antCurrentRow][antCurrentCol] = '*';    

      printBoard();
    }


 //Ant Steps South(row change only); ant faces west if white(' ') and east if black ('#')
 if (antFacing == South)
    {
      //set new ant location a position lower on array
      int antOldRow = antCurrentRow;
      setAntRow(antCurrentRow+1); 
      antCurrentRow = getAntRow();
      int maxRows =(getBoardRows() - 1);
      //wraps board around if step takes ant off board 
      if(antCurrentRow > maxRows)
        {
	        setAntRow(0); 
	     }

      //record color of new spot ant is standing on
      antCurrentRow = getAntRow();
      antCurrentCol = getAntColumn();	
      char currentColor = boardPointer[antCurrentRow][antCurrentCol];
      setColorUnderAnt(currentColor);

      //Change the ants direction
      if (currentColor== ' ')
         {
 	        setAntDirection(West);
	      }
      else  
	      {    
	        setAntDirection(East);
	      }

      //Change the old ants spot on board from '*' to Black or white
      if (startColorUnderAnt == ' ')
         {
         boardPointer[antOldRow][antCurrentCol] = '#';
         }
      else  
         {
         boardPointer[antOldRow][antCurrentCol] = ' ';
         }
      
      //Add the new '*' to the Board
      boardPointer[antCurrentRow][antCurrentCol] = '*';    

      printBoard();
   }



//Ant steps East(Col change only); ant faces South if white(' ') and North if black('#')
 if (antFacing == East)
    {
      //set new ant location a position right on array
      int antOldCol = antCurrentCol;
      setAntColumn(antCurrentCol+1); 
      antCurrentCol = getAntColumn();
      int maxCols = (getBoardColumns() - 1);
      if (maxCols < antCurrentCol)
	 {
	  setAntColumn(0);
	 } 
      
      //record color of new spot ant is standing on
      antCurrentRow = getAntRow();
      antCurrentCol = getAntColumn();	
      char currentColor =  boardPointer[antCurrentRow][antCurrentCol];
      setColorUnderAnt(currentColor);

      //Change the ants direction
      if (currentColor== ' ')
         {
       	  setAntDirection(South);
	      }
      else  
	     {    
	        setAntDirection(North);
	     }

      //Change the old ants spot on board from '*' to Black or white
      if (startColorUnderAnt == ' ')
         {
         boardPointer[antCurrentRow][antOldCol] = '#';
         }
      else  
         {
         boardPointer[antCurrentRow][antOldCol] = ' ';
         }

      //Add the new '*' to the Board
      boardPointer[antCurrentRow][antCurrentCol] = '*';    

      printBoard();
   }


//Ant steps West(Col change only); ant faces North if white(' ') and South if black('#')
 if (antFacing == West)
    {
      //set new ant location a position left on array
      int antOldCol = antCurrentCol;
      setAntColumn(antCurrentCol-1); 
      antCurrentCol = getAntColumn();
      int maxCols = (getBoardColumns() - 1);
      if (antCurrentCol < 0)
	      {
	         setAntColumn(maxCols);
	      } 

      //record color of new spot ant is standing on
      antCurrentRow = getAntRow();
      antCurrentCol = getAntColumn();	
       
      char currentColor = boardPointer[antCurrentRow][antCurrentCol];
      setColorUnderAnt(currentColor);

      //Change the ants direction
      if (currentColor== ' ')
         {
 	         setAntDirection(North);
      	}
      else  
	     {    
	        setAntDirection(South);
  	     }
        
      //Change the old ants spot on board from '*' to Black or white
      if (startColorUnderAnt == ' ')
         {
         boardPointer[antCurrentRow][antOldCol] = '#';
         }
      else  
         {
         boardPointer[antCurrentRow][antOldCol] = ' ';
         }

      //Add the new '*' to the Board
      boardPointer[antCurrentRow][antCurrentCol] = '*';    

      printBoard();

   }


}
 	

/**************************************
 * 	Ant::printBoard
 *Description: Prints out entire Board array with current * location and black and white squares
**************************************/

void Ant::printBoard()
{
   int tempRows = getBoardRows();
   int tempColumns = getBoardColumns();
   char * printTemp;

   //print top line
   cout << " ";
   for (int count = 0; count < tempColumns; count++)
       {
	cout << "-";
       }
   cout << " ";

   //print each row one at a time
   for (int count = 0; count < tempRows; count++)
       {
	     cout << endl;
	     cout << "|";
	     for (int count2 = 0; count2 < tempColumns; count2++)
	        {
	        printTemp = boardPointer[count];
	        cout << printTemp[count2];
	        }
	     cout << "|";
       }	      
   cout << endl;

   //print last line
   cout << " ";
   for (int count = 0; count < tempColumns; count++)
       {
	cout << "-";
       }
   cout << endl;
}

					
