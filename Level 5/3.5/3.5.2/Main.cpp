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
#include "Circle.hpp"		// Header file for Circle class
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
	Point p(10, 20);	// Create Point
	Shape* sp;			// Create pointer to a shape variable. 
	sp = &p;			// Point in a shape variable

	cout << sp->ToString() << endl;	// Calls ToString() function of the Point class

	Line l(p, Point(0, 0));	// Create Line
	sp = &l;				// Line in a shape variable

	cout << sp->ToString() << endl;	// Calls ToString() function of the Line class

	Circle c(p, 5); // Create Circle
	sp = &c;		// Line in a shape variable

	cout << sp->ToString() << endl;	// Calls ToString() function of the Circle class

	// Return successful execution
	return 0;
}