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
	Array arrOne;		// Default constructor
	Array arrTwo(3);	// Constructor that accepts size as argument

	// Assigning values to each element of arrTwo
	arrTwo[0] = Point(0, 0);
	arrTwo[1] = Point(1, 1);
	arrTwo[2] = Point(3, 4);

	// Print contents of arrayTwo
	cout << "\nContents of arrTwo: " << endl;
	for (int i = 0; i < arrTwo.Size(); i++)
	{
		cout << "arrTwo[" << i << "] = " << arrTwo[i] << endl;
	}

	// Assignment operator
	arrOne = arrTwo;

	// Print contents of arrOne
	cout << "\nContents of arrOne: " << endl;
	for (int i = 0; i < arrOne.Size(); i++)
	{
		cout << "arrOne[" << i << "] = " << arrOne[i] << endl;
	}

	// Copy constructor
	Array arrThree(arrTwo);

	// Print contents of arrThree, using [] operator
	cout << "\nContents of arrThree: " << endl;
	for (int i = 0; i < arrThree.Size(); i++)
	{
		cout << "arrThree[" << i << "] = " << arrThree[i] << endl;
	}

	// Using GetElement
	cout << "\narrThree.GetElement(2) = " << arrThree.GetElement(2) << endl;

	// Using SetElement
	arrThree.SetElement(2, Point(11, 13));
	cout << "arrThree.SetElement(2, Point(11, 13)) = " << arrThree.GetElement(2) << endl;

	// Getting Size
	cout << "arrThree.Size() = " << arrThree.Size() << endl;

	// Using [] operator on const Array object
	const Array arrFour(arrThree);

	// Print contents of arrThree
	cout << "\nContents of arrThree: " << endl;
	for (int i = 0; i < arrThree.Size(); i++)
	{
		cout << "arrThree[" << i << "] = " << arrThree[i] << endl;
	}

	// Return successful execution
	return 0;
}