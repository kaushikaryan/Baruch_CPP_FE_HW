/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program creates four Point objects,
* asks the user for input, and displays their properties.
*
* @author:  Kaushik Aryan R
* @date:    23-05-2025
* @version: 1.0
*
**/

#include "Point.hpp"	// Header file for Point class
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
	Point* p1 = new Point();		// Using default constructor
	Point* p2 = new Point(6, 8);	// Using constructor that accepts X and Y coordinate
	Point* p3 = new Point(*p2);		// Using copy constructor

	// Printing string representation of points
	cout << *p1 << ", " << *p2 << ", " << *p3 << endl;

	// Using the Distance() function to print distance between points
	cout << "Distance between P1 & P2: " << p1->Distance(*p2) << "\n" << "Distance between P2 & P3: " << p2->Distance(*p3) << endl;

	// Deleting Point objects created on the heap
	delete p1;
	delete p2;
	delete p3;

	// Prompt the user for input
	cout << "Enter the size of the array: " << endl;
	unsigned int size = 0;

	if (!(cin >> size) || (size < 1))
	{
		cout << "Error: Invalid arguments provided." << endl;
		return 1;
	}

	// Creating an array on the stack using variable size, results in compiler error
	//Point* p4[size];
	
	// Creating an array using the new operator
	Point* p4 = new Point[size]; // Cannot use any other constructor other than default constructor

	// Delete array created on the heap
	delete[] p4;

	// Return successful execution
	return 0;
}