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
	Shape* shapes[3];
	shapes[0] = new Point;
	shapes[1] = new Line;
	shapes[2] = new Circle;

	// Call Draw() function for each object
	for (int i = 0; i < 3; i++)
		shapes[i]->Draw();

	// Delete objects created on the heap
	for (int i = 0; i < 3; i++)
		delete shapes[i];

	// Cannot create an instance of an abstract base class
	//Shape sp;
	//	'Shape': cannot instantiate abstract class
	//	object of abstract class type "Shape" is not allowed:

	// Return successful execution
	return 0;
}