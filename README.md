LangtonAnt
Langton’s Ant is a well know universal Turing machine that uses an algorithm to describe an Ant’s behavior as it moves across a game board. The board is comprised of grid squares that each initially start out with a background color white. The Ant takes a single step from one square to whichever square it is facing and depending on the color of the square, either turns right or left to face a new direction. If a square is white, the Ant will turn right. If a square is Black, the Ant will turn left. The square color will also change from white to black or vise versa when the Ant steps onto the square.

The following code represents a simulation of the Langton’s Ant turning machine. 

menu.cpp/menu.hpp – menu class declarations; focus on user input/preparing simulation
mainLangton2.cpp – main function
ant.cpp/ant.hpp – Ant class declarations; Langton’s Ant algorithm implementation.   
Makefile – GCC compile instructions
	$ make		creates executable “AntSimulation”
	$ make clean	removes object and executable files

Author: Daniel Yopp
Date: 4/11/2018
