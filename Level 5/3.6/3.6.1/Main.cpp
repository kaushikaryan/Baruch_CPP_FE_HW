/**
*
* Main.cpp
*
* C++ program to test the Array class.
* The program, initializes 4 Array objects
* and displays their properties and member functions.
*
* @author:  Kaushik Aryan R
* @date:    24-05-2025
* @version: 1.0
*
**/

#include "Point.hpp"	// Header file for Point class
#include "Array.hpp"	// Header file for Array class
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
	// Initializing array objects
	Array arrOne(3);	// Constructor that accepts size as argument

	// Assigning values to each element of arrTwo
	arrOne[0] = Point(0, 0);
	arrOne[1] = Point(1, 1);
	arrOne[2] = Point(3, 4);

	// Using GetElement on an index that does not exist
	//cout << arrOne.GetElement(3) << endl;
	// Output- Debug error, Abort() has been called

	// Using GetElement on an index that does not exist
	try
	{
		cout << arrOne.GetElement(3) << endl;
	}
	catch (int error)
	{
		if (error == -1)
			cout << "Error: Index out of bounds" << endl;
	}

	// Return successful execution
	return 0;
}