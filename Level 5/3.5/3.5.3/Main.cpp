/**
*
* Main.cpp
*
* C++ program to test Inheritance.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#include "Shape.hpp"	// Header file for Shape class
#include "Point.hpp"	// Header file for Point class
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
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++)
		delete shapes[i];
	/*
	*
	* Initial output without declaring destructor as virtual in Shape base class:
	*	Destructor called for Shape Class.
	*	Destructor called for Shape Class.
	*	Destructor called for Shape Class.
	* 
	* After declaring destructor as virtual:
	*	Destructor called for Shape Class.
	*	Destructor called for Point Class.
	*	Destructor called for Shape Class.
	*	Destructor called for Line Class.
	*	Destructor called for Point Class.
	*	Destructor called for Shape Class.
	*	Destructor called for Point Class.
	*	Destructor called for Shape Class.
	*	Destructor called for Shape Class.
	* 
	* We can see that the derived class destructor will only be called when
	* the destructor is declared virtual in the base class.
	* 
	*/

	// Return successful execution
	return 0;
}