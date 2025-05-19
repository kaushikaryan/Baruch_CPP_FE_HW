/**
*
* Main.cpp
*
* C++ program to test the Circle class.
* The program, gets radius and x and y coordinates for center point
* of the circle from the user, creates a Circle object, and displays its properties.
*
* @author:  Kaushik Aryan R
* @date:    17-05-2025
* @version: 1.0
*
**/

#include <iostream>
#include "Circle.hpp"	// Header file for Circle class
#include "Point.hpp"	// Header file for Point class

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
	double x, y, radius;

	// Take input from user
	cout << "Enter the X and Y coordinates of the center point of the circle, followed by the radius" << endl;
	if (!(cin >> x >> y >> radius))
	{
		cout << "Error: Invalid inputs." << endl;
		return 1;
	}

	// Initialize Point object
	Point centerPoint(x, y);

	// Initialize Circle object
	Circle circle(centerPoint, radius);

	// Print the center point of the circle
	cout << "The center point of the circle is: " << circle.CentrePoint().ToString() << endl;

	// Print the radius of the circle
	cout << "The radius of the circle is: " << circle.Radius() << endl;

	// Print the diameter of the circle
	cout << "The diameter of the circle is: " << circle.Diameter() << endl;

	// Print the area of the circle
	cout << "The area of the circle is: " << circle.Area() << endl;

	// Print the circumference of the circle
	cout << "The circumference of the circle is: " << circle.Circumference() << endl;

	// Print the string representation of the circle
	cout << "The string representation of the circle- " << circle.ToString() << endl;

	// Indicate successful execution
	return 0;
}