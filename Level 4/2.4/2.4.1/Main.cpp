/**
*
* Main.cpp
*
* C++ program to test the Point, Line and Circle classes.
* The program, creates objects from the Point, Line and Circle classes
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
	// Tests for Point class

	// Initializing Point object
	const Point p1(1, 1);

	Point p2 = -p1;	// Negate the coordinates
	cout << "P1: " << p1.ToString() << ", -P1: " << p2.ToString() << endl;

	p2 = p1 * 2;	// Scale the coordinates 
	cout << "P1: " << p1.ToString() << ", 2 * P1: " << p2.ToString() << endl;

	Point p3 = p1 + p2;	// Add coordinates 
	cout << "P1: " << p1.ToString() << ", P2: " << p2.ToString() << "; P1 + P2: " << p3.ToString() << endl;

	// Equally compare operator
	cout << "P2: " << p2.ToString() << ", P2: " << p2.ToString() << "; P3 == P2: " << (p3 == p2) << endl;

	p2 = p3;	// Assignment operator
	cout << "P2: " << p2.ToString() << ", P2: " << p2.ToString() << "; P3 == P2: " << (p3 == p2) << endl;

	// Scale the coordinates & assign
	const int factor = 7;
	p2 *= factor;
	cout << "P2: " << p2.ToString() << ", Scaling factor: " << factor << endl;

	// Tests for Line class

	// Initializing Line object
	Line l1(Point(0, 0), Point(10, -10));

	Line l2 = l1;	// Assignment operator
	cout << "L1: " << l1.ToString() << "; L2: " << l2.ToString() << endl;

	// Tests for Circle class

	// Initializing Circle object
	Circle c1(Point(4, -8), 10.0);

	Circle c2 = c1;	// Assignment operator
	cout << "C1: " << c1.ToString() << "; C2: " << c2.ToString() << endl;

	// Return successful execution
	return 0;
}