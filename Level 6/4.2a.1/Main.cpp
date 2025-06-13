/**
*
* Main.cpp
* C++ program to test the Array class
*
* @author:  Kaushik Aryan R
* @date:    09-06-2025
* @version: 1.0
*
**/

#include <iostream>
#include "Point.hpp"
#include "Array.hpp"

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
	int size = 3;

	// Constructor that accepts size as argument
	Array<Point> points(size);

	// Default constructor
	Array<Point> pointArray;

	cout << "Size of pointArray: " << pointArray.Size() << endl;

	// Square bracket operator
	points[0] = Point(4, 5);
	points[1] = Point(6, 8);
	points[2] = Point(5, 12);

	cout << "points[0]: " << points[0] << endl;
	cout << "pointArray[2]: " << pointArray[2] << endl;

	// Assignment operator
	pointArray = points;

	// Getter for element of the array at index
	cout << "pointArray.GetElement(2): " << pointArray.GetElement(2) << endl;

	// Setter for element of the array at index
	pointArray.SetElement(2, Point(12, 13));

	// Return successful execution
	return 0;
}