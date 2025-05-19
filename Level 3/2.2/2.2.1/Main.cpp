/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program, gets x and y coordinates from the user, creates a Point object,
* and displays its properties.
*
* @author:	Kaushik Aryan R
* @date:	12-05-2025
* @version:	1.0
*
**/


#include "Point.hpp"
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
	// Initialize variables for input coordinates
	double xCord = 0, yCord = 0;

	// Prompt the user for input
	cout << "Provide the X and Y co-ordinates for a Point\n";
	if (!(cin >> xCord >> yCord))
	{
		cout << "Error: Invalid arguments provided." << endl;
		return 1;
	}

	// Create a Point object using the default constructor
	Point point;

	// Set the coordinates using the setter functions
	point.SetX(xCord);
	point.SetY(yCord);

	// Print the string representation of the point
	cout << point.ToString() << endl;

	// Print the individual points using Getters
	cout << "Coordinates are: X: " << point.GetX() << ", Y: " << point.GetY() << endl;

	// Return successful execution
	return 0;
}