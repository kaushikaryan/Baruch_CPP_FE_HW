/**
*
* Main.cpp
*
* C++ program to test the Point and Line class.
* The program, creates objects of the Point and Line class
* and prints them usingt the << operator.
*
* @author:  Kaushik Aryan R
* @date:    23-05-2025
* @version: 1.0
*
**/

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
	// Initializing Point object
	Point p1 = Point(1, 1);

	cout << "P1: " << p1 << endl;

	// Initializing Line object
	Line l1(Point(0, 0), Point(10, -10));

	cout << "L1: " << l1 << endl;

	// Return successful execution
	return 0;
}