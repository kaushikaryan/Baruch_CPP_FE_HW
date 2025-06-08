/**
*
* Main.cpp
*
* C++ program to test the Exception class.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#include <iostream>
#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"

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

	// Using GetElement on an index that does not exist
	try
	{
		cout << arrOne.GetElement(3) << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	// Return successful execution
	return 0;
}