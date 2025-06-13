/**
*
* Main.cpp
* C++ program to test the Array class
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#include <iostream>
#include "NumericArray.hpp"
#include "Point.hpp"

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
	// Default constructor
	NumericArray<double> doubleArray0;
	cout << "doubleArray0.Size(): " << doubleArray0.Size() << "\n";

	// Constructor that takes size as input
	NumericArray<double> doubleArray1(5);
	for (int i = 1; i < 6; i++)
		doubleArray1[i-1] = i;	// [] operator

	cout << "doubleArray1: " << doubleArray1.ToString() << "\n";

	// Scaling array by a factor
	NumericArray<double> doubleArray2(doubleArray1);	// Copy constructor
	doubleArray2 = doubleArray1 * 2.5;					// Assignment & * operators

	cout << "Scaling doubleArray1 by a factor of 2.5: " << doubleArray2.ToString() << "\n";

	// Sum of two arrays
	NumericArray<double> doubleArray3 = doubleArray1 + doubleArray2;
	cout << "Sum of doubleArray1 and doubleArray2: " << doubleArray3.ToString() << "\n";

	try
	{
		// Trying to find sum of arrays with unequal sizes
		NumericArray<double> doubleArray3 = doubleArray0 + doubleArray1;
	}
	catch (const ArrayException& e)
	{
		cout << e.GetMessage() << endl;
	}

	// Dot product of array
	doubleArray3 = doubleArray3 * 2;
	cout << "doubleArray3: " << doubleArray3.ToString();
	cout << "Dot Product of doubleArray1 and doubleArray3: " << doubleArray1.DotProduct(doubleArray3) << "\n";
	try
	{
		// Trying to find dot product of arrays with unequal sizes
		doubleArray1.DotProduct(doubleArray0);
	}
	catch (const ArrayException& e)
	{
		cout << e.GetMessage() << endl;
	}

	// Creating a NumericArray with Point objects
	NumericArray<Point> pointArray(5);
	cout << "Size of Point array: " << pointArray.Size();
	
	// Return successful execution
	return 0;
}

/*
* Assumptions made: 
* 
* T has a default constructor
* T has a default constructor that takes value as an input (T dotProduct = 0)
* 
* T supports the '+', '*', '+=', and '*=' operators
* 
* T supports the '<<' operator (stream << m_data[i])
* 
* Yes. We can create NumericArrays with Point objects. How ever, since the Point class 
* does not support all the operations/ operators supported by the NumericArray<T> class, 
* it cannot be used for the above operations.
* 
*/