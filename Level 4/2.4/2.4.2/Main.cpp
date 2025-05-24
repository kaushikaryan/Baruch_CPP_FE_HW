/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program, gets x and y coordinates from the user, creates two Point objects,
* and displays their properties.
*
* @author:  Kaushik Aryan R
* @date:    23-05-2025
* @version: 1.0
*
**/

#include "Point.hpp"	// Header file for Point class
#include "Line.hpp"		// Header file for Line class
#include "Circle.hpp"	// Header file for Circle class
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
	// Initialize Point object
	Point p1 = Point(1, 1);

	cout << p1 << endl;

	// Initializing Line object
	Line l1(Point(0, 0), Point(10, -10));

	Line l2 = l1;	// Assignment operator
	cout << "L1: " << l1 << "; L2: " << l2 << endl;
	
	// Initializing Circle object
	Circle c1(Point(4, -8), 10.0);
	Circle c2 = c1;

	cout << "C1: " << c1 << "; C2: " << c2 << endl;

	// Return successful execution
	return 0;
}