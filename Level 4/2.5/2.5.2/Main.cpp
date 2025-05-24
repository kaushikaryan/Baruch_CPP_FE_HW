/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program creates and deletes Point objects on the heap.
*
* @author:  Kaushik Aryan R
* @date:    24-05-2025
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
	// Creating an array of Point pointers on the heap
	Point** pArray = new Point*[3];
	
	// Initializing Point objects for each element of the array
	pArray[0] = new Point();				// Using default constructor
	pArray[1] = new Point(6, 8);			// Using constructor that accepts X and Y coordinate
	pArray[2] = new Point(*pArray[1]);		// Using copy constructor

	// Printing string representation of points
	for (int i = 0; i < 3; i++)
	{
		cout << *pArray[i] << endl;
	}

	// Deleting Point objects created on the heap
	for (int i = 0; i < 3; i++)
	{
		delete pArray[i];
	}

	// Delete array created on the heap
	delete[] pArray;

	// Return successful execution
	return 0;
}