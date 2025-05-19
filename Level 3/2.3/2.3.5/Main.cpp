/**
*
* Main.cpp
*
* C++ program to test the Line class.
* The program, gets x and y coordinates for start and end points from the user, 
* creates a Line object, and displays its properties.
*
* @author:  Kaushik Aryan R
* @date:    17-05-2025
* @version: 1.0
*
**/

#include <iostream>
#include "Point.hpp"	// Header file for Point class
#include "Line.hpp"		// Header file for Line class

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
	// Declare input variables
	double x, y;
	
	// Take inputs from user
	cout << "Provide the X and Y co-ordinates for the start point of the line:" << endl;
	if (!(cin >> x >> y))
	{
		cout << "Error: Invalid inputs." << endl;
	}

	// Initialize Point p1
	const Point p1(x, y);

	cout << "Provide the X and Y co-ordinates for the end point of the line:" << endl;
	if (!(cin >> x >> y))
	{
		cout << "Error: Invalid inputs." << endl;
	}

	// Initialize Point p2
	const Point p2(x, y);

	// Initialize Line object
	Line line(p1, p2);

	// Print the string representation of the line
	cout << "String representation of the line is: " << line.ToString() << endl;

	// Print the length of the line
	cout << "Length of the line is: " << line.Length() << endl;

	// Indicate successful execution
	return 0;
}