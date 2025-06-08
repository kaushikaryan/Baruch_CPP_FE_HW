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
	Shape s;							// Create shape
	Point p(10, 20);					// Create point
	Line l(Point(1, 2), Point(3, 4));	// Create line

	cout << s.ToString() << endl;	// Print shape.	Output- ID: 41
	cout << p.ToString() << endl;	// Print point.	Output- Point(10, 20)
	cout << l.ToString() << endl;	// Print line.	Output- Line: Point(1, 2), Point(3, 4)

	cout << "Shape ID: " << s.ID() << endl;	// ID of the shape. Shape ID: 41
	cout << "Point ID: " << p.ID() << endl;	// ID of the point. Does this work? Yes. Output- Point ID: 18467
	cout << "Line ID: " << l.ID() << endl;	// ID of the line. Does this work? Yes. Output- Line ID: 19169

	Shape* sp;	// Create pointer to a shape variable. 
	sp = &p;	// Point in a shape variable. Possible? Yes. Since Point is a derived class of the Shape base class,
				// it is also an instance of the Shape class.

	cout << sp->ToString() << endl;	// What is printed? Output- ID: 18467

	// Create and copy Point p to new point. 
	Point p2;
	p2 = p;

	cout << p2 << ", " << p2.ID() << endl;	// Is the ID copied if you do not call the base class assignment in point? Output- Point(10, 20), 18467
											// No. The value of id is not copied over to p2 if we do not call the assignment operator for the
											// Shape base class within the assignment operator for the Point class.

	// Return successful execution
	return 0;
}