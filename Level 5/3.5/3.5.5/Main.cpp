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
	Shape* shapes[2];
	shapes[0] = new Point;
	shapes[1] = new Line;

	// Call Draw() function for each object
	for (int i = 0; i < 2; i++)
		shapes[i]->Print();

	// Delete objects created on the heap
	for (int i = 0; i < 2; i++)
		delete shapes[i];

	// Return successful execution
	return 0;
}