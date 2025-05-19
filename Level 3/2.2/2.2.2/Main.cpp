/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program, gets x and y coordinates from the user, creates two Point objects,
* and displays their properties.
*
* @author:	Kaushik Aryan R
* @date:	17-05-2025
* @version:	1.1
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
	cout << "Provide the X and Y co-ordinates for Point #1:\n";
	if (!(cin >> xCord >> yCord))
	{
		cout << "Error: Invalid arguments provided." << endl;
		return 1;
	}

	// Create a Point object using the default constructor
	Point pointOne;

	// Set the coordinates using the setter functions
	pointOne.SetX(xCord);
	pointOne.SetY(yCord);

	// Print the string representation of the point
	cout << pointOne.ToString() << endl;

	// Print the individual points using Getters
	cout << "Coordinates are: X: " << pointOne.GetX() << ", Y: " << pointOne.GetY() << endl;

	// Print the distance of the point from the origin
	cout << "The distance of Point #1 from the origin is: " << pointOne.DistanceOrigin() << endl;

	// Prompt the user for input
	cout << "Provide the X and Y co-ordinates for Point #2:\n";
	if (!(cin >> xCord >> yCord))
	{
		cout << "Error: Invalid arguments provided." << endl;
		return 1;
	}

	// Create a Point object using the default constructor
	Point pointTwo;

	// Set the coordinates using the setter functions
	pointTwo.SetX(xCord);
	pointTwo.SetY(yCord);

	// Print the distance of the point from another point p
	cout << "The distance of Point #1 from Point #2 is: " << pointOne.Distance(pointTwo) << endl;

	// Return successful execution
	return 0;
}