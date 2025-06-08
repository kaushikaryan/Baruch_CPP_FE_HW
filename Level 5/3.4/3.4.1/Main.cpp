/**
*
* Main.cpp
*
* C++ program to test the colon operator.
* The program, creates an object of the Line class.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#include "Line.hpp"		// Header file for Line class
#include <iostream>

// Using standard namespace to simplify code
using namespace std;

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	// Declaring Line object
	Line l;

	/*
	*
	* Output using constructors without colon syntax:
	* 
	*	Default constructor for Point class called.
	*	Default constructor for Point class called.
	*	Custom constructor that accepts X and Y coordinates for Point class called.
	*	Assignment operator for Point class called.
	*	Destructor for Point class called.
	*	Custom constructor that accepts X and Y coordinates for Point class called.
	*	Assignment operator for Point class called.
	*	Destructor for Point class called.
	*	Destructor for Point class called.
	*	Destructor for Point class called.
	* 
	*	Calls to Constructor:			4
	*	Calls to Assignment operator:	2
	*	Calls to Destructor:			4
	* 
	* Output using constructors with colon syntax:
	* 
	*	Custom constructor that accepts X and Y coordinates for Point class called.
	*	Custom constructor that accepts X and Y coordinates for Point class called.
	*	Destructor for Point class called.
	*	Destructor for Point class called.
	* 
	*	Calls to Constructor:			2
	*	Calls to Assignment operator:	0
	*	Calls to Destructor:			2
	* 
	* It can  be seen that using the colon operator reduces the number of calls
	* to constructors, the destructor and the assignment operator.
	* 
	*/

	// Return successful execution
	return 0;
}