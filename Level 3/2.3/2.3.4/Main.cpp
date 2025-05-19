/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program, gets x and y coordinates from the user, creates two Point objects,
* and displays their properties.
*
* @author:  Kaushik Aryan R
* @date:    17-05-2025
* @version: 1.5
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
	cout << "Provide the X and Y co-ordinates for Point #1: \n";
	if (!(cin >> xCord >> yCord))
	{
		cout << "Error: Invalid arguments provided." << endl;
		return 1;
	}

	// Create a Point object using the new constructor that accepts X and Y coordinates
	Point pointOne(xCord, yCord);

	// Prompt the user for input
	cout << "Provide the X and Y co-ordinates for Point #2: \n";
	if (!(cin >> xCord >> yCord))
	{
		cout << "Error: Invalid arguments provided." << endl;
		return 1;
	}

	// Create a Point object using the default constructor
	Point pointTwo(xCord, yCord);

	// Print the distance of the point from another point p
	cout << "The distance of Point #1 from Point #2 is: " << pointOne.Distance(pointTwo) << endl;

	const Point cp(1.5, 3.9);
	//cp.X(0.3); // Results in compiler error

	cout << cp.X() << endl;

	// Return successful execution
	return 0;
}